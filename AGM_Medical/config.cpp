// PATCH CONFIG
class CfgPatches {
  class AGM_Medical {
    units[] = {"AGM_Box_Medical"};
    weapons[] = {"AGM_Bandage", "AGM_Morphine", "AGM_Epipen", "AGM_Bloodbag"};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Medical {
    class AGM_Medical {
      file = "AGM_Medical\functions";
      class bandage;
      class bloodbag;
      class carry;
      class diagnose;
      class displayText;
      class drag;
      class dropWeapon;
      class epinephrine;
      class forceProne;
      class handleDamage;
      class init;
      class isDiagnosed;
      class isInMedicalVehicle;
      class isMedic;
      class knockOut;
      class loadIntoVehicle;
      class module;
      class morphine;
      class release;
      class setDamage;
      class setHitPointDamage;
      class takeItem;
      class unloadPatients;
      class wakeUp;
    };
  };
};

class Extended_Init_EventHandlers {
  class CAManBase {
    class AGM_Medical {
      init = "_this call AGM_Medical_fnc_init";
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Medical {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_Medical\clientInit.sqf'";
  };
};

class AGM_Core_canInteractConditions {
  class AGM_Medical_canTreat {
    condition = "player getVariable ['AGM_CanTreat', true]";
  };
  class AGM_Medical_isConscious {
    condition = "!(player getVariable ['AGM_Unconscious', false])";
  };
  class AGM_Medical_isNotOverdosing {
    condition = "!(player getVariable ['AGM_Overdosing', false])";
  };
};

class AGM_Core_Options {
  class keepMedicalMenuOpen {
    displayName = "$STR_AGM_Medical_keepMenuOpen";
    default = 0;
  };
};

class CfgMovesBasic {
  class Default;
};
class CfgMovesMaleSdr: CfgMovesBasic {
  //class Default: Default;
  class States {
    class Unconscious: Default {
      //forceAim = 1; //0;
      head = "headNo";
      static = 1;
    };
  };
};

class CfgVehicles {
  class Man;
  class CAManBase: Man {
    armor = 2.5;
    armorStructural = 5;

    class HitPoints {
      // "DEACTIVE" DEFAULT HITPOINTS
      class HitHands {
        armor = 999; //armor = 2;
        explosionShielding = 0; //explosionShielding = 1;
        material = -1;
        minimalHit = 0;
        name = "";
        passThrough = 1; //passThrough = 1;
        radius = 0; //radius = 0.06;
        visual = "injury_hands";
      };
      class HitLegs {
        armor = 999; //armor = 2;
        explosionShielding = 0; //explosionShielding = 1;
        material = -1;
        minimalHit = 0;
        name = "";
        passThrough = 1; //passThrough = 1;
        radius = 0; //radius = 0.08;
        visual = "injury_legs";
      };

      class HitHead {
        armor = 0.5;
        explosionShielding = 1;
        material = -1;
        minimalHit = 0;
        name = "head";
        passThrough = 1;
        radius = 0.1;
      };
      class HitBody {
        armor = 0.5;
        explosionShielding = 6;
        material = -1;
        minimalHit = 0;
        name = "body";
        passThrough = 1;
        radius = 0.15;
        visual = "injury_body";
      };
      class HitLeftArm {
        armor = 2;
        explosionShielding = 1;
        material = -1;
        minimalHit = 0;
        name = "hand_l";
        passThrough = 1;
        radius = 0.06;
        visual = "injury_hands";
      };
      class HitRightArm: HitLeftArm {
        name = "hand_r";
      };
      class HitLeftLeg {
        armor = 2;
        explosionShielding = 1;
        material = -1;
        minimalHit = 0;
        name = "leg_l";
        passThrough = 1;
        radius = 0.08;
        visual = "injury_legs";
      };
      class HitRightLeg: HitLeftLeg {
        name = "leg_r";
      };
    };

    class AGM_Actions {
      class AGM_Medical {
        displayName = "$STR_AGM_Medical_Treat";
        distance = 4;
        condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player";
        statement = "'AGM_Medical' call AGM_Interaction_fnc_openMenu;";
        showDisabled = 1;
        priority = 6;

