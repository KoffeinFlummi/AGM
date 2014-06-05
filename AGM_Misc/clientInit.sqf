/*
 * Author: KoffeinFlummi
 * 
 * IR Strobes, ...
 *
 */

AGM_Misc_fnc_activateStrobe = {
  private ["_unit","_strobeClass", "_strobe"];

  _unit = _this select 1;

  if ("B_IR_Grenade" in magazines _unit) then {
    _strobeClass = "B_IR_Grenade";
  } else {
    if ("I_IR_Grenade" in magazines _unit) then {
      _strobeClass = "I_IR_Grenade";
    } else {
      _strobeClass = "O_IR_Grenade";
    }
  };
  _strobe = (toString [(toArray _strobeClass) select 0] + "_IRStrobe") createVehicle (getPos _unit);

  _unit removeMagazine _strobeClass;
  _unit setVariable ["AGM_IRStrobe", _strobe];

  _strobe attachTo [_unit, [0,0,0.2], "neck"];
};

AGM_Misc_fnc_deactivateStrobe = {
  private ["_unit", "_strobe"];

  _unit = _this select 1;

  _strobe = _unit getVariable "AGM_IRStrobe";

  _unit addMagazine (toString [(toArray (typeOf _strobe)) select 0] + "_IR_Grenade");
  _unit setVariable ["AGM_IRStrobe", ""];

  detach _strobe;
  _strobe setPos [0,0,-500]; // cause fuck you, that's why. (deleteVehicle wouldn't work for some reason.)
};

AGM_Misc_fnc_attachStrobe = {
  private ["_unit", "_target", "_strobeClass", "_strobe", "_offset"];

  _unit = _this select 1;
  _target = _this select 3;

  if ("B_IR_Grenade" in magazines _unit) then {
    _strobeClass = "B_IR_Grenade";
  } else {
    if ("I_IR_Grenade" in magazines _unit) then {
      _strobeClass = "I_IR_Grenade";
    } else {
      _strobeClass = "O_IR_Grenade";
    }
  };
  _strobe = (toString [(toArray _strobeClass) select 0] + "_IRStrobe") createVehicle (getPos _target);

  _unit removeMagazine _strobeClass;
  _target setVariable ["AGM_IRStrobe", _strobe];

  // GET OFFSET (LATER)
  _offset = [0,0,5];

  _strobe attachTo [_target, [0,0,0.2]];
};

AGM_Misc_fnc_detachStrobe = {
  private ["_unit", "_target", "_strobe"];

  _unit = _this select 1;
  _target = _this select 3;

  _strobe = _target getVariable "AGM_IRStrobe";

  _unit addMagazine (toString [(toArray (typeOf _strobe)) select 0] + "_IR_Grenade");

  detach _strobe;
  _strobe setPos [0,0,-500]; // cause fuck you again (see above)
};

player setVariable ["AGM_IRStrobe", Null];

// Move actions to config?
player addAction ["Activate Strobelight", {_this call AGM_Misc_fnc_activateStrobe}, "", 0, false, true, "", "('B_IR_Grenade' in (magazines player) or 'I_IR_Grenade' in (magazines player) or 'O_IR_Grenade' in (magazines player)) and player getVariable 'AGM_IRStrobe' == ''"];
player addAction ["Deactivate Strobelight", {_this call AGM_Misc_fnc_deactivateStrobe}, "", 0, false, true, "", "!isNull(player getVariable 'AGM_IRStrobe')"];
player addAction ["Attach Strobelight", {_this call AGM_Misc_fnc_attachStrobe}, cursorTarget, 0, false, true, "", "cursorTarget distance player < 4 and (cursorTarget isKindOf 'Car' or cursorTarget isKindOf 'Tank' or cursorTarget isKindOf 'Helicopter' or cursorTarget isKindOf 'Ship') and ('B_IR_Grenade' in (magazines player) or 'I_IR_Grenade' in (magazines player) or 'O_IR_Grenade' in (magazines player)) and cursorTarget getVariable 'AGM_IRStrobe' == ''"];
player addAction ["Detach Strobelight", {_this call AGM_Misc_fnc_detachStrobe}, cursorTarget, 0, false, true, "", "!isNull(cursorTarget getVariable 'AGM_IRStrobe') and cursorTarget distance player < 4"];

// Init EH for vehicles
AGM_Misc_fnc_initEH = {

};