// by commy2

_files = [];
{
	_addon = toArray _x;
	_addon resize 4; 
	_addon = toString _addon;

	if (_addon == "AGM_") then {
		_files set [count _files, _x];
	};
} forEach activatedAddons;

_versionMain = parseNumber getText (configFile >> "CfgPatches" >> "AGM_Core" >> "version");

_versions = [];
{
	_version = parseNumber getText (configFile >> "CfgPatches" >> _x >> "version");
	_versions set [_forEachIndex, _version];
} forEach _files;

if (isServer) then {
	diag_log text format ["[AGM] Server: agm_core is Version %1.", _versionMain];

	{
		_version = _versions select _forEachIndex;
		if (_version != _versionMain) then {
			diag_log text format ["[AGM] Server: %1 is Version %2.", _x, _version];
		};
	} forEach _files;

	AGM_Version_ServerVersions = [_files, _versions];
	publicVariable "AGM_Version_ServerVersions";
} else {
	diag_log text format ["[AGM] Client: AGM_Core is Version %1.", _versionMain];

	{
		_version = _versions select _forEachIndex;
		if (_version != _versionMain) then {
			diag_log text format ["[AGM] Client: %1 is Version %2.", _x, _version];
		};
	} forEach _files;

	AGM_Version_ClientVersions = [_files, _versions];
};

// Begin client version check 
if (!isServer) then {
	0 spawn {

		// Wait for server to send the servers files and version numbers
		waitUntil {
			sleep 1;
			!isNil "AGM_Version_ClientVersions" && {!isNil "AGM_Version_ServerVersions"}
		};

		_client = profileName;

		_files = AGM_Version_ClientVersions select 0;
		_versions = AGM_Version_ClientVersions select 1;

		_serverFiles = AGM_Version_ServerVersions select 0;
		_serverVersions = AGM_Version_ServerVersions select 1;

		// Compare client and server files and versions
		_missingAddons = [];
		_oldVersionsClient = [];
		_oldVersionsServer = [];
		{
			_serverVersion = _serverVersions select _forEachIndex;

			_index = _files find _x;
			if (_index == -1) then {
				_missingAddons set [count _missingAddons, _x];
			} else {

				_clientVersion = _versions select _index;

				if (_clientVersion < _serverVersion) then {
					_oldVersionsClient set [count _oldVersionsClient, [_x, _clientVersion, _serverVersion]];
				};

				if (_clientVersion > _serverVersion) then {
					_oldVersionsServer set [count _oldVersionsServer, [_x, _clientVersion, _serverVersion]];
				};
			};
		} forEach _serverFiles;

		// find client files which the server doesn't have
		_missingAddonsServer = [];
		{
			_index = _serverFiles find _x;
			if (_index == -1) then {
				_missingAddonsServer set [count _missingAddonsServer, _x];
			}
		} forEach _files;

		// display and log error messages
		_fnc_cutComma = {
			_string = _this;
			_string = toArray _string;

			_count = count _string;
			_string set [_count - 2, toArray "." select 0];
			_string set [_count - 1, -1];
			_string = _string - [-1];

			toString _string;
		};

		_missingAddon = false;
		if (count _missingAddons > 0) then {
			_missingAddon = true;

			_error = format ["[AGM] %1: ERROR missing addon(s): ", _client];
			{
				_error = _error + format ["%1, ", _x];
			} forEach _missingAddons;

			_error = _error call _fnc_cutComma;

			diag_log text _error;
			[_error, "{systemChat _this}"] call AGM_Core_fnc_execRemoteFnc;
		};

		_missingAddonServer = false;
		if (count _missingAddonsServer > 0) then {
			_missingAddonServer = true;

			_error = format ["[AGM] %1: ERROR missing server addon(s): ", _client];
			{
				_error = _error + format ["%1, ", _x];
			} forEach _missingAddonsServer;

			_error = _error call _fnc_cutComma;

			diag_log text _error;
			[_error, "{systemChat _this}"] call AGM_Core_fnc_execRemoteFnc;
		};

		_oldVersionClient = false;
		if (count _oldVersionsClient > 0) then {
			_oldVersionClient = true;

			_error = format ["[AGM] %1: ERROR outdated addon(s): ", _client];
			{
				_error = _error + format ["%1 (client: %2, server: %3), ", _x select 0, _x select 1, _x select 2];
			} forEach _oldVersionsClient;

			_error = _error call _fnc_cutComma;

			diag_log text _error;
			[_error, "{systemChat _this}"] call AGM_Core_fnc_execRemoteFnc;
		};

		_oldVersionServer = false;
		if (count _oldVersionsServer > 0) then {
			_oldVersionServer = true;

			_error = format ["[AGM] %1: ERROR outdated server addon(s): ", _client];
			{
				_error = _error + format ["%1 (client: %2, server: %3), ", _x select 0, _x select 1, _x select 2];
			} forEach _oldVersionsServer;

			_error = _error call _fnc_cutComma;

			diag_log text _error;
			[_error, "{systemChat _this}"] call AGM_Core_fnc_execRemoteFnc;
		};

		AGM_Version_ClientErrors = [_missingAddon, _missingAddonServer, _oldVersionClient, _oldVersionServer];
	};
};
