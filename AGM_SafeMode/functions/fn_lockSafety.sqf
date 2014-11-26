// by commy2

private ["_unit", "_weapon", "_safedWeapons"];

_unit = _this select 0;
_weapon = _this select 1;

// don't immediately switch back
if (inputAction "nextWeapon" > 0) exitWith {};

_safedWeapons = _unit getVariable ["AGM_SafeMode_safedWeapons", []];

if (_weapon in _safedWeapons) exitWith {
  _this call AGM_SafeMode_fnc_unlockSafety;
};

_safedWeapons pushBack _weapon;

_unit setVariable ["AGM_SafeMode_safedWeapons", _safedWeapons];

if (_unit getVariable ["AGM_SafeWeapon_actionID", -1] == -1) then {
  private ["_condition", "_statement", "_actionID"];

  _condition = {
    if (
      [_this select 1] call AGM_Core_fnc_canUseWeapon
      && {
        if (inputAction "nextWeapon" > 0) then {
          [_this select 1, currentWeapon (_this select 1)] call AGM_SafeMode_fnc_unlockSafety;
        };
        currentMuzzle (_this select 1) in ((_this select 1) getVariable ["AGM_SafeMode_safedWeapons", []])
      }
    ) then {
      // player hud
      [false] call AGM_SafeMode_fnc_setSafeModeVisual;
      true
    } else {
      // player hud
      [true] call AGM_SafeMode_fnc_setSafeModeVisual;
      false
    }
  };

  _statement = {
    [_this select 1, currentWeapon (_this select 1)] call AGM_SafeMode_fnc_unlockSafety;
  };

  _actionID = [_unit, format ["<t color=""#FFFF00"" >%1</t>", localize "STR_AGM_SafeMode_TakeOffSafety"], "DefaultAction", _condition, {}, {true}, _statement, 10] call AGM_Core_fnc_addActionMenuEventHandler;

  _unit setVariable ["AGM_SafeWeapon_actionID", _actionID];
};

_unit selectWeapon _weapon;

// play fire mode selector sound
[_unit, _weapon] call AGM_SafeMode_fnc_playChangeFiremodeSound;

private "_picture";
_picture = getText (configFile >> "CfgWeapons" >> _weapon >> "picture");
[localize "STR_AGM_SafeMode_PutOnSafety", _picture] call AGM_Core_fnc_displayTextPicture;
