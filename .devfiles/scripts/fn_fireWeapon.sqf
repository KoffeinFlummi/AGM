// by commy2

private ["_unit", "_muzzle", "_mode", "_index", "_logic"];

_this resize 3;

_unit = _this select 0;
_muzzle = _this select 1;  // optional
_mode = _this select 2;    // optional

// execute on local unit
if (!local _unit) exitWith {
  [_this, _fnc_scriptName, _unit] call AGM_Core_fnc_execRemoteFnc;
};

// set default values
if (isNil "_muzzle") then {_muzzle = currentMuzzle _unit};
if (isNil "_mode") then {_mode = currentWeaponMode _unit};

// get weapon index
_unit action ["SwitchWeapon", _unit, _unit, 0];

_index = -1;
while {
    _index = _index + 1;
    _index < 100 && {currentMuzzle _unit != _muzzle || {currentWeaponMode _unit != _mode}}
} do {
    _unit action ["SwitchWeapon", _unit, _unit, _index];
};

// fire weapon with this index
_logic = createGroup sideLogic createUnit ["Logic", [0,0,0], [], 0, "NONE"];
_logic action ["useWeapon", _unit, _unit, _index];
deleteVehicle _logic;
