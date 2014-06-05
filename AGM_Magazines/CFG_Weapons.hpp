
class Mode_SemiAuto;
class Mode_FullAuto;

class CfgWeapons {
	class Rifle_Base_F;
	class Rifle_Long_Base_F;


	/* MX */

	class arifle_MX_Base_F : Rifle_Base_F {
		magazines[] = {
			"30Rnd_65x39_caseless_mag",
			"30Rnd_65x39_caseless_mag_Tracer",
			"AGM_30Rnd_65x39_caseless_mag_Tracer_Dim",
			"AGM_30Rnd_65x39_caseless_mag_SD",
			"AGM_30Rnd_65x39_caseless_mag_AP",
			"100Rnd_65x39_caseless_mag",
			"100Rnd_65x39_caseless_mag_Tracer"
		};
	};

	class arifle_MX_SW_Base_F;
	class arifle_MX_SW_F : arifle_MX_SW_Base_F {
		magazines[] = {
			"30Rnd_65x39_caseless_mag",
			"30Rnd_65x39_caseless_mag_Tracer",
			"AGM_30Rnd_65x39_caseless_mag_Tracer_Dim",
			"AGM_30Rnd_65x39_caseless_mag_SD",
			"AGM_30Rnd_65x39_caseless_mag_AP",
			"100Rnd_65x39_caseless_mag",
			"100Rnd_65x39_caseless_mag_Tracer"
		};
	};

	class arifle_MXM_Base_F;
	class arifle_MXM_F : arifle_MXM_Base_F {
		magazines[] = {
			"30Rnd_65x39_caseless_mag",
			"30Rnd_65x39_caseless_mag_Tracer",
			"AGM_30Rnd_65x39_caseless_mag_Tracer_Dim",
			"AGM_30Rnd_65x39_caseless_mag_SD",
			"AGM_30Rnd_65x39_caseless_mag_AP",
			"100Rnd_65x39_caseless_mag",
			"100Rnd_65x39_caseless_mag_Tracer"
		};
	};


	/* Katiba */

	class arifle_katiba_Base_F : Rifle_Base_F {
		magazines[] = {
			"30Rnd_65x39_caseless_green",
			"30Rnd_65x39_caseless_green_mag_Tracer",
			"AGM_30Rnd_65x39_caseless_green_mag_Tracer_Dim",
			"AGM_30Rnd_65x39_caseless_green_mag_SD",
			"AGM_30Rnd_65x39_caseless_green_mag_AP"
		};
	};


	/* Other */

	class LMG_Mk200_F;
	class LMG_Zafir_F;
	class Tavor_base_F : Rifle_Base_F {
		magazines[] = {
			"20Rnd_556x45_UW_mag",
			"30Rnd_556x45_Stanag",
			"30Rnd_556x45_Stanag_Tracer_Red",
			"30Rnd_556x45_Stanag_Tracer_Green",
			"30Rnd_556x45_Stanag_Tracer_Yellow",
			"AGM_30Rnd_556x45_Stanag_Tracer_Dim",
			"AGM_30Rnd_556x45_Stanag_SD",
			"AGM_30Rnd_556x45_Stanag_AP"
		};
	};
	class mk20_base_F : Rifle_Base_F {
		magazines[] = {
			"30Rnd_556x45_Stanag",
			"30Rnd_556x45_Stanag_Tracer_Red",
			"30Rnd_556x45_Stanag_Tracer_Green",
			"30Rnd_556x45_Stanag_Tracer_Yellow",
			"AGM_30Rnd_556x45_Stanag_Tracer_Dim",
			"AGM_30Rnd_556x45_Stanag_SD",
			"AGM_30Rnd_556x45_Stanag_AP"
		};
	};
	class SDAR_base_F : Rifle_Base_F {
		magazines[] = {
			"30Rnd_556x45_Stanag",
			"30Rnd_556x45_Stanag_Tracer_Red",
			"30Rnd_556x45_Stanag_Tracer_Green",
			"30Rnd_556x45_Stanag_Tracer_Yellow",
			"AGM_30Rnd_556x45_Stanag_Tracer_Dim",
			"AGM_30Rnd_556x45_Stanag_SD",
			"AGM_30Rnd_556x45_Stanag_AP"
		};
	};


	/* Silencers */
	class ItemCore;
	class InventoryMuzzleItem_Base_F;

	class muzzle_snds_H: ItemCore {
		class ItemInfo: InventoryMuzzleItem_Base_F {
			class MagazineCoef {
				initSpeed = 1.0;
			};

			class AmmoCoef {
				hit = 0.9;
				visibleFire = 0.5;
				audibleFire = 0.1;
				visibleFireTime = 0.5;
				audibleFireTime = 0.5;
				cost = 1.0;
				typicalSpeed = 1.0;
				airFriction = 1.0;
			};
		};
	};

	class muzzle_snds_L: muzzle_snds_H {
		class ItemInfo: InventoryMuzzleItem_Base_F {
			class MagazineCoef {
				initSpeed = 1.0;
			};

			class AmmoCoef {
				hit = 0.9;
				visibleFire = 0.5;
				audibleFire = 0.1;
				visibleFireTime = 0.5;
				audibleFireTime = 0.5;
				cost = 1.0;
				typicalSpeed = 1.0;
				airFriction = 1.0;
			};
		};
	};

	class muzzle_snds_M: muzzle_snds_H {
		class ItemInfo: InventoryMuzzleItem_Base_F {
			class MagazineCoef {
				initSpeed = 1.0;
			};

			class AmmoCoef {
				hit = 0.9;
				visibleFire = 0.5;
				audibleFire = 0.1;
				visibleFireTime = 0.5;
				audibleFireTime = 0.5;
				cost = 1.0;
				typicalSpeed = 1.0;
				airFriction = 1.0;
			};
		};
	};

	class muzzle_snds_B: muzzle_snds_H {
		class ItemInfo: InventoryMuzzleItem_Base_F {
			class MagazineCoef {
				initSpeed = 1.0;
			};

			class AmmoCoef {
				hit = 0.9;
				visibleFire = 0.5;
				audibleFire = 0.1;
				visibleFireTime = 0.5;
				audibleFireTime = 0.5;
				cost = 1.0;
				typicalSpeed = 1.0;
				airFriction = 1.0;
			};
		};
	};

	class muzzle_snds_H_MG: muzzle_snds_H {
		class ItemInfo: InventoryMuzzleItem_Base_F {
			class MagazineCoef {
				initSpeed = 1.0;
			};

			class AmmoCoef {
				hit = 0.9;
				visibleFire = 0.5;
				audibleFire = 0.1;
				visibleFireTime = 0.5;
				audibleFireTime = 0.5;
				cost = 1.0;
				typicalSpeed = 1.0;
				airFriction = 1.0;
			};
		};
	};

	class muzzle_snds_H_SW: muzzle_snds_H_MG {
		class ItemInfo: InventoryMuzzleItem_Base_F {
			class MagazineCoef {
				initSpeed = 1.0;
			};

			class AmmoCoef {
				hit = 0.9;
				visibleFire = 0.5;
				audibleFire = 0.1;
				visibleFireTime = 0.5;
				audibleFireTime = 0.5;
				cost = 1.0;
				typicalSpeed = 1.0;
				airFriction = 1.0;
			};
		};
	};
};
