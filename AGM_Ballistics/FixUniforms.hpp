
// INTEGER
#define ARMOR_BASE            2
#define ARMORSTRUCTURAL_BASE  5

// INTEGER
#define ARMOR_HEAD            2
#define ARMOR_BODY            5
#define ARMOR_HANDS           3
#define ARMOR_LEGS            3

// FLOAT, 0-1
#define PASSTHROUGH_HEAD      1
#define PASSTHROUGH_BODY      1
#define PASSTHROUGH_HANDS     1
#define PASSTHROUGH_LEGS      1

class Man;
class CAManBase: Man {
  class HitPoints {
    class HitHead {
      armor = ARMOR_HEAD; //1;
      passThrough = PASSTHROUGH_HEAD; //1;
      /*radius = 0.1;
      explosionShielding = 0.5;
      minimalHit = 0;*/
    };

    class HitBody {
      armor = ARMOR_BODY; //1;
      passThrough = PASSTHROUGH_BODY; //1;
      /*radius = 0.15;
      explosionShielding = 10;
      minimalHit = 0;*/
    };

    class HitHands {
      armor = ARMOR_HANDS; //1;
      passThrough = PASSTHROUGH_HANDS; //1;
      /*radius = 0.08;
      explosionShielding = 1;
      minimalHit = 0;*/
    };

    class HitLegs {
      armor = ARMOR_LEGS; //1;
      passThrough = PASSTHROUGH_LEGS; //1;
      /*radius = 0.1;
      explosionShielding = 1;
      minimalHit = 0;*/
    };
  };

  armor = ARMOR_BASE; //2;
  armorStructural = ARMORSTRUCTURAL_BASE; //5;
};

class Civilian: CAManBase {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //1;
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //2;
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //2;
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //2;
    };
  };
};

class Civilian_F: Civilian {};
class C_man_1: Civilian_F {};

class SoldierWB: CAManBase {};
class SoldierEB: CAManBase {};
class SoldierGB: CAManBase {};

class B_Soldier_base_F: SoldierWB {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //1;
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //2;
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //2;
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //2;
    };
  };

  armor = ARMOR_BASE; //2;
  armorStructural = ARMORSTRUCTURAL_BASE; //5;
};

class B_Soldier_02_f: B_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //1;
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //1;
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //1;
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //2;
    };
  };

  armorStructural = ARMORSTRUCTURAL_BASE; //7;
};

class B_Soldier_03_f: B_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //1;
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //2;
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //1;
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //2;
    };
  };

  armorStructural = ARMORSTRUCTURAL_BASE; //7;
};

class B_Soldier_04_f: B_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //1;
      passThrough = PASSTHROUGH_HEAD; //1;
      /*explosionShielding = 0.5;*/
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //2;
      passThrough = PASSTHROUGH_BODY; //0.5;
      /*explosionShielding = 2.4;*/
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //8;
      passThrough = PASSTHROUGH_HANDS; //0.5;
      /*explosionShielding = 1.2;*/
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //8;
      passThrough = PASSTHROUGH_LEGS; //0.5;
      /*explosionShielding = 1.2;*/
    };
  };
};

class B_Soldier_05_f: B_Soldier_base_F {
  armorStructural = ARMORSTRUCTURAL_BASE; //3;

  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //1;
      passThrough = PASSTHROUGH_HEAD; //1;
      /*explosionShielding = 0.5;*/
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //2;
      passThrough = PASSTHROUGH_BODY; //0.5;
      /*explosionShielding = 2.4;*/
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //8;
      passThrough = PASSTHROUGH_HANDS; //1;
      /*explosionShielding = 1.2;*/
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //8;
      passThrough = PASSTHROUGH_LEGS; //1;
      /*explosionShielding = 1.2;*/
    };
  };
};

class B_Soldier_diver_base_F: B_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //2;
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //2;
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //2;
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //2;
    };
  };
};

// these appear to be broken, remnants from A2?
/*class C_man_p_fugitive_F: C_man_1 {
  class HitPoints: HitPoints {
    class HitBody: HitBody {
      armor = "0.3*10";
    };

    class HitLegs: HitLegs {
      armor = "0.3*5";
    };
  };
};

class C_man_w_worker_F: C_man_1 {
  class HitPoints: HitPoints {
    class HitBody: HitBody {
      armor = "0.6*10";
    };

    class HitHands: HitHands {
      armor = "0.5*5";
    };

    class HitLegs: HitLegs {
      armor = "0.5*5";
    };
  };
};

class C_man_hunter_1_F: C_man_1 {
  class HitPoints: HitPoints {
    class HitBody: HitBody {
      armor = "0.6*10";
    };

    class HitHands: HitHands {
      armor = "0.5*5";
    };

    class HitLegs: HitLegs {
      armor = "0.5*5";
    };
  };
};

class C_man_p_shorts_1_F: C_man_1 {
  class HitPoints: HitPoints {
    class HitLegs: HitLegs {
      armor = "0.3*5";
    };
  };
};

class C_man_pilot_F: C_man_1 {
  class HitPoints: HitPoints {
    class HitBody: HitBody {
      armor = "0.6*10";
    };

    class HitHands: HitHands {
      armor = "0.5*5";
    };

    class HitLegs: HitLegs {
      armor = "0.5*5";
    };
  };
};*/

