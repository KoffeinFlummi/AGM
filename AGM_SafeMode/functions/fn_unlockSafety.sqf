// by commy2

private ["_unit", "_weapon", "_safedWeapons"];

_unit = _this select 0;
_weapon = _this select 1;

_safedWeapons = _unit getVariable ["AGM_SafeMode_safedWeapons", []];

if (_weapon in _safedWeapons) then {
  _safedWeapons = _safedWeapons - [_weapon];

  _unit setVariable ["AGM_SafeMode_safedWeapons", _safedWeapons];

  if (count _safedWeapons == 0) then {
  	private "_actionIDs";

    _actionIDs = _unit getVariable ["AGM_SafeWeaponActionIDs", [-1, -1]];
    //_unit removeAction _actionID;
    [_unit, "DefaultAction", _actionIDs select 0] call AGM_Core_fnc_removeActionMenuEventHandler;
    [_unit, "nextWeapon",    _actionIDs select 1] call AGM_Core_fnc_removeActionEventHandler;
    _unit setVariable ["AGM_SafeWeaponActionIDs", [-1, -1]];
  };
};

_unit selectWeapon _weapon;

// play fire mode selector sound
[_unit, _weapon] call AGM_SafeMode_fnc_playChangeFiremodeSound;

// player hud
[true] call AGM_SafeMode_fnc_setSafeModeVisual;
