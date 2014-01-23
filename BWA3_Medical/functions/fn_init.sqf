/*
Author: KoffeinFlummi

Do I really need to explain what this does?!
*/

_this addEventHandler ["HandleDamage", {[_this] call BWA3_Medical_fnc_handleDamage}];

_this setVariable ["BWA3_Blood", 1];      // Amount of blood in the body.
_this setVariable ["BWA3_Bleeding", 0];   // Is the unit losing blood? (Rate is determined by damage.)
_this setVariable ["BWA3_Painkiller", 1]; // How much painkillers the guy is on.
_this setVariable ["BWA3_Pain", 0];       // Is the unit currently in pain? (Rate is determined by damage.)
_this setVariable ["BWA3_CPR", 0];        // Chance of CPR being successfull (0 for alive units)