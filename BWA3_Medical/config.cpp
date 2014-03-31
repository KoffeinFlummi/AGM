// PATCH CONFIG
class CfgPatches {
  class BWA3_Medical {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
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
    class BWA3_Medical_Init {
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
      class Test {
        displayName = "Test";
        distance = 4;
        condition = "false";
        statement = "hint 'Schinken!'";
      };
      class Test2 {
        displayName = "Test2";
        distance = 4;
        condition = "true";
        statement = "hint 'Schinken! mhm'";
      };
    };

    class BWA3_SelfActions {
      class Test {
        displayName = "Test Self";
        condition = "true";
        statement = "hint 'YOLOSWAG'";
      };
      class Test2 {
        displayName = "Test Self";
        condition = "true";
        statement = "hint 'YOLOSWAG'";
      };
      class Test3 {
        displayName = "Test Self";
        condition = "true";
        statement = "hint 'YOLOSWAG'";
      };
      class Test4 {
        displayName = "Test Self";
        condition = "true";
        statement = "hint 'YOLOSWAG'";
      };
      class Test5 {
        displayName = "Test Self";
        condition = "false";
        statement = "hint 'YOLOSWAG'";
      };
    };

    class UserActions {
      // Documentation:
      // http://community.bistudio.com/wiki/UserActions

      class BWA3_Drag {
        displayName = "<t color='#ff0000'>Drag</t>";  // name in action menu
        displayNameDefault = "";                      // name on screen (icons)
        priority = 6;                                 // 0 (low) - 6 (high)
        position = "leaning_axis";                    // memory point of model
        radius = 3;                                   // minimum distance for the action to be available
        showWindow = false;                           // show text/icon on screen
        onlyForPlayer = false;                        // enable AI to be ordered to do something
        shortcut = "";                                // key (CfgDefaultKeyMappings)
        hideOnUse = 1;
        condition = "vehicle player == player and vehicle this == this and alive this and this != player and this getVariable 'BWA3_Treatable' and this getVariable 'BWA3_Unconscious' and isNull (player getVariable 'BWA3_Dragging') and isNull (player getVariable 'BWA3_Carrying')";
        statement = "[this] call BWA3_Medical_fnc_drag;";
      };
      class BWA3_Carry: BWA3_Drag {
        displayName = "<t color='#ff0000'>Carry</t>";
        priority = 5.99;
        statement = "[this] call BWA3_Medical_fnc_carry;";
      };
      class BWA3_Release: BWA3_Drag {
        displayName = "<t color='#ff0000'>Release</t>";
        priority = 6;
        condition = "vehicle player == player and vehicle this == this and alive this and this != player and ((player getVariable 'BWA3_Dragging') isKindOf 'Man' or (player getVariable 'BWA3_Carrying') isKindOf 'Man')"
        statement = "[this] call BWA3_Medical_fnc_release;";
      };

      class BWA3_Load: BWA3_Drag {
        displayName = "<t color='#ff0000'>Load Into Vehicle</t>"
        priority = 5.99;
        condition = "!(cursorTarget isKindOf 'Man') and vehicle player == player and this == player and ((player getVariable 'BWA3_Dragging') isKindOf 'Man' or (player getVariable 'BWA3_Carrying') isKindOf 'Man') and cursorTarget distance player < 5 and cursorTarget emptyPositions 'cargo' > 0";
        statement = "[cursorTarget] call BWA3_Medical_fnc_loadIntoVehicle;";
      };
      class BWA3_Unload: BWA3_Drag {
        displayName = "<t color='#ff0000'>Unload Patients</t>"
        priority = 5.985;
        condition = "return = false; {if (_x getVariable 'BWA3_Unconscious') exitWith {return = true;};} foreach (crew cursorTarget); return and vehicle player == player and this == player and (cursorTarget distance player < 5) and !(cursorTarget isKindOf 'Man')";
        statement = "[cursorTarget] call BWA3_Medical_fnc_unloadPatients;";
      };

