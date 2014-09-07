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
				text = "AGM_Goggles\textures\fx\rain\d1.paa";
				w = 0.04;
				h = 0.04;
			};
			class rainImage2: rainImage1{
				idc = 10671;
				text = "AGM_Goggles\textures\fx\rain\d2.paa";
			};
			class rainImage3: rainImage1{
				idc = 10672;
				text = "AGM_Goggles\textures\fx\rain\d3.paa";
			};
			class rainImage4: rainImage1{
				idc = 10673;
				text = "AGM_Goggles\textures\fx\rain\d4.paa";
			};
			class rainImage5: rainImage1{
				idc = 10674;
				text = "AGM_Goggles\textures\fx\rain\d5.paa";
			};
			class rainImage6: rainImage1{
				idc = 10675;
				text = "AGM_Goggles\textures\fx\rain\d2.paa";
			};
			class rainImage7: rainImage1{
				idc = 10676;
				text = "AGM_Goggles\textures\fx\rain\d3.paa";
			};
			/*
			class rainImage8: rainImage1{
				idc = 10677;
				text = "AGM_Goggles\textures\fx\rain\d5.paa";
			};
			class rainImage9: rainImage1{
				idc = 10678;
				text = "AGM_Goggles\textures\fx\rain\d1.paa";
			};
			class rainImage10: rainImage1{
				idc = 10679;
				text = "AGM_Goggles\textures\fx\rain\d4.paa";
			};
			class rainImage11: rainImage1{
				idc = 10680;
				text = "AGM_Goggles\textures\fx\rain\d5.paa";
			};
			class rainImage12: rainImage1{
				idc = 10681;
				text = "AGM_Goggles\textures\fx\rain\d1.paa";
			};
			class rainImage13: rainImage1{
				idc = 10682;
				text = "AGM_Goggles\textures\fx\rain\d4.paa";
			};
			class rainImage14: rainImage1{
				idc = 10683;
				text = "AGM_Goggles\textures\fx\rain\d3.paa";
			};
			class rainImage15: rainImage1{
				idc = 10684;
				text = "AGM_Goggles\textures\fx\rain\d2.paa";
			};
			*/
		};
	};
};
