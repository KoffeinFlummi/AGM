/*
Author: eRazeri and CAA-Picard

Attach an item to the unit

Arguments:
  0: OBJECT - unit doing the attaching (player)
  1: OBJECT - vehicle that it will be attached to (player or vehicle)
  2: STRING - placement point name (self, right, left, back)
  3: STRING - classname of attached item (from CfgMagazines or CfgWeapons)

Return Value:
  none
*/
private ["_unit", "_attachToVehicle", "_attachToPointName", "_itemName", "_attachPosition", "_attachedItem"];

_unit = _this select 0;
_attachToVehicle = _this select 1;
_attachToPointName = _this select 2;
_itemName = _this select 3;

// Check if unit has an attached item
if (_attachToVehicle getVariable [(format ["AGM_AttachedItemName_%1", _attachToPointName]), ""] != "") exitWith {};

// Check if the unit still has the item
if !((_itemName in items _unit) or (_itemName in magazines _unit)) exitWith {};

_attachPosition = if (_unit == _attachToVehicle) then {
  [_unit, [-0.05,0,0.12], "rightshoulder"];
} else {
  [_attachToVehicle, ([_attachToVehicle, _attachToPointName] call AGM_Attach_fnc_vehicleGetAttachPoint)];
};

_attachedItem = objNull;


switch true do {
  case (_itemName == "AGM_IR_Strobe_Item"): {
    _attachedItem = "AGM_IR_Strobe_Effect" createVehicle [0,0,0];
    if (_unit == _attachToVehicle) then {_attachPosition = [_unit,[0,-0.11,0.16],"pilot"];};  //makes it attach to the head a bit better, shoulder is not good for visibility - eRazeri
    [localize "STR_AGM_Attach_IrStrobe_Attached"] call AGM_Core_fnc_displayTextStructured;
  };
  case (_itemName == "B_IR_Grenade"): {
    _attachedItem = "B_IRStrobe" createVehicle [0,0,0];
    [localize "STR_AGM_Attach_IrGrenade_Attached"] call AGM_Core_fnc_displayTextStructured;
  };
  case (_itemName == "O_IR_Grenade"): {
    _attachedItem = "O_IRStrobe" createVehicle [0,0,0];
    [localize "STR_AGM_Attach_IrGrenade_Attached"] call AGM_Core_fnc_displayTextStructured;
  };
  case (_itemName == "I_IR_Grenade"): {
    _attachedItem = "I_IRStrobe" createVehicle [0,0,0];
    [localize "STR_AGM_Attach_IrGrenade_Attached"] call AGM_Core_fnc_displayTextStructured;
  };
  case (_itemName == "Chemlight_blue" or {_itemName == "Chemlight_green"} or {_itemName == "Chemlight_red"} or {_itemName == "Chemlight_yellow"}): {
    _attachedItem = _itemName createVehicle [0,0,0];
    [localize "STR_AGM_Attach_Chemlight_Attached"] call AGM_Core_fnc_displayTextStructured;
  };
  default {
    if (true) exitWith {};
  };
};

if (isNull _attachedItem) exitWith {["AGM_Attach_fnc_attach - could not createVehicle from Item [%1]", _itemName] call bis_fnc_error;};

// Attach item
_attachedItem attachTo _attachPosition;

// Remove item
_unit removeItem _itemName;

_attachToVehicle setVariable [(format ["AGM_AttachedItemName_%1", _attachToPointName]), _itemName, true];
_attachToVehicle setVariable [(format ["AGM_AttachedItem_%1", _attachToPointName]), _attachedItem, true];
