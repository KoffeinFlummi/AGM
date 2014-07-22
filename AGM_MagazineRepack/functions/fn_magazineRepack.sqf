// by commy2

private ["_magazines", "_ammoTotal", "_isValidArray", "_magazine", "_ammo", "_count", "_index"];

_magazines = [];
_ammoTotal = [];
_isValidArray = [];

// get all mags and ammo count
{
	_magazine = _x select 0;
	_ammo = _x select 1;

	_count = getNumber (configfile >> "CfgMagazines" >> _magazine >> "count");

	if !(_magazine in _magazines && _ammo != _count) then {
		_index = count _magazines;
		_magazines set [_index, _magazine];
		_ammoTotal set [_index, _ammo];

		_isValidArray set [_index, false];
	} else {
		_index = _magazines find _magazine;
		_ammoTotal set [_index, (_ammoTotal select _index) + _ammo];

		if !(_isValidArray select _index) then {
			_isValidArray set [_index, _count > 1];	// additional checks here
		};
	};
} forEach magazinesAmmoFull player;

// Remove invalid magazines
{
	if !(_x) then {
		_magazines set [_forEachIndex, -1];
		_ammoTotal set [_forEachIndex, -1];
	};
} forEach _isValidArray;

_magazines = _magazines - [-1];
_ammoTotal = _ammoTotal - [-1];

[_magazines, _ammoTotal] call AGM_MagazineRepack_fnc_openSelectMagazineUI;
