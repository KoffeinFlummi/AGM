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

class CfgMods {
  class BWA3_Medical {
    dir = "BWA3_Medical";
    name = "BWA3: Medical Module";
    picture = "";
    hidePicture = "true";
    hideName = "true";
    actionName = "Github";
    action = "https://github.com/KoffeinFlummi/BWA3_Realism";
  };
};

class CfgFunctions {
  class BWA3_Medical {
    class BWA3_Medical {
      file = "BWA3_Medical\functions";
      class bandage {};
      class cpr {};
      class diagnose {};
      class drag {};
      class carry {};
      class epinephrine {};
      class handleDamage {};
      class init {};
      class knockOut {};
      class morphine {};
      class release {};
      class wakeUp {};
    };
  };
};

class Extended_Init_EventHandlers {
  class CAManBase {
    class BWA3_Medical_Init {
      init = "_this spawn BWA3_Medical_fnc_init";
    };
  };
};


class CfgVehicles {

  class Land_CargoBox_V1_F;

  // Why the fuck does CAManBase not work?!
  class SoldierWB {
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

    class UserActions {
      // Documentation:
      // http://community.bistudio.com/wiki/UserActions
      //
      // Ideas for later:
      // - Color Coding
      // - Icons

      class BWA3_Drag {
        displayName = "Drag";         // name in action menu
        displayNameDefault = "";      // name on screen (icons)
        priority = 6;                 // 0 (low) - 6 (high)
        position = "leaning_axis";    // memory point of model
        radius = 3;                   // minimum distance for the action to be available
        showWindow = false;           // show text/icon on screen
        onlyForPlayer = false;        // enable AI to be ordered to do something
        shortcut = "";                // key (CfgDefaultKeyMappings)
        condition = "this != player and this getVariable 'BWA3_Unconscious' and !(player getVariable 'BWA3_Dragging') and !(player getVariable 'BWA3_Carrying')";
        statement = "[this] spawn BWA3_Medical_fnc_drag";
      };
      class BWA3_Carry: BWA3_Drag {
        displayName = "Carry";
        priority = 5.99;
        statement = "[this] spawn BWA3_Medical_fnc_carry";
      };
      class BWA3_Release: BWA3_Drag {
        displayName = "Release";
        priority = 6;
        condition = "this != player and ((player getVariable 'BWA3_Dragging') isKindOf 'Man' or (player getVariable 'BWA3_Carrying') isKindOf 'Man')"
      };
      class BWA3_Diagnose: BWA3_Drag {
        displayName = "Diagnose";
        priority = 5.98;
        condition = "this != player";
        statement = "[this] spawn BWA3_Medical_fnc_diagnose";
      };
      class BWA3_Diagnose_Self: BWA3_Diagnose {
        displayName = "Diagnose (Self)";
        priority = 0.485;
        condition = "this == player";
      };

      class BWA3_CPR: BWA3_Drag {
        displayName = "Perform CPR";
        priority = 5.9;
        condition = "this != player and this getVariable 'BWA3_Dead' > 0";
        statement = "[this] spawn BWA3_Medical_fnc_CPR";
      };
      class BWA3_Epinephrine: BWA3_Drag {
        displayName = "Inject Epinephrine";
        priority = 5.89;
        condition = "this != player";
        statement = "[this] spawn BWA3_Medical_fnc_epinephrine";
      };
      class BWA3_Epinephrine_Self: BWA3_Epinephrine {
        displayName = "Inject Epinephrine (Self)";
        priority = 0.395;
        condition = "this == player";
      };
      class BWA3_Morphine: BWA3_Drag {
        displayName = "Inject Morphine";
        priority = 5.88;
        condition = "this != player";
        statement = "[this] spawn BWA3_Medical_fnc_morphine";
      };
      class BWA3_Morphine_Self: BWA3_Morphine {
        displayName = "Inject Morphine (Self)";
        priority = 0.385;
        condition = "this == player";
      };

    };
  };

  /*
  class SoldierEB {
    armor = 1.5;
    armorStructural = 4.5;

    class HitPoints {
      // "DEACTIVE" DEFAULT HITPOINTS
      
      class HitHands {
        armor = 0; //armor = 2;
        explosionShielding = 0; //explosionShielding = 1;
        material = -1;
        minimalHit = 0;
        name = "";
        passThrough = 1; //passThrough = 1;
        radius = 0; //radius = 0.06;
        visual = "injury_hands";
      };
      class HitLegs {
        armor = 0; //armor = 2;
        explosionShielding = 0; //explosionShielding = 1;
        material = -1;
        minimalHit = 0;
        name = "";
        passThrough = 1; //passThrough = 1;
        radius = 0; //radius = 0.08;
        visual = "injury_legs";4

      };

      // HEAD
      class HitHead {
        armor = 1;
        explosionShielding = 1;
        material = -1;
        minimalHit = 0;
        name = "head";
        passThrough = 1;
        radius = 0.1;
      };
      // TORSO
      class HitBody {
        armor = 2;
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
  };
  class SoldierGB {
    armor = 1.5;
    armorStructural = 4.5;

    class HitPoints {
      // "DEACTIVE" DEFAULT HITPOINTS
      
      class HitHands {
        armor = 0; //armor = 2;
        explosionShielding = 0; //explosionShielding = 1;
        material = -1;
        minimalHit = 0;
        name = "";
        passThrough = 1; //passThrough = 1;
        radius = 0; //radius = 0.06;
        visual = "injury_hands";
      };
      class HitLegs {
        armor = 0; //armor = 2;
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
        armor = 1;
        explosionShielding = 1;
        material = -1;
        minimalHit = 0;
        name = "head";
        passThrough = 1;
        radius = 0.1;
      };
      // TORSO
      class HitBody {
        armor = 2;
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
  };
  */

  class BWA3_Medical_CollisionHelper: Land_CargoBox_V1_F {
    model = "\BWA3_Medical\BWA3_Medical_Helper.p3d";
  };

};
