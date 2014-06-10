/*
 * Author: commy2
 *
 * Check if wind is set on auto.
 * 
 * Argument:
 * None.
 * 
 * Return value:
 * This mission has automatic wind? (Bool)
 */

["Mission", "Intel", "windForced"] call AGM_Core_fnc_getNumberFromMissionSQM != 1
