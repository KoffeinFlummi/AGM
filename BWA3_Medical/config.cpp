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
      class carry;
      class diagnose;
      class drag;
      class dropWeapon;
      class forceProne;
      class handleDamage;
      class init;
      class isMedic;
      class knockOut;
      class morphine;
      class release;
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
    armor = 1.5;
    armorStructural = 4.5;

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

      // HEAD
      class HitHead {
        armor = 0.5;
        explosionShielding = 1;
        material = -1;
        minimalHit = 0;
        name = "head";
        passThrough = 1;
        radius = 0.1;
      };
      // TORSO
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
      // ARMS
      class HitLeftShoulder {
        armor = 2;
        explosionShielding = 1;
        material = -1;
        minimalHit = 0;
        name = "LeftArm";
        passThrough = 1;
        radius = 0.06;
        visual = "injury_hands";
      };
      class HitLeftArm: HitLeftShoulder {
        name = "LeftArmRoll";
      };
      class HitLeftForeArm: HitLeftShoulder {
        name = "LeftForeArm";
      };
      class HitRightShoulder: HitLeftShoulder {
        name = "RightArm";
      };
      class HitRightArm: HitLeftShoulder {
        name = "RightArmRoll";
      };
      class HitRightForeArm: HitLeftShoulder {
        name = "RightForeArm";
      };
      // LEGS
      class HitLeftUpLeg {
        armor = 2;
        explosionShielding = 1;
        material = -1;
        minimalHit = 0;
        name = "L_Femur_hit";
        passThrough = 1;
        radius = 0.08;
        visual = "injury_legs";
      };
      class HitLeftLeg: HitLeftUpLeg {
        name = "LeftLegRoll";
      };
      class HitLeftFoot: HitLeftUpLeg {
        name = "LeftFoot";
      };
      class HitRightUpLeg: HitLeftUpLeg {
        name = "R_Femur_hit";
      };
      class HitRightLeg: HitLeftUpLeg {
        name = "RightLeg";
      };
      class HitRightFoot: HitLeftUpLeg {
        name = "RightFoot";
      };
    };

    /* for later (custom interaction system)
    class BWA3_Actions {
      class Drag {
        displayName = "Drag";
        distance = 4;
        condition = "this != player and this getVariable 'BWA3_Unconscious' and !(player getVariable 'BWA3_Dragging') and !(player getVariable 'BWA3_Carrying')";
        statement = "[this] call BWA3_Medical_fnc_drag";
      };
      class Carry: Drag {
        displayName = "Carry";
        statement = "[this] call BWA3_Medical_fnc_carry";
      };
      class Release: Drag {
        displayName = "Release";
        condition = "this != player and ((player getVariable 'BWA3_Dragging') isKindOf 'Man' or (player getVariable 'BWA3_Carrying') isKindOf 'Man')"
        statement = "[this] call BWA3_Medical_fnc_release";
      };
      class Diagnose: Drag {
        displayName = "Diagnose";
        condition = "this != player";
        statement = "[this] call BWA3_Medical_fnc_diagnose";
      };
    };*/

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
        condition = "alive this and this != player and this getVariable 'BWA3_Unconscious' and isNull (player getVariable 'BWA3_Dragging') and isNull (player getVariable 'BWA3_Carrying')";
        statement = "[this] call BWA3_Medical_fnc_drag";
      };
      class BWA3_Carry: BWA3_Drag {
        displayName = "<t color='#ff0000'>Carry</t>";
        priority = 5.99;
        statement = "[this] call BWA3_Medical_fnc_carry";
      };
      class BWA3_Release: BWA3_Drag {
        displayName = "<t color='#ff0000'>Release</t>";
        priority = 6;
        condition = "alive this and this != player and ((player getVariable 'BWA3_Dragging') isKindOf 'Man' or (player getVariable 'BWA3_Carrying') isKindOf 'Man')"
      };

      class BWA3_Diagnose: BWA3_Drag {
        displayName = "<t color='#ff0000'>Diagnose</t>";
        priority = 5.98;
        condition = "alive this and this != player";
        statement = "[this] call BWA3_Medical_fnc_diagnose";
      };
      class BWA3_Diagnose_Self: BWA3_Diagnose {
        displayName = "<t color='#ffbb00'>Diagnose (Self)</t>";
        priority = 0.485;
        condition = "alive this and this == player";
      };
      class BWA3_Morphine: BWA3_Drag {
        displayName = "<t color='#ff0000'>Inject Morphine</t>";
        priority = 5.9;
        condition = "alive this and this != player";
        statement = "[this] call BWA3_Medical_fnc_morphine";
      };
      class BWA3_Morphine_Self: BWA3_Morphine {
        displayName = "<t color='#ffbb00'>Inject Morphine (Self)</t>";
        priority = 0.385;
        condition = "alive this and this == player";
      };

      class BWA3_Bandage_Menu: BWA3_Drag {
        displayName = "<t color='#ff0000'>Bandage ...</t>";
        priority = 5.8;
        hideOnUse = 0;
        condition = "alive this and this != player and (damage this > 0.001)";
        statement = "if (GC_bandageMenu) then {GC_bandageMenu = false;} else {GC_bandageMenu = true;};";
      };
      class BWA3_Bandage_Head: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Head</t>";
        priority = 5.799;
        condition = "alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitHead' > 0.01)";
        statement = "[this, 'HitHead'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_Body: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Torso</t>";
        priority = 5.798;
        condition = "alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitBody' > 0.01)";
        statement = "[this, 'HitBody'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_LeftShoulder: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Left Shoulder</t>";
        priority = 5.797;
        condition = "alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitLeftShoulder' > 0.01)";
        statement = "[this, 'HitLeftShoulder'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_LeftArm: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Left Arm</t>";
        priority = 5.796;
        condition = "alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitLeftArm' > 0.01)";
        statement = "[this, 'HitLeftArm'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_LeftForeArm: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Left Forearm</t>";
        priority = 5.795;
        condition = "alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitLeftForeArm' > 0.01)";
        statement = "[this, 'HitLeftForeArm'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_RightShoulder: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Right Shoulder</t>";
        priority = 5.794;
        condition = "alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitRightShoulder' > 0.01)";
        statement = "[this, 'HitRightShoulder'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_RightArm: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Right Arm</t>";
        priority = 5.793;
        condition = "alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitRightArm' > 0.01)";
        statement = "[this, 'HitRightArm'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_RightForeArm: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Right Forearm</t>";
        priority = 5.792;
        condition = "alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitRightForeArm' > 0.01)";
        statement = "[this, 'HitRightForeArm'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_LeftUpLeg: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Left Upper Leg</t>";
        priority = 5.791;
        condition = "alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitLeftUpLeg' > 0.01)";
        statement = "[this, 'HitLeftUpLeg'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_LeftLeg: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Left Leg</t>";
        priority = 5.790;
        condition = "alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitLeftLeg' > 0.01)";
        statement = "[this, 'HitLeftLeg'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_LeftFoot: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Left Foot</t>";
        priority = 5.789;
        condition = "alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitLeftFoot' > 0.01)";
        statement = "[this, 'HitLeftFoot'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_RightUpLeg: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Right Upper Leg</t>";
        priority = 5.788;
        condition = "alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitRightUpLeg' > 0.01)";
        statement = "[this, 'HitRightUpLeg'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_RightLeg: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Right Leg</t>";
        priority = 5.787;
        condition = "alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitRightLeg' > 0.01)";
        statement = "[this, 'HitRightLeg'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };
      class BWA3_Bandage_RightFoot: BWA3_Drag {
        displayName = "<t color='#cc0000'>... Right Foot</t>";
        priority = 5.786;
        condition = "alive this and this != player and GC_bandageMenu and (this getHitPointDamage 'HitRightFoot' > 0.01)";
        statement = "[this, 'HitRightFoot'] call BWA3_Medical_fnc_bandage; GC_bandageMenu = false;";
      };

      class BWA3_Bandage_Menu_Self: BWA3_Drag {
        displayName = "<t color='#ffbb00'>Bandage (self) ...</t>";
        priority = 0.2;
        hideOnUse = 0;
        condition = "alive this and this == player and (damage this > 0.001)";
        statement = "if (GC_bandageMenuSelf) then {GC_bandageMenuSelf = false;} else {GC_bandageMenuSelf = true;};";
      };
      class BWA3_Bandage_Head_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Head</t>";
        priority = 0.199;
        condition = "alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitHead' > 0.01)";
        statement = "[this, 'HitHead'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_Body_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Torso</t>";
        priority = 0.198;
        condition = "alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitBody' > 0.01)";
        statement = "[this, 'HitBody'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_LeftShoulder_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Left Shoulder</t>";
        priority = 0.197;
        condition = "alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitLeftShoulder' > 0.01)";
        statement = "[this, 'HitLeftShoulder'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_LeftArm_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Left Arm</t>";
        priority = 0.196;
        condition = "alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitLeftArm' > 0.01)";
        statement = "[this, 'HitLeftArm'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_LeftForeArm_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Left Forearm</t>";
        priority = 0.195;
        condition = "alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitLeftForeArm' > 0.01)";
        statement = "[this, 'HitLeftForeArm'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_RightShoulder_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Right Shoulder</t>";
        priority = 0.194;
        condition = "alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitRightShoulder' > 0.01)";
        statement = "[this, 'HitRightShoulder'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_RightArm_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Right Arm</t>";
        priority = 0.193;
        condition = "alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitRightArm' > 0.01)";
        statement = "[this, 'HitRightArm'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_RightForeArm_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Right Forearm</t>";
        priority = 0.192;
        condition = "alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitRightForeArm' > 0.01)";
        statement = "[this, 'HitRightForeArm'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_LeftUpLeg_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Left Upper Leg</t>";
        priority = 0.191;
        condition = "alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitLeftUpLeg' > 0.01)";
        statement = "[this, 'HitLeftUpLeg'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_LeftLeg_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Left Leg</t>";
        priority = 0.190;
        condition = "alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitLeftLeg' > 0.01)";
        statement = "[this, 'HitLeftLeg'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_LeftFoot_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Left Foot</t>";
        priority = 0.189;
        condition = "alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitLeftFoot' > 0.01)";
        statement = "[this, 'HitLeftFoot'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_RightUpLeg_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Right Upper Leg</t>";
        priority = 0.188;
        condition = "alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitRightUpLeg' > 0.01)";
        statement = "[this, 'HitRightUpLeg'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_RightLeg_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Right Leg</t>";
        priority = 0.187;
        condition = "alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitRightLeg' > 0.01)";
        statement = "[this, 'HitRightLeg'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
      };
      class BWA3_Bandage_RightFoot_Self: BWA3_Drag {
        displayName = "<t color='#ccbb00'>... Right Foot</t>";
        priority = 0.186;
        condition = "alive this and this == player and GC_bandageMenuSelf and (this getHitPointDamage 'HitRightFoot' > 0.01)";
        statement = "[this, 'HitRightFoot'] call BWA3_Medical_fnc_bandage; GC_bandageMenuSelf = false;";
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
  class FirstAidKit {
    type = 0;
  };
  class Medikit {
    type = 0;
  };
};