class I_Soldier_base_F: SoldierGB {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //1;
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //2;
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //2;
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //2;
    };
  };

  armor = ARMOR_BASE; //2;
  armorStructural = ARMORSTRUCTURAL_BASE; //7;
};

class I_Soldier_02_F: I_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //1;
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //2;
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //1;
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //2;
    };
  };
};

class I_Soldier_03_F: I_Soldier_base_F {
  armorStructural = ARMORSTRUCTURAL_BASE; //5;

  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //1;
      passThrough = PASSTHROUGH_HEAD; //1;
      /*explosionShielding = 0.5;*/
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //2;
      passThrough = PASSTHROUGH_BODY; //0.5;
      /*explosionShielding = 2.4;*/
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //8;
      passThrough = PASSTHROUGH_HANDS; //0.5;
      /*explosionShielding = 1.2;*/
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //8;
      passThrough = PASSTHROUGH_LEGS; //0.5;
      /*explosionShielding = 1.2;*/
    };
  };
};

class I_Soldier_04_F: I_Soldier_base_F {
  armorStructural = ARMORSTRUCTURAL_BASE; //3;

  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //1;
      passThrough = PASSTHROUGH_HEAD; //1;
      /*explosionShielding = 0.5;*/
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //2;
      passThrough = PASSTHROUGH_BODY; //0.5;
      /*explosionShielding = 2.4;*/
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //8;
      passThrough = PASSTHROUGH_HANDS; //1;
      /*explosionShielding = 1.2;*/
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //8;
      passThrough = PASSTHROUGH_LEGS; //1;
      /*explosionShielding = 1.2;*/
    };
  };
};

class I_Soldier_diver_base_F: I_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //2;
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //2;
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //2;
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //2;
    };
  };
};

class O_Soldier_base_F: SoldierEB {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //1;
      passThrough = PASSTHROUGH_HEAD; //1;
      /*explosionShielding = 0.5;*/
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //6;
      passThrough = PASSTHROUGH_BODY; //0.5;
      /*explosionShielding = 1.5;*/
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //8;
      passThrough = PASSTHROUGH_HANDS; //0.5;
      /*explosionShielding = 0.8;*/
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //8;
      passThrough = PASSTHROUGH_LEGS; //0.5;
      /*explosionShielding = 0.8;*/
    };
  };

  armor = ARMOR_BASE; //2;
  armorStructural = ARMORSTRUCTURAL_BASE; //5;
};

class O_officer_F: O_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //1;
      passThrough = PASSTHROUGH_HEAD; //1;
      /*explosionShielding = 0.5;*/
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //2;
      passThrough = PASSTHROUGH_BODY; //1;
      /*explosionShielding = 10;*/
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //2;
      passThrough = PASSTHROUGH_HANDS; //1;
      /*explosionShielding = 1;*/
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //8;
      passThrough = PASSTHROUGH_LEGS; //0.5;
      /*explosionShielding = 1;*/
    };
  };
};

class O_Soldier_02_F: O_Soldier_base_F {
  armorStructural = ARMORSTRUCTURAL_BASE; //3;

  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //1;
      passThrough = PASSTHROUGH_HEAD; //1;
      /*explosionShielding = 0.5;*/
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //6;
      passThrough = PASSTHROUGH_BODY; //0.5;
      /*explosionShielding = 1.5;*/
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //8;
      passThrough = PASSTHROUGH_HANDS; //1;
      /*explosionShielding = 0.8;*/
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //8;
      passThrough = PASSTHROUGH_LEGS; //1;
      /*explosionShielding = 0.8;*/
    };
  };
};

class O_Soldier_diver_base_F: O_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //2;
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //2;
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //2;
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //2;
    };
  };
};

class O_Soldier_VR_F: O_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //1;
      passThrough = PASSTHROUGH_HEAD; //1;
      /*explosionShielding = 0.5;*/
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //2;
      passThrough = PASSTHROUGH_BODY; //1;
      /*explosionShielding = 10;*/
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //2;
      passThrough = PASSTHROUGH_HANDS; //1;
      /*explosionShielding = 1;*/
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //2;
      passThrough = PASSTHROUGH_LEGS; //1;
      /*explosionShielding = 1;*/
    };
  };
};

class O_Protagonist_VR_F: O_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      armor = ARMOR_HEAD; //1;
      passThrough = PASSTHROUGH_HEAD; //1;
      /*explosionShielding = 0.5;*/
    };

    class HitBody: HitBody {
      armor = ARMOR_BODY; //2;
      passThrough = PASSTHROUGH_BODY; //1;
      /*explosionShielding = 10;*/
    };

    class HitHands: HitHands {
      armor = ARMOR_HANDS; //2;
      passThrough = PASSTHROUGH_HANDS; //1;
      /*explosionShielding = 1;*/
    };

    class HitLegs: HitLegs {
      armor = ARMOR_LEGS; //2;
      passThrough = PASSTHROUGH_LEGS; //1;
      /*explosionShielding = 1;*/
    };
  };
};
