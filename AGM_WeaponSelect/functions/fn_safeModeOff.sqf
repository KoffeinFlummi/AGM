// by commy2

private ["_unit", "_muzzle", "_safedMuzzles", "_actionID"];

_unit = _this select 0;
_muzzle = _this select 1;

_safedMuzzles = _unit getVariable ["AGM_WeaponSelect_safedMuzzles", []];

if (_muzzle in _safedMuzzles) exitWith {
	_safedMuzzles = _safedMuzzles - [_muzzle];

	_unit setVariable ["AGM_WeaponSelect_safedMuzzles", _safedMuzzles];

	playSound "AGM_Sound_Click";

	// remove safe mode action
	if (count _safedMuzzles == 0) then {
		_actionID = _unit getVariable ["AGM_SafeModeActionID", -1];
		_unit removeAction _actionID;
		_unit setVariable ["AGM_SafeModeActionID", -1];
	};
	true
};
false
