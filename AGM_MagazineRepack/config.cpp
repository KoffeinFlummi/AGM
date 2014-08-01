class CfgPatches {
  class AGM_MagazineRepack {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
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
        statement = "call AGM_MagazineRepack_fnc_magazineRepack";
        showDisabled = 0;
        priority = -2;
      };
    };
  };
};

class AGM_Parameters {
  AGM_MagazineRepack_TimePerAmmo = 1.5;
  AGM_MagazineRepack_TimePerMagazine = 2.0;
};
