// by commy2

private ["_weapon", "_modes"];

_weapon = _this select 0;

_modes = [];
{
	if (getNumber (configFile >> "CfgWeapons" >> _weapon >> _x >> "showToPlayer") == 1) then {
		_modes set [count _modes, _x];
	};
	if (_x == "this") then {
		_modes set [count _modes, _weapon];
	};
} forEach getArray (configfile >> "CfgWeapons" >> _weapon >> "modes");

_modes
