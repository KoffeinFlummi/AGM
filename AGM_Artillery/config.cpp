class CfgPatches{
  class AGM_Artillery  {
    units[] = {"B_AGM_Artillery_backpack_tube", "B_AGM_Artillery_backpack_baseplate", "B_AGM_advancedMortar"};
    weapons[] = {"AGM_RangeTable_81mm"};
    requiredVersion = 0.6;
    //Wind for air density/temp, Vector for the assets (scope view and digital numbers)
    requiredAddons[] = {"AGM_Core", "AGM_Wind", "AGM_Vector"};
    version = "0.95";
    versionStr = "0.95";
    versionAr[] = {0,95,0};
    author[] = {"Pabst Mirror"};
  };
};

class RscControlsGroup;
class VScrollbar;
class HScrollbar;
class RscText;
class RscObject;
class RscPicture;
class RscStructuredText;
class RscMapControl;
class RscListbox;
class RscListNBox;
class RscFrame;
class RscEdit;
class RscButton;
class ScrollBar;
class RscActiveText;
class RCWSOptics;

#include "gui_mapComputer.hpp"
#include "gui_mortarHud.hpp"
#include "gui_rangeTable.hpp"

class CfgFunctions {
  class AGM_Artillery {
    class AGM_Artillery {
      file = "\AGM_Artillery\functions";
      class createFiringSolution;
      class dev_buildTable;
      class firedEH;
      class formatNumber;
      class getPosFromMapCords;

      class mapCompEventClickOnMap;
      class mapCompEventDrawMap;
      class mapCompEventEnterCords;
      class mapCompOpen;

      class onHudLoad;

      class rangerFinderStart;

      class rangeTableOpen;
      class rangeTablePageChange;
      class rangeTablePreCalculatedValues;

      class simulateCalcRangeTableLine;
      class simulateFindSolution;
      class simulateShot;
    };
  };
};


//ToDo: Figure out how to intergrate with the normal fire control / rangefinder button
class AGM_Core_Default_Keys {
  class AGM_Artillery_mortarRangefinder {
    displayName = "Mortar: RangeFinder";
    condition = "(_player == (gunner _vehicle)) && {_vehicle isKindOf 'AGM_advancedMortar_base'} && {_vehicle getVariable ['AGM_Artillery_mapComputerEnabled', false]}";
    statement = "AGM_Artillery_rangefinderKeyDown = true; [_vehicle] call AGM_Artillery_fnc_rangerFinderStart;";
    conditionUp = "true";
    statementUp = "AGM_Artillery_rangefinderKeyDown = false;";
    key = 15;
    shift = 0;
    control = 0;
    alt = 0;
  };
};


class CfgAmmo {
  class SubmunitionBase;
  class Sh_82mm_AMOS;
  class Smoke_82mm_AMOS_White;
  class Flare_82mm_AMOS_White;

  //Ammo
  class AGM_81mmShell_AMMO_HE: Sh_82mm_AMOS {
    airFriction = 0;
    AGM_Artillery_realAirFriction = -0.0001;
    // hit = 165; //default is 165
    // indirectHit = 52; //default is 52
    indirectHitRange = 20;  //default 18
  };
  class AGM_81mmShell_AMMO_smokeWhite: Smoke_82mm_AMOS_White {
    airFriction = 0;
    AGM_Artillery_realAirFriction = -0.0001;
  };
  class AGM_81mmShell_AMMO_smokeRed: AGM_81mmShell_AMMO_smokeWhite {
    submunitionAmmo = "SmokeShellRed";
  };
  // class AGM_81mmShell_AMMO_Incinerate: AGM_81mmShell_AMMO_smokeWhite { //Warcrimes?
  // submunitionAmmo = "IncinerateShell";
  // };
  class AGM_81mmShell_AMMO_airburst: AGM_81mmShell_AMMO_smokeWhite {
    submunitionAmmo = "";
    AGM_Artillery_carryAmmo = "AGM_81mmShell_AMMO_EJECT_Airburst";
    AGM_Artillery_carryEjectHeight = 10;
  };
  class AGM_81mmShell_AMMO_flareWhite: AGM_81mmShell_AMMO_smokeWhite {
    submunitionAmmo = "";
    AGM_Artillery_carryAmmo = "AGM_81mmShell_AMMO_EJECT_Flare";
    AGM_Artillery_carryEjectHeight = 475;
  };

  //Helpers-Submunitions
  class AGM_81mmShell_AMMO_EJECT_Airburst: AGM_81mmShell_AMMO_HE {
    explosionTime = 0.00001;
  };
  class AGM_81mmShell_AMMO_EJECT_Flare: Flare_82mm_AMOS_White {
    triggerTime = 0.00001;
    timeToLive = 60;
    intensity = 525000;
  };
};

