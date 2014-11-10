/*
 * Author: KoffeinFlummi
 *
 * Cuts the ropes from the helicopter
 *
 * Arguments:
 * 0: helicopter
 *
 * Return Value:
 * None
 */

_vehicle = _this select 0;

_ropes = _vehicle getVariable "AGM_Ropes";
{
  (_x select 2) ropeDetach (_x select 0);
  ropeDestroy (_x select 0);
  //deleteVehicle (_x select 2);
} forEach _ropes;

_vehicle setVariable ["AGM_RopesDeployed", False, True];
