// by commy2

AGM_Logistics_loadedItemsDummy = "Sign_Sphere10cm_F" createVehicle [-1000, -1000, 0];
AGM_Logistics_isCarrying = false;


// Magazines

AGM_Logistics_applyMagazineNames = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\Magazines\applyMagazineNames.sqf";
AGM_Logistics_getWeaponsOfMagazine = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\Magazines\getWeaponsOfMagazine.sqf";
AGM_Logistics_getMagazineOfVehicle = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\Magazines\getMagazineOfVehicle.sqf";
AGM_Logistics_getLoadableMagazines = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\Magazines\getLoadableMagazines.sqf";
AGM_Logistics_canLoadMagazine = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\Magazines\canLoadMagazine.sqf";
AGM_Logistics_reloadMagazine = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\Magazines\reloadMagazine.sqf";
AGM_Logistics_reloadMagazineCallback = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\Magazines\reloadMagazineCallback.sqf";


// Crates

AGM_Logistics_carryItem = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\carryItem.sqf";
AGM_Logistics_dropItem = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\dropItem.sqf";
//AGM_Logistics_loadBoxIntoVehicle = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\loadBoxIntoVehicle.sqf";
//AGM_Logistics_loadBoxIntoVehicleCallback = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\loadBoxIntoVehicleCallback.sqf";
//AGM_Logistics_unloadBox = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\unloadBox.sqf";
//AGM_Logistics_unloadBoxCallback = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\unloadBoxCallback.sqf";
//AGM_Logistics_canLoadInto = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\canLoadInto.sqf";
//AGM_Logistics_canUnload = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\canUnload.sqf";


// Jerry Can

AGM_Logistics_carryJerryCan = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\JerryCan\carryJerryCan.sqf";
AGM_Logistics_dropJerryCan = compile preprocessFileLineNumbers "\AGM_Logistics\scripts\JerryCan\dropJerryCan.sqf";


// Tyres

/*WIP*/
