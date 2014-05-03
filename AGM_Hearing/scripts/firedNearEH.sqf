// by commy2

_unit = _this select 0;
_firer = _this select 1;
_distance = _this select 2;
_weapon = _this select 3;
_muzzle = _this select 4;
_mode = _this select 5;
_ammo = _this select 6;

_loudness = configFile >> "CfgAmmo" >> _ammo >> "audiblefire";

_time = time;
_loudness = _loudness / _distance ^ 2;

player getVariable ["", ];


hint str _loudness;
