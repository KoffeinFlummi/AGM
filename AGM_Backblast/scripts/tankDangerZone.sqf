// by commy2

#define BARREL_MUZZLE "usti hlavne"

_unit = _this select 0;
_vehicle = vehicle (_this select 1);
_distance = _this select 2;
_weapon = _this select 3;

if (vehicle _unit != _unit) exitWith {};

_dangerZoneAngle = getNumber (configFile >> "CfgWeapons" >> _weapon >> "AGM_DangerZone_Angle") / 2;
_dangerZoneRange = getNumber (configFile >> "CfgWeapons" >> _weapon >> "AGM_DangerZone_Range");
_dangerZoneDamage = getNumber (configFile >> "CfgWeapons" >> _weapon >> "AGM_DangerZone_Damage") * 2;

_position = ATLToASL (_vehicle modelToWorld (_vehicle selectionPosition BARREL_MUZZLE));
_direction = _vehicle weaponDirection _weapon;

if (_unit != _vehicle) then {
	_azimuth = (_direction select 0) atan2 (_direction select 1);
	_inclination = asin (_direction select 2);

	_relativePosition = eyePos _unit;
	_relativeDirection = [_position, _relativePosition] call AGM_Backblast_getDirectionVector;

	_relativeAzimuth = (_relativeDirection select 0) atan2 (_relativeDirection select 1);
	_relativeInclination = asin (_relativeDirection select 2);

	_angle = sqrt ((_relativeAzimuth - _azimuth) ^ 2 + (_relativeInclination - _inclination) ^ 2);
	_distance = sqrt (
		((_position select 0) - (_relativePosition select 0)) ^ 2 +
		((_position select 1) - (_relativePosition select 1)) ^ 2 +
		((_position select 2) - (_relativePosition select 2)) ^ 2
	);
	_line = [_position, _relativePosition];

	if (_angle < _dangerZoneAngle && {_distance < _dangerZoneRange} && {!lineIntersects (_line + [_vehicle])} && {!terrainIntersectASL _line}) then {
		_alpha = sqrt (1 - _distance / _dangerZoneRange);
		_beta = sqrt (1 - _angle / _dangerZoneAngle);

		_damage = 2 * _alpha * _beta * _dangerZoneDamage;
		if (_unit == player) then {[_damage * 100] call BIS_fnc_bloodEffect};
		_unit setDamage (damage _unit + _damage);
	};
};
