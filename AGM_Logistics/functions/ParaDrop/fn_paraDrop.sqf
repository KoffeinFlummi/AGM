//marc_book, commy2, CAA-Picard, Ir0n1E
_this spawn {
  _vehicle      = _this select 0;
  _itemHolder   = (_this select 1) select 0;
  _varIndex     = (_this select 1) select 1;
  _item         = (_vehicle getVariable _itemHolder) select _varIndex;
  _loadedItems  = _vehicle getVariable [_itemHolder, []];

  if !(_item in _loadedItems) exitWith {};

  _fnc_smoke = {
    _smoke = "SmokeshellYellow" createVehicle (_position);
    _smoke attachTo [_item, [0, 0, 0]];
  };

  _fnc_light = {
    _light = "Chemlight_yellow" createVehicle (_position);
    _light attachTo [_item, [0, 0, 0]];
  };

  _loadedItems = _loadedItems - [_item];
  _vehicle setVariable [_itemHolder, _loadedItems, true];

  _position = ((vectorDir _vehicle) vectorMultiply -15) vectorAdd getPosASL _vehicle;

  detach _item;
  _item enableSimulationGlobal true;
  _item hideObjectGlobal false;
  [_item, "{{_x reveal _this} forEach allUnits}", 2] call AGM_Core_fnc_execRemoteFnc;

  _item setPosASL _position;

  sleep 0.7;

  _parachute = createVehicle ["B_Parachute_02_F", position _item, [], 0, "CAN_COLLIDE"];
  _parachute attachTo [_item, [0, 0, 0]];

  detach _parachute;
  _item attachTo [_parachute, [0, 0, -1]];

  _light = [] call _fnc_light;

  waitUntil {sleep 0.1; position _item select 2 < 1};
  detach _item;
  _smoke = [] call _fnc_smoke;
};