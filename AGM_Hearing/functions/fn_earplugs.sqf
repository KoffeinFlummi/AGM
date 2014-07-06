/*
 * Author: Hope Johnson
 *
 * Puts in / takes out earplugs.
 *
 * Arguments:
 * none
 *
 * Return Value:
 * none
 */

// Buds already in and removing them.
if (AGM_EarPlugsIn) exitWith {
  _count = count items player;
  player addItem "AGM_EarBuds";

  if (count items player > _count) then { // ear bugs fit into inventory
    [localize "STR_AGM_Hearing_Earbuds_Off"] call AGM_Core_fnc_displayTextStructured;
    AGM_EarPlugsIn = false;
  } else { // inventory full
    [localize "STR_AGM_Hearing_Inventory_Full"] call AGM_Core_fnc_displayTextStructured;
  };
};

// Buds in inventory, putting them in
if ("AGM_EarBuds" in items player) exitWith {
  player removeItem "AGM_EarBuds";
  
  [localize "STR_AGM_Hearing_Earbuds_On"] call AGM_Core_fnc_displayTextStructured;
  AGM_EarPlugsIn = true;
};

// No Ear Buds in inventory, telling user
[localize "STR_AGM_Hearing_NoBuds"] call AGM_Core_fnc_displayTextStructured;