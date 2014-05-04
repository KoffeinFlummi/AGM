/*
 * By: KoffeinFlummi
 * 
 * Knocks the given player out by ragdollizing him and stopping all movement, thereby making it impossible to differentiate between a dead and unconcious player.
 * 
 * Arguments:
 * 0: Unit to be knocked out (Object)
 * 
 * Return Values:
 * None
 */

private ["_unit", "_newGroup"];

_unit = _this select 0;
if !(isPlayer _unit) exitWith {_unit setDamage 1;};

_unit setVariable ["AGM_Unconscious", true, true];
_unit setVariable ["AGM_CanTreat", false, true];

_oldGroup = group _unit;
_newGroup = createGroup side _unit;
[_unit] joinSilent _newGroup;
{
  _unit reveal _x;
} 
forEach (units _oldGroup);
_unit setVariable ["AGM_Group", _oldGroup, true];

if (isClass (configFile >> "CfgPatches" >> "task_force_radio")) then {
  player setVariable ["tf_unable_to_use_radio", true, true];
  player setVariable ["tf_voiceVolume", 0, true];
};

if (_unit == player) then {
  [0, "BLACK", 0.15, 1] spawn BIS_fnc_FadeEffect;
  4209 cutText ["You are unconscious.\nIf someone doesn't treat your wounds, you will bleed out soon.\n\nHave fun :>", "PLAIN", 0, false];
};

_unit setCaptive 213;

_unit disableAI "MOVE";
_unit disableAI "ANIM";
_unit disableAI "TARGET";
_unit disableAI "AUTOTARGET";
_unit disableAI "FSM";

if (vehicle _unit != _unit) then {
  _unit playMoveNow (((configfile >> "CfgMovesMaleSdr" >> "States" >> animationState _unit >> "interpolateTo") call BIS_fnc_getCfgData) select 0);
} else {
  _unit playMoveNow "Unconscious";
};

_unit spawn {
  sleep 3.8;
  waitUntil {isTouchingGround _this};
  sleep 0.2;
  _this enableSimulation false;
};

/*
if (_unit == player) then {
  [0, "BLACK", 0.15, 1] call BIS_fnc_FadeEffect;
};

// Not possible to ragdollize on command, so we slam a 'vehicle' in his face.
_unit setCaptive 213;
_unit allowDamage false;

_unit disableAI "MOVE";
_unit disableAI "ANIM";
_unit disableAI "TARGET";
_unit disableAI "AUTOTARGET";
_unit disableAI "FSM";
//_eh = _unit addEventHandler ["EpeContactStart", {(_this select 0) setVariable ["AGM_Collision", (_this select 1)];}];


_helper = "AGM_CollisionHelper" createVehicle [0,0,0];
_helper setPosATL [(getPos _unit select 0), (getPos _unit select 1), 1.8];
_helper setVectorUp [0,0,1];

{
  if (_x != _unit) then {
    _helper disableCollisionWith _x;
  };
} foreach (_unit nearEntities 5);

sleep 0.7;

deleteVehicle _helper;

player globalChat "Helper deleted.";

_unit allowDamage true;

sleep 2;
_unit enableSimulation false;
_unit switchMove "unconscious";

player globalChat "done.";
*/