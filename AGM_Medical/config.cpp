// PATCH CONFIG
class CfgPatches {
  class AGM_Medical {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction, Extended_EventHandlers, A3_Anims_F, A3_Anims_F_Config_Sdr, A3_Weapons_F_Items};
    version = 1.0;
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
    class AGM_Medical {
      init = "_this spawn AGM_Medical_fnc_init";
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

    class AGM_Actions {
      class AGM_Medical {
        displayName = "$STR_AGM_Treat";
        distance = 4;
        condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player";
        statement = "'AGM_Medical' call AGM_Interaction_fnc_openMenu;";
        showDisabled = 1;
        priority = 1;

        class AGM_Diagnose {
          displayName = "$STR_AGM_Diagnose";
          condition = "(player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and AGM_Interaction_Target != player";
          statement = "[AGM_Interaction_Target] call AGM_Medical_fnc_diagnose;";
          showDisabled = 1;
          priority = 1;
        };
        class AGM_Morphine {
          displayName = "$STR_AGM_Inject_Morphine";
          condition = "(player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and alive AGM_Interaction_Target and AGM_Interaction_Target != player and 'AGM_Morphine' in itemsWithMagazines player";
          statement = "[AGM_Interaction_Target] call AGM_Medical_fnc_morphine;";
          showDisabled = 1;
          priority = 0.9;
        };
        class AGM_Epipen {
          displayName = "$STR_AGM_Inject_Epinephrine";
          condition = "(player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and alive AGM_Interaction_Target and AGM_Interaction_Target != player and 'AGM_Epipen' in itemsWithMagazines player and AGM_Interaction_Target getVariable 'AGM_Unconscious'";
          statement = "[AGM_Interaction_Target] call AGM_Medical_fnc_epinephrine;";
          showDisabled = 1;
          priority = 0.8;
        };
        class AGM_BloodBag {
          displayName = "$STR_AGM_Transfuse_Blood";
          condition = "(player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and alive AGM_Interaction_Target and AGM_Interaction_Target != player and 'AGM_Bloodbag' in itemsWithMagazines player and (AGM_Interaction_Target getVariable 'AGM_Blood' < 0.7)";
          statement = "[AGM_Interaction_Target] call AGM_Medical_fnc_bloodbag;";
          showDisabled = 1;
          priority = 0.7;
        };
        class AGM_Bandage_Head {
          displayName = "$STR_AGM_Bandage_Head";
          condition = "(player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitHead' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitHead'] call AGM_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.6;
        };
        class AGM_Bandage_Body {
          displayName = "$STR_AGM_Bandage_Body";
          condition = "(player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitBody' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitBody'] call AGM_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.5;
        };
        class AGM_Bandage_LeftArm {
          displayName = "$STR_AGM_Bandage_LeftArm";
          condition = "(player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitLeftArm' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitLeftArm'] call AGM_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.4;
        };
        class AGM_Bandage_RightArm {
          displayName = "$STR_AGM_Bandage_RightArm";
          condition = "(player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitRightArm' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitRightArm'] call AGM_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.3;
        };
        class AGM_Bandage_LeftLeg {
          displayName = "$STR_AGM_Bandage_LeftLeg";
          condition = "(player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitLeftLeg' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitLeftLeg'] call AGM_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.2;
        };
        class AGM_Bandage_RightLeg {
          displayName = "$STR_AGM_Bandage_RightLeg";
          condition = "(player getVariable 'AGM_CanTreat') and (AGM_Interaction_Target getVariable 'AGM_Treatable') and vehicle player == player and vehicle AGM_Interaction_Target == AGM_Interaction_Target and 'AGM_Bandage' in itemsWithMagazines player and alive AGM_Interaction_Target and AGM_Interaction_Target != player and (AGM_Interaction_Target getHitPointDamage 'HitRightLeg' > 0.01)";
          statement = "[AGM_Interaction_Target, 'HitRightLeg'] call AGM_Medical_fnc_bandage;";
          showDisabled = 1;
          priority = 0.15;
        };
      };

