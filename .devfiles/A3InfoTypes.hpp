
class RscInGameUI {
	class RscUnitInfo {
		onLoad = "[""onLoad"",_this,""RscUnitInfo"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
		onUnload = "[""onUnload"",_this,""RscUnitInfo"",'IGUI'] call compile preprocessfilelinenumbers ""A3\ui_f\scripts\initDisplay.sqf""";
		idd = 300;
		controls[] = {"WeaponInfoControlsGroupRight","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel"};
	};
	class RscUnitInfoNoHUD {
		idd = 300;
	};
	class RscUnitInfoSoldier: RscUnitInfo {
		idd = 300;
		controls[] = {"WeaponInfoControlsGroupLeft","CA_Speed_Freefall","CA_Alt_Freefall"};
	};
	class RscUnitInfoTank: RscUnitInfo {
		idd = 300;
		controls[] = {"WeaponInfoControlsGroupRight","CA_Zeroing","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_Radar"};
	};
	class RscUnitInfoAir: RscUnitInfo {
		controls[] = {"WeaponInfoControlsGroupRight","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_AltBackground","CA_AltUnits","CA_Alt","CA_Stabilize","CA_Radar"};
	};
	class RscUnitInfo_AH64D_gunner {
		idd = 300;
		controls[] = {"CA_Distance","CA_VisionMode","CA_FlirMode","CA_FOVMode","CA_Compass","CA_Heading","CA_Autohover","CA_BalisticComputer","CA_BallRange","CA_LaserMarker","CA_WeaponZeroingText","CA_WeaponZeroing"};
	};
	class RscUnitInfoSubmarine: RscUnitInfo {
		idd = 300;
		controls[] = {"WeaponInfoControlsGroupRight","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_AltBackground","CA_AltUnits","CA_Depth"};
	};
	class RscUnitInfoShip: RscUnitInfo {
		idd = 300;
		updateWidthByWeapon = 0;
		updateHeightByCrew = 0;
		updateWidthByCrew = 0;
		controls[] = {"WeaponInfoControlsGroupRight","CA_Zeroing","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_Radar"};
	};
	class RscOptics_Rangefinder: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_IGUI_elements_group"};
		class CA_IGUI_elements_group: RscControlsGroup
	};
	class RscOptics_crows: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group"};
	};
	class RscWeaponZeroing: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing"};
	};
	class RscWeaponRangeZeroing: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing","CA_DistanceText","CA_Distance"};
	};
	class RscOptics_sos: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_IGUI_elements_group","CA_Sniper_WFOV_mode_group","CA_Sniper_NFOV_mode_group"};
	};
	class RscOptics_nightstalker: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_IGUI_elements_group"};
	};
	class RscOptics_tws: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_IGUI_elements_group","CA_WFOV_mode_group","CA_NFOV_mode_group"};
	};
	class RscOptics_cows: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_WFOV_mode_group","CA_NFOV_mode_group"};
	};
	class RscUnitInfoParachute: RscUnitInfo {
		idd = 300;
		controls[] = {"WeaponInfoControlsGroupRight","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_AltBackground","CA_AltUnits","CA_Alt","CA_Stabilize"};
	};
	class RscOptics_tws_sniper: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_IGUI_elements_group","CA_WFOV_mode_group","CA_NFOV_mode_group"};
	};
	class RscOptics_tws_mg: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_IGUI_elements_group","CA_WFOV_mode_group","CA_NFOV_mode_group"};
	};
	class RscOptics_SDV_driver: RscUnitInfo {
		idd = 300;
		controls[] = {"DriverOpticsGroup","WeaponInfoControlsGroupRight","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_Radar","CA_AltBackground","CA_AltUnits","CA_Depth"};
	};
	class RscOptics_Heli_Attack_02_gunner: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group"};
	};
	class RscOptics_Heli_Attack_01_gunner: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group"};
	};
	class RscOptics_AV_pilot: RscUnitInfo {
		idd = 300;
		controls[] = {"WeaponInfoControlsGroupRight","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_AltBackground","CA_AltUnits","CA_Alt","CA_Stabilize","CA_Radar","DriverOpticsGroup"};
	};
	class RscOptics_AV_driver: RscUnitInfo {
		idd = 300;
		controls[] = {"WeaponInfoControlsGroupRight","CA_Zeroing","CA_BackgroundVehicle","CA_BackgroundVehicleTitle","CA_BackgroundVehicleTitleDark","CA_BackgroundFuel","CA_Vehicle","CA_VehicleRole","CA_HitZones","CA_SpeedBackground","CA_SpeedUnits","CA_Speed","CA_ValueFuel","CA_Radar","DriverOpticsGroup"};
	};
	class RscOptics_UAV_gunner: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_IGUI_elements_group"};
	};
	class RscOptics_UGV_gunner: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group"};
	};
	class RscOptics_APC_Tracked_01_gunner: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
	};
	class RscOptics_APC_Tracked_03_gunner: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
	};
	class RscOptics_APC_Wheeled_01_gunner: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
	};
	class RscOptics_APC_Wheeled_03_commander: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
	};
	class RscOptics_APC_Wheeled_03_gunner: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
	};
	class RscOptics_MBT_01_commander: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
	};
	class RscOptics_MBT_01_gunner: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group","CA_APC_WFOV_mode_group","CA_APC_NFOV_mode_group"};
	};
	class RscOptics_MBT_02_commander: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group"};
	};
	class RscOptics_MBT_02_gunner: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group"};
	};
	class RscOptics_MBT_03_gunner: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing","CA_IGUI_elements_group"};
	};
	class RscOptics_Offroad_01: RscUnitInfo {
		idd = 300;
		controls[] = {"CA_Zeroing"};
	};
};
