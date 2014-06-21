// SEE LICENSE.TXT FOR LICENSING INFORMATION

class CfgPatches {
	class AGM_Magazines {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.60;
		requiredAddons[] = {A3_Weapons_F, A3_Weapons_F_beta, A3_Weapons_F_Acc, A3_Weapons_F_Beta_Acc, A3_Characters_F, A3_Weapons_F_EPA_Ammoboxes, A3_Weapons_F_EPB_Ammoboxes};
        version = "0.91";
        versionStr = "0.91";
        versionAr[] = {0,91,0};
        author[] = {"commy2"};
        authorUrl = "https://github.com/commy2";
    };
};

#include <CFG_Ammo.hpp>
#include <CFG_Magazines.hpp>
#include <CFG_Weapons.hpp>
#include <CFG_Vehicles.hpp>
