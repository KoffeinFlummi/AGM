/*
Author: KoffeinFlummi

Do I really need to explain what this does?!
*/

AGM_Medical_Hits = [];
AGM_Medical_IsFalling = false;

_this spawn {
  _unit = _this select 0;

  sleep 2;
  if !(local _unit) exitWith {};

  AGM_Medical_unitInit = {
    if (_this == player) then {
      player setVariable ["tf_globalVolume", 1];
      player setVariable ["tf_voiceVolume", 1, true];
      player setVariable ["tf_unable_to_use_radio", false, true];

      player setVariable ["acre_sys_core_isDisabled", false, true];
      player setVariable ["acre_sys_core_globalVolume", 1];
    };

    [_this, "AGM_Unconscious", false] call AGM_Interaction_fnc_setCaptivityStatus;
    _this setVariable ["AGM_Diagnosed", false, true];   // Is the unit diagnosed?
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
    _this setVariable ["AGM_Overdosing", false];
    _this setVariable ["AGM_Dragging", objNull];
    _this setVariable ["AGM_Carrying", objNull];

    [false] call AGM_Core_fnc_disableUserInput;
  };

  AGM_Medical_itemCheck = {
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
      _this addItemToBackpack "AGM_Morphine";
      _this addItemToBackpack "AGM_Epipen";
      _this addItemToBackpack "AGM_Epipen";
      _this addItemToBackpack "AGM_Epipen";
      _this addItemToBackpack "AGM_Epipen";
      _this addItemToBackpack "AGM_Bloodbag";
      _this addItemToBackpack "AGM_Bloodbag";
    };
  };

  _unit call AGM_Medical_unitInit;
  _unit call AGM_Medical_itemCheck;

  _unit addEventHandler ["HandleDamage", { _this call AGM_Medical_fnc_handleDamage; }];
  _unit addEventHandler ["Respawn", { (_this select 0) call AGM_Medical_unitInit; (_this select 0) call AGM_Medical_itemCheck; }];
  _unit addEventHandler ["Take", { (_this select 0) call AGM_Medical_itemCheck; }];

  _unit spawn {
    while {true} do {
      sleep 1;
      _this call AGM_Medical_itemCheck;
    };
  };
};

// Bloodloss effect
/*
_this spawn {
  AGM_Bloodloss_CC = ppEffectCreate ["ColorCorrections", 4210];
  AGM_Bloodloss_CC ppEffectEnable true;
  AGM_Bloodloss_CC ppEffectForceInNVG true;
  AGM_Bloodloss_CC ppEffectAdjust [1,1,0,[0,0,0,0],[1,1,1,1],[0,0,0,0]];
  AGM_Bloodloss_CC ppEffectCommit 0.01;
};
*/