      class AGM_Drag {
        displayName = "$STR_AGM_Drag";
        distance = 4;
        condition = "vehicle player == player and vehicle cursorTarget == cursorTarget and alive cursorTarget and cursorTarget != player and cursorTarget getVariable 'AGM_Treatable' and cursorTarget getVariable 'AGM_Unconscious' and isNull (player getVariable 'AGM_Dragging') and isNull (player getVariable 'AGM_Carrying')";
        statement = "[cursorTarget] call AGM_Medical_fnc_drag;";
      };
      class AGM_Carry {
        displayName = "$STR_AGM_Carry";
        distance = 4;
        condition = "vehicle player == player and vehicle cursorTarget == cursorTarget and alive cursorTarget and cursorTarget != player and cursorTarget getVariable 'AGM_Treatable' and cursorTarget getVariable 'AGM_Unconscious' and isNull (player getVariable 'AGM_Dragging') and isNull (player getVariable 'AGM_Carrying')";
        statement = "[cursorTarget] call AGM_Medical_fnc_carry;";
      };

      class AGM_Load {
        displayName = "$STR_AGM_Load"
        distance = 4;
        condition = "!(cursorTarget isKindOf 'Man') and vehicle player == player and ((player getVariable 'AGM_Dragging') isKindOf 'Man' or (player getVariable 'AGM_Carrying') isKindOf 'Man') and cursorTarget distance player < 5 and cursorTarget emptyPositions 'cargo' > 0";
        statement = "[cursorTarget] call AGM_Medical_fnc_loadIntoVehicle;";
      };
      class AGM_Unload {
        displayName = "$STR_AGM_Unload"
        distance = 4;
        condition = "return = false; {if (_x getVariable 'AGM_Unconscious') exitWith {return = true;};} foreach (crew cursorTarget); return and vehicle player == player and (cursorTarget distance player < 5) and !(cursorTarget isKindOf 'Man')";
        statement = "[cursorTarget] call AGM_Medical_fnc_unloadPatients;";
      };
    };

    class AGM_SelfActions {
      class AGM_Medical {
        displayName = "$STR_AGM_Treat_Self";
        condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player";
        statement = "'AGM_Medical' call AGM_Interaction_fnc_openMenuSelf;";
        showDisabled = 1;
        priority = 1;

        class AGM_Diagnose {
          displayName = "$STR_AGM_Diagnose";
          condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player";
          statement = "[player] call AGM_Medical_fnc_diagnose;";
          priority = 1;
          showDisabled = 1;
        };
        class AGM_Morphine {
          displayName = "$STR_AGM_Inject_Morphine";
          condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Morphine' in itemsWithMagazines player";
          statement = "[player] call AGM_Medical_fnc_morphine;";
          priority = 0.9;
          showDisabled = 1;
        };

        class AGM_Bandage_Head {
          displayName = "$STR_AGM_Bandage_Head";
          condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitHead' > 0.01)";
          statement = "[player, 'HitHead'] call AGM_Medical_fnc_bandage;";
          priority = 0.6;
          showDisabled = 1;
        };
        class AGM_Bandage_Body {
          displayName = "$STR_AGM_Bandage_Body";
          condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitBody' > 0.01)";
          statement = "[player, 'HitBody'] call AGM_Medical_fnc_bandage;";
          priority = 0.5;
          showDisabled = 1;
        };
        class AGM_Bandage_LeftArm {
          displayName = "$STR_AGM_Bandage_LeftArm";
          condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitLeftArm' > 0.01)";
          statement = "[player, 'HitLeftArm'] call AGM_Medical_fnc_bandage;";
          priority = 0.4;
          showDisabled = 1;
        };
        class AGM_Bandage_RightArm {
          displayName = "$STR_AGM_Bandage_RightArm";
          condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitRightArm' > 0.01)";
          statement = "[player, 'HitRightArm'] call AGM_Medical_fnc_bandage;";
          priority = 0.3;
          showDisabled = 1;
        };
        class AGM_Bandage_LeftLeg {
          displayName = "$STR_AGM_Bandage_LeftLeg";
          condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitLeftLeg' > 0.01)";
          statement = "[player, 'HitLeftLeg'] call AGM_Medical_fnc_bandage;";
          priority = 0.2;
          showDisabled = 1;
        };
        class AGM_Bandage_RightLeg {
          displayName = "$STR_AGM_Bandage_RightLeg";
          condition = "(player getVariable 'AGM_CanTreat') and (player getVariable 'AGM_Treatable') and vehicle player == player and 'AGM_Bandage' in itemsWithMagazines player and (player getHitPointDamage 'HitRightLeg' > 0.01)";
          statement = "[player, 'HitRightLeg'] call AGM_Medical_fnc_bandage;";
          priority = 0.15;
          showDisabled = 1;
        };
      };