        class AGM_Diagnose {
          displayName = "$STR_AGM_Medical_Diagnose";
          condition = "(player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and AGM_Interaction_Target != player";
          statement = "[AGM_Interaction_Target] call AGM_Medical_fnc_diagnose;";
          showDisabled = 1;
          priority = 1;
        };
        class AGM_Morphine {
          displayName = "$STR_AGM_Medical_Inject_Morphine";
          condition = "([AGM_Interaction_Target] call AGM_Medical_fnc_isDiagnosed) and (player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and alive AGM_Interaction_Target and AGM_Interaction_Target != player and 'AGM_Morphine' in itemsWithMagazines player";
          statement = "[AGM_Interaction_Target] call AGM_Medical_fnc_morphine;";
          showDisabled = 1;
          priority = 0.9;
        };
        class AGM_Epipen {
          displayName = "$STR_AGM_Medical_Inject_Epinephrine";
          condition = "([AGM_Interaction_Target] call AGM_Medical_fnc_isDiagnosed) and (player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and alive AGM_Interaction_Target and AGM_Interaction_Target != player and 'AGM_Epipen' in itemsWithMagazines player and AGM_Interaction_Target getVariable 'AGM_Unconscious'";
          statement = "[AGM_Interaction_Target] call AGM_Medical_fnc_epinephrine;";
          showDisabled = 1;
          priority = 0.8;
        };
        class AGM_BloodBag {
          displayName = "$STR_AGM_Medical_Transfuse_Blood";
          condition = "([AGM_Interaction_Target] call AGM_Medical_fnc_isDiagnosed) and (player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and alive AGM_Interaction_Target and AGM_Interaction_Target != player and 'AGM_Bloodbag' in itemsWithMagazines player and (AGM_Interaction_Target getVariable 'AGM_Blood' < 0.7)";
          statement = "[AGM_Interaction_Target] call AGM_Medical_fnc_bloodbag;";
          showDisabled = 1;
          priority = 0.7;
        };
        class AGM_Bandage {
          displayName = "$STR_AGM_Medical_Bandage";
          condition = "AGM_Medical_SingleBandage > 0 and ([AGM_Interaction_Target] call AGM_Medical_fnc_isDiagnosed) and (player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (damage AGM_Interaction_Target > 0.01)";
          statement = "[AGM_Interaction_Target, 'All'] call AGM_Medical_fnc_bandage;";
          priority = 0.6;
          conditionShow = "AGM_Medical_SingleBandage > 0";
        };
        class AGM_Bandage_Head {
          displayName = "$STR_AGM_Medical_Bandage_HitHead";
          condition = "AGM_Medical_SingleBandage == 0 and ([AGM_Interaction_Target] call AGM_Medical_fnc_isDiagnosed) and (player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitHead' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitHead'] call AGM_Medical_fnc_bandage;";
          priority = 0.6;
          conditionShow = "AGM_Medical_SingleBandage == 0";
        };
        class AGM_Bandage_Body {
          displayName = "$STR_AGM_Medical_Bandage_HitBody";
          condition = "AGM_Medical_SingleBandage == 0 and ([AGM_Interaction_Target] call AGM_Medical_fnc_isDiagnosed) and (player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitBody' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitBody'] call AGM_Medical_fnc_bandage;";
          priority = 0.5;
          conditionShow = "AGM_Medical_SingleBandage == 0";
        };
        class AGM_Bandage_LeftArm {
          displayName = "$STR_AGM_Medical_Bandage_HitLeftArm";
          condition = "AGM_Medical_SingleBandage == 0 and ([AGM_Interaction_Target] call AGM_Medical_fnc_isDiagnosed) and (player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitLeftArm' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitLeftArm'] call AGM_Medical_fnc_bandage;";
          priority = 0.4;
          conditionShow = "AGM_Medical_SingleBandage == 0";
        };
        class AGM_Bandage_RightArm {
          displayName = "$STR_AGM_Medical_Bandage_HitRightArm";
          condition = "AGM_Medical_SingleBandage == 0 and ([AGM_Interaction_Target] call AGM_Medical_fnc_isDiagnosed) and (player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitRightArm' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitRightArm'] call AGM_Medical_fnc_bandage;";
          priority = 0.3;
          conditionShow = "AGM_Medical_SingleBandage == 0";
        };
        class AGM_Bandage_LeftLeg {
          displayName = "$STR_AGM_Medical_Bandage_HitLeftLeg";
          condition = "AGM_Medical_SingleBandage == 0 and ([AGM_Interaction_Target] call AGM_Medical_fnc_isDiagnosed) and (player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitLeftLeg' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitLeftLeg'] call AGM_Medical_fnc_bandage;";
          priority = 0.2;
          conditionShow = "AGM_Medical_SingleBandage == 0";
        };
        class AGM_Bandage_RightLeg {
          displayName = "$STR_AGM_Medical_Bandage_HitRightLeg";
          condition = "AGM_Medical_SingleBandage == 0 and ([AGM_Interaction_Target] call AGM_Medical_fnc_isDiagnosed) and (player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitRightLeg' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitRightLeg'] call AGM_Medical_fnc_bandage;";
          priority = 0.15;
          conditionShow = "AGM_Medical_SingleBandage == 0";
        };
      };

