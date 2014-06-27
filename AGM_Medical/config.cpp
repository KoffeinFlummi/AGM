// PATCH CONFIG
class CfgPatches {
  class AGM_Medical {
    units[] = {
      "AGM_Box_Medical"
    };
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {
      AGM_Core,
      AGM_Interaction,
      Extended_EventHandlers,
      A3_Data_F,
      A3_Anims_F,
      A3_Anims_F_Config_Sdr,
      A3_Anims_F_EPA,
      A3_Anims_F_EPC,
      A3_CargoPoses_F,
      A3_Characters_F,
      A3_Weapons_F_Items,
      A3_UI_F
    };
    version = "0.91";
    versionStr = "0.91";
    versionAr[] = {0,91,0};
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
      class setHitPointDamage;
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

class AGM_Core_Options {
  class keepMedicalMenuOpen {
    displayName = "$STR_AGM_Medical_keepMenuOpen";
    default = 0;
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
        priority = 1;

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
        class AGM_Bandage_Head {
          displayName = "$STR_AGM_Medical_Bandage_HitHead";
          condition = "([AGM_Interaction_Target] call AGM_Medical_fnc_isDiagnosed) and (player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitHead' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitHead'] call AGM_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.6;
        };
        class AGM_Bandage_Body {
          displayName = "$STR_AGM_Medical_Bandage_HitBody";
          condition = "([AGM_Interaction_Target] call AGM_Medical_fnc_isDiagnosed) and (player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitBody' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitBody'] call AGM_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.5;
        };
        class AGM_Bandage_LeftArm {
          displayName = "$STR_AGM_Medical_Bandage_HitLeftArm";
          condition = "([AGM_Interaction_Target] call AGM_Medical_fnc_isDiagnosed) and (player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitLeftArm' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitLeftArm'] call AGM_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.4;
        };
        class AGM_Bandage_RightArm {
          displayName = "$STR_AGM_Medical_Bandage_HitRightArm";
          condition = "([AGM_Interaction_Target] call AGM_Medical_fnc_isDiagnosed) and (player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitRightArm' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitRightArm'] call AGM_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.3;
        };
        class AGM_Bandage_LeftLeg {
          displayName = "$STR_AGM_Medical_Bandage_HitLeftLeg";
          condition = "([AGM_Interaction_Target] call AGM_Medical_fnc_isDiagnosed) and (player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitLeftLeg' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitLeftLeg'] call AGM_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.2;
        };
        class AGM_Bandage_RightLeg {
          displayName = "$STR_AGM_Medical_Bandage_HitRightLeg";
          condition = "([AGM_Interaction_Target] call AGM_Medical_fnc_isDiagnosed) and (player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitRightLeg' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitRightLeg'] call AGM_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.15;
        };
      };

      class AGM_Drag {
        displayName = "$STR_AGM_Medical_Drag";
        distance = 4;
        condition = "vehicle player == player and vehicle cursorTarget == cursorTarget and alive cursorTarget and cursorTarget != player and cursorTarget getVariable 'AGM_Treatable' and cursorTarget getVariable 'AGM_Unconscious' and isNull (player getVariable 'AGM_Dragging') and isNull (player getVariable 'AGM_Carrying')";
        statement = "[cursorTarget] call AGM_Medical_fnc_drag;";
      };
      class AGM_Carry {
        displayName = "$STR_AGM_Medical_Carry";
        distance = 4;
        condition = "vehicle player == player and vehicle cursorTarget == cursorTarget and alive cursorTarget and cursorTarget != player and cursorTarget getVariable 'AGM_Treatable' and cursorTarget getVariable 'AGM_Unconscious' and isNull (player getVariable 'AGM_Dragging') and isNull (player getVariable 'AGM_Carrying')";
        statement = "[cursorTarget] call AGM_Medical_fnc_carry;";
      };
    };

    class AGM_SelfActions {
      class AGM_Medical {
        displayName = "$STR_AGM_Medical_Treat_Self";
        condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player";
        statement = "'AGM_Medical' call AGM_Interaction_fnc_openMenuSelf;";
        showDisabled = 1;
        priority = 1;

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

        class AGM_Bandage_Head {
          displayName = "$STR_AGM_Medical_Bandage_HitHead";
          condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitHead' > 0.01)";
          statement = "[player, 'HitHead'] call AGM_Medical_fnc_bandage;";
          priority = 0.6;
          showDisabled = 1;
        };
        class AGM_Bandage_Body {
          displayName = "$STR_AGM_Medical_Bandage_HitBody";
          condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitBody' > 0.01)";
          statement = "[player, 'HitBody'] call AGM_Medical_fnc_bandage;";
          priority = 0.5;
          showDisabled = 1;
        };
        class AGM_Bandage_LeftArm {
          displayName = "$STR_AGM_Medical_Bandage_HitLeftArm";
          condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitLeftArm' > 0.01)";
          statement = "[player, 'HitLeftArm'] call AGM_Medical_fnc_bandage;";
          priority = 0.4;
          showDisabled = 1;
        };
        class AGM_Bandage_RightArm {
          displayName = "$STR_AGM_Medical_Bandage_HitRightArm";
          condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitRightArm' > 0.01)";
          statement = "[player, 'HitRightArm'] call AGM_Medical_fnc_bandage;";
          priority = 0.3;
          showDisabled = 1;
        };
        class AGM_Bandage_LeftLeg {
          displayName = "$STR_AGM_Medical_Bandage_HitLeftLeg";
          condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitLeftLeg' > 0.01)";
          statement = "[player, 'HitLeftLeg'] call AGM_Medical_fnc_bandage;";
          priority = 0.2;
          showDisabled = 1;
        };
        class AGM_Bandage_RightLeg {
          displayName = "$STR_AGM_Medical_Bandage_HitRightLeg";
          condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitRightLeg' > 0.01)";
          statement = "[player, 'HitRightLeg'] call AGM_Medical_fnc_bandage;";
          priority = 0.15;
          showDisabled = 1;
        };
      };

