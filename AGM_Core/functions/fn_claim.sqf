// by commy2

private ["_unit", "_target", "_owner"];

_unit = _this select 0;
_target = _this select 1;

_owner = _target getVariable ["AGM_isUsedBy", objNull];

if (!isNull _owner && {_unit != _owner}) then {
	diag_log text "[AGM] ERROR: Claiming already owned object.";
};

_target setVariable ["AGM_isUsedBy", _unit, true];