      class BWA3_Diagnose: BWA3_Drag {
        displayName = "<t color='#ff0000'>Diagnose</t>";
        priority = 5.98;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and this != player";
        statement = "[this] call BWA3_Medical_fnc_diagnose;";
      };
      class BWA3_Morphine: BWA3_Drag {
        displayName = "<t color='#ff0000'>Inject Morphine</t>";
        priority = 5.97;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and alive this and this != player and 'BWA3_Morphine' in itemsWithMagazines player";
        statement = "[this] call BWA3_Medical_fnc_morphine;";
      };
      class BWA3_Epipen: BWA3_Drag {
        displayName = "<t color='#ff0000'>Inject Epinephrine</t>";
        priority = 5.96;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and alive this and this != player and 'BWA3_Epipen' in itemsWithMagazines player and this getVariable 'BWA3_Unconscious'";
        statement = "[this] call BWA3_Medical_fnc_epinephrine;";
      };
      class BWA3_BloodBag: BWA3_Drag {
        displayName = "<t color='#ff0000'>Transfuse Blood</t>";
        priority = 5.95;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and alive this and this != player and 'BWA3_Bloodbag' in itemsWithMagazines player and (this getVariable 'BWA3_Blood' < 0.7)";
        statement = "[this] call BWA3_Medical_fnc_bloodbag;";
      };
      class BWA3_Diagnose_Self: BWA3_Diagnose {
        displayName = "<t color='#ffbb00'>Diagnose (Self)</t>";
        priority = 0.485;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and alive this and this == player";
      };
      class BWA3_Morphine_Self: BWA3_Morphine {
        displayName = "<t color='#ffbb00'>Inject Morphine (Self)</t>";
        priority = 0.385;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and alive this and this == player and 'BWA3_Morphine' in itemsWithMagazines player";
      };

      class BWA3_Bandage_Menu: BWA3_Drag {
        displayName = "<t color='#ff0000'>Bandage ...</t>";
        priority = 5.8;
        hideOnUse = 0;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and 'BWA3_Bandage' in itemsWithMagazines player and alive this and this != player and (damage this > 0.01)";
        statement = "if (GC_bandageMenu) then {GC_bandageMenu = false;} else {GC_bandageMenu = true;};";
      };
      class BWA3_Bandage_Head: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Head</t>";
        priority = 5.799;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and 'BWA3_Bandage' in itemsWithMagazines player and alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitHead' > 0.01)";
        statement = "[this, 'HitHead'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_Body: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Torso</t>";
        priority = 5.798;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and 'BWA3_Bandage' in itemsWithMagazines player and alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitBody' > 0.01)";
        statement = "[this, 'HitBody'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_LeftArm: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Left Arm</t>";
        priority = 5.796;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and 'BWA3_Bandage' in itemsWithMagazines player and alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitLeftArm' > 0.01)";
        statement = "[this, 'HitLeftArm'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_RightArm: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Right Arm</t>";
        priority = 5.793;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and 'BWA3_Bandage' in itemsWithMagazines player and alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitRightArm' > 0.01)";
        statement = "[this, 'HitRightArm'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_LeftLeg: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Left Leg</t>";
        priority = 5.790;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and 'BWA3_Bandage' in itemsWithMagazines player and alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitLeftLeg' > 0.01)";
        statement = "[this, 'HitLeftLeg'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_RightLeg: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Right Leg</t>";
        priority = 5.787;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and 'BWA3_Bandage' in itemsWithMagazines player and alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitRightLeg' > 0.01)";
        statement = "[this, 'HitRightLeg'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };

      class BWA3_Bandage_Menu_Self: BWA3_Drag {
        displayName = "<t color='#ffbb00'>Bandage (self) ...</t>";
        priority = 0.2;
        hideOnUse = 0;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and 'BWA3_Bandage' in itemsWithMagazines player and alive this and this == player and (damage this > 0.01)";
        statement = "if (GC_bandageMenuSelf) then {GC_bandageMenuSelf = false;} else {GC_bandageMenuSelf = true;};";
      };
      class BWA3_Bandage_Head_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Head</t>";
        priority = 0.199;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and 'BWA3_Bandage' in itemsWithMagazines player and alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitHead' > 0.01)";
        statement = "[this, 'HitHead'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_Body_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Torso</t>";
        priority = 0.198;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and 'BWA3_Bandage' in itemsWithMagazines player and alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitBody' > 0.01)";
        statement = "[this, 'HitBody'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_LeftArm_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Left Arm</t>";
        priority = 0.196;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and 'BWA3_Bandage' in itemsWithMagazines player and alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitLeftArm' > 0.01)";
        statement = "[this, 'HitLeftArm'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_RightArm_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Right Arm</t>";
        priority = 0.193;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and 'BWA3_Bandage' in itemsWithMagazines player and alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitRightArm' > 0.01)";
        statement = "[this, 'HitRightArm'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_LeftLeg_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Left Leg</t>";
        priority = 0.190;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and 'BWA3_Bandage' in itemsWithMagazines player and alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitLeftLeg' > 0.01)";
        statement = "[this, 'HitLeftLeg'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_RightLeg_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Right Leg</t>";
        priority = 0.187;
        condition = "(player getVariable 'BWA3_CanTreat') and (this getVariable 'BWA3_Treatable') and vehicle player == player and vehicle this == this and 'BWA3_Bandage' in itemsWithMagazines player and alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitRightLeg' > 0.01)";
        statement = "[this, 'HitRightLeg'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
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
