// by commy2

private ["_unit", "_side"];

_unit = _this select 0;
_side = _this select 1;

_unit getVariable ['AGM_canMoveRallypoint', false]
&& {_side in [west, east, independent]}
&& {!isNull ([AGM_Rallypoint_West, AGM_Rallypoint_East, AGM_Rallypoint_Independent] select ([west, east, independent] find _side))}
