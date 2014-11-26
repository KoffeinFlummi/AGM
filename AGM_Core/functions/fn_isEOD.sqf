/*
  Name: AGM_Core_fnc_isEOD
  
  Author: Garth de Wet (LH)
  
  Description:
    Checks whether the passed unit is an explosive specialist.
    Either through config entry: "canDeactivateMines"
    or 
    unit setVariable ["AGM_isEOD", true]
  
  Parameters: 
    0: OBJECT - Unit to check if is a specialist
  
  Returns:
    BOOLEAN
  
  Example:
    _isSpecialist = [player] call AGM_Core_fnc_isEOD;
*/

private "_unit";

_unit = _this select 0;

_unit getVariable ["AGM_isEOD", false]
|| {getNumber (configFile >> "CfgVehicles" >> typeOf _unit >> "canDeactivateMines") == 1}
