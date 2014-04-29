/*
Author: KoffeinFlummi

Do I really need to explain what this does?!
*/

_unit = _this select 0;

sleep 2;
if !(local _unit) exitWith {};

AGM_unitInit = {
  if (_this == player) then {
    0 spawn {
      sleep 1;
      [1, "BLACK", 0.01, 1] call BIS_fnc_FadeEffect;
    };
    4209 cutText ["", "PLAIN", 0, false];
  };

  _this setCaptive false;
  _this setVariable ["AGM_CanTreat", true, false];    // Can unit treat others?
  _this setVariable ["AGM_Treatable", true, true];    // Can unit be treated/diagnosed?
  _this setVariable ["AGM_Blood", 1, true];           // Amount of blood in the body.
  _this setVariable ["AGM_Bleeding", false, true];    // Is the unit losing blood? (Rate is determined by damage.)
  _this setVariable ["AGM_Painkiller", 1, true];      // How much painkillers the guy is on.
  _this setVariable ["AGM_Pain", 0, true];            // Amount of pain the unit is in.
  _this setVariable ["AGM_InPain", false, true];      // Is the weid effect going on?
  _this setVariable ["AGM_NoLegs", false, true];      // Is the unit able to walk?
  _this setVariable ["AGM_NoArms", false, true];      // Is the unit able to hold a gun?
  _this setVariable ["AGM_Unconscious", false, true]; // figure it out
  _this setVariable ["AGM_Dragging", objNull];
  _this setVariable ["AGM_Carrying", objNull];
};

AGM_itemCheck = {
  while {count (itemsWithMagazines _this) > count (itemsWithMagazines _this - ["FirstAidKit"])} do {
    _this removeItem "FirstAidKit";
    _this addItem "AGM_Bandage";
    _this addItem "AGM_Bandage";
  };
  while {count (itemsWithMagazines _this) > count (itemsWithMagazines _this - ["Medikit"])} do {
    _this removeItem "Medikit";
    _this addItemToBackpack "AGM_Morphine";
    _this addItemToBackpack "AGM_Morphine";
    _this addItemToBackpack "AGM_Morphine";
    _this addItemToBackpack "AGM_Morphine";
    _this addItemToBackpack "AGM_Epipen";
    _this addItemToBackpack "AGM_Epipen";
    _this addItemToBackpack "AGM_Epipen";
    _this addItemToBackpack "AGM_Epipen";
    _this addItemToBackpack "AGM_Bloodbag";
    _this addItemToBackpack "AGM_Bloodbag";
  };
};

GC_bandageMenu = false;
GC_bandageMenuSelf = false;

_unit call AGM_unitInit;
_unit call AGM_itemCheck;

_unit addEventHandler ["HandleDamage", { _this call AGM_Medical_fnc_handleDamage; }];
_unit addEventHandler ["Respawn", { (_this select 0) call AGM_unitInit; (_this select 0) call AGM_itemCheck; }];
_unit addEventHandler ["Take", { (_this select 0) call AGM_itemCheck; }];
