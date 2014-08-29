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

// Buds in inventory, putting them in
player removeItem "AGM_EarBuds";

AGM_EarPlugsIn = true;

[localize "STR_AGM_Hearing_Earbuds_On"] call AGM_Core_fnc_displayTextStructured;

/*// No Ear Buds in inventory, telling user
[localize "STR_AGM_Hearing_NoBuds"] call AGM_Core_fnc_displayTextStructured;*/

