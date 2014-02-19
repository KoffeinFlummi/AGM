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

_backblastAngle = getNumber (configFile >> "CfgWeapons" >> _weapon >> "BWA3_Backblast_Angle") / 2;
_backblastRange = getNumber (configFile >> "CfgWeapons" >> _weapon >> "BWA3_Backblast_Range");
_backblastDamage = getNumber (configFile >> "CfgWeapons" >> _weapon >> "BWA3_Backblast_Damage") * 2;

_position = eyePos _firer;
_direction = direction _firer;

if (_unit == _firer) then {
	_line = [
		_position,
		[
			(_position select 0) - (sin _direction) * _backblastRange,
			(_position select 1) - (cos _direction) * _backblastRange,
			_position select 2
		]
	];

	_hitSelf = false;
	{
		if (_x isKindOf "Static" || {_x isKindOf "AllVehicles"}) then {
			_hitSelf = true;
		};
	} forEach lineIntersectsWith _line;

	if (terrainIntersectASL _line) then {
		_hitSelf = true;
	};

	if (_hitSelf) then {
		_damage = _backblastDamage / 2;
		[_damage * 100] call BIS_fnc_bloodEffect;
		_unit setDamage (damage _unit + _damage);
	};
} else {
	if (vehicle _unit != _unit) exitWith {};

	if (_direction > 180) then {_direction = _direction - 360};

	_relativePosition = eyePos _unit;
	_relativeDirection = ((_position select 0) - (_relativePosition select 0)) atan2 ((_position select 1) - (_relativePosition select 1));

	_difference = abs ((_direction + 360) - (_relativeDirection + 360));
	_height = abs ((_position select 2) - (_relativePosition select 2));

	if (_distance < _backblastRange && {_difference < _backblastAngle} && {_height < 1} && {!lineIntersects [_position, _relativePosition, _unit, _firer]}) then {
		_alpha = sqrt (1 - _difference / _backblastAngle);
		_beta = sqrt (1 - _distance / _backblastRange);

		_damage = _backblastDamage * 2 * _alpha * _beta;
		if (_unit == player) then {[_damage * 100] call BIS_fnc_bloodEffect};
		_unit setDamage (damage _unit + _damage);
	};
};
