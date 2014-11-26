// by commy2

private "_unit";

_unit = _this select 0;

if (side _unit == civilian || {side group AGM_player in (_unit getVariable ["AGM_nameKnownToSides", [side group _unit]])}) then {
  _unit getVariable ["AGM_Name", localize "STR_AGM_Core_Unknown"]
} else {
  localize "STR_AGM_Core_Unknown"
}
