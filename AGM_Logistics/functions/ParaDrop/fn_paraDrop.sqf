//marc_book, commy2, Ir0n1E

// We have to spawn this function (waitUntil and sleep construction)
_this spawn {
	private ["_vehicle", "_fnc_smoke", "_fnc_light", "_items", "_count", "_item", "_position", "_parachute", "_smoke", "_light"];

	_vehicle = _this select 0;

	_fnc_smoke = {
		_smoke = "SmokeshellYellow" createVehicle (_position);
		_smoke attachTo [_item, [0, 0, 0]];
	};

	_fnc_light = {
		_light = "Chemlight_yellow" createVehicle (_position);
		_light attachTo [_item, [0, 0, 0]];
	};

	_items = _vehicle getVariable ["AGM_Logistics_loadedItems", []];
	_count = count _items;
	_item = _items select (_count - 1);
	_items = _items - [_item];

	_vehicle setVariable ["AGM_Logistics_loadedItems", _items, true];
	_position = ((vectorDir _vehicle) vectorMultiply -15) vectorAdd getPos _vehicle;

	detach _item;

	//Ramdom Parachute Positions - Like MCC Parachute
	_dir = (direction _vehicle) + (random 180);
	_item setPos _position;
	_item setDir ((_dir)-5+(random 10));
	_parachute = createVehicle ["B_Parachute_02_F", position _item, [], 0, 'NONE'];

	_parachute setPos (getPos _item);
	_parachute setDir ((_dir)-5+(random 10));
	_item setDir (direction _parachute);
	_parachute setPos (getPos _item);
	_item setDir ((_dir)-5+(random 10));
	_parachute attachTo [_item, [0, 0, 0]];

	detach _parachute;
	_item attachTo [_parachute, [0, 0, -1]];

	//_smoke = [] call _fnc_smoke;
	_light = [] call _fnc_light;

	waitUntil {sleep 0.1; position _item select 2 < 1};
	//_smoke = [] call _fnc_smoke; Smoke, yes or no
	detach _item;
};