class CfgPatches {
  class AGM_Attach {
    units[] = {};
    weapons[] = {"AGM_IR_Strobe_Item"};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
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
        statement = "'AGM_Attach' call AGM_Interaction_fnc_openMenuSelf";
        exceptions[] = {"AGM_Drag_isNotDragging"};
        showDisabled = 0;
        priority = 5;

        class AGM_Attach_IrStrobe {
          displayName = "$STR_AGM_Attach_Attach_IrStrobe";
          condition = "['AGM_IR_Strobe_Item'] call AGM_Attach_fnc_canAttach";
          statement = "[player, 'AGM_IR_Strobe_Item'] call AGM_Attach_fnc_attach";
          exceptions[] = {"AGM_Drag_isNotDragging"};
          showDisabled = 0;
          priority = 3;
        };
        class AGM_Attach_IrStrobeB {
          displayName = "$STR_AGM_Attach_Attach_IrGrenade";
          condition = "['B_IR_Grenade'] call AGM_Attach_fnc_canAttach";
          statement = "[player, 'B_IR_Grenade'] call AGM_Attach_fnc_attach";
          exceptions[] = {"AGM_Drag_isNotDragging"};
          showDisabled = 0;
          priority = 2;
        };
        class AGM_Attach_IrStrobeO {
          displayName = "$STR_AGM_Attach_Attach_IrGrenade";
          condition = "['O_IR_Grenade'] call AGM_Attach_fnc_canAttach && {!('B_IR_Grenade' in magazines player)}";
          statement = "[player, 'O_IR_Grenade'] call AGM_Attach_fnc_attach";
          exceptions[] = {"AGM_Drag_isNotDragging"};
          showDisabled = 0;
          priority = 2;
        };
        class AGM_Attach_IrStrobeI {
          displayName = "$STR_AGM_Attach_Attach_IrGrenade";
          condition = "['I_IR_Grenade'] call AGM_Attach_fnc_canAttach && {!('B_IR_Grenade' in magazines player)} && {!('O_IR_Grenade' in magazines player)}";
          statement = "[player, 'I_IR_Grenade'] call AGM_Attach_fnc_attach";
          exceptions[] = {"AGM_Drag_isNotDragging"};
          showDisabled = 0;
          priority = 2;
        };
        class AGM_Attach_Chemlight_blue {
          displayName = "$STR_AGM_Attach_Attach_Chemlight_blue";
          condition = "['Chemlight_blue'] call AGM_Attach_fnc_canAttach";
          statement = "[player, 'Chemlight_blue'] call AGM_Attach_fnc_attach";
          exceptions[] = {"AGM_Drag_isNotDragging"};
          showDisabled = 0;
          priority = 1;
        };
        class AGM_Attach_Chemlight_green {
          displayName = "$STR_AGM_Attach_Attach_Chemlight_green";
          condition = "['Chemlight_green'] call AGM_Attach_fnc_canAttach";
          statement = "[player, 'Chemlight_green'] call AGM_Attach_fnc_attach";
          exceptions[] = {"AGM_Drag_isNotDragging"};
          showDisabled = 0;
          priority = 1;
        };
        class AGM_Attach_Chemlight_red {
          displayName = "$STR_AGM_Attach_Attach_Chemlight_red";
          condition = "['Chemlight_red'] call AGM_Attach_fnc_canAttach";
          statement = "[player, 'Chemlight_red'] call AGM_Attach_fnc_attach";
          exceptions[] = {"AGM_Drag_isNotDragging"};
          showDisabled = 0;
          priority = 1;
        };
        class AGM_Attach_Chemlight_yellow {
          displayName = "$STR_AGM_Attach_Attach_Chemlight_yellow";
          condition = "['Chemlight_yellow'] call AGM_Attach_fnc_canAttach";
          statement = "[player, 'Chemlight_yellow'] call AGM_Attach_fnc_attach";
          exceptions[] = {"AGM_Drag_isNotDragging"};
          showDisabled = 0;
          priority = 1;
        };
        class AGM_OpenUIDummy {
          displayName = "";
          condition = "false";
          statement = "";
          showDisabled = 1;
          priority = -9;
        };
      };

      class AGM_Attach_Detach {
        displayName = "$STR_AGM_Attach_Detach";
        condition = "call AGM_Attach_fnc_canDetach";
        statement = "[player] call AGM_Attach_fnc_detach";
        exceptions[] = {"AGM_Drag_isNotDragging"};
        showDisabled = 0;
        priority = 5;
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
      type = 401;
    };
  };
};