      class AGM_Medical_Drag {
        displayName = "$STR_AGM_Medical_Drag";
        distance = 4;
        condition = "vehicle player == player and vehicle cursorTarget == cursorTarget and alive cursorTarget and cursorTarget != player and cursorTarget getVariable 'AGM_Treatable' and cursorTarget getVariable 'AGM_Unconscious' and isNull (player getVariable 'AGM_Dragging') and isNull (player getVariable 'AGM_Carrying')";
        statement = "[cursorTarget] call AGM_Medical_fnc_drag;";
        priority = 2.1;
      };
      class AGM_Medical_Carry {
        displayName = "$STR_AGM_Medical_Carry";
        distance = 4;
        condition = "vehicle player == player and vehicle cursorTarget == cursorTarget and alive cursorTarget and cursorTarget != player and cursorTarget getVariable 'AGM_Treatable' and cursorTarget getVariable 'AGM_Unconscious' and isNull (player getVariable 'AGM_Dragging') and isNull (player getVariable 'AGM_Carrying')";
        statement = "[cursorTarget] call AGM_Medical_fnc_carry;";
        priority = 2.0;
      };
    };

    class AGM_SelfActions {
      class AGM_Medical {
        displayName = "$STR_AGM_Medical_Treat_Self";
        condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player";
        statement = "'AGM_Medical' call AGM_Interaction_fnc_openMenuSelf;";
        showDisabled = 1;
        priority = 6;

        class AGM_Diagnose {
          displayName = "$STR_AGM_Medical_Diagnose";
          condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player";
          statement = "[player] call AGM_Medical_fnc_diagnose;";
          priority = 1;
          showDisabled = 1;
        };
        class AGM_Morphine {
          displayName = "$STR_AGM_Medical_Inject_Morphine";
          condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Morphine' in itemsWithMagazines player";
          statement = "[player] call AGM_Medical_fnc_morphine;";
          priority = 0.9;
          showDisabled = 1;
        };

