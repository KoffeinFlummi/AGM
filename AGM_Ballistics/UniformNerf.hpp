
// base classes
class Man;
class CAManBase: Man {
  class HitPoints {
    class HitHead {
      passThrough = 1;
    };
    class HitBody {
      passThrough = 1;
    };
    class HitHands {
      passThrough = 1;
    };
    class HitLegs {
      passThrough = 1;
    };
  };
};

// NATO
class SoldierWB: CAManBase {};
class B_Soldier_base_F: SoldierWB {};
class B_Soldier_04_f: B_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      passThrough = 1;
    };
    class HitBody: HitBody {
      passThrough = 1; //0.5;
    };
    class HitHands: HitHands {
      passThrough = 1; //0.5;
    };
    class HitLegs: HitLegs {
      passThrough = 1; //0.5;
    };
  };
};
class B_Soldier_05_f: B_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      passThrough = 1;
    };
    class HitBody: HitBody {
      passThrough = 1; //0.5;
    };
    class HitHands: HitHands {
      passThrough = 1;
    };
    class HitLegs: HitLegs {
      passThrough = 1;
    };
  };
};

// AAF
class SoldierGB: CAManBase {};
class I_Soldier_base_F: SoldierGB {};
class I_Soldier_03_F: I_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      passThrough = 1;
    };
    class HitBody: HitBody {
      passThrough = 1; //0.5;
    };
    class HitHands: HitHands {
      passThrough = 1; //0.5;
    };
    class HitLegs: HitLegs {
      passThrough = 1; //0.5;
    };
  };
};
class I_Soldier_04_F: I_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      passThrough = 1;
    };
    class HitBody: HitBody {
      passThrough = 1; //0.5;
    };
    class HitHands: HitHands {
      passThrough = 1;
    };
    class HitLegs: HitLegs {
      passThrough = 1;
    };
  };
};

// CSAT
class SoldierEB: CAManBase {};
class O_Soldier_base_F: SoldierEB {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      passThrough = 1;
    };
    class HitBody: HitBody {
      passThrough = 1; //0.5;
    };
    class HitHands: HitHands {
      passThrough = 1; //0.5;
    };
    class HitLegs: HitLegs {
      passThrough = 1; //0.5;
    };
  };
};
class O_officer_F: O_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      passThrough = 1;
    };
    class HitBody: HitBody {
      passThrough = 1;
    };
    class HitHands: HitHands {
      passThrough = 1;
    };
    class HitLegs: HitLegs {
      passThrough = 1; //0.5;
    };
  };
};
class O_Soldier_02_F: O_Soldier_base_F {
  armorStructural = 3;
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      passThrough = 1;
    };
    class HitBody: HitBody {
      passThrough = 1; //0.5;
    };
    class HitHands: HitHands {
      passThrough = 1;
    };
    class HitLegs: HitLegs {
      passThrough = 1;
    };
  };
};

// VR
class O_Soldier_VR_F: O_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      passThrough = 1;
    };
    class HitBody: HitBody {
      passThrough = 1;
    };
    class HitHands: HitHands {
      passThrough = 1;
    };
    class HitLegs: HitLegs {
      passThrough = 1;
    };
  };
};
class O_Protagonist_VR_F: O_Soldier_base_F {
  class HitPoints: HitPoints {
    class HitHead: HitHead {
      passThrough = 1;
    };
    class HitBody: HitBody {
      passThrough = 1;
    };
    class HitHands: HitHands {
      passThrough = 1;
    };
    class HitLegs: HitLegs {
      passThrough = 1;
    };
  };
};
