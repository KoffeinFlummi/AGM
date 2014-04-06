// PATCH CONFIG
class CfgPatches {
  class BWA3_Medical {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    //requiredAddons[] = {BWA3_Interaction, Extended_EventHandlers};
    requiredAddons[] = {Extended_EventHandlers};
    version = 1.0;
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class BWA3_Medical {
    class BWA3_Medical {
      file = "BWA3_Medical\functions";
      class bandage;
      class bloodbag;
      class carry;
      class diagnose;
      class drag;
      class dropWeapon;
      class epinephrine;
      class forceProne;
      class handleDamage;
      class init;
      class isMedic;
      class knockOut;
      class loadIntoVehicle;
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
    class BWA3_Medical {
      init = "_this call BWA3_Medical_fnc_init";
    };
  };
};

class CfgVehicles {
  class Man;
  class Land_CargoBox_V1_F;

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
        visual = "infury_body";
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

    class BWA3_Actions {
      class BWA3_Medical {
        displayName = "$STR_BWA3_Treat";
        distance = 4;
        condition = "(player getVariable 'BWA3_CanTreat') and (player getVariable 'BWA3_Treatable') and vehicle player == player";
        statement = "'BWA3_Medical' call BWA3_Interaction_fnc_openMenu;";
        showDisabled = 1;
        priority = 1;