        class AGM_Bandage {
          displayName = "$STR_AGM_Medical_Bandage";
          condition = "AGM_Medical_SingleBandage > 0 and (player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (damage player > 0.01)";
          statement = "[player, 'All'] call AGM_Medical_fnc_bandage;";
          priority = 0.6;
          conditionShow = "AGM_Medical_SingleBandage > 0";
        };
        class AGM_Bandage_Head {
          displayName = "$STR_AGM_Medical_Bandage_HitHead";
          condition = "AGM_Medical_SingleBandage == 0 and (player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitHead' > 0.01)";
          statement = "[player, 'HitHead'] call AGM_Medical_fnc_bandage;";
          priority = 0.6;
          conditionShow = "AGM_Medical_SingleBandage == 0";
        };
        class AGM_Bandage_Body {
          displayName = "$STR_AGM_Medical_Bandage_HitBody";
          condition = "AGM_Medical_SingleBandage == 0 and (player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitBody' > 0.01)";
          statement = "[player, 'HitBody'] call AGM_Medical_fnc_bandage;";
          priority = 0.5;
          conditionShow = "AGM_Medical_SingleBandage == 0";
        };
        class AGM_Bandage_LeftArm {
          displayName = "$STR_AGM_Medical_Bandage_HitLeftArm";
          condition = "AGM_Medical_SingleBandage == 0 and (player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitLeftArm' > 0.01)";
          statement = "[player, 'HitLeftArm'] call AGM_Medical_fnc_bandage;";
          priority = 0.4;
          conditionShow = "AGM_Medical_SingleBandage == 0";
        };
        class AGM_Bandage_RightArm {
          displayName = "$STR_AGM_Medical_Bandage_HitRightArm";
          condition = "AGM_Medical_SingleBandage == 0 and (player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitRightArm' > 0.01)";
          statement = "[player, 'HitRightArm'] call AGM_Medical_fnc_bandage;";
          priority = 0.3;
          conditionShow = "AGM_Medical_SingleBandage == 0";
        };
        class AGM_Bandage_LeftLeg {
          displayName = "$STR_AGM_Medical_Bandage_HitLeftLeg";
          condition = "AGM_Medical_SingleBandage == 0 and (player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitLeftLeg' > 0.01)";
          statement = "[player, 'HitLeftLeg'] call AGM_Medical_fnc_bandage;";
          priority = 0.2;
          conditionShow = "AGM_Medical_SingleBandage == 0";
        };
        class AGM_Bandage_RightLeg {
          displayName = "$STR_AGM_Medical_Bandage_HitRightLeg";
          condition = "AGM_Medical_SingleBandage == 0 and (player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitRightLeg' > 0.01)";
          statement = "[player, 'HitRightLeg'] call AGM_Medical_fnc_bandage;";
          priority = 0.15;
          conditionShow = "AGM_Medical_SingleBandage == 0";
        };
      };

      class AGM_Release_Drag {
        displayName = "$STR_AGM_Medical_Release";
        distance = 4;
        condition = "vehicle player == player and ((player getVariable 'AGM_Dragging') isKindOf 'Man')";
        statement = "[(player getVariable 'AGM_Dragging')] call AGM_Medical_fnc_release;";
        exceptions[] = {"AGM_Medical_canTreat"};
      };
      class AGM_Release_Carry: AGM_Release_Drag {
        condition = "vehicle player == player and ((player getVariable 'AGM_Carrying') isKindOf 'Man')";
        statement = "[(player getVariable 'AGM_Carrying')] call AGM_Medical_fnc_release;";
        exceptions[] = {"AGM_Medical_canTreat"};
      };
    };
  };

