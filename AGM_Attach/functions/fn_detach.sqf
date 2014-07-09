/*
Author: eRazeri and CAA-Picard

Detach an item from a unit

Arguments:
unit

Return Value:
none
*/

private ["_unit", "_itemName", "_count", "_attachedItem"];

_unit = _this;
_itemName = _unit getVariable ["AGM_AttachedItemName", ""];

// Check if unit has an attached item
if (_itemName == "") exitWith {};

// Add item to inventory
_count = count items _unit;
_unit addItem _itemName;
if ((count items _unit) <= _count) exitWith {
  [localize "STR_AGM_Attach_Inventory_Full"] call AGM_Core_fnc_displayTextStructured;
};

// Delete attached item
deleteVehicle (_unit getVariable "AGM_AttachedItem");

// Reset unit variables
_unit setVariable ["AGM_AttachedItemName","", true];
_unit setVariable ["AGM_AttachedItem",nil, true];

// Display message
switch (_itemName) do {
  case "AGM_IR_Strobe_Item" : {
    [localize "STR_AGM_Attach_IrStrobe_Off"] call AGM_Core_fnc_displayTextStructured;
  };
  default {
    if (true) exitWith {};
  };
};
