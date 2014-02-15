0 spawn {
  waitUntil {!isNull (findDisplay 46)};
  (findDisplay 46) displayAddEventHandler ["KeyDown", "[_this select 1, _this select 2, _this select 3] call BWA3_Scripts_keyInput"];
};

BWA3_Scripts_keyInput = {
  _key = _this select 0;
  _shft = _this select 1;
  _ctrl = _this select 2;
  _isInput = false;

  if (player == vehicle player) then {
    if (_key == 19 && {_ctrl} && {BWA3_isWeaponJammed}) then {
      playSound "BWA3_click";
      call BWA3_clearJam;
      _isInput = true;
    };
    _isInput
  };
};

_temperature = 0;
_time = time;

BWA3_isWeaponJammed = false;
player setVariable ["BWA3_Overheat", [_temperature, _time], false];

BWA3_clearJam = {
  BWA3_isWeaponJammed = false;
};

BWA3_weaponJamming = {
  BWA3_isWeaponJammed = true;
  waitUntil {
    player setWeaponReloadingTime [player, currentWeapon player, 0.55];
    !BWA3_isWeaponJammed || {inputAction "reloadMagazine" > 0}
  };
  BWA3_isWeaponJammed = false;
};

BWA3_weaponOverheat = {
  _unit = _this select 0;
  _weapon = _this select 1;
  _ammo = _this select 5;
  _projectile = _this select 6;

  if (!local _unit) exitwith {};
  if (!isPlayer _unit) exitwith {};
  if !(_unit == player) exitwith {};

  #define INCREMENT 0.02
  #define COOLDOWN 0.01

  _overheat = player getVariable "BWA3_Overheat";
  _temperature = _overheat select 0;
  _time = _overheat select 1;

  _temperature = (_temperature + INCREMENT) * (1 / (COOLDOWN * (time - _time) + 1) ^ 2);
  hint ("Temp.:" + str(_temperature) + "\n" + "Zeit:" + str(time - _time));
  _time = time;

  player setVariable ["BWA3_Overheat", [_temperature, _time], false];

  if (_temperature > 1 + random 10) then {
    0 spawn BWA3_weaponJamming;
  };
};

player addEventHandler ["fired", "_this call BWA3_weaponOverheat"];