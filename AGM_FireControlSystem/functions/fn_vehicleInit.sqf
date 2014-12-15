/*
 * Author: KoffeinFlummi, edited by commy2
 *
 * Checks if a vehicle is equipped with an FCS and if so, adds the fired event handler
 *
 * Arguments:
 * 0: Vehicle 
 *
 * Return Value:
 * none
 */

private ["_gunBeg", "_gunnerView", "_gunBegPos", "_gunnerViewPos", "_viewDiff"];

// iterate through all turrets and check if they have any compatible with FCS
private "_turrets";
_turrets = [typeOf (_this select 0)] call AGM_Core_fnc_getTurrets;

_hasTurretWithFCSEnabled = false;
{
  private "_turret";
  _turret = [configFile >> "CfgVehicles" >> typeOf (_this select 0), _x] call AGM_Core_fnc_getTurretConfigPath;

  if (getNumber (_turret >> "AGM_FCSEnabled") == 1) exitWith {_hasTurretWithFCSEnabled = true};
} forEach _turrets;

if (_hasTurretWithFCSEnabled) then {
  (_this select 0) addEventHandler ["Fired", {_this call AGM_FCS_fnc_firedEH}];

  (_this select 0) setVariable ["AGM_FCSDistance",  0,   true];
  (_this select 0) setVariable ["AGM_FCSMagazines", [],  true];
  (_this select 0) setVariable ["AGM_FCSElevation", [],  true];
  (_this select 0) setVariable ["AGM_FCSAzimuth",   0,   true];

  // calculate offset between gunner camera and muzzle position
  if !((_this select 0) isKindOf "Air") then {
    _gunBeg = getText (configFile >> "CfgVehicles" >> (typeOf (_this select 0)) >> "Turrets" >> "MainTurret" >> "gunBeg");
    _gunnerView = getText (configFile >> "CfgVehicles" >>  (typeOf (_this select 0)) >> "Turrets" >> "MainTurret" >> "memoryPointGunnerOptics");
    _gunBegPos = ((_this select 0) selectionPosition _gunBeg) select 0;
    _gunnerViewPos = ((_this select 0) selectionPosition _gunnerView) select 0;
    _viewDiff = _gunBegPos - _gunnerViewPos;
    (_this select 0) setVariable ["AGM_FCSViewDiff", _viewDiff, true];
  } else {
    (_this select 0) setVariable ["AGM_FCSViewDiff", 0, true];
  };
};
