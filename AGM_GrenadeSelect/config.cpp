class CfgPatches {
  class AGM_GrenadeSelect {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"CAA-Picard"};
    authorUrl = "https://github.com/esteldunedain/";
  };
};

class CfgFunctions {
  class AGM_GrenadeSelect {
    class AGM_GrenadeSelect {
      file = "\AGM_GrenadeSelect\functions";
      class selectGrenadeFrag;
      class selectGrenadeOther;

      class countMagazinesForGrenadeMuzzle;
      class displayGrenadeTypeAndNumber;
      class setNextGrenadeMuzzle;
    };
  };
};

class AGM_Core_Default_Keys {
  class selectGrenadeFrag {
    displayName = "$STR_AGM_GrenadeSelect_SelectGrenadeFrag";
    condition = "player == _vehicle && {alive player} && {!(player getVariable ['AGM_Unconscious', false])}";
    statement = "call AGM_GrenadeSelect_fnc_selectGrenadeFrag";
    key = 7;
    shift = 0;
    control = 0;
    alt = 0;
  };
  class selectGrenadeOther {
    displayName = "$STR_AGM_GrenadeSelect_SelectGrenadeOther";
    condition = "player == _vehicle && {alive player} && {!(player getVariable ['AGM_Unconscious', false])}";
    statement = "call AGM_GrenadeSelect_fnc_selectGrenadeOther";
    key = 8;
    shift = 0;
    control = 0;
    alt = 0;
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_GrenadeSelect {
    clientInit = "call compile preprocessFileLineNumbers '\AGM_GrenadeSelect\clientInit.sqf'";
  };
};
