/*
 * Author: Hope Johnson
 * Edited by commy2
 *
 * Puts in / takes out earplugs.
 *
 * Arguments:
 * none
 *
 * Return Value:
 * none
 */

if !(player canAdd "AGM_EarBuds") exitWith { // inventory full
  [localize "STR_AGM_Hearing_Inventory_Full"] call AGM_Core_fnc_displayTextStructured;
};

// Buds already in and removing them.
player addItem "AGM_EarBuds";

AGM_EarPlugsIn = false;

[localize "STR_AGM_Hearing_Earbuds_Off"] call AGM_Core_fnc_displayTextStructured;
