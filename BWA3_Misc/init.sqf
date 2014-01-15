// BWA3 Misc - IR Strobes
// (C) 2013 KoffeinFlummi. See LICENSE.

BWA3_Misc_fnc_attachStrobe = {
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
  _strobe = "B_IRStrobe" createVehicle (getPos _unit);

  _unit removeMagazine _strobeClass;
  _unit setVariable ["BWA3_IRStrobe", _strobe];

  _strobe attachTo [_unit, [0,0,0.2], "neck"];
};

BWA3_Misc_fnc_detachStrobe = {
  private ["_unit"];

  _unit = _this select 1;

  _strobe = _unit getVariable "BWA3_IRStrobe";

  _unit addMagazine (toString [(toArray (typeOf _strobe)) select 0] + "_IR_Grenade");
  _unit setVariable ["BWA3_IRStrobe", ""];

  detach _strobe;
  _strobe setPos [0,0,-500]; // cause fuck you, that's why. (deleteVehicle wouldn't work for some reason.)
};

player setVariable ["BWA3_IRStrobe", ""];
player addAction ["Activate Strobelight", {_this call BWA3_Misc_fnc_attachStrobe}, "", 0, false, true, "", "('B_IR_Grenade' in (magazines player) or 'I_IR_Grenade' in (magazines player) or 'O_IR_Grenade' in (magazines player)) and player getVariable 'BWA3_IRStrobe' == ''"];
player addAction ["Deactivate Strobelight", {_this call BWA3_Misc_fnc_detachStrobe}, "", 0, false, true, "", "!isNull(player getVariable 'BWA3_IRStrobe')"];