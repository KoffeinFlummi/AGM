/*
 * By: KoffeinFlummi
 * 
 * Diagnoses a unit.
 * 
 * Arguments:
 * 0: Unit that is diagnosed (Object)
 * 
 * Return value:
 * none
 */

#define DIAGNOSETIME 8
#define DIAGNOSEMOVE "AinvPknlMstpSnonWnonDnon_medic1"

_this spawn {
  _unit = _this select 0;

  AGM_Medical_diagnoseCallback = {
    _unit = _this select 0;

    _damages = [
      ["head",      floor ((_unit getHitPointDamage "HitHead")     * 100) / 100],
      ["torso",     floor ((_unit getHitPointDamage "HitBody")     * 100) / 100],
      ["left arm",  floor ((_unit getHitPointDamage "HitLeftArm")  * 100) / 100],
      ["right arm", floor ((_unit getHitPointDamage "HitRightArm") * 100) / 100],
      ["left leg",  floor ((_unit getHitPointDamage "HitLeftLeg")  * 100) / 100],
      ["right leg", floor ((_unit getHitPointDamage "HitRightLeg") * 100) / 100]
    ];

    _string = format ["Patient: %1", (_unit getVariable ["AGM_Name", (name _unit)])];

    if (damage _unit >= 1) then {
      _string = _string + "<br/><br/>The patient is dead.";
    } else {
      // Consciousness
      if (_unit getVariable "AGM_Unconscious") then {
        _string = _string + "<br/><br/>The patient is unconscious.";
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
      if (_unit getVariable "AGM_Bleeding") then {
        _string = _string + "<br/><br/>The patient is bleeding; ";
      } else {
        _string = _string + "<br/><br/>The patient is not bleeding at the moment; ";
      };
      if (_unit getVariable "AGM_Blood" < 0.4) then {
        _string = _string + "The patient has already lost a lot of blood.";
      } else {
        if (_unit getVariable "AGM_Blood" < 1) then {
          _string = _string + "The patient has already lost some blood.";
        } else {
          _string = _string + "The patient hasn't lost any blood.";
        };
      };

      // Pain
      if (_unit getVariable "AGM_Painkiller" < 0.4) then {
        _string = _string + "<br/><br/>The patient is on heavy painkillers ";
      } else {
        if (_unit getVariable "AGM_Painkiller" < 0.9) then {
          _string = _string + "<br/><br/>The patient is on some morphine ";
        } else {
          _string = _string + "<br/><br/>The patient isn't on painkillers ";
        };
      };
      if (_unit getVariable "AGM_Pain" > 0.4) then {
        _string = _string + "and in heavy pain";
      } else {
        if (_unit getVariable "AGM_Pain" > 0.1) then {
          _string = _string + "and in light pain.";
        } else {
          _string = _string + "and not in pain.";
        };
      };

    };

    hintSilent parseText _string;
  };

  if (_unit != player) then {
    player playMoveNow DIAGNOSEMOVE;

    player setVariable ["AGM_CanTreat", false, false];
    DIAGNOSETIME spawn {
      sleep _this;
      player setVariable ["AGM_CanTreat", true, false];
    };

    [DIAGNOSETIME, _this, "AGM_Medical_diagnoseCallback", localize "STR_AGM_Diagnosing"] call AGM_Core_fnc_progressBar;
  } else {
    _this call AGM_Medical_diagnoseCallback;
  };

  /*
  if (getNumber(configFile >> "AGM_Realism_Settings" >> "reopenInteractionMenu") == 1) then {
    if (_unit == player) then {
      "AGM_Medical" call AGM_Interaction_fnc_openMenuSelf;
    } else {
      "AGM_Medical" call AGM_Interaction_fnc_openMenu;
    }
  };
  */
};