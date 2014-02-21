/*
BWA3 function, by commy2
this code is property of the ArmA 3 Bundeswehr modification
ask us nicely at http://www.bwmod.de/ if you want to re-use any of this script
we don't support changed code based on this work
*/

_unit = _this select 0;
_firer = _this select 1;
_distance = _this select 2;
_weapon = _this select 3;

if (vehicle _unit != _unit) exitWith {};

_backblastAngle = getNumber (configFile >> "CfgWeapons" >> _weapon >> "BWA3_Backblast_Angle") / 2;
_backblastRange = getNumber (configFile >> "CfgWeapons" >> _weapon >> "BWA3_Backblast_Range");
_backblastDamage = getNumber (configFile >> "CfgWeapons" >> _weapon >> "BWA3_Backblast_Damage") * 2;

_position = eyePos _firer;
_direction = _firer weaponDirection currentWeapon _firer;

if (_unit == _firer) then {
	_direction set [0, (_position select 0) - _backblastRange * (_direction select 0)];
	_direction set [1, (_position select 1) - _backblastRange * (_direction select 1)];
	_direction set [2, (_position select 2) - _backblastRange * (_direction select 2)];

	_direction = [_position, _direction] call BWA3_Backblast_fnc_getDistance;

	_distance = _position distance _direction;

	if (_distance < _backblastRange) then {
		_alpha = sqrt (1 - _distance / _backblastRange);
		_beta = sqrt 0.5;

		_damage = 2 * _alpha * _beta * _backblastDamage;
		[_damage * 100] call BIS_fnc_bloodEffect;
		_unit setDamage (damage _unit + _damage);
	};
} else {
	_direction set [0, - (_direction select 0)];
	_direction set [1, - (_direction select 1)];
	_direction set [2, - (_direction select 2)];

	_azimuth = (_direction select 0) atan2 (_direction select 1);
	_inclination = asin (_direction select 2);

	_relativePosition = eyePos _unit;
	_relativeDirection = [_position, _relativePosition] call BWA3_Core_fnc_getDirectionVector;

	_relativeAzimuth = (_relativeDirection select 0) atan2 (_relativeDirection select 1);
	_relativeInclination = asin (_relativeDirection select 2);

	_angle = sqrt ((_relativeAzimuth - _azimuth) ^ 2 + (_relativeInclination - _inclination) ^ 2);
	_distance = _position distance _relativePosition;
	_line = [_position, _relativePosition];

	if (_angle < _backblastAngle && {_distance < _backblastRange} && {!lineIntersects _line} && {!terrainIntersectASL _line}) then {
		_alpha = sqrt (1 - _distance / _backblastRange);
		_beta = sqrt (1 - _angle / _backblastAngle);

		_damage = 2 * _alpha * _beta * _backblastDamage;
		if (_unit == player) then {[_damage * 100] call BIS_fnc_bloodEffect};
		_unit setDamage (damage _unit + _damage);
	};
};
