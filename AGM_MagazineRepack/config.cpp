class CfgPatches {
  class AGM_MagazineRepack {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.95";
    versionStr = "0.95";
    versionAr[] = {0,95,0};
    author[] = {"commy2", "CAA-Picard"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_MagazineRepack {
    class AGM_MagazineRepack {
      file = "\AGM_MagazineRepack\functions";
      class magazineRepack;
      class magazineRepackCallback;
      class openSelectMagazineUI;
      class selectFromInventory;
      class startPackingProgressBar;
    };
  };
};

class CfgVehicles {
  class Man;

  class CAManBase: Man {
    class AGM_SelfActions {
      class AGM_RepackMagazines {
        displayName = "$STR_AGM_MagazineRepack_RepackMagazines";
        condition = "true";
        statement = "[true] call AGM_MagazineRepack_fnc_magazineRepack";
        showDisabled = 0;
        priority = -2;
        icon = "AGM_MagazineRepack\UI\repack_ca.paa";
        hotkey = "R";
        enableInside = 1;
      };
    };
  };
};

class AGM_Parameters {
  AGM_MagazineRepack_TimePerAmmo = 1.5;
  AGM_MagazineRepack_TimePerMagazine = 2.0;
};

class CfgMagazines {
  class Default;
  class CA_Magazine: Default {
    class AGM_InventoryActions {
      class AGM_RepackMag {
        displayName = "$STR_AGM_MagazineRepack_RepackMagazines";
        condition = "_classname in (([false] call AGM_MagazineRepack_fnc_magazineRepack) select 0)";
        statement = "_this call AGM_MagazineRepack_fnc_selectFromInventory";        
        closeInventory = 1;
      };
    };
  };
};
