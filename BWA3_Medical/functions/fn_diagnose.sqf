/*
By: KoffeinFlummi

Diagnoses a unit.

Arguments:
0: Unit that is diagnosed (Object)

Return value:
none
*/

#define DIAGNOSEMOVE "AinvPknlMstpSnonWnonDnon_medic1"

_this spawn {
  _unit = _this select 0;

  player setVariable ["BWA3_CanTreat", false, false];

  player playMoveNow DIAGNOSEMOVE;

  _damages = [
    ["head", floor ((_unit getHitPointDamage "HitHead") * 100) / 100],
    ["torso", floor ((_unit getHitPointDamage "HitBody") * 100) / 100],
    ["left shoulder", floor ((_unit getHitPointDamage "HitLeftShoulder") * 100) / 100],
    ["left arm", floor ((_unit getHitPointDamage "HitLeftArm") * 100) / 100],
    ["left forearm", floor ((_unit getHitPointDamage "HitLeftForeArm") * 100) / 100],
    ["right shoulder", floor ((_unit getHitPointDamage "HitRightShoulder") * 100) / 100],
    ["right arm", floor ((_unit getHitPointDamage "HitRightArm") * 100) / 100],
    ["right forearm", floor ((_unit getHitPointDamage "HitRightForeArm") * 100) / 100],
    ["left upper leg", floor ((_unit getHitPointDamage "HitLeftUpLeg") * 100) / 100],
    ["left lower leg", floor ((_unit getHitPointDamage "HitLeftLeg") * 100) / 100],
    ["left foot", floor ((_unit getHitPointDamage "HitLeftFoot") * 100) / 100],
    ["right upper leg", floor ((_unit getHitPointDamage "HitRightUpLeg") * 100) / 100],
    ["right lower leg", floor ((_unit getHitPointDamage "HitRightLeg") * 100) / 100],
    ["right foot", floor ((_unit getHitPointDamage "HitRightFoot") * 100) / 100]
  ];

  // wait for animation to finish without using absolute times or event handlers
  waitUntil {sleep 0.5; animationState player == DIAGNOSEMOVE};
  waitUntil {sleep 0.5; animationState player != DIAGNOSEMOVE};

  _string = "Patient: " + name _unit;

  if (damage _unit >= 1) then {
    _string = _string + "<br/><br/>The patient is dead.";
  } else {
    // Consciousness
    if (_unit getVariable "BWA3_Unconscious") then {
      _string = _string + "<br/><br/>The patient is unconsious.";
    } else {
      _string = _string + "<br/><br/>The patient is awake.";
    };

    // Injuries
    _heavyinjuries = "";
    {
      if ((_x select 1) >= 0.5) then {
        if (_heavyinjuries != "") then { _heavyinjuries = _heavyinjuries + ", "; };
        _heavyinjuries = _heavyinjuries + (_x select 0);
      };
    } forEach _damages;
    if (_heavyinjuries != "") then {
      _string = _string + "<br/><br/>The patient has heavy injuries in: " + _heavyinjuries;
    };

    _lightinjuries = "";
    {
      if ((_x select 1) < 0.5 and (_x select 1) > 0.01) then {
        if (_lightinjuries != "") then { _lightinjuries = _lightinjuries + ", "; };
        _lightinjuries = _lightinjuries + (_x select 0);
      };
    } forEach _damages;
    if (_lightinjuries != "") then {
      _string = _string + "<br/><br/>The patient has light injuries in: " + _lightinjuries;
    };

    if (_lightinjuries == "" and _heavyinjuries == "") then {
      _string = _string + "<br/><br/>The patient is not injured.";
    };

    // Blood
    if (_unit getVariable "BWA3_Bleeding") then {
      _string = _string + "<br/><br/>The patient is bleeding; ";
    } else {
      _string = _string + "<br/><br/>The patient is not bleeding at the moment; ";
    };
    if (_unit getVariable "BWA3_Blood" < 0.4) then {
      _string = _string + "The patient has already lost a lot of blood.";
    } else {
      if (_unit getVariable "BWA3_Blood" < 0.98) then {
        _string = _string + "The patient has already lost some blood.";
      } else {
        _string = _string + "The patient hasn't lost any blood.";
      };
    };

    // Pain
    if (_unit getVariable "BWA3_Painkiller" < 0.4) then {
      _string = _string + "<br/><br/>The patient is on heavy painkillers ";
    } else {
      if (_unit getVariable "BWA3_Painkiller" < 0.9) then {
        _string = _string + "<br/><br/>The patient is on some morphine ";
      } else {
        _string = _string + "<br/><br/>The patient isn't on painkillers ";
      };
    };
    if (_unit getVariable "BWA3_Pain" > 0.4) then {
      _string = _string + "and in heavy pain";
    } else {
      if (_unit getVariable "BWA3_Pain" > 0.1) then {
        _string = _string + "and in light pain.";
      } else {
        _string = _string + "and not in pain.";
      };
    };

  };

  hintSilent parseText _string;

  player setVariable ["BWA3_CanTreat", true, false];
};