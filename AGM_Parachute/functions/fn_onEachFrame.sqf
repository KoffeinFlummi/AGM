if (isNull player) exitWith {["AGM_ParachuteFix", "OnEachFrame"] call BIS_fnc_removeStackedEventHandler;AGM_Parachuting_PFH = false;};
if !((vehicle player) isKindOf "ParachuteBase") exitWith {};
if (isTouchingGround player) exitWith {};
if ((getPosATL player select 2) < 0.75) then {
	private ["_parachute"];
	_parachute = nearestObjects [player, ["ParachuteBase"], 5];
	{
		deleteVehicle _x;
	} count _parachute;
	[player] call AGM_Parachute_fnc_doLanding;
};