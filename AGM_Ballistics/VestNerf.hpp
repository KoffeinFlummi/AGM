
// base vests
class Vest_Camo_Base: ItemCore {
  class ItemInfo: VestItem {
    armor = 0;
    passThrough = 1;
  };
};
class Vest_NoCamo_Base: ItemCore {
  class ItemInfo: VestItem {
    armor = 0;
    passThrough = 1;
  };
};

// plate carriers
class V_PlateCarrier1_blk: Vest_Camo_Base {
  class ItemInfo: ItemInfo {
    armor = "20*0.4";
    passThrough = 0.75; //0.5;
  };
};
class V_PlateCarrier1_rgr: Vest_NoCamo_Base {
  class ItemInfo: ItemInfo {
    armor = "20*0.4";
    passThrough = 0.75; //0.5;
  };
};
class V_PlateCarrier2_rgr: V_PlateCarrier1_rgr {
  class ItemInfo: ItemInfo {
    armor = "30*0.4";
    passThrough = 0.75; //0.5;
  };
};
class V_PlateCarrierL_CTRG: V_PlateCarrier1_rgr {
  class ItemInfo: ItemInfo {
    armor = "20*0.4";
    passThrough = 0.75; //0.5;
  };
};
class V_PlateCarrier3_rgr: Vest_NoCamo_Base {
  class ItemInfo: ItemInfo {
    armor = "30*0.4";
    passThrough = 0.75; //0.5;
  };
};
class V_PlateCarrier_Kerry: V_PlateCarrier1_rgr {
  class ItemInfo: ItemInfo {
    armor = "30*0.4";
    passThrough = 0.75; //0.5;
  };
};
class V_PlateCarrierGL_rgr: Vest_NoCamo_Base {
  class ItemInfo: ItemInfo {
    armor = 24; //"100*0.4";
    passThrough = 0.75; //0.7;
  };
};
class V_PlateCarrierH_CTRG: V_PlateCarrier2_rgr {
  class ItemInfo: ItemInfo {
    armor = "30*0.4";
    passThrough = 0.75; //0.5;
  };
};
class V_PlateCarrierIA1_dgtl: Vest_NoCamo_Base {
  class ItemInfo: VestItem {
    armor = "20*0.4";
    passThrough = 0.75; //0.5;
  };
};
class V_PlateCarrierIA2_dgtl: V_PlateCarrierIA1_dgtl {
  class ItemInfo: VestItem {
    armor = "30*0.4";
    passThrough = 0.6; //0.5;
  };
};
class V_PlateCarrierIAGL_dgtl: V_PlateCarrierIA2_dgtl {
  class ItemInfo: VestItem {
    armor = 24; //"100*0.4";
    passThrough = 0.75; //0.7;
  };
};
class V_PlateCarrierSpec_rgr: Vest_NoCamo_Base {
  class ItemInfo: ItemInfo {
    armor = 16 //"40*0.4";
    passThrough = 0.45; //0.1;
  };
};

// rebreathers (WHY ARE THESE ARMOURED ANYWAYS?!)
class V_RebreatherB: Vest_Camo_Base {
  class ItemInfo: ItemInfo {
    armor = 0; //20;
    passThrough = 1;
  };
};
class V_RebreatherIR: V_RebreatherB {
};
class V_RebreatherIA: V_RebreatherB {
};

// tac vests
class V_TacVest_camo: Vest_Camo_Base {
  class ItemInfo: ItemInfo {
    armor = 4; //20;
    passThrough = 1;
  };
};
class V_TacVest_khk: Vest_Camo_Base {
  class ItemInfo: ItemInfo {
    armor = 4; //20;
    passThrough = 1;
  };
};
//class V_TacVest_brn: V_TacVest_khk {};
//class V_TacVest_oli: V_TacVest_khk {};
//class V_TacVest_blk: V_TacVest_khk {};
class V_TacVest_blk_POLICE: Vest_Camo_Base {
  class ItemInfo: ItemInfo {
    armor = 4; //100;
    passThrough = 0.7;
  };
};
class V_TacVestIR_blk: Vest_NoCamo_Base {
  class ItemInfo: VestItem {
    armor = 4; //20;
    passThrough = 0.5;
  };
};
class V_TacVestCamo_khk: Vest_Camo_Base {
  class ItemInfo: VestItem {
    armor = 4; //20;
    passThrough = 1;
  };
};

// bandolliers
class V_BandollierB_khk: Vest_Camo_Base {
  class ItemInfo: ItemInfo {
    armor = 0;
    passThrough = 1;
  };
};
class V_BandollierB_cbr: V_BandollierB_khk {
  class ItemInfo: ItemInfo {};
};
class V_BandollierB_rgr: V_BandollierB_khk {
  class ItemInfo: ItemInfo {};
};
class V_BandollierB_blk: V_BandollierB_khk {
  class ItemInfo: ItemInfo {};
};
class V_BandollierB_oli: V_BandollierB_khk {
  class ItemInfo: ItemInfo {};
};

// chestrigs
class V_Chestrig_khk: Vest_Camo_Base {
  class ItemInfo: ItemInfo {
    armor = 0;
    passThrough = 1;
  };
};
class V_Chestrig_rgr: V_Chestrig_khk {
};
class V_Chestrig_blk: V_Chestrig_khk {
};
class V_Chestrig_oli: Vest_Camo_Base {
  class ItemInfo: ItemInfo {
    armor = 0;
    passThrough = 1;
  };
};

// harnesses
class V_HarnessO_brn: Vest_NoCamo_Base {
  class ItemInfo: ItemInfo {
    armor = 0;
    passThrough = 0.85; //0.5;
  };
};
class V_HarnessOGL_brn: Vest_NoCamo_Base {
  class ItemInfo: ItemInfo {
    armor = 0;
    passThrough = 0.85; //0.5;
  };
};
class V_HarnessO_gry: V_HarnessO_brn {
  class ItemInfo: ItemInfo {
    armor = 0;
    passThrough = 0.85; //0.5;
  };
};
class V_HarnessOGL_gry: V_HarnessO_gry {
  class ItemInfo: ItemInfo {
    armor = 0;
    passThrough = 0.85; //0.5;
  };
};
class V_HarnessOSpec_brn: V_HarnessO_brn {
  class ItemInfo: VestItem {
    armor = 0;
    passThrough = 0.85; //0.5;
  };
};
class V_HarnessOSpec_gry: V_HarnessO_gry {
  class ItemInfo: ItemInfo {
    armor = 0;
    passThrough = 0.85; //0.5;
  };
};

// other
class V_Rangemaster_belt: Vest_NoCamo_Base {
  class ItemInfo: ItemInfo {
    armor = 0;
    passThrough = 1;
  };
};
class V_I_G_resistanceLeader_F: V_TacVest_camo {
  class ItemInfo: ItemInfo {};
};
class V_Press_F: Vest_Camo_Base {
  class ItemInfo: ItemInfo {
    armor = 0;
    passThrough = 1;
  };
};
