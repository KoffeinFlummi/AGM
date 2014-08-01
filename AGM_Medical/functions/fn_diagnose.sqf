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
#define DIAGNOSEMOVE "AinvPknlMstpSnonWnonDr_medic4"

_this spawn {
  _unit = _this select 0;

  AGM_Medical_diagnoseCallback = {
    _unit = _this select 0;

    player setVariable ["AGM_CanTreat", true, false];

    _damages = [
      ["HitHead",     floor ((_unit getHitPointDamage "HitHead")     * 100) / 100],
      ["HitBody",     floor ((_unit getHitPointDamage "HitBody")     * 100) / 100],
      ["HitLeftArm",  floor ((_unit getHitPointDamage "HitLeftArm")  * 100) / 100],
      ["HitRightArm", floor ((_unit getHitPointDamage "HitRightArm") * 100) / 100],
      ["HitLeftLeg",  floor ((_unit getHitPointDamage "HitLeftLeg")  * 100) / 100],
      ["HitRightLeg", floor ((_unit getHitPointDamage "HitRightLeg") * 100) / 100]
    ];

    _unit setVariable ["AGM_Diagnosed", true, false];

    // Tell bystanders what's up if necessary
    if (AGM_Medical_RequireDiagnosis > 0) then {
      _bystanders = nearestObjects [player, ["Man"], 10];
      [-1, {
        if (player in (_this select 1)) then {
          (_this select 0) setVariable ["AGM_Diagnosed", true, false];
        };
      }, [_unit, _bystanders]] call CBA_fnc_globalExecute;
    };

    _string = format ["<t align='center' size='0.8'>%1: %2", localize "STR_AGM_Medical_Patient", (_unit getVariable ["AGM_Name", (name _unit)])];

    if (damage _unit >= 1) then {
      _string = _string + "<br/><br/>" + localize "STR_AGM_Medical_PatientIsDead";
    } else {
      // Consciousness
      if (_unit getVariable "AGM_Unconscious") then {
        _string = _string + "<br/><br/>" + localize "STR_AGM_Medical_PatientIsUnconscious";
      } else {
        _string = _string + "<br/><br/>" + localize "STR_AGM_Medical_PatientIsAwake";
      };

      // Injuries
      if (AGM_Medical_SingleBandage > 0) then {
        if (damage _unit >= 0.5) then {
          _string = _string + "<br/><br/>" + localize "STR_AGM_Medical_PatientHeavilyInjured";
        };
        if (damage _unit < 0.5 and damage _unit > 0) then {
          _string = _string + "<br/><br/>" + localize "STR_AGM_Medical_PatientLightlyInjured";
        };
        if (damage _unit == 0) then {
          _string = _string + "<br/><br/>" + localize "STR_AGM_Medical_PatientNotInjured";
        };
      } else {
        _heavyinjuries = "";
        {
          if ((_x select 1) >= 0.5) then {
            if (_heavyinjuries != "") then { _heavyinjuries = _heavyinjuries + ", "; };
            _heavyinjuries = _heavyinjuries + localize (format ["STR_AGM_Medical_%1", (_x select 0)]);
          };
        } forEach _damages;
        if (_heavyinjuries != "") then {
          _string = _string + "<br/><br/>" + (localize "STR_AGM_Medical_PatientHeavyInjuries") + " " + _heavyinjuries;
        };

        _lightinjuries = "";
        {
          if ((_x select 1) < 0.5 and (_x select 1) > 0.01) then {
            if (_lightinjuries != "") then { _lightinjuries = _lightinjuries + ", "; };
            _lightinjuries = _lightinjuries + localize (format ["STR_AGM_Medical_%1", (_x select 0)]);
          };
        } forEach _damages;
        if (_lightinjuries != "") then {
          _string = _string + "<br/><br/>" + (localize "STR_AGM_Medical_PatientLightInjuries") + " " + _lightinjuries;
        };

        if (_lightinjuries == "" and _heavyinjuries == "") then {
          _string = _string + "<br/><br/>" + localize "STR_AGM_Medical_PatientNotInjured";
        };
      };

      // Blood
      if (_unit getVariable "AGM_Bleeding") then {
        _string = _string + "<br/><br/>" + localize "STR_AGM_Medical_PatientBleeding" + " ";
      } else {
        _string = _string + "<br/><br/>" + localize "STR_AGM_Medical_PatientNotBleeding" + " ";
      };
      if (_unit getVariable "AGM_Blood" < 0.4) then {
        _string = _string + localize "STR_AGM_Medical_PatientLostBlood";
      } else {
        if (_unit getVariable "AGM_Blood" < 1) then {
          _string = _string + localize "STR_AGM_Medical_PatientLostSomeBlood";
        } else {
          _string = _string + localize "STR_AGM_Medical_PatientLostNoBlood";
        };
      };

      // Pain
      if (_unit getVariable "AGM_Painkiller" < 0.4) then {
        _string = _string + "<br/><br/>" + localize "STR_AGM_Medical_PatientPainkillers" + " ";
      } else {
        if (_unit getVariable "AGM_Painkiller" < 0.9) then {
          _string = _string + "<br/><br/>" + localize "STR_AGM_Medical_PatientSomePainkillers" + " ";
        } else {
          _string = _string + "<br/><br/>" + localize "STR_AGM_Medical_PatientNoPainkillers" + " ";
        };
      };
      if (_unit getVariable "AGM_Pain" > 0.4) then {
        _string = _string + localize "STR_AGM_Medical_PatientHeavyPain";
      } else {
        if (_unit getVariable "AGM_Pain" > 0.1) then {
          _string = _string + localize "STR_AGM_Medical_PatientLightPain";
        } else {
          _string = _string + localize "STR_AGM_Medical_PatientNoPain";
        };
      };

    };
    _string = _string + "</t>";
    [composeText [lineBreak, parseText _string]] call AGM_Medical_fnc_displayText;

    if (profileNamespace getVariable ["AGM_keepMedicalMenuOpen", false]) then {
      if (_unit == player) then {
        "AGM_Medical" call AGM_Interaction_fnc_openMenuSelf;
      } else {
        "AGM_Medical" call AGM_Interaction_fnc_openMenu;
      }
    };
  };

  AGM_Medical_diagnoseAbort = {
    player playMoveNow "AmovPknlMstpSrasWrflDnon";
    player setVariable ["AGM_CanTreat", true, false];
  };

  if (_unit != player) then {
    player playMoveNow DIAGNOSEMOVE;

    player setVariable ["AGM_CanTreat", false, false];

    [DIAGNOSETIME, _this, "AGM_Medical_diagnoseCallback", localize "STR_AGM_Medical_Diagnosing", "AGM_Medical_diagnoseAbort"] call AGM_Core_fnc_progressBar;
    [_unit, true] call AGM_Core_fnc_closeDialogIfTargetMoves;
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