      class AGM_Release_Drag {
        displayName = "$STR_AGM_Release";
        distance = 4;
        condition = "vehicle player == player and ((player getVariable 'AGM_Dragging') isKindOf 'Man')"
        statement = "[(player getVariable 'AGM_Dragging')] call AGM_Medical_fnc_release;";
      };
      class AGM_Release_Carry: AGM_Release_Drag {
        condition = "vehicle player == player and ((player getVariable 'AGM_Carrying') isKindOf 'Man')"
        statement = "[(player getVariable 'AGM_Carrying')] call AGM_Medical_fnc_release;";
      };
    };
  };
  /*
  class AGM_CollisionHelper: Land_CargoBox_V1_F {
    model = "\AGM_Medical\AGM_Medical_Helper.p3d";
  };
  */

  class Box_NATO_Support_F;

  class AGM_Box_Medical: Box_NATO_Support_F {
    author = "AGM";
    displayName = "Sanikiste";
    transportmaxmagazines = 128;
    transportmaxbackpacks = 0;
    maximumload = 2000;

    class TransportMagazines {};
    class TransportWeapons {
      class _xx_BWA3_Vector {
        count = 4;
        weapon = "BWA3_Vector";
      };
    };
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
};

class CfgWeapons {
  class ItemCore;
  class InventoryItem_Base_F;

  // ITEMS
  class FirstAidKit: ItemCore {
    type = 0;
    class ItemInfo: InventoryItem_Base_F {
      mass = 4;
      type = 201;
    };
  };
  class Medikit: ItemCore {
    type = 0;
    class ItemInfo: InventoryItem_Base_F {
      mass = 60;
      type = 201;
    };
  };

  class AGM_Bandage: ItemCore {
    displayname = "Bandage";
    descriptionshort = "Use to stop the bleeding.<br/>Usable on: Others &amp; Self";
    model = "\A3\Structures_F_EPA\Items\Medical\Bandage_F.p3d";
    picture = "\AGM_Medical\UI\AGM_bandage_ca.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 2;
      type = 201;
    };
  };
  class AGM_Morphine: AGM_Bandage {
    displayName = "Morphine Injector";
    descriptionShort = "Heavy Painkiller<br/>Usable on: Others & Self";
    model = "\A3\Structures_F_EPA\Items\Medical\PainKillers_F.p3d";
    picture = "\AGM_Medical\UI\AGM_morphine_ca.paa";
  };
  class AGM_Epipen: AGM_Bandage {
    displayName = "Epinephrine Injector";
    descriptionShort = "Used to wake up unconscious units.<br/>Usable on: Others &amp; Self";
    model = "\A3\Weapons_F\Items\FirstAidkit";
    picture = "\AGM_Medical\UI\AGM_epipen_ca.paa";
  };
  class AGM_Bloodbag: AGM_Bandage {
    displayName = "Blood Bag";
    descriptionShort = "0- blood used to compensate for heavy blood loss.<br/>Usable on: Others &amp; Self";
    model = "\A3\Structures_F_EPA\Items\Medical\BloodBag_F.p3d";
    picture = "\AGM_Medical\UI\AGM_bloodbag_ca.paa";
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

class CfgMovesBasic {
  class Actions;
};

class CfgMovesMaleSdr: CfgMovesBasic {
  class Actions: Actions {
    class MoveWithInjuredMan;

