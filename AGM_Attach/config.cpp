class CfgPatches {
  class AGM_Attach {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core, AGM_Interaction};
    version = "0.92";
    versionStr = "0.92";
    versionAr[] = {0,92,0};
    author[] = {"KoffeinFlummi", "eRazeri", "CAA-Picard"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

class CfgFunctions {
  class AGM_Attach {
    class AGM_Attach {
      file = "AGM_Attach\functions";
      class attach;
      class detach;
    };
  };
};

class CfgVehicles {
  class Man;
  class CAManBase: Man {
    class AGM_SelfActions {

      class AGM_Attach {
        displayName = "$STR_AGM_Attach_AttachDetach";
        condition = "canStand player && {alive player}";
        statement = "'AGM_Attach' call AGM_Interaction_fnc_openMenuSelf;";
        showDisabled = 1;
        priority = -10;

        class AGM_Attach_Detach {
          displayName = "$STR_AGM_Attach_Detach";
          condition = "canStand player && {alive player} && {player getVariable ['AGM_AttachedItemName', ''] != ''}";
          statement = "player call AGM_Attach_fnc_detach;";
          showDisabled = 1;
          priority = 10;
        };
        class AGM_Attach_IrStrobeB {
          displayName = "$STR_AGM_Attach_Attach_IrStrobe";
          condition = "canStand player && {alive player} && {player getVariable ['AGM_AttachedItemName', ''] == ''} && {'B_IR_Grenade' in magazines player}";
          statement = "[player, 'B_IR_Grenade'] call AGM_Attach_fnc_attach;";
          showDisabled = 0;
          priority = 9;
        };
        class AGM_Attach_IrStrobeO {
          displayName = "$STR_AGM_Attach_Attach_IrStrobe";
          condition = "canStand player && {alive player} && {player getVariable ['AGM_AttachedItemName', ''] == ''} && {'O_IR_Grenade' in magazines player} && {!('B_IR_Grenade' in magazines player)}";
          statement = "[player, 'O_IR_Grenade'] call AGM_Attach_fnc_attach;";
          showDisabled = 0;
          priority = 9;
        };
        class AGM_Attach_Chemlight_blue {
          displayName = "$STR_AGM_Attach_Attach_Chemlight_blue";
          condition = "canStand player && {alive player} && {player getVariable ['AGM_AttachedItemName', ''] == ''} && {'Chemlight_blue' in magazines player}";
          statement = "[player, 'Chemlight_blue'] call AGM_Attach_fnc_attach;";
          showDisabled = 0;
          priority = 8;
        };
        class AGM_Attach_Chemlight_green {
          displayName = "$STR_AGM_Attach_Attach_Chemlight_green";
          condition = "canStand player && {alive player} && {player getVariable ['AGM_AttachedItemName', ''] == ''} && {'Chemlight_green' in magazines player}";
          statement = "[player, 'Chemlight_green'] call AGM_Attach_fnc_attach;";
          showDisabled = 0;
          priority = 8;
        };
        class AGM_Attach_Chemlight_red {
          displayName = "$STR_AGM_Attach_Attach_Chemlight_red";
          condition = "canStand player && {alive player} && {player getVariable ['AGM_AttachedItemName', ''] == ''} && {'Chemlight_red' in magazines player}";
          statement = "[player, 'Chemlight_red'] call AGM_Attach_fnc_attach;";
          showDisabled = 0;
          priority = 8;
        };
        class AGM_Attach_Chemlight_yellow {
          displayName = "$STR_AGM_Attach_Attach_Chemlight_yellow";
          condition = "canStand player && {alive player} && {player getVariable ['AGM_AttachedItemName', ''] == ''} && {'Chemlight_yellow' in magazines player}";
          statement = "[player, 'Chemlight_yellow'] call AGM_Attach_fnc_attach;";
          showDisabled = 0;
          priority = 8;
        };
      };
    };
  };
};
