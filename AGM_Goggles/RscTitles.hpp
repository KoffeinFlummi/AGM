class RscTitles{
	#include "define.hpp"
	
	class RscAGM_Goggles_BaseTitle{
		idd = -1;
		onLoad = "uiNamespace setVariable ['AGM_Goggles_Display', _this select 0]";
		onUnload = "uiNamespace setVariable ['AGM_Goggles_Display', displayNull]";
		fadeIn=0.5;
		fadeOut=0.5;
		movingEnable = false;
		duration = 10e10;
		name = "RscAGM_Goggles_BaseTitle"; 
		class controls;
	};
	
	class RscAGM_Goggles:RscAGM_Goggles_BaseTitle{
		idd = 1044;
		name = "RscAGM_Goggles"; 
		class controls{
			class gogglesImage: RscPicture{
				idc = 10650;
			};
		};
	};
	
	class RscAGM_GogglesEffects:RscAGM_Goggles_BaseTitle{
		idd = 1045;
		onLoad = "uiNamespace setVariable ['AGM_Goggles_DisplayEffects', _this select 0]";
		onUnload = "uiNamespace setVariable ['AGM_Goggles_DisplayEffects', displayNull]";
		name = "RscAGM_GogglesEffects"; 
		fadeIn=0;
		fadeOut=0.5;
		class controls{
			class dirtImage: RscPicture	{
				idc = 10660;
			};
			class dustImage: RscPicture {
				idc = 10662;
			};
		};
	};
	class RscAGM_RainEffects:RscAGM_Goggles_BaseTitle{
		idd = 1046;
		onLoad = "uiNamespace setVariable ['AGM_Goggles_Rain', _this select 0]";
		onUnload = "uiNamespace setVariable ['AGM_Goggles_Rain', displayNull]";
		name = "RscAGM_RainEffects"; 
		fadeIn=0;
		fadeOut=0.5;
		class controls{
			class rainImage1: RscPicture{
				idc = 10670;
				text = "AGM_Goggles\textures\fx\rain\1.paa";
			};
			class rainImage2: RscPicture{
				idc = 10671;
				text = "AGM_Goggles\textures\fx\rain\2.paa";
			};
			class rainImage3: RscPicture{
				idc = 10672;
				text = "AGM_Goggles\textures\fx\rain\3.paa";
			};
			class rainImage4: RscPicture{
				idc = 10673;
				text = "AGM_Goggles\textures\fx\rain\4.paa";
			};
			
			class rainImage1Dup: RscPicture{
				idc = 10680;
				text = "AGM_Goggles\textures\fx\rain\1.paa";
				y = "(safezoneY - safezoneH)";
			};
			class rainImage2Dup: rainImage1Dup{
				idc = 10681;
				text = "AGM_Goggles\textures\fx\rain\2.paa";
			};
			class rainImage3Dup: rainImage1Dup{
				idc = 10682;
				text = "AGM_Goggles\textures\fx\rain\3.paa";
			};
			class rainImage4Dup: rainImage1Dup{
				idc = 10683;
				text = "AGM_Goggles\textures\fx\rain\4.paa";
			};
		};
	};
};
