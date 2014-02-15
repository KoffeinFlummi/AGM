/*
By: KoffeinFlummi

Knocks the given player out by ragdollizing him and stopping all movement, thereby making it impossible to differentiate between a dead and unconcious player.

Arguments:
0: Unit to be knocked out (Object)

Return Values:
None
*/

private ["_unit", "_eh", "_helper"];

_unit = _this select 0;

_unit setVariable ["BWA3_Unconscious", true, true];

player globalChat format ["Unit: %1:", _unit];

if (_unit == player) then {
  [0, "BLACK", 0.15, 1] call BIS_fnc_FadeEffect;
};

// Not possible to ragdollize on command, so we slam a 'vehicle' in his face.
_unit setCaptive 13;
_unit allowDamage false;
//_eh = _unit addEventHandler ["EpeContactStart", {(_this select 0) setVariable ["BWA3_Collision", (_this select 1)];}];

player globalChat "still here...";

_helper = "BWA3_CollisionHelper" createVehicle [0,0,0];
_helper setPosATL [(getPos _unit select 0), (getPos _unit select 1), 1.8];
_helper setVectorUp [0,0,1];

{
  if (_x != _unit) then {
    _helper disableCollisionWith _x;
  };
} foreach (_unit nearEntities 5);

player globalChat format ["Helper: %1", _helper];

sleep 0.7;

/*
// Plan B incase the collision didn't happen; generic death animation
if (_unit getVariable "BWA3_Collision" == _helper) then {
  _unit switchMove "Static_Dead";
  sleep 0.1;
  _unit enableSimulation false;
  _unit removeEventHandler ["EpeContactEnd", _eh];
};
*/
deleteVehicle _helper;

player globalChat "Helper deleted.";

_unit allowDamage true;

sleep 2;
_unit enableSimulation false;
player globalChat "done.";