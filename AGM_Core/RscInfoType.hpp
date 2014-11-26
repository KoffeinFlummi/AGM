
class RscInGameUI {
	class RscUnitInfo;
	class RscUnitInfoSoldier: RscUnitInfo {
		onLoad = "uiNamespace setVariable ['AGM_dlgSoldier',   _this select 0]; {_this call _x} forEach ((missionNamespace getVariable ['AGM_onLoadInfoSoldier',   [-1, [], []]]) select 2); {_this call _x} forEach ((missionNamespace getVariable ['AGM_onLoadInfoAny', [-1, [], []]]) select 2); [""onLoad"",_this,""RscUnitInfo"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
	};
	class RscUnitInfoTank: RscUnitInfo {
		onLoad = "uiNamespace setVariable ['AGM_dlgVehicle',   _this select 0]; {_this call _x} forEach ((missionNamespace getVariable ['AGM_onLoadInfoVehicle',   [-1, [], []]]) select 2); {_this call _x} forEach ((missionNamespace getVariable ['AGM_onLoadInfoAny', [-1, [], []]]) select 2); [""onLoad"",_this,""RscUnitInfo"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
	};
	class RscUnitInfoAir: RscUnitInfo {
		onLoad = "uiNamespace setVariable ['AGM_dlgAircraft',  _this select 0]; {_this call _x} forEach ((missionNamespace getVariable ['AGM_onLoadInfoAircraft',  [-1, [], []]]) select 2); {_this call _x} forEach ((missionNamespace getVariable ['AGM_onLoadInfoAny', [-1, [], []]]) select 2); [""onLoad"",_this,""RscUnitInfo"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
	};
	class RscUnitInfoShip: RscUnitInfo {
		onLoad = "uiNamespace setVariable ['AGM_dlgShip',      _this select 0]; {_this call _x} forEach ((missionNamespace getVariable ['AGM_onLoadInfoShip',      [-1, [], []]]) select 2); {_this call _x} forEach ((missionNamespace getVariable ['AGM_onLoadInfoAny', [-1, [], []]]) select 2); [""onLoad"",_this,""RscUnitInfo"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
	};
	class RscUnitInfoParachute: RscUnitInfo {
		onLoad = "uiNamespace setVariable ['AGM_dlgParachute', _this select 0]; {_this call _x} forEach ((missionNamespace getVariable ['AGM_onLoadInfoParachute', [-1, [], []]]) select 2); {_this call _x} forEach ((missionNamespace getVariable ['AGM_onLoadInfoAny', [-1, [], []]]) select 2); [""onLoad"",_this,""RscUnitInfo"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
	};
};

class RscDisplayInventory {
	onLoad = "[""onLoad"",_this,""RscDisplayInventory"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""; {_this call _x} forEach ((missionNamespace getVariable ['AGM_onLoadInventory', [-1, [], []]]) select 2);";
};

class RscDisplayOptionsLayout {
	onLoad = "uiNamespace setVariable ['AGM_dlgActionMenu', _this select 0]; [""onLoad"",_this,""RscDisplayOptionsLayout"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""; {_this call _x} forEach ((missionNamespace getVariable ['AGM_onLoadActionMenu', [-1, [], []]]) select 2);";
};

class RscDisplayChannel {
	class controls {
		class AGM_GetChannel: RscMapControl {
			onDraw = "missionNamespace setVariable ['AGM_currentChannel', ctrlText ((ctrlParent (_this select 0)) displayCtrl 101)];";
			idc = -1;
			w = 0;
			h = 0;
		};
	};
};
