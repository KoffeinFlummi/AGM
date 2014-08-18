// by commy2

private ["_unit", "_weapon", "_skipAnim", "_jammedWeapons", "_actionID", "_reloadAction"];

_unit = _this select 0;
_weapon = _this select 1;
_skipAnim = _this select 2;

_jammedWeapons = _unit getVariable ["AGM_Overheating_jammedWeapons", []];

if (_weapon in _jammedWeapons) then {
	_jammedWeapons = _jammedWeapons - [_weapon];

	_unit setVariable ["AGM_Overheating_jammedWeapons", _jammedWeapons];

	if (count _jammedWeapons == 0) then {
		_actionID = _unit getVariable ["AGM_JammingActionID", -1];
		//_unit removeAction _actionID;
		[_unit, "DefaultAction", _actionID] call AGM_Core_fnc_removeActionEventHandler;
		_unit setVariable ["AGM_JammingActionID", -1];
	};

	if !(_skipAnim) then {
		_reloadAction = getText (configFile >> "CfgWeapons" >> _weapon >> "reloadAction");
		_unit playActionNow _reloadAction;
	};

	[localize "STR_AGM_Overheating_WeaponUnjammed"] call AGM_Core_fnc_displayTextStructured;
};
