class CfgPatches {
  class AGM_GetIn {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.931";
    versionStr = "0.931";
    versionAr[] = {0,931,0};
    author[] = {"commy2"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_GetIn {
    class AGM_GetIn {
      file = "AGM_GetIn\functions";
      class canGetInCargo;
      class canGetInCoDriver;
      class canGetInCommander;
      class canGetInCoPilot;
      class canGetInDoorGunner;
      class canGetInDriver;
      class canGetInGunner;
      class canGetInPilot;
      class canGetInTurret;
      class getInCargo;
      class getInCoDriver;
      class getInCommander;
      class getInCoPilot;
      class getInDoorGunner;
      class getInDriver;
      class getInGunner;
      class getInPilot;
      class getInTurret;
    };
  };
};

class CfgVehicles {
  class LandVehicle;
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

  class Car: LandVehicle {
    class AGM_Actions {
      class AGM_GetInDriver {
        displayName = "$STR_AGM_GetInVehicleAsDriver";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInDriver";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInDriver";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
      };
      class AGM_GetInGunner {
        displayName = "$STR_AGM_GetInVehicleAsGunner";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInGunner";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInGunner";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
      };
      class AGM_GetInCommander {
        displayName = "$STR_AGM_GetInVehicleAsCommander";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInCommander";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInCommander";
        showDisabled = 0;
        priority = -1.92;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
      };
      class AGM_GetInCargo {
        displayName = "$STR_AGM_GetInVehicleAsCargo";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target, -1] call AGM_GetIn_fnc_canGetInCargo";
        statement = "[_player, AGM_Interaction_Target, -1] call AGM_GetIn_fnc_getInCargo";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
      };
      class AGM_GetInCoDriver {
        displayName = "$STR_AGM_GetInVehicleAsCoDriver";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInCoDriver";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInCoDriver";
        showDisabled = 0;
        priority = -1.94;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
      };
    };
    class AGM_SelfActions {
      class AGM_MoveToDriver {
        displayName = "$STR_AGM_MoveToDriver";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInDriver";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInDriver";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToGunner {
        displayName = "$STR_AGM_MoveToGunner";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInGunner";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInGunner";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCommander {
        displayName = "$STR_AGM_MoveToCommander";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInCommander";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInCommander";
        showDisabled = 0;
        priority = -1.92;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCargo {
        displayName = "$STR_AGM_MoveToCargo";
        condition = "[_player, vehicle _player, -1] call AGM_GetIn_fnc_canGetInCargo";
        statement = "[_player, vehicle _player, -1] call AGM_GetIn_fnc_getInCargo";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCoDriver {
        displayName = "$STR_AGM_MoveToCoDriver";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInCoDriver";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInCoDriver";
        showDisabled = 0;
        priority = -1.94;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        enableInside = 1;
      };
    };
  };

  class Tank: LandVehicle {
    class AGM_Actions {
      class AGM_GetInDriver {
        displayName = "$STR_AGM_GetInVehicleAsDriver";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInDriver";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInDriver";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
      };
      class AGM_GetInGunner {
        displayName = "$STR_AGM_GetInVehicleAsGunner";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInGunner";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInGunner";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
      };
      class AGM_GetInCommander {
        displayName = "$STR_AGM_GetInVehicleAsCommander";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInCommander";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInCommander";
        showDisabled = 0;
        priority = -1.92;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
      };
      class AGM_GetInCargo {
        displayName = "$STR_AGM_GetInVehicleAsCargo";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target, -1] call AGM_GetIn_fnc_canGetInCargo";
        statement = "[_player, AGM_Interaction_Target, -1] call AGM_GetIn_fnc_getInCargo";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
      };
      class AGM_GetInCoDriver {
        displayName = "$STR_AGM_GetInVehicleAsCoDriver";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInCoDriver";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInCoDriver";
        showDisabled = 0;
        priority = -1.94;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
      };
    };
    class AGM_SelfActions {
      class AGM_MoveToDriver {
        displayName = "$STR_AGM_MoveToDriver";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInDriver";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInDriver";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToGunner {
        displayName = "$STR_AGM_MoveToGunner";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInGunner";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInGunner";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCommander {
        displayName = "$STR_AGM_MoveToCommander";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInCommander";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInCommander";
        showDisabled = 0;
        priority = -1.92;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCargo {
        displayName = "$STR_AGM_MoveToCargo";
        condition = "[_player, vehicle _player, -1] call AGM_GetIn_fnc_canGetInCargo";
        statement = "[_player, vehicle _player, -1] call AGM_GetIn_fnc_getInCargo";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCoDriver {
        displayName = "$STR_AGM_MoveToCoDriver";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInCoDriver";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInCoDriver";
        showDisabled = 0;
        priority = -1.94;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        enableInside = 1;
      };
    };
  };
  
  class Ship;
  class Ship_F: Ship {
    class AGM_Actions {
      class AGM_GetInDriver {
        displayName = "$STR_AGM_GetInVehicleAsDriver";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInDriver";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInDriver";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
      };
      class AGM_GetInGunner {
        displayName = "$STR_AGM_GetInVehicleAsGunner";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInGunner";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInGunner";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
      };
      class AGM_GetInCommander {
        displayName = "$STR_AGM_GetInVehicleAsCommander";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInCommander";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInCommander";
        showDisabled = 0;
        priority = -1.92;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
      };
      class AGM_GetInCargo {
        displayName = "$STR_AGM_GetInVehicleAsCargo";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target, -1] call AGM_GetIn_fnc_canGetInCargo";
        statement = "[_player, AGM_Interaction_Target, -1] call AGM_GetIn_fnc_getInCargo";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
      };
    };
    class AGM_SelfActions {
      class AGM_MoveToDriver {
        displayName = "$STR_AGM_MoveToDriver";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInDriver";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInDriver";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getindriver_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToGunner {
        displayName = "$STR_AGM_MoveToGunner";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInGunner";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInGunner";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCommander {
        displayName = "$STR_AGM_MoveToCommander";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInCommander";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInCommander";
        showDisabled = 0;
        priority = -1.92;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincommander_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCargo {
        displayName = "$STR_AGM_MoveToCargo";
        condition = "[_player, vehicle _player, -1] call AGM_GetIn_fnc_canGetInCargo";
        statement = "[_player, vehicle _player, -1] call AGM_GetIn_fnc_getInCargo";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        enableInside = 1;
      };
    };
  };
  
  class Air;
  class Plane: Air {
    class AGM_Actions {
      class AGM_GetInPilot {
        displayName = "$STR_AGM_GetInVehicleAsPilot";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInPilot";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInPilot";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
      };
      class AGM_GetInCoPilot {
        displayName = "$STR_AGM_GetInVehicleAsCoPilot";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInCoPilot";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInCoPilot";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
      };
      class AGM_GetInCargo {
        displayName = "$STR_AGM_GetInVehicleAsCargo";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target, -1] call AGM_GetIn_fnc_canGetInCargo";
        statement = "[_player, AGM_Interaction_Target, -1] call AGM_GetIn_fnc_getInCargo";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
      };
    };
    class AGM_SelfActions {
      class AGM_MoveToPilot {
        displayName = "$STR_AGM_MoveToPilot";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInPilot";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInPilot";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCoPilot {
        displayName = "$STR_AGM_MoveToCoPilot";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInCoPilot";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInCoPilot";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCargo {
        displayName = "$STR_AGM_MoveToCargo";
        condition = "[_player, vehicle _player, -1] call AGM_GetIn_fnc_canGetInCargo";
        statement = "[_player, vehicle _player, -1] call AGM_GetIn_fnc_getInCargo";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        enableInside = 1;
      };
    };
  };
  /*
  class Helicopter: Air {
    class AGM_Actions {
      class AGM_GetInPilot {
        displayName = "$STR_AGM_GetInVehicleAsPilot";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInPilot";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInPilot";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
      };
      class AGM_GetInCoPilot {
        displayName = "$STR_AGM_GetInVehicleAsCoPilot";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInCoPilot";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInCoPilot";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
      };
      class AGM_GetInDoorGunnerLeft {
        displayName = "$STR_AGM_GetInVehicleAsDoorGunnerLeft";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target, 0] call AGM_GetIn_fnc_canGetInDoorGunner";
        statement = "[_player, AGM_Interaction_Target, 0] call AGM_GetIn_fnc_getInDoorGunner";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
      };
      class AGM_GetInDoorGunnerRight {
        displayName = "$STR_AGM_GetInVehicleAsDoorGunnerRight";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target, 1] call AGM_GetIn_fnc_canGetInDoorGunner";
        statement = "[_player, AGM_Interaction_Target, 1] call AGM_GetIn_fnc_getInDoorGunner";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
      };
      class AGM_GetInCargo {
        displayName = "$STR_AGM_GetInVehicleAsCargo";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target, -1] call AGM_GetIn_fnc_canGetInCargo";
        statement = "[_player, AGM_Interaction_Target, -1] call AGM_GetIn_fnc_getInCargo";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
      };
    };
    class AGM_SelfActions {
      class AGM_MoveToPilot {
        displayName = "$STR_AGM_MoveToPilot";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInPilot";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInPilot";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCoPilot {
        displayName = "$STR_AGM_MoveToCoPilot";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInCoPilot";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInCoPilot";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCargo {
        displayName = "$STR_AGM_MoveToCargo";
        condition = "[_player, vehicle _player, -1] call AGM_GetIn_fnc_canGetInCargo";
        statement = "[_player, vehicle _player, -1] call AGM_GetIn_fnc_getInCargo";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        enableInside = 1;
      };
    };
  };
  */
  
  class Helicopter;
  class Helicopter_Base_F;
  class Helicopter_Base_H;
  
  // Attack
  class Heli_Attack_01_base_F: Helicopter_Base_F {
    class AGM_Actions {
      class AGM_GetInPilot {
        displayName = "$STR_AGM_GetInVehicleAsPilot";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInPilot";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInPilot";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
      };
      class AGM_GetInGunner {
        displayName = "$STR_AGM_GetInVehicleAsGunner";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInGunner";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInGunner";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
      };
    };
    class AGM_SelfActions {
      class AGM_MoveToPilot {
        displayName = "$STR_AGM_MoveToPilot";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInPilot";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInPilot";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToGunner {
        displayName = "$STR_AGM_MoveToGunner";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInGunner";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInGunner";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        enableInside = 1;
      };
    };
  };
  
  class Heli_Attack_02_base_F: Helicopter_Base_F {
    class AGM_Actions {
      class AGM_GetInPilot {
        displayName = "$STR_AGM_GetInVehicleAsPilot";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInPilot";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInPilot";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
      };
      class AGM_GetInGunner {
        displayName = "$STR_AGM_GetInVehicleAsGunner";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_canGetInGunner";
        statement = "[_player, AGM_Interaction_Target] call AGM_GetIn_fnc_getInGunner";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
      };
      class AGM_GetInCargo {
        displayName = "$STR_AGM_GetInVehicleAsCargo";
        distance = 4;
        condition = "[_player, AGM_Interaction_Target, -1] call AGM_GetIn_fnc_canGetInCargo";
        statement = "[_player, AGM_Interaction_Target, -1] call AGM_GetIn_fnc_getInCargo";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
      };
    };
    class AGM_SelfActions {
      class AGM_MoveToPilot {
        displayName = "$STR_AGM_MoveToPilot";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInPilot";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInPilot";
        showDisabled = 0;
        priority = -1.90;
        icon = "\A3\ui_f\data\igui\cfg\actions\getinpilot_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToGunner {
        displayName = "$STR_AGM_MoveToGunner";
        condition = "[_player, vehicle _player] call AGM_GetIn_fnc_canGetInGunner";
        statement = "[_player, vehicle _player] call AGM_GetIn_fnc_getInGunner";
        showDisabled = 0;
        priority = -1.91;
        icon = "\A3\ui_f\data\igui\cfg\actions\getingunner_ca.paa";
        enableInside = 1;
      };
      class AGM_MoveToCargo {
        displayName = "$STR_AGM_MoveToCargo";
        condition = "[_player, vehicle _player, -1] call AGM_GetIn_fnc_canGetInCargo";
        statement = "[_player, vehicle _player, -1] call AGM_GetIn_fnc_getInCargo";
        showDisabled = 0;
        priority = -1.93;
        icon = "\A3\ui_f\data\igui\cfg\actions\getincargo_ca.paa";
        enableInside = 1;
      };
    };
  };

  
  
};
