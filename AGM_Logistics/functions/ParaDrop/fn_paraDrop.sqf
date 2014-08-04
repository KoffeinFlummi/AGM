//marc_book, commy2

SMOKE = {
	_smoke = "SmokeshellYellow" createVehicle (_position);
	_smoke attachTo [_item, [0, 0, 0]];	
};

LIGHT = {
	_light = "Chemlight_yellow" createVehicle (_position);
	_light attachTo [_item, [0, 0, 0]];
};

_vehicle = vehicle player;
_items = _vehicle getVariable ["AGM_Logistics_loadedItems", []];
_count = count _items;
_item = _items select (_count - 1);
_items = _items - [_item];
_vehicle setVariable ["AGM_Logistics_loadedItems", _items, true];
_position = ((vectorDir _vehicle) vectorMultiply -15) vectorAdd getPosASL _vehicle;
detach _item;
_item setPosASL _position;
sleep 0.7;
_parachute = createVehicle ["B_Parachute_02_F", position _item, [], 0, "CAN_COLLIDE"];
_parachute attachTo [_item, [0, 0, 0]];
detach _parachute;
_item attachTo [_parachute, [0, 0, -1]];

_s = [] call SMOKE;
_l = [] call LIGHT;

waitUntil {sleep 0.1; position _item select 2 < 1};
_s = [] call SMOKE;
detach _item;
