/*
Name: AGM_Attach_fnc_detach

Author: eRazeri and CAA-Picard

Detach an item from a unit

Arguments:
  0: OBJECT - unit doing the attaching (player)
  1: OBJECT - vehicle that it will be attached to (player or vehicle)

Return Value:
  none
*/
private ["_unit", "_attachToVehicle", "_attachToPointName", "_itemName", "_count", "_attachedItem"];

_unit = _this select 0;
_attachToVehicle = _this select 1;

_attachedObjectsArray = _attachToVehicle getVariable ["AGM_AttachedObjects", []];
_attachedItemsArray = _attachToVehicle getVariable ["AGM_AttachedItemNames", []];
_attachedObject = objNull;
_itemName = "";

//Find closest attached object
_minDistance = 1000;
_unitPos = getPos _unit;
_unitPos set [2,0];
{
  _objectPos = getPos _x;
  _objectPos set [2, 0];
  if ((_objectPos distance _unitPos) < _minDistance) then {
    _minDistance = (_objectPos distance _unitPos);
    _attachedObject = _x;
    _itemName = _attachedItemsArray select _forEachIndex;
  };
} forEach _attachedObjectsArray;

//Error Checking
if (isNull _attachedObject) exitWith {["AGM_Attach_fnc_detach - null _attachedObject [%1]", _this] call bis_fnc_error;};
if (_itemName == "") exitWith {["AGM_Attach_fnc_detach - _itemName is empty"] call bis_fnc_error;};

// Add item to inventory
_count = (count items _unit) + (count magazines _unit);
_unit addItem _itemName;
if ((count items _unit) + (count magazines _unit) <= _count) exitWith {
  [localize "STR_AGM_Attach_Inventory_Full"] call AGM_Core_fnc_displayTextStructured;
};

if (_itemName == "B_IR_Grenade" or _itemName == "O_IR_Grenade" or _itemName == "I_IR_Grenade") then {
  // Hack for dealing with X_IR_Grenade effect not dissapearing on deleteVehicle
  [_attachedObject, _unit] spawn {
    _attachedItem = _this select 0;
    _unit = _this select 1;
    detach _attachedItem;
    _attachedItem setPos [getPos _unit select 0, getPos _unit select 1, (getPos _unit select 2) -1000];
    sleep 0.5;
    deleteVehicle _attachedItem;
  };
} else {
  // Delete attached item
  deleteVehicle _attachedObject;
};

// Remove Deleted (null) entries
{
  if (isNull _x) then {
    _attachedObjectsArray deleteAt _forEachIndex;
    _attachedItemsArray deleteAt _forEachIndex;
  };
} forEach _attachedObjectsArray;
_attachToVehicle setVariable ["AGM_AttachedObjects", _attachedObjectsArray, true];
_attachToVehicle setVariable ["AGM_AttachedItemNames", _attachedItemsArray, true];

// Display message
switch true do {
case (_itemName == "AGM_IR_Strobe_Item") : {
    [localize "STR_AGM_Attach_IrStrobe_Detached"] call AGM_Core_fnc_displayTextStructured;
  };
case (_itemName == "B_IR_Grenade" or _itemName == "O_IR_Grenade" or _itemName == "I_IR_Grenade") : {
    [localize "STR_AGM_Attach_IrGrenade_Detached"] call AGM_Core_fnc_displayTextStructured;
  };
case (_itemName == "Chemlight_blue" or {_itemName == "Chemlight_green"} or {_itemName == "Chemlight_red"} or {_itemName == "Chemlight_yellow"}) : {
    [localize "STR_AGM_Attach_Chemlight_Detached"] call AGM_Core_fnc_displayTextStructured;
  };
  default {
    if (true) exitWith {};
  };
};
