class CfgPatches {
  class AGM_GrenadeSelect {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"CAA-Picard"};
    authorUrl = "https://github.com/esteldunedain/";
  };
};

class CfgFunctions {
  class AGM_GrenadeSelect {
    class AGM_GrenadeSelect {
      file = "\AGM_GrenadeSelect\functions";
      class selectGrenadeFrag;
      class selectGrenadeOther;

      class countMagazinesForGrenadeMuzzle;
      class displayGrenadeTypeAndNumber;
      class throwGrenade;
    };
  };
};

class AGM_Core_Default_Keys {
	class AGM_GrenadeSelect {
		displayName = "AGM Grenade Select";
		class selectGrenadeFrag {
			displayName = "$STR_AGM_GrenadeSelect_SelectGrenadeFrag";
			condition = "player == _vehicle && {player getVariable ['AGM_CanTreat', true]} && {!(player getVariable ['AGM_Unconscious', false])}";
			statement = "call AGM_GrenadeSelect_fnc_selectGrenadeFrag";
			key = 7;
			shift = 0;
			control = 0;
			alt = 0;
		};
		class selectGrenadeOther {
			displayName = "$STR_AGM_GrenadeSelect_SelectGrenadeOther";
			condition = "player == _vehicle && {player getVariable ['AGM_CanTreat', true]} && {!(player getVariable ['AGM_Unconscious', false])}";
			statement = "call AGM_GrenadeSelect_fnc_selectGrenadeOther";
			key = 8;
			shift = 0;
			control = 0;
			alt = 0;
		};
		class throwGrenade {
			displayName = "$STR_AGM_GrenadeSelect_ThrowGrenade";
			condition = "player == _vehicle && {player getVariable ['AGM_CanTreat', true]} && {!(player getVariable ['AGM_Unconscious', false])}";
			statement = "call AGM_GrenadeSelect_fnc_throwGrenade";
			key = 34;
			shift = 0;
			control = 0;
			alt = 0;
		};
	};
};

class Extended_PostInit_EventHandlers {
  class AGM_GrenadeSelect {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_GrenadeSelect\clientInit.sqf'";
  };
};

class RscControlsGroup;
class RscText;
class RscInGameUI {
  class RscUnitInfo {
    // Soldier only
    class WeaponInfoControlsGroupLeft: RscControlsGroup {
      class controls {
        class CA_GrenadeType: RscText {
          sizeEx = 0;
        };
        class CA_GrenadeCount: RscText {
          sizeEx = 0;
        };
      };
    };
    // Vehicles only
    /*class WeaponInfoControlsGroupRight: RscControlsGroup {
      class controls {
        class CA_AmmoCount: RscText {
          sizeEx = 0;
        };
      };
    };*/
  };
};
/*        class CA_GrenadeType: RscText
				{
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					style = 2;
					idc = 152;
					x = "3.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "4.5 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
				class CA_GrenadeCount: RscText
				{
					colorText[] = {"(profilenamespace getvariable ['IGUI_TEXT_RGB_R',0])","(profilenamespace getvariable ['IGUI_TEXT_RGB_G',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_B',1])","(profilenamespace getvariable ['IGUI_TEXT_RGB_A',0.8])"};
					style = 1;
					idc = 151;
					x = "8 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					y = "2.5 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					w = "2 * 					(			((safezoneW / safezoneH) min 1.2) / 40)";
					h = "1 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
					sizeEx = "0.8 * 					(			(			((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
				};
*/
