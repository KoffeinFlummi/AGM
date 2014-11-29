class CfgPatches {
  class AGM_GetIn {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.94.1";
    versionStr = "0.94.1";
    versionAr[] = {0,94,1};
    author[] = {"commy2"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_GetIn {
    class AGM_GetIn {
      file = "AGM_GetIn\functions";
      class moduleAllowEnemies;
    };
  };
};

class AGM_Parameters {
  AGM_GetIn_canBoardEnemyVehicle = 0;
};

class CfgVehicles {
  class Logic;
  class Module_F: Logic {
    class ArgumentsBaseUnits {};
    class ModuleDescription {};
  };
  class AGM_GetIn_ModuleAllowEnemies: Module_F {
    author = "Pabst Mirror";
    category = "AGM";
    displayName = "GetIn: Hostile Vehicles";
    function = "AGM_GetIn_fnc_moduleAllowEnemies";
    scope = 2;
    isGlobal = 1;
    // icon = "\AGM_Explosives\UI\IconExplosives_ca.paa";  //todo
    functionPriority = 0;
    class Arguments {
      class CanBoardHostileVehicle {
        displayName = "GetIn Hostile Vehicles"; // Argument label
        description = "Can use the GetIn Interaction on a hostile vehicle.  Default: No"; // Tooltip description
        typeName = "NUMBER"; // Value type, can be "NUMBER", "STRING" or "BOOL"
        class values {
          class Yes { name = "Yes"; value = 1;};
          class No { default = 1; name = "No"; value = 0; };
        };
      };
    };
    class ModuleDescription: ModuleDescription {
      description = "Default ArmA3 prevents boarding a vehicle that has a hostile in it (or player with 'enemy' rating from teamkills).  This allows the GetIn Interaction menu to override.";
      sync[] = {};
    };
  };
  
  class LandVehicle;
  class Car: LandVehicle {
    class AGM_Actions {
      class AGM_GetIn {
        displayName = "$STR_AGM_GetInVehicle";
        distance = 4;
        condition = "";
        statement = "";
        showDisabled = 0;
        priority = 1.9;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        subMenu[] = {"AGM_GetIn", 0};
        hotkey = "G";

        class AGM_GetInDriver {
          displayName = "$STR_AGM_GetInVehicleAsDriver";
          distance = 4;
          condition = "[_player, _target, 'Driver', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Driver'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.90;
          icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
        };
        class AGM_GetInGunner {
          displayName = "$STR_AGM_GetInVehicleAsGunner";
          distance = 4;
          condition = "[_player, _target, 'Gunner', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Gunner'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.91;
          icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        };
        class AGM_GetInCommander {
          displayName = "$STR_AGM_GetInVehicleAsCommander";
          distance = 4;
          condition = "[_player, _target, 'Commander', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Commander'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.92;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
        };
        class AGM_GetInCargo {
          displayName = "$STR_AGM_GetInVehicleAsCargo";
          distance = 4;
          condition = "[_player, _target, 'Cargo', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Cargo'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.93;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        };
        class AGM_GetInCoDriver {
          displayName = "$STR_AGM_GetInVehicleAsCoDriver";
          distance = 4;
          condition = "[_player, _target, 'Codriver', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Codriver'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.94;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        };
        class AGM_Dummy {
          displayName = "";
          condition = "false";
          statement = "";
          showDisabled = 1;
          priority = -99;
          icon = "AGM_Core\UI\blank_CO.paa";
          enableInside = 1;
        };
      };
    };
    class AGM_SelfActions {
      class AGM_MoveTo {
        displayName = "$STR_AGM_MoveTo";
        distance = 4;
        condition = "";
        statement = "";
        showDisabled = 0;
        priority = 1.9;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        subMenu[] = {"AGM_MoveTo", 1};
        hotkey = "N";
        enableInside = 1;

        class AGM_MoveToDriver {
          displayName = "$STR_AGM_MoveToDriver";
          condition = "[_player, _vehicle, 'Driver', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Driver'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.90;
          icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
          enableInside = 1;
        };
        class AGM_MoveToGunner {
          displayName = "$STR_AGM_MoveToGunner";
          condition = "[_player, _vehicle, 'Gunner', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Gunner'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.91;
          icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
          enableInside = 1;
        };
        class AGM_MoveToCommander {
          displayName = "$STR_AGM_MoveToCommander";
          condition = "[_player, _vehicle, 'Commander', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Commander'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.92;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
          enableInside = 1;
        };
        class AGM_MoveToCargo {
          displayName = "$STR_AGM_MoveToCargo";
          condition = "[_player, _vehicle, 'Cargo', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Cargo'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.93;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
          enableInside = 1;
        };
        class AGM_MoveToCoDriver {
          displayName = "$STR_AGM_MoveToCoDriver";
          condition = "[_player, _vehicle, 'Codriver', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Codriver'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.94;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
          enableInside = 1;
        };
        class AGM_Dummy {
          displayName = "";
          condition = "false";
          statement = "";
          showDisabled = 1;
          priority = -99;
          icon = "AGM_Core\UI\blank_CO.paa";
          enableInside = 1;
        };
      };
    };
  };
  class Car_F: Car {};
  class Wheeled_APC_F: Car_F {
    class AGM_Actions: AGM_Actions {
      class AGM_GetIn: AGM_GetIn {
        delete AGM_GetInCoDriver;
      };
    };
    class AGM_SelfActions: AGM_SelfActions {
      class AGM_MoveTo: AGM_MoveTo {
        delete AGM_MoveToCoDriver;
      };
    };
  };

  class Tank: LandVehicle {
    class AGM_Actions {
      class AGM_GetIn {
        displayName = "$STR_AGM_GetInVehicle";
        distance = 4;
        condition = "";
        statement = "";
        showDisabled = 0;
        priority = 1.9;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        subMenu[] = {"AGM_GetIn", 0};
        hotkey = "G";

        class AGM_GetInDriver {
          displayName = "$STR_AGM_GetInVehicleAsDriver";
          distance = 4;
          condition = "[_player, _target, 'Driver', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Driver'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.90;
          icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
        };
        class AGM_GetInGunner {
          displayName = "$STR_AGM_GetInVehicleAsGunner";
          distance = 4;
          condition = "[_player, _target, 'Gunner', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Gunner'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.91;
          icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        };
        class AGM_GetInCommander {
          displayName = "$STR_AGM_GetInVehicleAsCommander";
          distance = 4;
          condition = "[_player, _target, 'Commander', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Commander'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.92;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
        };
        class AGM_GetInCargo {
          displayName = "$STR_AGM_GetInVehicleAsCargo";
          distance = 4;
          condition = "[_player, _target, 'Cargo', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Cargo'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.93;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        };
        class AGM_Dummy {
          displayName = "";
          condition = "false";
          statement = "";
          showDisabled = 1;
          priority = -99;
          icon = "AGM_Core\UI\blank_CO.paa";
          enableInside = 1;
        };
      };
    };
    class AGM_SelfActions {
      class AGM_MoveTo {
        displayName = "$STR_AGM_MoveTo";
        distance = 4;
        condition = "";
        statement = "";
        showDisabled = 0;
        priority = 1.9;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        subMenu[] = {"AGM_MoveTo", 1};
        hotkey = "N";
        enableInside = 1;

        class AGM_MoveToDriver {
          displayName = "$STR_AGM_MoveToDriver";
          condition = "[_player, _vehicle, 'Driver', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Driver'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.90;
          icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
          enableInside = 1;
        };
        class AGM_MoveToGunner {
          displayName = "$STR_AGM_MoveToGunner";
          condition = "[_player, _vehicle, 'Gunner', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Gunner'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.91;
          icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
          enableInside = 1;
        };
        class AGM_MoveToCommander {
          displayName = "$STR_AGM_MoveToCommander";
          condition = "[_player, _vehicle, 'Commander', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Commander'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.92;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
          enableInside = 1;
        };
        class AGM_MoveToCargo {
          displayName = "$STR_AGM_MoveToCargo";
          condition = "[_player, _vehicle, 'Cargo', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Cargo'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.93;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
          enableInside = 1;
        };
        class AGM_Dummy {
          displayName = "";
          condition = "false";
          statement = "";
          showDisabled = 1;
          priority = -99;
          icon = "AGM_Core\UI\blank_CO.paa";
          enableInside = 1;
        };
      };
    };
  };

  class Air;
  class Helicopter : Air {
    class AGM_Actions {
      class AGM_GetIn {
        displayName = "$STR_AGM_GetInVehicle";
        distance = 4;
        condition = "";
        statement = "";
        showDisabled = 0;
        priority = 1.9;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        subMenu[] = {"AGM_GetIn", 0};
        hotkey = "G";

        class AGM_GetInPilot {
          displayName = "$STR_AGM_GetInVehicleAsPilot";
          distance = 4;
          condition = "[_player, _target, 'Pilot', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Pilot'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.90;
          icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
        };
        class AGM_GetInCoPilot {
          displayName = "$STR_AGM_GetInVehicleAsCoPilot";
          distance = 4;
          condition = "[_player, _target, 'Copilot', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Copilot'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.90;
          icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
        };
        class AGM_GetInGunner {
          displayName = "$STR_AGM_GetInVehicleAsGunner";
          distance = 4;
          condition = "[_player, _target, 'Gunner', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Gunner'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.91;
          icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        };
        class AGM_GetInCargo {
          displayName = "$STR_AGM_GetInVehicleAsCargo";
          distance = 4;
          condition = "[_player, _target, 'Cargo', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Cargo'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.93;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        };
        class AGM_Dummy {
          displayName = "";
          condition = "false";
          statement = "";
          showDisabled = 1;
          priority = -99;
          icon = "AGM_Core\UI\blank_CO.paa";
          enableInside = 1;
        };
      };
    };
    class AGM_SelfActions {
      class AGM_MoveTo {
        displayName = "$STR_AGM_MoveTo";
        distance = 4;
        condition = "";
        statement = "";
        showDisabled = 0;
        priority = 1.9;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        subMenu[] = {"AGM_MoveTo", 1};
        hotkey = "N";
        enableInside = 1;

        class AGM_MoveToPilot {
          displayName = "$STR_AGM_MoveToPilot";
          condition = "[_player, _vehicle, 'Pilot', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Pilot'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.90;
          icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
          enableInside = 1;
        };
        class AGM_MoveToCoPilot {
          displayName = "$STR_AGM_MoveToCoPilot";
          condition = "[_player, _vehicle, 'Copilot', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Copilot'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.90;
          icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
          enableInside = 1;
        };
        class AGM_MoveToGunner {
          displayName = "$STR_AGM_MoveToGunner";
          condition = "[_player, _vehicle, 'Gunner', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Gunner'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.91;
          icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
          enableInside = 1;
        };
        class AGM_MoveToCargo {
          displayName = "$STR_AGM_MoveToCargo";
          condition = "[_player, _vehicle, 'Cargo', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Cargo'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.93;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
          enableInside = 1;
        };
        class AGM_Dummy {
          displayName = "";
          condition = "false";
          statement = "";
          showDisabled = 1;
          priority = -99;
          icon = "AGM_Core\UI\blank_CO.paa";
          enableInside = 1;
        };
      };
    };
  };
  class Plane: Air {
    class AGM_Actions {
      class AGM_GetIn {
        displayName = "$STR_AGM_GetInVehicle";
        distance = 4;
        condition = "";
        statement = "";
        showDisabled = 0;
        priority = 1.9;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        subMenu[] = {"AGM_GetIn", 0};
        hotkey = "G";

        class AGM_GetInPilot {
          displayName = "$STR_AGM_GetInVehicleAsPilot";
          distance = 4;
          condition = "[_player, _target, 'Pilot', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Pilot'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.90;
          icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
        };
        class AGM_GetInCoPilot {
          displayName = "$STR_AGM_GetInVehicleAsCoPilot";
          distance = 4;
          condition = "[_player, _target, 'Copilot', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Copilot'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.90;
          icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
        };
        class AGM_GetInCargo {
          displayName = "$STR_AGM_GetInVehicleAsCargo";
          distance = 4;
          condition = "[_player, _target, 'Cargo', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Cargo'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.93;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        };
        class AGM_Dummy {
          displayName = "";
          condition = "false";
          statement = "";
          showDisabled = 1;
          priority = -99;
          icon = "AGM_Core\UI\blank_CO.paa";
          enableInside = 1;
        };
      };
    };
    class AGM_SelfActions {
      class AGM_MoveTo {
        displayName = "$STR_AGM_MoveTo";
        distance = 4;
        condition = "";
        statement = "";
        showDisabled = 0;
        priority = 1.9;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        subMenu[] = {"AGM_MoveTo", 1};
        hotkey = "N";
        enableInside = 1;

        class AGM_MoveToPilot {
          displayName = "$STR_AGM_MoveToPilot";
          condition = "[_player, _vehicle, 'Pilot', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Pilot'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.90;
          icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
          enableInside = 1;
        };
        class AGM_MoveToCoPilot {
          displayName = "$STR_AGM_MoveToCoPilot";
          condition = "[_player, _vehicle, 'Copilot', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Copilot'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.90;
          icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
          enableInside = 1;
        };
        class AGM_MoveToCargo {
          displayName = "$STR_AGM_MoveToCargo";
          condition = "[_player, _vehicle, 'Cargo', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Cargo'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.93;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
          enableInside = 1;
        };
        class AGM_Dummy {
          displayName = "";
          condition = "false";
          statement = "";
          showDisabled = 1;
          priority = -99;
          icon = "AGM_Core\UI\blank_CO.paa";
          enableInside = 1;
        };
      };
    };
  };

  class Ship;
  class Ship_F: Ship {
    class AGM_Actions {
      class AGM_GetIn {
        displayName = "$STR_AGM_GetInVehicle";
        distance = 4;
        condition = "";
        statement = "";
        showDisabled = 0;
        priority = 1.9;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        subMenu[] = {"AGM_GetIn", 0};
        hotkey = "G";

        class AGM_GetInDriver {
          displayName = "$STR_AGM_GetInVehicleAsDriver";
          distance = 4;
          condition = "[_player, _target, 'Driver', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Driver'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.90;
          icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
        };
        class AGM_GetInGunner {
          displayName = "$STR_AGM_GetInVehicleAsGunner";
          distance = 4;
          condition = "[_player, _target, 'Gunner', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Gunner'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.91;
          icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        };
        class AGM_GetInCommander {
          displayName = "$STR_AGM_GetInVehicleAsCommander";
          distance = 4;
          condition = "[_player, _target, 'Commander', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Commander'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.92;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
        };
        class AGM_GetInCargo {
          displayName = "$STR_AGM_GetInVehicleAsCargo";
          distance = 4;
          condition = "[_player, _target, 'Cargo', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Cargo'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.93;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        };
        class AGM_Dummy {
          displayName = "";
          condition = "false";
          statement = "";
          showDisabled = 1;
          priority = -99;
          icon = "AGM_Core\UI\blank_CO.paa";
          enableInside = 1;
        };
      };
    };
    class AGM_SelfActions {
      class AGM_MoveTo {
        displayName = "$STR_AGM_MoveTo";
        distance = 4;
        condition = "";
        statement = "";
        showDisabled = 0;
        priority = 1.9;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        subMenu[] = {"AGM_MoveTo", 1};
        hotkey = "N";
        enableInside = 1;

        class AGM_MoveToDriver {
          displayName = "$STR_AGM_MoveToDriver";
          condition = "[_player, _vehicle, 'Driver', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Driver'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.90;
          icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
          enableInside = 1;
        };
        class AGM_MoveToGunner {
          displayName = "$STR_AGM_MoveToGunner";
          condition = "[_player, _vehicle, 'Gunner', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Gunner'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.91;
          icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
          enableInside = 1;
        };
        class AGM_MoveToCommander {
          displayName = "$STR_AGM_MoveToCommander";
          condition = "[_player, _vehicle, 'Commander', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Commander'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.92;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
          enableInside = 1;
        };
        class AGM_MoveToCargo {
          displayName = "$STR_AGM_MoveToCargo";
          condition = "[_player, _vehicle, 'Cargo', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Cargo'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.93;
          icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
          enableInside = 1;
        };
        class AGM_Dummy {
          displayName = "";
          condition = "false";
          statement = "";
          showDisabled = 1;
          priority = -99;
          icon = "AGM_Core\UI\blank_CO.paa";
          enableInside = 1;
        };
      };
    };
  };

  class Helicopter_Base_F: Helicopter {};
  class Helicopter_Base_H: Helicopter_Base_F {};
  class Heli_Transport_01_base_F: Helicopter_Base_H {
    class AGM_Actions: AGM_Actions {
      class AGM_GetIn: AGM_GetIn {
        class AGM_GetInDoorgunner {
          displayName = "$STR_AGM_GetInVehicleAsDoorGunnerRight";
          distance = 4;
          condition = "[_player, _target, 'Turret', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _target, 'Turret'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.90;
          icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        };
      };
    };
    class AGM_SelfActions: AGM_SelfActions {
      class AGM_MoveTo: AGM_MoveTo {
        class AGM_MoveToDoorgunner {
          displayName = "$STR_AGM_MoveToDoorGunnerRight";
          condition = "[_player, _vehicle, 'Turret', true] call AGM_Core_fnc_canGetInPosition";
          statement = "[_player, _vehicle, 'Turret'] call AGM_Core_fnc_getInPosition";
          showDisabled = 0;
          priority = -1.90;
          icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
          enableInside = 1;
        };
      };
    };
  };

  /*class StaticWeapon: LandVehicle {
    class AGM_Actions {
      class AGM_GetIn {
        displayName = "$STR_AGM_GetInVehicle";
        distance = 4;
        condition = "[AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInGunner";
        statement = "[AGM_Interaction_Target] call AGM_GetIn_fnc_getInGunner";
        showDisabled = 0;
        priority = -1.91;
      };
    };
  };

  class StaticMortar;
  class Mortar_01_base_F: StaticMortar {
    class AGM_Actions {
      class AGM_GetIn {
        displayName = "$STR_AGM_GetInVehicle";
        distance = 4;
        condition = "[AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInGunner";
        statement = "[AGM_Interaction_Target] call AGM_GetIn_fnc_getInGunner";
        showDisabled = 0;
        priority = -1.91;
      };
    };
  };*/
};
