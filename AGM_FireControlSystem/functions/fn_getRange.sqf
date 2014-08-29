// by commy2

private ["_dlgRangefinder", "_range"];

disableSerialization;
_dlgRangefinder = uiNamespace getVariable ["AGM_dlgRangefinder", displayNull];

_range = ctrlText (_dlgRangefinder displayCtrl 151);
(_dlgRangefinder displayCtrl 1713151) ctrlSetText _range;

parseNumber _range

