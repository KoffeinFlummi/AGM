// by commy2

private ["_marker", "_data", "_config"];

_marker = _this select 0;

_data = uiNamespace getVariable "AGM_Map_currentMarkerData";

if (isNil "_data") exitWith {};

_config = (configfile >> "CfgMarkers") select (_data select 0);
_marker setMarkerType configName _config;

_config = (configfile >> "CfgMarkerColors") select (_data select 1);
_marker setMarkerColor configName _config;

_marker setMarkerDir (_data select 2);

uiNamespace setVariable ["AGM_Map_currentMarkerData", nil];
