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
	{
		diag_log text format ["AGM Client: %1 is Version %2.", _x, _versions select _forEachIndex];
	} forEach _files;

	AGM_Version_ClientVersions = [_files, _versions];
};
