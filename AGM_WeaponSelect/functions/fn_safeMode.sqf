// by commy2

private ["_unit", "_muzzle", "_safedMuzzles", "_actionID"];

_unit = _this select 0;
_muzzle = _this select 1;

_safedMuzzles = _unit getVariable ["AGM_WeaponSelect_safedMuzzles", []];

if (_muzzle in _safedMuzzles) exitWith {};

_safedMuzzles set [count _safedMuzzles, _muzzle];

_unit setVariable ["AGM_WeaponSelect_safedMuzzles", _safedMuzzles];

playSound "AGM_Sound_Click";

// add safe mode action
if (_unit getVariable ["AGM_SafeModeActionID", -1] == -1) then {
	_actionID = _unit addAction [
		"",
		{},
		"",
		0,
		false,
		true,
		"DefaultAction",
		"player == vehicle player && {currentMuzzle player in (player getVariable ['AGM_WeaponSelect_safedMuzzles', []])}"
	];

	_unit setVariable ["AGM_SafeModeActionID", _actionID];
};
