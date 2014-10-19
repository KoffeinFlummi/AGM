 /*
  Name: AGM_Core_fnc_getCopilotTurret
  
  Author(s):
    jodav
  
  Description:
    Returns the index of the copilot turret (usually that's [0])
  
  Parameters:
    0: STRING - vehicle type
  
  Returns:
    ARRAY<NUMBER>
*/

private ["_vehicleType", "_turrets", "_copilotTurret", "_config"];

_vehicleType = _this select 0;

_turrets = [_vehicleType] call AGM_Core_fnc_getTurrets;

_copilotTurret = [];

{
  _config = configFile >> "CfgVehicles" >> _vehicleType;
  _config = [_config, _x] call AGM_Core_fnc_getTurretConfigPath;

  if ( (toUpper (getText (_config >> "gunnerName")) == "COPILOT") || ( getNumber (_config >> "isCopilot") == 1 ) ) then {
    _copilotTurret = _x;
  };
} forEach _turrets;

_copilotTurret
