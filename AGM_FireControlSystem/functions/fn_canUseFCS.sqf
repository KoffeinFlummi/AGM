/*
 * Author: commy2
 *
 * Called from config. Returns true if the player is a gunner and the players current vehicle has a FCS. 
 * 
 * Argument:
 * Nothing
 * 
 * Return value:
 * Boolean (Bool)
 */

_player in _vehicle && {
	private "_turret";
	_turret = [_player] call AGM_Core_fnc_getTurretIndex;
	_turret = [configFile >> "CfgVehicles" >> typeOf _vehicle, _turret] call AGM_Core_fnc_getTurretConfigPath;

	getNumber (_turret >> "AGM_FCSEnabled") == 1
}
