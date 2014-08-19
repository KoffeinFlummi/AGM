if (isNull player) exitWith {["AGM_ParachuteFix", "OnEachFrame"] call BIS_fnc_removeStackedEventHandler;AGM_Parachuting_PFH = false;};
if !((vehicle player) isKindOf "ParachuteBase") exitWith {};
if (isTouchingGround player) exitWith {};

private ["_pos", "_intersects"];
_pos = getPosATL (Vehicle player);
_intersects = lineIntersectsWith [_pos, _pos vectorAdd [0,0,-0.5], vehicle player, player];

if ((count _intersects > 0) || {(_pos select 2) < 0.75}) then {
	deleteVehicle (vehicle player);
	[player] call AGM_Parachute_fnc_doLanding;
};