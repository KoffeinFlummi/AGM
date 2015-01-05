// by commy2

["test", "onEachFrame", {

	_unit = player;
	_range = 30;

	_p0 = _unit modelToWorld (_unit selectionPosition "righthand");
	_d  = _unit weaponDirection currentWeapon _unit;

	_p1 = _p0 vectorAdd (_d vectorMultiply _range);

	_offset0 = getTerrainHeightASL _p0;
	_offset1 = getTerrainHeightASL _p1;

	_p1 = _p1 vectorAdd [0, 0, _offset0 - _offset1];

	_fnc_getDistance = {
		private "_distance";

		_pX = + _p0;
		_line = [ATLToASL _p0, ATLToASL _pX];

		_distance = _this;
		_iteration = _distance;

		while {
			_iteration > 0.01 / 2
		} do {
			_iteration = _iteration / 2;

			_pX = _p0 vectorAdd (_d vectorMultiply _distance);

			_offsetX = getTerrainHeightASL _pX;

			_pX = _pX vectorAdd [0, 0, _offset0 - _offsetX];

			_line set [1, ATLToASL _pX];

			_distance = _distance + (([1, -1] select (lineIntersects (_line + [_unit]) || {terrainIntersectASL _line})) * _iteration);

			if (_distance > _this) exitWith {_distance = _this};
		};

		_distance
	};

	_distance = _range call _fnc_getDistance;

	_units = nearestObjects [_unit, ["CAManbase"], _distance];
	_units deleteAt (_units find _unit);

	_fnc_doesIntersect = {
		_pX = _p0 vectorAdd (_d vectorMultiply (_this select 1));

		_offsetX = getTerrainHeightASL _pX;

		_pX = _pX vectorAdd [0, 0, _offset0 - _o1];

		count ([_this select 0, "FIRE"] intersect [_p0, _pX]) > 0
	};

	{
		if ([_x, _distance] call _fnc_doesIntersect) then {
			_distance = _distance min (_unit distance _x);
		};
	} forEach _units;

	comment str _distance;

	_pL = _p0 vectorAdd (_d vectorMultiply _distance);

	_offsetL = getTerrainHeightASL _pL;

	_pL = _pL vectorAdd [0, 0, _offset0 - _offsetL];

	_spL = worldToScreen _pL;

	systemChat str _spL;

	drawLine3D [
		_p0,
		_pL,
		[1,0,0,1]
	];

}] call BIS_fnc_addStackedEventhandler;








































