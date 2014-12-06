/*
Author: eRazeri and CAA-Picard

Detach an item from a unit

Arguments:
  0: OBJECT - unit doing the attaching (player)
  1: OBJECT - vehicle that it will be attached to (player or vehicle)
  2: STRING - placement point name (self, right, left, back)

Return Value:
  none
*/
private ["_unit", "_attachToVehicle", "_attachToPointName", "_itemName", "_count", "_attachedItem"];

_unit = _this select 0;
_attachToVehicle = _this select 1;
_attachToPointName = _this select 2;

_itemName = _attachToVehicle getVariable [(format ["AGM_AttachedItemName_%1", _attachToPointName]), ""];

// Check if unit has an attached item
if (_itemName == "") exitWith {};

// Add item to inventory
_count = (count items _unit) + (count magazines _unit);
_unit addItem _itemName;
if ((count items _unit) + (count magazines _unit) <= _count) exitWith {
  [localize "STR_AGM_Attach_Inventory_Full"] call AGM_Core_fnc_displayTextStructured;
};

if (_itemName == "B_IR_Grenade" or _itemName == "O_IR_Grenade" or _itemName == "I_IR_Grenade") then {
  // Hack for dealing with X_IR_Grenade effect not dissapearing on deleteVehicle
  [(_attachToVehicle getVariable [(format ["AGM_AttachedItem_%1", _attachToPointName]), objNull]), _unit] spawn {
    _attachedItem = _this select 0;
    _unit = _this select 1;
    detach _attachedItem;
    _attachedItem setPos [getPos _unit select 0, getPos _unit select 1, (getPos _unit select 2) -1000];
    sleep 0.5;
    deleteVehicle _attachedItem;
  };
}
else
{
  // Delete attached item
  deleteVehicle (_attachToVehicle getVariable [(format ["AGM_AttachedItem_%1", _attachToPointName]), objNull]);
};

// Reset unit variables
_attachToVehicle setVariable [(format ["AGM_AttachedItemName_%1", _attachToPointName]), "", true];
_attachToVehicle setVariable [(format ["AGM_AttachedItem_%1", _attachToPointName]), nil, true];

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
