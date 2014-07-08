class CfgPatches {
  class AGM_IrStrobe {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"KoffeinFlummi", "eRazeri"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_IrStrobe {
    class AGM_IrStrobe {
      file = "AGM_IrStrobe\functions";
      class condition;
      class irstrobe;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_IrStrobe {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_IrStrobe\clientInit.sqf'";
  };
};

class AGM_Core_Default_Keys {
	class AGM_IrStrobe {
		displayName = "AGM IR Strobe";
		class IrStrobe {
			displayName = "$STR_AGM_IrStrobe_On";
			condition = "true";
			statement = "[] call AGM_IrStrobe_fnc_irstrobe";
			key = 23;//I
			shift = 0;
			control = 1;
			alt = 0;
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
    picture = "\AGM_IrStrobe\UI\irstrobe_item.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 1;
      type = 401;
    };
  };
};

class CfgVehicles {
class All;
class AGM_IR_Strobe_Effect: All
	{
		scope = 1;
    displayName = "IR Strobe";
		model = "\A3\Weapons_F\empty.p3d";
		simulation = "nvmarker";
		class NVGMarker
		{
			diffuse[] = {0,0,0};
			ambient[] = {0,0,0};
			brightness = 0.01;
			name = "pozicni blik";
			drawLight = 1;
			drawLightSize = 0.001;
			drawLightCenterSize = 0.001;
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
		brightness = 0.02;
    blinking=1;//doesnt effect, maybe because of simulation
    blinkingStartsOn=1;//doesnt effect, maybe because of simulation
    blinkingPattern[] = {2,2};//doesnt effect, maybe because of simulation
    blinkingPatternGuarantee = false;//doesnt effect, maybe because of simulation
	};
};