        class BWA3_Diagnose {
          displayName = "$STR_BWA3_Diagnose";
          condition = "(player getVariable 'BWA3_CanTreat') and (BWA3_Interaction_Target getVariable 'BWA3_Treatable') and vehicle player == player and vehicle BWA3_Interaction_Target == BWA3_Interaction_Target and BWA3_Interaction_Target != player";
          statement = "[BWA3_Interaction_Target] call BWA3_Medical_fnc_diagnose;";
          showDisabled = 1;
          priority = 1;
        };
        class BWA3_Morphine {
          displayName = "$STR_BWA3_Inject_Morphine";
          condition = "(player getVariable 'BWA3_CanTreat') and (BWA3_Interaction_Target getVariable 'BWA3_Treatable') and vehicle player == player and vehicle BWA3_Interaction_Target == BWA3_Interaction_Target and alive BWA3_Interaction_Target and BWA3_Interaction_Target != player and 'BWA3_Morphine' in itemsWithMagazines player";
          statement = "[BWA3_Interaction_Target] call BWA3_Medical_fnc_morphine;";
          showDisabled = 1;
          priority = 0.9;
        };
        class BWA3_Epipen {
          displayName = "$STR_BWA3_Inject_Epinephrine";
          condition = "(player getVariable 'BWA3_CanTreat') and (BWA3_Interaction_Target getVariable 'BWA3_Treatable') and vehicle player == player and vehicle BWA3_Interaction_Target == BWA3_Interaction_Target and alive BWA3_Interaction_Target and BWA3_Interaction_Target != player and 'BWA3_Epipen' in itemsWithMagazines player and BWA3_Interaction_Target getVariable 'BWA3_Unconscious'";
          statement = "[BWA3_Interaction_Target] call BWA3_Medical_fnc_epinephrine;";
          showDisabled = 1;
          priority = 0.8;
        };
        class BWA3_BloodBag {
          displayName = "$STR_BWA3_Transfuse_Blood";
          condition = "(player getVariable 'BWA3_CanTreat') and (BWA3_Interaction_Target getVariable 'BWA3_Treatable') and vehicle player == player and vehicle BWA3_Interaction_Target == BWA3_Interaction_Target and alive BWA3_Interaction_Target and BWA3_Interaction_Target != player and 'BWA3_Bloodbag' in itemsWithMagazines player and (BWA3_Interaction_Target getVariable 'BWA3_Blood' < 0.7)";
          statement = "[BWA3_Interaction_Target] call BWA3_Medical_fnc_bloodbag;";
          showDisabled = 1;
          priority = 0.7;
        };
        class BWA3_Bandage_Head {
          displayName = "$STR_BWA3_Bandage_Head";
          condition = "(player getVariable 'BWA3_CanTreat') and (BWA3_Interaction_Target getVariable 'BWA3_Treatable') and vehicle player == player and vehicle BWA3_Interaction_Target == BWA3_Interaction_Target and 'BWA3_Bandage' in itemsWithMagazines player and alive BWA3_Interaction_Target and BWA3_Interaction_Target != player and (BWA3_Interaction_Target getHitPointDamage 'HitHead' > 0.01)";
          statement = "[BWA3_Interaction_Target, 'HitHead'] call BWA3_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.6;
        };
        class BWA3_Bandage_Body {
          displayName = "$STR_BWA3_Bandage_Body";
          condition = "(player getVariable 'BWA3_CanTreat') and (BWA3_Interaction_Target getVariable 'BWA3_Treatable') and vehicle player == player and vehicle BWA3_Interaction_Target == BWA3_Interaction_Target and 'BWA3_Bandage' in itemsWithMagazines player and alive BWA3_Interaction_Target and BWA3_Interaction_Target != player and (BWA3_Interaction_Target getHitPointDamage 'HitBody' > 0.01)";
          statement = "[BWA3_Interaction_Target, 'HitBody'] call BWA3_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.5;
        };
        class BWA3_Bandage_LeftArm {
          displayName = "$STR_BWA3_Bandage_LeftArm";
          condition = "(player getVariable 'BWA3_CanTreat') and (BWA3_Interaction_Target getVariable 'BWA3_Treatable') and vehicle player == player and vehicle BWA3_Interaction_Target == BWA3_Interaction_Target and 'BWA3_Bandage' in itemsWithMagazines player and alive BWA3_Interaction_Target and BWA3_Interaction_Target != player and (BWA3_Interaction_Target getHitPointDamage 'HitLeftArm' > 0.01)";
          statement = "[BWA3_Interaction_Target, 'HitLeftArm'] call BWA3_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.4;
        };
        class BWA3_Bandage_RightArm {
          displayName = "$STR_BWA3_Bandage_RightArm";
          condition = "(player getVariable 'BWA3_CanTreat') and (BWA3_Interaction_Target getVariable 'BWA3_Treatable') and vehicle player == player and vehicle BWA3_Interaction_Target == BWA3_Interaction_Target and 'BWA3_Bandage' in itemsWithMagazines player and alive BWA3_Interaction_Target and BWA3_Interaction_Target != player and (BWA3_Interaction_Target getHitPointDamage 'HitRightArm' > 0.01)";
          statement = "[BWA3_Interaction_Target, 'HitRightArm'] call BWA3_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.3;
        };
        class BWA3_Bandage_LeftLeg {
          displayName = "$STR_BWA3_Bandage_LeftLeg";
          condition = "(player getVariable 'BWA3_CanTreat') and (BWA3_Interaction_Target getVariable 'BWA3_Treatable') and vehicle player == player and vehicle BWA3_Interaction_Target == BWA3_Interaction_Target and 'BWA3_Bandage' in itemsWithMagazines player and alive BWA3_Interaction_Target and BWA3_Interaction_Target != player and (BWA3_Interaction_Target getHitPointDamage 'HitLeftLeg' > 0.01)";
          statement = "[BWA3_Interaction_Target, 'HitLeftLeg'] call BWA3_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.2;
        };
        class BWA3_Bandage_RightLeg {
          displayName = "$STR_BWA3_Bandage_RightLeg";
          condition = "(player getVariable 'BWA3_CanTreat') and (BWA3_Interaction_Target getVariable 'BWA3_Treatable') and vehicle player == player and vehicle BWA3_Interaction_Target == BWA3_Interaction_Target and 'BWA3_Bandage' in itemsWithMagazines player and alive BWA3_Interaction_Target and BWA3_Interaction_Target != player and (BWA3_Interaction_Target getHitPointDamage 'HitRightLeg' > 0.01)";
          statement = "[BWA3_Interaction_Target, 'HitRightLeg'] call BWA3_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.15;
        };
      };

