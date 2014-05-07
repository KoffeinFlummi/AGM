class CfgPatches {
  class AGM_Hearing {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = 0.7;
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Hearing {
    class AGM_Hearing {
      file = "AGM_Hearing\functions";
      class earRinging;
      class explosionEH;
      class firedNearEH;
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Hearing {
    clientInit = "execVM '\AGM_Hearing\init.sqf'";
  };
};

class CfgSounds {
  class AGM_EarRinging_Weak {
    sound[] = {"\AGM_Hearing\sounds\agm_earringing_weak.wav",8,1.7};
    titles[] = {};
  };
  class AGM_EarRinging_Medium {
    sound[] = {"\AGM_Hearing\sounds\agm_earringing_medium.wav",8,1.7};
    titles[] = {};
  };
  class AGM_EarRinging_Heavy {
    sound[] = {"\AGM_Hearing\sounds\agm_earringing_heavy.wav",8,1.7};
    titles[] = {};
  };
};