      class AGM_Release_Drag {
        displayName = "$STR_AGM_Medical_Release";
        distance = 4;
        condition = "vehicle player == player and ((player getVariable 'AGM_Dragging') isKindOf 'Man')";
        statement = "[(player getVariable 'AGM_Dragging')] call AGM_Medical_fnc_release;";
      };
      class AGM_Release_Carry: AGM_Release_Drag {
        condition = "vehicle player == player and ((player getVariable 'AGM_Carrying') isKindOf 'Man')";
        statement = "[(player getVariable 'AGM_Carrying')] call AGM_Medical_fnc_release;";
      };
    };
  };

  class All;
  class AllVehicles: All {
    class AGM_Actions {
      class AGM_Unload {
        displayName = "$STR_AGM_Medical_Unload";
        distance = 6;
        condition = "return = false; {if (_x getVariable 'AGM_Unconscious') exitWith {return = true;};} foreach (crew AGM_Interaction_Target); return and vehicle player == player and !(AGM_Interaction_Target isKindOf 'Man')";
        statement = "[AGM_Interaction_Target] call AGM_Medical_fnc_unloadPatients;";
      };
      class AGM_Load {
        displayName = "$STR_AGM_Medical_Load";
        distance = 6;
        condition = "!(AGM_Interaction_Target isKindOf 'Man') and vehicle player == player and ((player getVariable 'AGM_Dragging') isKindOf 'Man' or (player getVariable 'AGM_Carrying') isKindOf 'Man') and AGM_Interaction_Target emptyPositions 'cargo' > 0";
        statement = "[AGM_Interaction_Target] call AGM_Medical_fnc_loadIntoVehicle;";
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

    };
  };
};

class CfgWeapons {
  class ItemCore;
  class InventoryItem_Base_F;
  class InventoryFirstAidKitItem_Base_F;
  class MedikitItem;
  class VestItem;

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
    model = "\A3\Weapons_F\Items\FirstAidkit";
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

  // VESTS
  // basically we are reducing the amount of shots a vest can take from something like 5 to 2.
  class Vest_Camo_Base: ItemCore {
    class ItemInfo;
  };
  class Vest_NoCamo_Base: ItemCore {
    class ItemInfo;
  };

  // plate carriers
  class V_PlateCarrier1_blk: Vest_Camo_Base {
    class ItemInfo: ItemInfo {
      armor = 8;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrier1_rgr: Vest_NoCamo_Base {
    class ItemInfo: ItemInfo {
      armor = 8;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrier2_rgr: V_PlateCarrier1_rgr {
    class ItemInfo: ItemInfo {
      armor = 12;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrierL_CTRG: V_PlateCarrier1_rgr {
    class ItemInfo: ItemInfo {
      armor = 8;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrier3_rgr: Vest_NoCamo_Base {
    class ItemInfo: ItemInfo {
      armor = 12;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrier_Kerry: V_PlateCarrier1_rgr {
    class ItemInfo: ItemInfo {
      armor = 12;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrierGL_rgr: Vest_NoCamo_Base {
    class ItemInfo: ItemInfo {
      armor = 24;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrierH_CTRG: V_PlateCarrier2_rgr {
    class ItemInfo: ItemInfo {
      armor = 12;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrierIA1_dgtl: Vest_NoCamo_Base {
    class ItemInfo: VestItem {
      armor = 8;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrierIA2_dgtl: V_PlateCarrierIA1_dgtl {
    class ItemInfo: VestItem {
      armor = 12;
      passThrough = 0.6;
    };
  };
  class V_PlateCarrierIAGL_dgtl: V_PlateCarrierIA2_dgtl {
    class ItemInfo: VestItem {
      armor = 20;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrierSpec_rgr: Vest_NoCamo_Base {
    class ItemInfo: ItemInfo {
      armor = 16;
      passThrough = 0.45;
    };
  };

  // rebreathers (WHY ARE THESE ARMOURED ANYWAYS?!)
  class V_RebreatherB: Vest_Camo_Base {
    class ItemInfo: ItemInfo {
      armor = 0;
    };
  };
  class V_RebreatherIA: V_RebreatherB {
    class ItemInfo: ItemInfo {
      armor = 0;
    };
  };
  class V_RebreatherIR: V_RebreatherB {
    class ItemInfo: ItemInfo {
      armor = 0;
    };
  };

  // tac vests
  class V_TacVest_camo: Vest_Camo_Base {
    class ItemInfo: ItemInfo {
      armor = 8;
    };
  };
  class V_TacVest_khk: Vest_Camo_Base {
    class ItemInfo: ItemInfo {
      armor = 8;
    };
  };
  class V_TacVest_brn: V_TacVest_khk {
    class ItemInfo: ItemInfo {
      armor = 8;
    };
  };
  class V_TacVest_oli: V_TacVest_khk {
    class ItemInfo: ItemInfo {
      armor = 8;
    };
  };
  class V_TacVest_blk: V_TacVest_khk {
    class ItemInfo: ItemInfo {
      armor = 8;
    };
  };
  class V_TacVest_blk_POLICE: Vest_Camo_Base {
    class ItemInfo: ItemInfo {
      armor = 8;
    };
  };
  class V_TacVest_RU: Vest_Camo_Base {
    class ItemInfo: ItemInfo {
      armor = 8;
    };
  };
  class V_TacVestCamo_khk: Vest_Camo_Base {
    class ItemInfo: VestItem {
      armor = 8;
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

#include <HintConfig.hpp>
