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

_versions = [];
{
	_version = parseNumber getText (configFile >> "CfgPatches" >> _x >> "version");
	_versions set [_forEachIndex, _version];
} forEach _files;

if (isServer) then {
	{
		diag_log text format ["AGM Server: %1 is Version %2.", _x, _versions select _forEachIndex];
	} forEach _files;

	AGM_Version_ServerVersions = [_files, _versions];
	publicVariable "AGM_Version_ServerVersions";

} else {
	[_files, _versions] spawn {
		_files = _this select 0;
		_versions = _this select 1;

		waitUntil {
			sleep 5;
			!isNil "AGM_Version_ServerVersions"
		};

		_serverFiles = AGM_Version_ServerVersions select 0;
		_serverVersions = AGM_Version_ServerVersions select 1;

		_missingAddon = false;
		_oldVersionClient = false;
		_oldVersionServer = false;
		{
			_serverVersion = _serverVersions select _forEachIndex;

			_index = _files find _x;
			if (_index == -1) then {
				_missingAddon = true;
				diag_log text format ["AGM Client: ERROR addon %1 is missing.", _x];
			} else {

				_clientVersion = _versions select _index;

				if (_clientVersion < _serverVersion) then {
					_oldVersionClient = true;
					diag_log text format ["AGM Client: ERROR addon %1 is outdated. Server: %2, Client: %3", _x, _serverVersion, _clientVersion];
				};

				if (_clientVersion > _serverVersion) then {
					_oldVersionServer = true;
					diag_log text format ["AGM Client: ERROR addon %1 is newer than server addon. Server: %2, Client: %3", _x, _serverVersion, _clientVersion];
				};
			};
		} forEach _serverFiles;

		//TBC
	};
};
