  class BulletCore;
  class BulletBase : BulletCore {
    AGM_BulletMass = 0;       // Bullet mass in grams
  };

  // Rifle and MG rounds
  class B_556x45_Ball : BulletBase {
    AGM_BulletMass = 4.1;     // 5.56x45 NATO
  };

  class B_65x39_Caseless : BulletBase {
    AGM_BulletMass = 8;       // 6.5mm Grendel
  };

  class B_762x51_Ball : BulletBase {
    AGM_BulletMass = 10;      // 7.62x51 NATO
  };
  class AGM_B_762x51_M118LR : B_762x51_Ball {
    AGM_BulletMass = 11;      // 7.62x51 NATO M118
  };

  class B_127x99_Ball : BulletBase {
    AGM_BulletMass = 42;      // 12.7×99mm NATO (.50 BMG)
  };

  class B_127x108_Ball : BulletBase {
    AGM_BulletMass = 48.3;    // 12.7x108
  };
  
  class B_408_Ball : BulletBase {
    AGM_BulletMass = 27;      // .408 Cheyenne Tactical
  };

  // Pistol Rounds
  class B_9x21_Ball : BulletBase {
    AGM_BulletMass = 7.45;    // 9×21mm IMI
  };
  class B_9x19_Ball : B_9x21_Ball {
    AGM_BulletMass = 7.45;    // 9×19mm Parabellum
  };
  class B_127x33_Ball : BulletBase {
    AGM_BulletMass = 21;      // .50 AE
  };
  class B_45ACP_Ball : BulletBase {
    AGM_BulletMass = 12;      // .45 ACP
  };
  
