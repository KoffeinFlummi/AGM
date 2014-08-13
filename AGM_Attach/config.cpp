class CfgPatches {
  class AGM_Attach {
    units[] = {};
    weapons[] = {"AGM_IR_Strobe_Item"};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.93";
    versionStr = "0.93";
    versionAr[] = {0,93,0};
    author[] = {"KoffeinFlummi", "eRazeri", "CAA-Picard"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Attach {
    class AGM_Attach {
      file = "AGM_Attach\functions";
      class attach;
      class canAttach;
      class canDetach;
      class detach;
	  class openAttachUI;
    };
  };
};

#define MACRO_ADDITEM(ITEM,COUNT) class _xx_##ITEM { \
  name = #ITEM; \
  count = COUNT; \
};

class CfgVehicles {
  class Man;
  class CAManBase: Man {
    class AGM_SelfActions {
      class AGM_Attach {
        displayName = "$STR_AGM_Attach_AttachDetach";
        condition = "[''] call AGM_Attach_fnc_canAttach";
        statement = "[player] call AGM_Attach_fnc_openAttachUI;";
        exceptions[] = {"AGM_Drag_isNotDragging"};
        showDisabled = 0;
        priority = 5;
		icon = "\A3\ui_f\data\igui\cfg\actions\gear_ca.paa";
	  };
      class AGM_Attach_Detach {
        displayName = "$STR_AGM_Attach_Detach";
        condition = "call AGM_Attach_fnc_canDetach";
        statement = "[player] call AGM_Attach_fnc_detach";
        exceptions[] = {"AGM_Drag_isNotDragging"};
        showDisabled = 0;
        priority = 5;
		icon = "\A3\ui_f\data\igui\cfg\actions\gear_ca.paa";
      };
    };
  };

  class All;
  class AGM_IR_Strobe_Effect: All {
    scope = 1;
    displayName = "IR Strobe";
    model = "\A3\Weapons_F\empty.p3d";
    simulation = "nvmarker";

    class NVGMarker {
      diffuse[] = {0.006, 0.006, 0.006, 1};
      ambient[] = {0.005, 0.005, 0.005, 1};
      brightness = 0.2;
      name = "pozicni blik";
      drawLight = 1;
      drawLightSize = 0.2;
      drawLightCenterSize = 0.2;
      activeLight = 0;
      blinking=1;//doesnt effect, maybe because of simulation
      blinkingStartsOn=1;//doesnt effect, maybe because of simulation
      blinkingPattern[] = {2,2};//doesnt effect, maybe because of simulation
      blinkingPatternGuarantee = false;//doesnt effect, maybe because of simulation
      dayLight = 0;
      onlyInNvg = 1;
      useFlare = 0;
    };
    side = -1;//-1=noside,3=civ,4=neutral
    accuracy = 0.01;
    cost = 1;
    armor = 500;
    threat[] = {0,0,0};
    type = 0;
    weapons[] = {};
    magazines[] = {};
    nvTarget = 1;
    destrType = "DestructEngine";
    brightness = 20;
    blinking=1;//doesnt effect, maybe because of simulation
    blinkingStartsOn=1;//doesnt effect, maybe because of simulation
    blinkingPattern[] = {2,2};//doesnt effect, maybe because of simulation
    blinkingPatternGuarantee = false;//doesnt effect, maybe because of simulation
  };

  class NATO_Box_Base;
  class EAST_Box_Base;
  class IND_Box_Base;
  class FIA_Box_Base_F;

  class Box_NATO_Support_F: NATO_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_IR_Strobe_Item,12)
    };
  };

  class Box_East_Support_F: EAST_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_IR_Strobe_Item,12)
    };
  };

  class Box_IND_Support_F: IND_Box_Base {
    class TransportItems {
      MACRO_ADDITEM(AGM_IR_Strobe_Item,12)
    };
  };

  class Box_FIA_Support_F: FIA_Box_Base_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_IR_Strobe_Item,12)
    };
  };

  class AGM_Box_Misc: Box_NATO_Support_F {
    class TransportItems {
      MACRO_ADDITEM(AGM_IR_Strobe_Item,24)
    };
  };
};

class CfgWeapons {
  class ItemCore;
  class InventoryItem_Base_F;

  class AGM_IR_Strobe_Item: ItemCore {
    displayName = "$STR_AGM_IrStrobe_Name";
    descriptionShort = "$STR_AGM_IrStrobe_Description";
    model = "\A3\weapons_F\ammo\mag_univ.p3d";
    picture = "\AGM_Attach\UI\irstrobe_item.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 1;
      type = 201;
    };
  };
};
