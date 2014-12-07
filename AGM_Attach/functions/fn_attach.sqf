/*
Name: AGM_Attach_fnc_attach

Author: eRazeri and CAA-Picard

Attach an item to the unit.  For vehicles, it starts the custom placement)

Arguments:
0: OBJECT - unit doing the attaching (player)
1: OBJECT - vehicle that it will be attached to (player or vehicle)
2: STRING - classname of attached item (from CfgMagazines or CfgWeapons)

Return Value:
none
*/
private ["_unit", "_attachToVehicle", "_attachToPointName", "_itemName", "_attachPosition", "_attachedItem"];

_unit = _this select 0;
_attachToVehicle = _this select 1;
_itemName = _this select 2;

// For Self Placement - Check if unit has an attached item
if (_unit == _attachToVehicle) then {
  if ((count (_attachToVehicle getVariable ["AGM_AttachedObjects", []])) > 0) exitWith {};
};

// Check if the unit still has the item
if !((_itemName in items _unit) or (_itemName in magazines _unit)) exitWith {};

_selfAttachPosition = [_unit, [-0.05,0,0.12], "rightshoulder"];
_itemVehClass = "";
_onAtachText = "";

switch true do {
case (_itemName == "AGM_IR_Strobe_Item"): {
    _itemVehClass = "AGM_IR_Strobe_Effect";
    _onAtachText = localize "STR_AGM_Attach_IrStrobe_Attached";
    _selfAttachPosition = [_unit,[0,-0.11,0.16],"pilot"];  //makes it attach to the head a bit better, shoulder is not good for visibility - eRazeri
  };
case (_itemName == "B_IR_Grenade"): {
    _itemVehClass = "B_IRStrobe";
    _onAtachText = localize "STR_AGM_Attach_IrGrenade_Attached";
  };
case (_itemName == "O_IR_Grenade"): {
    _itemVehClass = "O_IRStrobe";
    _onAtachText = localize "STR_AGM_Attach_IrGrenade_Attached";
  };
case (_itemName == "I_IR_Grenade"): {
    _itemVehClass = "I_IRStrobe";
    _onAtachText = localize "STR_AGM_Attach_IrGrenade_Attached";
  };
case (_itemName == "Chemlight_blue" or {_itemName == "Chemlight_green"} or {_itemName == "Chemlight_red"} or {_itemName == "Chemlight_yellow"}): {
    _itemVehClass = _itemName;
    _onAtachText = localize "STR_AGM_Attach_Chemlight_Attached";
  };
  default {
    if (true) exitWith {};
  };
};

if (_itemVehClass == "") exitWith {["AGM_Attach_fnc_attach - no _itemVehClass for Item [%1]", _itemName] call bis_fnc_error;};

if (_unit == _attachToVehicle) then {  //Self Attachment
  _unit removeItem _itemName;  // Remove item
  _attachedItem = _itemVehClass createVehicle [0,0,0];
  _attachedItem attachTo _selfAttachPosition;
  [_onAtachText] call AGM_Core_fnc_displayTextStructured;
  _attachToVehicle setVariable ["AGM_AttachedObjects", [_attachedItem], true];
  _attachToVehicle setVariable ["AGM_AttachedItemNames", [_itemName], true];
} else {
  AGM_Attach_SetupObject = _itemVehClass createVehicleLocal [0,0,-10000];
  AGM_Attach_SetupObject enableSimulationGlobal false;
  AGM_Attach_SetupPlacmentText = _onAtachText;
  AGM_Attach_SetupPlacmentItem = _itemName;
  AGM_Attach_SetupAttachVehicle = _attachToVehicle;
  AGM_Attach_placer = _unit;
  _unit forceWalk true;

  ["AGM_Attach_Placement","OnEachFrame", {
    private "_player";
    _player = AGM_player;
	//Stop if player switch or player gets to far from vehicle
    if ((AGM_Attach_placer != _player) || ((_player distance AGM_Attach_SetupAttachVehicle) > 9)) exitWith {
      call AGM_Attach_fnc_Place_Cancel;
    };
    AGM_Attach_pfeh_running = true;
    _pos = (ASLtoATL eyePos _player) vectorAdd (positionCameraToWorld [0,0,1] vectorDiff positionCameraToWorld [0,0,0]);
    AGM_Attach_SetupObject setPosATL _pos;
  }] call BIS_fnc_addStackedEventHandler;

  //had to spawn the mouseHint, not sure why
  [localize "STR_AGM_Attach_PlaceAction", localize "STR_AGM_Attach_CancelAction"] spawn AGM_Interaction_fnc_showMouseHint;
  _unit setVariable ["AGM_Attach_Place", [_unit, "DefaultAction", {AGM_Attach_pfeh_running AND !isNull (AGM_Attach_SetupObject)}, {call AGM_Attach_fnc_Place_Approve;}] call AGM_Core_fnc_AddActionEventHandler];
  _unit setVariable ["AGM_Attach_Cancel", [_unit, "MenuBack", {AGM_Attach_pfeh_running AND !isNull (AGM_Attach_SetupObject)}, {call AGM_Attach_fnc_Place_Cancel;}] call AGM_Core_fnc_AddActionEventHandler];
};
