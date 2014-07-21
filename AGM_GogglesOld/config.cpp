class CfgPatches {
	class AGM_GogglesOld {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.6;
		requiredAddons[] = {AGM_Core};
		version = "0.92";
		versionStr = "0.92";
		versionAr[] = {};
		author[] = {"commy2","KoffeinFlummi"};
		authorUrl = "https://github.com/commy2/";
	};
};

class CfgFunctions {
	class AGM_GogglesOld {
		class AGM_GogglesOld {
			file = "\AGM_GogglesOld\functions";
			class gogglesEffect;
		};
	};
};

class Extended_PostInit_EventHandlers {
	class AGM_GogglesOld {
		clientInit = "call compile preprocessFileLineNumbers '\AGM_GogglesOld\clientInit.sqf'";
	};
};

class CfgGlasses {
	class None;
	class G_Aviator: None {
		AGM_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Combat: None {
		AGM_gogglesEffect = "[1, 1, -0.1, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Lowprofile: None {
		AGM_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Shades_Black: None {
		AGM_gogglesEffect = "[1, 1, -0.12, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Shades_Blue: None {
		AGM_gogglesEffect = "[1, 1, -0.03, [0,0,1,0.1], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Shades_Green: None {
		AGM_gogglesEffect = "[1, 1, -0.03, [0,1,0,0.07], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Shades_Red: None {
		AGM_gogglesEffect = "[1, 1, -0.03, [1,0,0,0.07], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Spectacles: None {
		AGM_gogglesEffect = "[1, 1, -0.08, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Spectacles_Tinted: None {
		AGM_gogglesEffect = "[1, 1, -0.12, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Sport_Blackred: None {
		AGM_gogglesEffect = "[1, 1, -0.07, [1,0,0,0.08], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Sport_BlackWhite: None {
		AGM_gogglesEffect = "[1, 1, -0.05, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Sport_Blackyellow: None {
		AGM_gogglesEffect = "[1, 1, -0.15, [0.5,0.5,0,0.2], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Sport_Checkered: None {
		AGM_gogglesEffect = "[1, 1, -0.05, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Sport_Greenblack: None {
		AGM_gogglesEffect = "[1, 1, -0.15, [0,0.5,0,0.2], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Sport_Red: None {
		AGM_gogglesEffect = "[1, 1, -0.15, [0.4,0,0,0.2], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Squares: None {
		AGM_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Squares_Tinted: None {
		AGM_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Tactical_Black: None {
		AGM_gogglesEffect = "[1, 1, -0.15, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
	};
	class G_Tactical_Clear: None {
		AGM_gogglesEffect = "[1, 1, -0.02, [0,0,0,0], [0,0,0,1], [0,0,0,1]]";
	};
};
