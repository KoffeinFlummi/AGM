
class RscInGameUI {
	class RscUnitInfo;
	class RscUnitInfoSoldier: RscUnitInfo {
		idd = 300;
		onLoad = "uiNamespace setVariable ['AGM_dlgSoldier', _this select 0]; {_this call _x} forEach (uiNamespace getVariable ['AGM_onLoadInfoSoldier', []]); [""onLoad"",_this,""RscUnitInfo"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
	};
	class RscUnitInfoTank: RscUnitInfo {
		idd = 300;
		onLoad = "uiNamespace setVariable ['AGM_dlgVehicle', _this select 0]; {_this call _x} forEach (uiNamespace getVariable ['AGM_onLoadInfoVehicle', []]); [""onLoad"",_this,""RscUnitInfo"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
	};
	class RscUnitInfoAir: RscUnitInfo {
		onLoad = "uiNamespace setVariable ['AGM_dlgAircraft', _this select 0]; {_this call _x} forEach (uiNamespace getVariable ['AGM_onLoadInfoAircraft', []]); [""onLoad"",_this,""RscUnitInfo"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
	};
};