class CfgMagazines {
  class 8Rnd_82mm_Mo_shells;
  class AGM_8Rnd_81mmShell_HE: 8Rnd_82mm_Mo_shells {
    count = 8;
    initSpeed = 300;
    displayName = "HE Mortar Shells (Fuze: Impact)";
    displayNameShort = "HE-IMPACT";
    ammo = "AGM_81mmShell_AMMO_HE";
  };
  class AGM_8Rnd_81mmShell_airburst: AGM_8Rnd_81mmShell_HE {
    displayName = "HE Mortar Shells (Fuze: Airburst)";
    displayNameShort = "HE-AIRBURST";
    ammo = "AGM_81mmShell_AMMO_airburst";
  };
  class AGM_8Rnd_81mmShell_smokeWhite: AGM_8Rnd_81mmShell_HE {
    displayName = "Smoke (White)";
    displayNameShort = "SMOKE";
    ammo = "AGM_81mmShell_AMMO_smokeWhite";
  };
  class AGM_8Rnd_81mmShell_smokeRed: AGM_8Rnd_81mmShell_HE {
    displayName = "Smoke (Red)";
    displayNameShort = "SMOKE-RED";
    ammo = "AGM_81mmShell_AMMO_smokeRed";
  };
  // class AGM_81mmShell_Incinerate: AGM_8Rnd_81mmShell_HE {
  // displayName = "Incinerate";
  // displayNameShort = "BURN";
  // ammo = "AGM_81mmShell_AMMO_Incinerate";
  // };
  class AGM_8Rnd_81mmShell_flareWhite: AGM_8Rnd_81mmShell_HE {
    displayName = "Flare (White)";
    displayNameShort = "FLARE-WHITE";
    ammo = "AGM_81mmShell_AMMO_flareWhite";
  };
};

class CfgWeapons {
  class AGM_ItemCore;
  class InventoryItem_Base_F;

  class AGM_RangeTable_81mm: AGM_ItemCore {
    displayName = "AGM_RangeTable_81mm";
    descriptionShort = "AGM_RangeTable_81mm";
    model = "\A3\weapons_F\ammo\mag_univ.p3d";
    picture = "\AGM_Artillery\UI\icon_rangeTable.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 1;
    };
  };

  class CannonCore;
  class mortar_82mm: CannonCore {
    class Single1;
  };

  class AGM_Artillery_81mm: mortar_82mm {
    displayname = "Mortar 81mm";

    magazineReloadTime = 2; //default: 5
    reloadTime = 2; //default: 1.8

    magazines[] = {"AGM_8Rnd_81mmShell_HE", "AGM_8Rnd_81mmShell_airburst", "AGM_8Rnd_81mmShell_smokeWhite", "AGM_8Rnd_81mmShell_smokeRed", "AGM_8Rnd_81mmShell_flareWhite"};
    modes[] = {"Charge1","Charge2","Charge3","Charge4","Charge5"};
    class Charge1: Single1 {
      artilleryDispersion = 1.9;
      artilleryCharge = 0.2;
      displayName = "Charge 0";
    };
    class Charge2: Charge1 {
      artilleryCharge = 0.4;
      displayName = "Charge 1";
    };
    class Charge3: Charge1 {
      artilleryCharge = 0.6;
      displayName = "Charge 2";
    };
    class Charge4: Charge1 {
      artilleryCharge = 0.8;
      displayName = "Charge 3";
    };
    class Charge5: Charge1 {
      artilleryCharge = 1;
      displayName = "Charge 4";
    };
  };
};

//Add Wind/Submunitions Event Handler
class Extended_FiredBIS_EventHandlers {
  class AGM_advancedMortar_base {
    class AGM_Artillery_fired {
      clientFiredBIS = "_this call AGM_Artillery_fnc_firedEH";
    };
  };
};

class CfgVehicles {
  //Range Table Actions For Player
  class Man;
  class CAManBase: Man {
    class AGM_SelfActions {
      class AGM_Equipment {
        class AGM_RangeTable {
          displayName = "81 mm Range Table";
          condition = "'AGM_RangeTable_81mm' in (items _player)";
          statement = "['AGM_Artillery_81mm'] call AGM_Artillery_fnc_rangeTableOpen;";
          showDisabled = 0;
          priority = 0;
          enableInside = 1;
        };
      };
    };
  };

  //Backpacks
  class Bag_Base;
  class Weapon_Bag_Base: Bag_Base {class assembleInfo;};
  class B_AGM_Artillery_backpack_tube: Weapon_Bag_Base {
    author = "Pabst Mirror";
    displayName = "AGM Mortar Tube (M253)";

