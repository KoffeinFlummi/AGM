class CfgPatches {
  class AGM_HitReactions {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.95";
    versionStr = "0.95";
    versionAr[] = {0,95,0};
    author[] = {"commy2"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_HitReactions {
    class AGM_HitReactions {
      file = "\AGM_HitReactions\functions";
      class fallDown;
    };
  };
};

class Extended_Hit_EventHandlers {
  class CAManBase {
    class AGM_HitReactions_FallDown {
      hit = "if (_this select 0 != _this select 1) then {_this call AGM_HitReactions_fnc_fallDown};";
    };
  };
};
