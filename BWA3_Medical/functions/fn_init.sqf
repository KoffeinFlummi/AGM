/*
Author: KoffeinFlummi

Do I really need to explain what this does?!
*/

_unit = _this select 0;
if !(local _unit) exitWith {};

GC_bandageMenu = false;
GC_bandageMenuSelf = false;

BWA3_unitInit = {
  if (_this == player) then {
    0 spawn {
      sleep 1;
      [1, "BLACK", 0.01, 1] call BIS_fnc_FadeEffect;
    };
    4209 cutText ["", "PLAIN", 0, false];
  };

  _this setCaptive false;
  _this setVariable ["BWA3_CanTreat", true, false];    // Can unit treat others?
  _this setVariable ["BWA3_Treatable", true, true];    // Can unit be treated/diagnosed?
  _this setVariable ["BWA3_Blood", 1, true];           // Amount of blood in the body.
  _this setVariable ["BWA3_Bleeding", false, true];    // Is the unit losing blood? (Rate is determined by damage.)
  _this setVariable ["BWA3_Painkiller", 1, true];      // How much painkillers the guy is on.
  _this setVariable ["BWA3_Pain", 0, true];            // Amount of pain the unit is in.
  _this setVariable ["BWA3_InPain", false, true];      // Is the weid effect going on?
  _this setVariable ["BWA3_NoLegs", false, true];      // Is the unit able to walk?
  _this setVariable ["BWA3_NoArms", false, true];      // Is the unit able to hold a gun?
  _this setVariable ["BWA3_Unconscious", false, true]; // figure it out
  _this setVariable ["BWA3_Dragging", objNull];
  _this setVariable ["BWA3_Carrying", objNull];
};

BWA3_itemCheck = {
  while {count (itemsWithMagazines _this) > count (itemsWithMagazines _this - ["FirstAidKit"])} do {
    _this removeItem "FirstAidKit";
    _this addItem "BWA3_Bandage";
    _this addItem "BWA3_Bandage";
  };
  while {count (itemsWithMagazines _this) > count (itemsWithMagazines _this - ["Medikit"])} do {
    _this removeItem "Medikit";
    _this addItemToBackpack "BWA3_Morphine";
    _this addItemToBackpack "BWA3_Morphine";
    _this addItemToBackpack "BWA3_Morphine";
    _this addItemToBackpack "BWA3_Morphine";
    _this addItemToBackpack "BWA3_Epipen";
    _this addItemToBackpack "BWA3_Epipen";
    _this addItemToBackpack "BWA3_Epipen";
    _this addItemToBackpack "BWA3_Epipen";
    _this addItemToBackpack "BWA3_Bloodbag";
    _this addItemToBackpack "BWA3_Bloodbag";
  };
};

_unit call BWA3_unitInit;
_unit call BWA3_itemCheck;

_unit addEventHandler ["HandleDamage", { _this call BWA3_Medical_fnc_handleDamage; }];
_unit addEventHandler ["Respawn", { (_this select 0) call BWA3_unitInit; (_this select 0) call BWA3_itemCheck; }];
_unit addEventHandler ["Take", { (_this select 0) call BWA3_itemCheck; }];
