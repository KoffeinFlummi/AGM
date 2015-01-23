// by commy2

class RscStructuredText;

class RscTitles {
	class AGM_Medical_RscHint {
		idd = -1;
		onLoad = "uiNamespace setVariable ['AGM_ctrlHint', (_this select 0) displayCtrl 1];";
		movingEnable = false;
		duration = 10;
		fadeIn = 0.2;
		fadeOut = 0.2;
		name = "AGM_Medical_RscHint";

		class controls {
			class HintBox: RscStructuredText {
				idc = 1;
				text = "";
				type = 13;
				size = "1 / 40 / (getResolution select 5)";
				sizeEx = 1;
				style = 0;
				colorText[] = {1, 1, 1, 1};
				colorBackground[] = {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"};
				x = safeZoneW + safeZoneX - 0.2 * safezoneW;
				y = safeZoneY + 0.2 * safezoneH;
				w = 0.2 * safeZoneW;
				h = 0.35 * SafeZoneH;
			};
		};
	};
};