  class LandVehicle;
  class Car: LandVehicle {
    class AGM_Actions {
      class AGM_Unload {
        displayName = "$STR_AGM_Medical_Unload";
        distance = 4;
        condition = "return = false; {if (_x getVariable 'AGM_Unconscious') exitWith {return = true;};} foreach (crew AGM_Interaction_Target); return and vehicle player == player and !(AGM_Interaction_Target isKindOf 'Man')";
        statement = "[AGM_Interaction_Target] call AGM_Medical_fnc_unloadPatients;";
      };
      class AGM_Load {
        displayName = "$STR_AGM_Medical_Load";
        distance = 4;
        condition = "!(AGM_Interaction_Target isKindOf 'Man') and vehicle player == player and ((player getVariable 'AGM_Dragging') isKindOf 'Man' or (player getVariable 'AGM_Carrying') isKindOf 'Man') and AGM_Interaction_Target emptyPositions 'cargo' > 0";
        statement = "[AGM_Interaction_Target] call AGM_Medical_fnc_loadIntoVehicle;";
        exceptions[] = {"AGM_Medical_canTreat"};
      };
    };
  };
  class Tank: LandVehicle {
    class AGM_Actions {
      class AGM_Unload {
        displayName = "$STR_AGM_Medical_Unload";
        distance = 4;
        condition = "return = false; {if (_x getVariable 'AGM_Unconscious') exitWith {return = true;};} foreach (crew AGM_Interaction_Target); return and vehicle player == player and !(AGM_Interaction_Target isKindOf 'Man')";
        statement = "[AGM_Interaction_Target] call AGM_Medical_fnc_unloadPatients;";
      };
      class AGM_Load {
        displayName = "$STR_AGM_Medical_Load";
        distance = 4;
        condition = "!(AGM_Interaction_Target isKindOf 'Man') and vehicle player == player and ((player getVariable 'AGM_Dragging') isKindOf 'Man' or (player getVariable 'AGM_Carrying') isKindOf 'Man') and AGM_Interaction_Target emptyPositions 'cargo' > 0";
        statement = "[AGM_Interaction_Target] call AGM_Medical_fnc_loadIntoVehicle;";
        exceptions[] = {"AGM_Medical_canTreat"};
      };
    };
  };
  class Air;
  class Helicopter: Air {
    class AGM_Actions {
      class AGM_Unload {
        displayName = "$STR_AGM_Medical_Unload";
        distance = 4;
        condition = "return = false; {if (_x getVariable 'AGM_Unconscious') exitWith {return = true;};} foreach (crew AGM_Interaction_Target); return and vehicle player == player and !(AGM_Interaction_Target isKindOf 'Man')";
        statement = "[AGM_Interaction_Target] call AGM_Medical_fnc_unloadPatients;";
      };
      class AGM_Load {
        displayName = "$STR_AGM_Medical_Load";
        distance = 4;
        condition = "!(AGM_Interaction_Target isKindOf 'Man') and vehicle player == player and ((player getVariable 'AGM_Dragging') isKindOf 'Man' or (player getVariable 'AGM_Carrying') isKindOf 'Man') and AGM_Interaction_Target emptyPositions 'cargo' > 0";
        statement = "[AGM_Interaction_Target] call AGM_Medical_fnc_loadIntoVehicle;";
        exceptions[] = {"AGM_Medical_canTreat"};
      };
    };
  };

  class Box_NATO_Support_F;
  class AGM_Box_Medical: Box_NATO_Support_F {
    author = "AGM";
    displayName = "$STR_AGM_Medical_MedicalSupplies";
    transportmaxmagazines = 128;
    transportmaxbackpacks = 0;
    maximumload = 2000;

    class TransportMagazines {};
    class TransportWeapons {};
    class TransportItems {
      class _xx_AGM_Bandage {
        count = 64;
        name = "AGM_Bandage";
      };
      /*class _xx_AGM_Bandage2 {
        count = 4;
        name = "AGM_Bandage";
      };*/
      class _xx_AGM_Morphine {
        count = 24;
        name = "AGM_Morphine";
      };
      class _xx_AGM_Epipen {
        count = 24;
        name = "AGM_Epipen";
      };
      class _xx_AGM_Bloodbag {
        count = 16;
        name = "AGM_Bloodbag";
      };
    };
  };

