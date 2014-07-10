/*
Author: eRazeri and CAA-Picard

Attach an item to the unit

Arguments:
0: unit
1: Item name

Return Value:
none
*/

private ["_unit", "_itemName", "_attachedItem"];

_unit = _this select 0;
_itemName = _this select 1;

// Check if unit has an attached item
if (_unit getVariable ["AGM_AttachedItemName", ""] != "") exitWith {};

// Check if the unit still has the item
if !(_itemName in items _unit ) exitWith {};

// Attach item
switch (_itemName) do {
  case "AGM_IR_Strobe_Item" : {
    _attachedItem = "AGM_IR_Strobe_Effect" createVehicle [0,0,0];
    _attachedItem attachTo [_unit,[0,-0.07,0.22],"neck"];//0,-0.05,0.19 looks good without helmet, 0,-0.07,0.22 looks good with helmet
    [localize "STR_AGM_Attach_IrStrobe_On"] call AGM_Core_fnc_displayTextStructured;
  };
  default {
    if (true) exitWith {};
  };
};

// Remove item
_unit removeItem _itemName;
_unit setVariable ["AGM_AttachedItemName", _itemName, true];
_unit setVariable ["AGM_AttachedItem", _attachedItem, true];
