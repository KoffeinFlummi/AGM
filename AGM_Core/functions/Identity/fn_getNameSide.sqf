// by commy2

private "_unit";

_unit = _this select 0;

if !(side group (call AGM_Core_fnc_player) in (_unit getVariable ["AGM_nameKnownToSides", [side group _unit]])) exitWith {
	localize "STR_AGM_Core_Unknown"
};

_unit getVariable ["AGM_Name", localize "STR_AGM_Core_Unknown"];