  class Module_F;
  class AGM_ModuleMedical: Module_F {
    author = "AGM Team";
    category = "AGM";
    displayName = "Medical System";
    function = "AGM_Medical_fnc_module";
    scope = 2;
    isGlobal = 1;
    icon = "\AGM_Medical\UI\IconMedical_ca.paa";
    class Arguments {
      class CoefBleeding {
        displayName = "Bleeding Speed Coef.";
        description = "Multiplier for the rate of bleeding. Default: 1 (obviously)";
        defaultValue = 1;
      };
      class CoefPain {
        displayName = "Pain Effect Coef.";
        description = "Multiplier for the intensity of the pain PP effect. Default: 1 (obviously)";
        defaultValue = 1;
      };
      class MaxUnconsciousnessTime {
        displayName = "Max Unconsc. Time"
        description = "Maximum time (in seconds) for a unit to be unconscious before dying. -1 disables this."
        defaultValue = -1;
      };
      class AllowNonmedics {
        displayName = "Allow non-medics?";
        description = "Allow non-medics to use epipens and bloodbags? Default: No";
        typeName = "BOOL";
        class values {
          class Yes {
            name = "Yes";
            value = 1;
          };
          class No {
            default = 1;
            name = "No";
            value = 0;
          };
        };
      };
      class PunishNonMedics {
        displayName = "Punish non-medics?";
        description = "Increase the time it takes to complete actions for non-medics? Default: Yes";
        typeName = "BOOL";
        class values {
          class Yes {
            default = 1;
            name = "Yes";
            value = 1;
          };
          class No {
            name = "No";
            value = 0;
          };
        };
      };
      class RequireDiagnosis {
        displayName = "Require diagnosis?";
        description = "Require an unconscious patient to be diagnosed before allowing treatment? Default: No";
        typeName = "BOOL";
        class values {
          class Yes {
            name = "Yes";
            value = 1;
          };
          class No {
            default = 1;
            name = "No";
            value = 0;
          };
        };
      };
      class PreventInstaDeath {
        displayName = "Prevent instant death?";
        description = "Prevent instant death and always put players in unconscious state instead? Default: No";
        typeName = "BOOL";
        class values {
          class Yes {
            name = "Yes";
            value = 1;
          };
          class No {
            default = 1;
            name = "No";
            value = 0;
          };
        };
      };
      class PreventDeathWhileUnconscious {
        displayName = "Prevent death while unconscious?";
        description = "Make unconscious units invulnerable? Default: No";
        typeName = "BOOL";
        class values {
          class Yes {
            name = "Yes";
            value = 1;
          };
          class No {
            default = 1;
            name = "No";
            value = 0;
          };
        };
      };
      class SingleBandage {
        displayName = "Single Bandage";
        description = "Use one bandage to heal the entire body? Default: No";
        typeName = "BOOL";
        class values {
          class Yes {
            name = "Yes";
            value = 1;
          };
          class No {
            default = 1;
            name = "No";
            value = 0;
          };
        };
      };
    };
  };
};

class CfgWeapons {
  class ItemCore;
  class InventoryItem_Base_F;
  class InventoryFirstAidKitItem_Base_F;
  class MedikitItem;

  // ITEMS
  class FirstAidKit: ItemCore {
    type = 0;
    class ItemInfo: InventoryFirstAidKitItem_Base_F {
      mass = 4;
      type = 401;
    };
  };
  class Medikit: ItemCore {
    type = 0;
    class ItemInfo: MedikitItem {
      mass = 60;
      type = 401;
    };
  };