    faction = "BLU_F";
    scope = 2;
    model = "\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\UAV_backpack_F.p3d";
    hiddenSelectionsTextures[] = {"\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\data\UAV_backpack_rgr_co.paa"};
    picture = "\A3\Drones_F\Weapons_F_Gamma\ammoboxes\bags\data\ui\icon_B_C_UAV_rgr_ca";
    icon = "iconBackpack";
    mass = 400; // mass = kg x 22.0462
    maximumLoad = 0;

    class assembleInfo: assembleInfo {
      displayName = "Assemble AGM Mortar";
      assembleTo = "B_AGM_advancedMortar";
      base[] = {"B_AGM_Artillery_backpack_baseplate"};
    };
  };
  class B_AGM_Artillery_backpack_baseplate: Bag_Base {
    author = "Pabst Mirror";
    displayName = "AGM Mortar Baseplate (M177)";

    faction = "BLU_F";
    scope = 2;
    model = "\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\UAV_backpack_F.p3d";
    hiddenSelectionsTextures[] = {"\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\data\UAV_backpack_rgr_co.paa"};
    picture = "\A3\Drones_F\Weapons_F_Gamma\ammoboxes\bags\data\ui\icon_B_C_UAV_rgr_ca";
    icon = "iconBackpack";
    mass = 400; // mass = kg x 22.0462
    maximumLoad = 0;

    class assembleInfo {
      primary = 0;
      base = "";
      assembleTo = "";
      dissasembleTo[] = {};
      displayName = "";
    };
  };

  //Mortar Itself
  class LandVehicle;
  class StaticWeapon: LandVehicle {
    class Turrets {
      class MainTurret;
    };
  };
  class StaticMortar: StaticWeapon {
    class Turrets: Turrets {
      class MainTurret: MainTurret {
        class ViewOptics;
      };
    };
  };
  class Mortar_01_base_F: StaticMortar {
    class assembleInfo;
  };

  class AGM_advancedMortar_base : Mortar_01_base_F {
    displayname = "AGM Advanced Mortar (M252A1)";
    artilleryScanner = 0;
    hiddenSelectionsTextures[] = {"\AGM_Artillery\data\mortar_01_grey_co.paa"};

    //add Artillery Computer Action
    class UserActions {
      class OpenComputer {
        displayName = "Artillery Computer";
        position = "";
        radius = 1;
        condition = "((gunner this) == AGM_player) && (this getVariable ['AGM_Artillery_mapComputerEnabled', false])";
        statement = "[] spawn AGM_Artillery_fnc_mapCompOpen;";
        onlyForPlayer = true;
      };
    };

    class Library {libTextDesc = "Mortar";};

    class Turrets: Turrets {
      class MainTurret: MainTurret {
        weapons[] = {"AGM_Artillery_81mm"};
        magazines[] = {"AGM_8Rnd_81mmShell_HE", "AGM_8Rnd_81mmShell_airburst", "AGM_8Rnd_81mmShell_smokeWhite", "AGM_8Rnd_81mmShell_smokeRed", "AGM_8Rnd_81mmShell_flareWhite"};

        elevationMode = 1;
        // gunnerForceOptics = 0;
        turretInfoType = "AGM_Artillery_RscWeaponRangeArtilleryCustom";
        class ViewOptics: ViewOptics {
          visionMode[] = {"Normal"};
        };
        class OpticsIn {
          class Wide: RCWSOptics {
            initFov = "0.2";
            minFov = "0.2";
            maxFov = "0.2";
            visionMode[] = {"Normal"};
            thermalMode[] = {};
            gunnerOpticsModel = "\a3\weapons_f\reticle\Optics_Driver_01_F";
            gunnerOpticsEffect[] = {};
          };
          class Medium: Wide {
            gunnerOpticsModel = "\AGM_Vector\agm_vector_optics";
            initFov = "0.03";
            minFov = "0.03"; //todo: tweak these values so mil marks match actual values (vector has same problem)
            maxFov = "0.03";
          };
          // class Narrow: Wide {
          // gunnerOpticsModel = "\A3\Weapons_F\acc\reticle_sniper_z_F";
          // initFov = "0.01";
          // minFov = "0.01";
          // maxFov = "0.01";
          // };
        };
      };
    };
  };

  class B_AGM_advancedMortar : AGM_advancedMortar_base {
    author = "Pabst Mirror";
    _generalMacro = "B_AGM_advancedMortar";
    scope = 2;
    side = 1;
    faction = "BLU_F";
    crew = "B_Soldier_F";
    availableForSupportTypes[] = {"Artillery"};

    class assembleInfo: assembleInfo {
      dissasembleTo[] = {"B_AGM_Artillery_backpack_tube", "B_AGM_Artillery_backpack_baseplate"};
    };
  };
};