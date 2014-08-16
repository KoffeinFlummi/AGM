/*
 * Author: KoffeinFlummi
 *
 * Creates the flashbang effect locally/knocks out AI units.
 *
 * Arguments:
 * 0: The unit (Object)
 * 1: The grenade (Object)
 *
 * Return Value:
 * None
 */

nul = _this spawn {
  _unit = _this select 0;
  _grenade = _this select 1;

  if (damage _unit >= 1) exitWith {};

  _strength = 1 - ((_unit distance _grenade) min 15) / 15;

  if !(isPlayer _unit) exitWith {
    _unit disableAI "MOVE";
    _unit disableAI "AUTOTARGET";
    _unit disableAI "TARGET";
    _unit disableAI "FSM";
    _unit setSkill (skill _unit / 50);

    sleep (10 * _strength);

    _unit enableAI "MOVE";
    _unit enableAI "AUTOTARGET";
    _unit enableAI "TARGET";
    _unit enableAI "FSM";
    _unit setSkill (skill _unit * 50);
  };

  // is there line of sight to the grenade?
  if (lineIntersects [getPosASL _grenade, getPosASL _unit, _grenade, _unit]) then {
    _strength = _strength / 10;
  };

  // beeeeeeeeeeeeeeeeeeeeeeeeeeeeep
  if (isClass (configFile >> "CfgPatches" >> "AGM_Hearing") and _strength > 0) then {
    [0.5 + (_strength / 2)] call AGM_Hearing_fnc_earRinging;
  };

  // account for people looking away by slightly
  // reducing the effect for visual effects.
  _posUnit = getPos _unit;
  _posGrenade = getPos _grenade;
  _angleGrenade = ((_posGrenade select 0) - (_posUnit select 0)) atan2 ((_posGrenade select 1) - (_posUnit select 1));
  _angleGrenade = (_angleGrenade + 360) % 360;

  _angleView = (eyeDirection player select 0) atan2 (eyeDirection player select 1);
  _angleView = (_angleView + 360) % 360;

  _angleDiff = 180 - abs (abs (_angleGrenade - _angleView) - 180);
  _strength = _strength - _strength * 0.4 * _angleDiff;

  // create flash to illuminate environment
  _light = "#lightpoint" createVehicleLocal getPos _grenade;
  _light setLightBrightness 200;
  _light setLightAmbient [1,1,1];
  _light setLightColor [1,1,1];
  _light setLightDayLight true;

  // blind player
  if (_strength > 0.1) then {
    AGM_Flashbang_CC ppEffectEnable true;
    AGM_Flashbang_CC ppEffectAdjust [1,1,0,[1,1,1,1*(0.5 + _strength * 0.5)],[0,0,0,1],[0,0,0,0]];
    AGM_Flashbang_CC ppEffectCommit 0.01;
  };

  sleep 0.1;
  deleteVehicle _light;
  sleep (5 * _strength);

  if (_strength > 0.1) then {
    AGM_Flashbang_CC ppEffectAdjust [1,1,0,[1,1,1,0],[0,0,0,1],[0,0,0,0]];
    AGM_Flashbang_CC ppEffectCommit (5 * _strength);

    sleep (5 * _strength);

    AGM_Flashbang_CC ppEffectEnable false;
  };
};