  class AGM_Bandage: ItemCore {
    displayname = "$STR_AGM_Medical_Bandage_Name";
    descriptionshort = "$STR_AGM_Medical_Bandage_Description";
    model = "\A3\Structures_F_EPA\Items\Medical\Bandage_F.p3d";
    picture = "\AGM_Medical\UI\AGM_bandage_ca.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 2;
      type = 401;
    };
  };
  class AGM_Morphine: AGM_Bandage {
    displayName = "$STR_AGM_Medical_Morphine_Name";
    descriptionShort = "$STR_AGM_Medical_Morphine_Description";
    model = "\A3\Structures_F_EPA\Items\Medical\PainKillers_F.p3d";
    picture = "\AGM_Medical\UI\AGM_morphine_ca.paa";
  };
  class AGM_Epipen: AGM_Bandage {
    displayName = "$STR_AGM_Medical_Epinephrine_Name";
    descriptionShort = "$STR_AGM_Medical_Epinephrine_Description";
    model = "\AGM_Medical\agm_epipen.p3d";
    picture = "\AGM_Medical\UI\AGM_epipen_ca.paa";
  };
  class AGM_Bloodbag: AGM_Bandage {
    displayName = "$STR_AGM_Medical_Bloodbag_Name";
    descriptionShort = "$STR_AGM_Medical_Bloodbag_Description";
    model = "\A3\Structures_F_EPA\Items\Medical\BloodBag_F.p3d";
    picture = "\AGM_Medical\UI\AGM_bloodbag_ca.paa";
    class ItemInfo: ItemInfo {
      mass = 21;
    };
  };
};

class CfgActions {
  class None;
  class HealSoldier: None {
    hideOnUse = 1;
    priority = 10;
    shortcut = "";
    show = 0;
    showWindow = 0;
    text = "Treat %1";
    textDefault = "<img image='\A3\ui_f\data\igui\cfg\actions\heal_ca.paa' size='1.8' shadow=2 />";
    textSimple = "";
  };
  class HealSoldierAuto: None {
    hideOnUse = 1;
    priority = 0;
    shortcut = "";
    show = 0;
    showWindow = 0;
    text = "Heal soldier";
    textDefault = "";
    textSimple = "";
  };
  class HealSoldierSelf: None {
    hideOnUse = 1;
    priority = 10;
    shortcut = "";
    show = 0;
    showWindow = 0;
    text = "Treat yourself";
    textDefault = "<img image='\A3\ui_f\data\igui\cfg\actions\heal_ca.paa' size='1.8' shadow=2 />";
    textSimple = "";
  };
};

// ANIMATIONS
class CfgMovesBasic {
  class Actions {
    class NoActions;
    class PistolStandActions: NoActions {
      grabDrag = "AmovPercMstpSlowWrflDnon_AcinPknlMwlkSlowWrflDb_2";
    };
    class LauncherKneelActions: NoActions {
      grabDrag = "AmovPercMstpSlowWrflDnon_AcinPknlMwlkSlowWrflDb_2";
    };
    class CivilStandActions: NoActions {
      grabDrag = "AmovPercMstpSlowWrflDnon_AcinPknlMwlkSlowWrflDb_2";
    };
  };
};

class CfgMovesMaleSdr: CfgMovesBasic {
  class States {
    class AmovPercMstpSnonWnonDnon_AcinPknlMwlkSnonWnonDb_1;

    class AcinPknlMstpSnonWnonDnon: AmovPercMstpSnonWnonDnon_AcinPknlMwlkSnonWnonDb_1 {
      enableDirectControl = 1;
    };
    class AcinPknlMwlkSnonWnonDb: AmovPercMstpSnonWnonDnon_AcinPknlMwlkSnonWnonDb_1 {
      enableDirectControl = 1;
    };
  };
};

// BLOOD MIST EFFECTS
class CfgCloudlets {
  class Blood;
  class AGM_BloodMist: Blood {
    particleShape = "\A3\data_f\ParticleEffects\Universal\Universal_02";
    particleFSNtieth = 8;
    particleFSIndex = 4;
    lifeTime = 1.8;
    size[] = {"((hit + 5) max 30) / 40", "((hit + 5) max 30) / 80", "((hit + 5) max 30) / 150"};
    color[] = {{1,0.1,0.1,0.10}, {1,0.1,0.1,0.05}, {1,0.1,0.1,0.025}};
    randomDirectionPeriod = 0.5;
    randomDirectionIntensity = 0.5;
  };
};

class ImpactEffectsBlood {
  class AGM_BloodMist {
    intensity = 1;
    interval = 1;
    lifeTime = 1;
    position[] = {0,0,0};
    simulation = "particles";
    type = "AGM_BloodMist";
  };
};

class AGM_Parameters {
  AGM_Medical_CoefBleeding = 1.0;
  AGM_Medical_CoefPain = 1.0;
  AGM_Medical_MaxUnconsciousnessTime = -1;
  // Boolean Parameters (0/1)
  AGM_Medical_AllowNonMedics = 0;
  AGM_Medical_PunishNonMedics = 1;
  AGM_Medical_RequireDiagnosis = 0;
  AGM_Medical_PreventInstaDeath = 0;
  AGM_Medical_PreventDeathWhileUnconscious = 0;
  AGM_Medical_SingleBandage = 0;
};
#include <HintConfig.hpp>
