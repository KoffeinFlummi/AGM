/*
Author: KoffeinFlummi

Do I really need to explain what this does?!
*/

_unit = _this select 0;

BWA3_setVariables = {
  _this setVariable ["BWA3_Blood", 1];           // Amount of blood in the body.
  _this setVariable ["BWA3_Bleeding", 0];        // Is the unit losing blood? (Rate is determined by damage.)
  _this setVariable ["BWA3_Painkiller", 1];      // How much painkillers the guy is on.
  _this setVariable ["BWA3_Pain", 0];            // Amount of pain the unit is in.
  _this setVariable ["BWA3_Epinephrine", false]; // Is the unit under the influence of epinephrine?
  _this setVariable ["BWA3_Dead", 0];            // 1 for dead, but revivable units (damage == 1 means unrevivable), 0 for alive ones
  _this setVariable ["BWA3_Unconscious", false]; // figure it out
};
_unit call BWA3_setVariables;

_unit addEventHandler ["HandleDamage", {_this call BWA3_Medical_fnc_handleDamage}];
_unit addEventHandler ["Respawn", {(_this select 0) call BWA3_setVariables}];

/*
// INTERACTION
_this addAction [
  "<t color='#FF0000'>Drag</t>",
  {[_this select 3] call BWA3_Medical_fnc_drag;},
  cursorTarget,
  6,
  false,
  false,
  "",
  {cursorTarget isKindOf "Man" and cursorTarget getVariable "BWA3_Unconscious"}
];
_this addAction [
  "<t color='#FF0000'>Carry</t>",
  {[_this select 3] call BWA3_Medical_fnc_carry;},
  cursorTarget,
  5.999,
  false,
  false,
  "",
  {cursorTarget isKindOf "Man" and cursorTarget getVariable "BWA3_Unconscious"}
];
_this addAction [
  "<t color='#FF0000'>Diagnose</t>",
  {[_this select 3] call BWA3_Medical_fnc_diagnose;},
  cursorTarget,
  5.998,
  false,
  false,
  "",
  {cursorTarget isKindOf "Man" and !(cursorTarget getVariable "BWA3_Diagnose") and damage cursorTarget > 0.01}
];

// HEALING
_this addAction [
  "<t color='#FF0000'>Perform CPR</t>",
  {[_this select 3] call BWA3_Medical_fnc_CPR;},
  cursorTarget,
  5.99,
  false,
  false,
  "",
  {cursorTarget isKindOf "Man" and cursorTarget getVariable "BWA3_CPR" > 0}
];
_this addAction [
  "<t color='#FF0000'>Inject Epinephrine</t>",
  {[_this select 3] call BWA3_Medical_fnc_epinephrine;},
  cursorTarget,
  5.989,
  false,
  false,
  "",
  {cursorTarget isKindOf "Man" and cursorTarget getVariable "BWA3_CPR" > 0}
];
_this addAction [
  "<t color='#FF0000'>Inject Morphine</t>",
  {[_this select 3] call BWA3_Medical_fnc_morphine;},
  cursorTarget,
  5.988,
  false,
  false,
  "",
  {cursorTarget isKindOf "Man" and cursorTarget getVariable "BWA3_Pain" > 0}
];
*/