      class BWA3_Drag {
        displayName = "$STR_BWA3_Drag";
        distance = 4;
        condition = "vehicle player == player and vehicle cursorTarget == cursorTarget and alive cursorTarget and cursorTarget != player and cursorTarget getVariable 'BWA3_Treatable' and cursorTarget getVariable 'BWA3_Unconscious' and isNull (player getVariable 'BWA3_Dragging') and isNull (player getVariable 'BWA3_Carrying')";
        statement = "[cursorTarget] call BWA3_Medical_fnc_drag;";
      };
      class BWA3_Carry {
        displayName = "$STR_BWA3_Carry";
        distance = 4;
        condition = "vehicle player == player and vehicle cursorTarget == cursorTarget and alive cursorTarget and cursorTarget != player and cursorTarget getVariable 'BWA3_Treatable' and cursorTarget getVariable 'BWA3_Unconscious' and isNull (player getVariable 'BWA3_Dragging') and isNull (player getVariable 'BWA3_Carrying')";
        statement = "[cursorTarget] call BWA3_Medical_fnc_carry;";
      };
      class BWA3_Release {
        displayName = "$STR_BWA3_Release";
        distance = 4;
        condition = "vehicle player == player and vehicle cursorTarget == cursorTarget and alive cursorTarget and cursorTarget != player and ((player getVariable 'BWA3_Dragging') isKindOf 'Man' or (player getVariable 'BWA3_Carrying') isKindOf 'Man')"
        statement = "[cursorTarget] call BWA3_Medical_fnc_release;";
      };

      class BWA3_Load {
        displayName = "$STR_BWA3_Load"
        distance = 4;
        condition = "!(cursorTarget isKindOf 'Man') and vehicle player == player and ((player getVariable 'BWA3_Dragging') isKindOf 'Man' or (player getVariable 'BWA3_Carrying') isKindOf 'Man') and cursorTarget distance player < 5 and cursorTarget emptyPositions 'cargo' > 0";
        statement = "[cursorTarget] call BWA3_Medical_fnc_loadIntoVehicle;";
      };
      class BWA3_Unload {
        displayName = "$STR_BWA3_Unload"
        distance = 4;
        condition = "return = false; {if (_x getVariable 'BWA3_Unconscious') exitWith {return = true;};} foreach (crew cursorTarget); return and vehicle player == player and (cursorTarget distance player < 5) and !(cursorTarget isKindOf 'Man')";
        statement = "[cursorTarget] call BWA3_Medical_fnc_unloadPatients;";
      };
    };

    class BWA3_SelfActions {
      class BWA3_Medical {
        displayName = "$STR_BWA3_Treat_Self";
        condition = "(player getVariable 'BWA3_CanTreat') and (player getVariable 'BWA3_Treatable') and vehicle player == player";
        statement = "'BWA3_Medical' call BWA3_Interaction_fnc_openMenuSelf;";
        showDisabled = 1;
        priority = 1;

        class BWA3_Diagnose {
          displayName = "$STR_BWA3_Diagnose";
          condition = "(player getVariable 'BWA3_CanTreat') and (player getVariable 'BWA3_Treatable') and vehicle player == player";
          statement = "[player] call BWA3_Medical_fnc_diagnose;";
          priority = 1;
          showDisabled = 1;
        };
        class BWA3_Morphine {
          displayName = "$STR_BWA3_Inject_Morphine";
          condition = "(player getVariable 'BWA3_CanTreat') and (player getVariable 'BWA3_Treatable') and vehicle player == player and 'BWA3_Morphine' in itemsWithMagazines player";
          statement = "[player] call BWA3_Medical_fnc_morphine;";
          priority = 0.9;
          showDisabled = 1;
        };

