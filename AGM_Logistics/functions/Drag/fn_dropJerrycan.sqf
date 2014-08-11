// by commy2

_unit = _this select 0;
_target =_this select 1;

_unit setVariable ["AGM_isDragging", false];
_unit setVariable ["AGM_carriedItem", objNull, true];
_target setVariable ["AGM_isUsedBy", objNull, true];

_unit allowDamage false;
detach _target;
_unit forceWalk false;
_unit allowDamage true;

_unit removeAction AGM_Drag_ReleaseActionID;

[_target, "{_this setVectorUp (surfaceNormal getPosASL _this)}", _target] call AGM_Core_fnc_execRemoteFnc;
