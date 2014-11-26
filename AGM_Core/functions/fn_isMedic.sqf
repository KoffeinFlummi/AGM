/*
 * Author: KoffeinFlummi
 *
 * Checks if a unit is a medic.
 *
 * Arguments:
 * 0: unit to be checked (object)
 *
 * Return Value:
 * Bool: is unit medic?
 */

private "_unit";

_unit = _this select 0;

_unit getVariable ["AGM_IsMedic", false]
|| {getNumber (configFile >> "CfgVehicles" >> typeOf _unit >> "attendant") == 1}
