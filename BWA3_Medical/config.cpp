// PATCH CONFIG
class CfgPatches {
  class BWA3_Medical {
    units[] = {};
    weapons[] = {};

    requiredVersion = 0.1;
    requiredAddons[] = {"Extended_EventHandlers"};
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
      class epinephrine {};
      class handleDamage {};
      class init {};
      class knockOut {};
      class morphine {};
      class undrag {};
      class wakeUp {};
    };
  };
};

class Extended_Init_EventHandlers {
  class CAManBase {
    class BWA3_Medical_Init {
      clientInit = "0 spawn BWA3_Medical_fnc_init";
    };
  };
};

// ACTIONS OVER CONFIG ?

class CfgVehicles {

  class Land_CargoBox_V1_F;

  class SoldierWB {
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
  };
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

  class BWA3_Medical_CollisionHelper: Land_CargoBox_V1_F {
    model = "\BWA3_Medical\BWA3_Medical_Helper.p3d";
  };

};