    class MoveWithInjuredManDragger: MoveWithInjuredMan {
      PlayerWalkB  = "AcinPknlMwlkSrasWrflDb";
      PlayerWalkLB = "AcinPknlMwlkSrasWrflDb";
      PlayerWalkRB = "AcinPknlMwlkSrasWrflDb";
      PlayerSlowB  = "AcinPknlMwlkSrasWrflDb";
      PlayerSlowLB = "AcinPknlMwlkSrasWrflDb";
      PlayerSlowRB = "AcinPknlMwlkSrasWrflDb";
      PlayerTactB  = "AcinPknlMwlkSrasWrflDb";
      PlayerTactLB = "AcinPknlMwlkSrasWrflDb";
      PlayerTactRB = "AcinPknlMwlkSrasWrflDb";
      WalkB        = "AcinPknlMwlkSrasWrflDb";
      WalkLB       = "AcinPknlMwlkSrasWrflDb";
      WalkRB       = "AcinPknlMwlkSrasWrflDb";
      SlowB        = "AcinPknlMwlkSrasWrflDb";
      SlowLB       = "AcinPknlMwlkSrasWrflDb";
      SlowRB       = "AcinPknlMwlkSrasWrflDb";
      TactB        = "AcinPknlMwlkSrasWrflDb";
      TactLB       = "AcinPknlMwlkSrasWrflDb";
      TactRB       = "AcinPknlMwlkSrasWrflDb";
    };
    class MoveWithInjuredManDraggerNon: MoveWithInjuredManDragger {
      /*
      PlayerTactB  = "AcinPknlMwlkSnonWnonDb";
      PlayerTactLB = "AcinPknlMwlkSnonWnonDb";
      PlayerTactRB = "AcinPknlMwlkSnonWnonDb";
      TactB        = "AcinPknlMwlkSnonWnonDb";
      TactLB       = "AcinPknlMwlkSnonWnonDb";
      TactRB       = "AcinPknlMwlkSnonWnonDb";
      */
      PlayerWalkB  = "AcinPknlMwlkSrasWrflDb";
      PlayerWalkLB = "AcinPknlMwlkSrasWrflDb";
      PlayerWalkRB = "AcinPknlMwlkSrasWrflDb";
      PlayerSlowB  = "AcinPknlMwlkSrasWrflDb";
      PlayerSlowLB = "AcinPknlMwlkSrasWrflDb";
      PlayerSlowRB = "AcinPknlMwlkSrasWrflDb";
      PlayerTactB  = "AcinPknlMwlkSrasWrflDb";
      PlayerTactLB = "AcinPknlMwlkSrasWrflDb";
      PlayerTactRB = "AcinPknlMwlkSrasWrflDb";
      WalkB        = "AcinPknlMwlkSrasWrflDb";
      WalkLB       = "AcinPknlMwlkSrasWrflDb";
      WalkRB       = "AcinPknlMwlkSrasWrflDb";
      SlowB        = "AcinPknlMwlkSrasWrflDb";
      SlowLB       = "AcinPknlMwlkSrasWrflDb";
      SlowRB       = "AcinPknlMwlkSrasWrflDb";
      TactB        = "AcinPknlMwlkSrasWrflDb";
      TactLB       = "AcinPknlMwlkSrasWrflDb";
      TactRB       = "AcinPknlMwlkSrasWrflDb";
    };
    class MoveWithInjuredManDraggerPst: MoveWithInjuredManDragger {
      /*
      PlayerTactB  = "AcinPknlMwlkSnonWpstDb";
      PlayerTactLB = "AcinPknlMwlkSnonWpstDb";
      PlayerTactRB = "AcinPknlMwlkSnonWpstDb";
      TactB        = "AcinPknlMwlkSnonWpstDb";
      TactLB       = "AcinPknlMwlkSnonWpstDb";
      TactRB       = "AcinPknlMwlkSnonWpstDb";
      */
      PlayerWalkB  = "AcinPknlMwlkSrasWrflDb";
      PlayerWalkLB = "AcinPknlMwlkSrasWrflDb";
      PlayerWalkRB = "AcinPknlMwlkSrasWrflDb";
      PlayerSlowB  = "AcinPknlMwlkSrasWrflDb";
      PlayerSlowLB = "AcinPknlMwlkSrasWrflDb";
      PlayerSlowRB = "AcinPknlMwlkSrasWrflDb";
      PlayerTactB  = "AcinPknlMwlkSrasWrflDb";
      PlayerTactLB = "AcinPknlMwlkSrasWrflDb";
      PlayerTactRB = "AcinPknlMwlkSrasWrflDb";
      WalkB        = "AcinPknlMwlkSrasWrflDb";
      WalkLB       = "AcinPknlMwlkSrasWrflDb";
      WalkRB       = "AcinPknlMwlkSrasWrflDb";
      SlowB        = "AcinPknlMwlkSrasWrflDb";
      SlowLB       = "AcinPknlMwlkSrasWrflDb";
      SlowRB       = "AcinPknlMwlkSrasWrflDb";
      TactB        = "AcinPknlMwlkSrasWrflDb";
      TactLB       = "AcinPknlMwlkSrasWrflDb";
      TactRB       = "AcinPknlMwlkSrasWrflDb";
    };
  };

  /*
  class States {
  };
  */

};