        class BWA3_Bandage_Head {
          displayName = "$STR_BWA3_Bandage_Head";
          condition = "(player getVariable 'BWA3_CanTreat') and (player getVariable 'BWA3_Treatable') and vehicle player == player and 'BWA3_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitHead' > 0.01)";
          statement = "[player, 'HitHead'] call BWA3_Medical_fnc_bandage;";
          priority = 0.6;
          showDisabled = 1;
        };
        class BWA3_Bandage_Body {
          displayName = "$STR_BWA3_Bandage_Body";
          condition = "(player getVariable 'BWA3_CanTreat') and (player getVariable 'BWA3_Treatable') and vehicle player == player and 'BWA3_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitBody' > 0.01)";
          statement = "[player, 'HitBody'] call BWA3_Medical_fnc_bandage;";
          priority = 0.5;
          showDisabled = 1;
        };
        class BWA3_Bandage_LeftArm {
          displayName = "$STR_BWA3_Bandage_LeftArm";
          condition = "(player getVariable 'BWA3_CanTreat') and (player getVariable 'BWA3_Treatable') and vehicle player == player and 'BWA3_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitLeftArm' > 0.01)";
          statement = "[player, 'HitLeftArm'] call BWA3_Medical_fnc_bandage;";
          priority = 0.4;
          showDisabled = 1;
        };
        class BWA3_Bandage_RightArm {
          displayName = "$STR_BWA3_Bandage_RightArm";
          condition = "(player getVariable 'BWA3_CanTreat') and (player getVariable 'BWA3_Treatable') and vehicle player == player and 'BWA3_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitRightArm' > 0.01)";
          statement = "[player, 'HitRightArm'] call BWA3_Medical_fnc_bandage;";
          priority = 0.3;
          showDisabled = 1;
        };
        class BWA3_Bandage_LeftLeg {
          displayName = "$STR_BWA3_Bandage_LeftLeg";
          condition = "(player getVariable 'BWA3_CanTreat') and (player getVariable 'BWA3_Treatable') and vehicle player == player and 'BWA3_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitLeftLeg' > 0.01)";
          statement = "[player, 'HitLeftLeg'] call BWA3_Medical_fnc_bandage;";
          priority = 0.2;
          showDisabled = 1;
        };
        class BWA3_Bandage_RightLeg {
          displayName = "$STR_BWA3_Bandage_RightLeg";
          condition = "(player getVariable 'BWA3_CanTreat') and (player getVariable 'BWA3_Treatable') and vehicle player == player and 'BWA3_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitRightLeg' > 0.01)";
          statement = "[player, 'HitRightLeg'] call BWA3_Medical_fnc_bandage;";
          priority = 0.15;
          showDisabled = 1;
        };
      };
    };
  };
  /*
  class BWA3_CollisionHelper: Land_CargoBox_V1_F {
    model = "\BWA3_Medical\BWA3_Medical_Helper.p3d";
  };
  */
};

class CfgWeapons {
  class ItemCore;
  class InventoryItem_Base_F;

  // ITEMS
  class FirstAidKit {
    type = 0;
    class ItemInfo: InventoryItem_Base_F {
      mass = 4;
      type = 201;
    };
  };
  class Medikit {
    type = 0;
    class ItemInfo: InventoryItem_Base_F {
      mass = 60;
      type = 201;
    };
  };

  class BWA3_Bandage: ItemCore {
    displayname = "Bandage";
    descriptionshort = "Use to stop the bleeding.<br/>Usable on: Others &amp; Self";
    model = "\A3\Structures_F_EPA\Items\Medical\Bandage_F.p3d";
    picture = "\A3\Weapons_F\Items\data\UI\gear_FirstAidKit_CA.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 2;
      type = 201;
    };
  };
  class BWA3_Morphine: BWA3_Bandage {
    displayName = "Morphine Injector";
    descriptionShort = "Heavy Painkiller<br/>Usable on: Others & Self";
    model = "\A3\Structures_F_EPA\Items\Medical\PainKillers_F.p3d";
  };
  class BWA3_Epipen: BWA3_Bandage {
    displayName = "Epinephrine Injector";
    descriptionShort = "Used to wake up unconscious units.<br/>Usable on: Others &amp; Self";
    model = "\A3\Weapons_F\Items\FirstAidkit";
  };
  class BWA3_Bloodbag: BWA3_Bandage {
    displayName = "Blood Bag";
    descriptionShort = "0- blood used to compensate for heavy blood loss.<br/>Usable on: Others &amp; Self";
    model = "\A3\Structures_F_EPA\Items\Medical\BloodBag_F.p3d";
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
    class ItemInfo: ItemInfo {
      armor = 8;
      passThrough = 0.75;
    };
  };
  class V_PlateCarrierIA2_dgtl: V_PlateCarrierIA1_dgtl {
    class ItemInfo: ItemInfo {
      armor = 12;
      passThrough = 0.6;
    };
  };
  class V_PlateCarrierIAGL_dgtl: V_PlateCarrierIA2_dgtl {
    class ItemInfo: ItemInfo {
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
    class ItemInfo: ItemInfo {
      armor = 8;
    };
  };

};
