
// TMR Dispersion values.
// Based on the general specifications of the corresponding real world weapon
// plus a bit of inaccuracy to reflect that it's a service rifle,
// not a finely tuned civilian weapon (except for Marksman rifles).

// Full auto dispersion is increased even though fire mode 
// obviously doesn't affect inherent accuracy.

// What it does affect is trigger pull, and a sloppy full auto
// trigger is easily worth the increase in dispersion here even
// when firing single shots with Auto selected.
// That's what I think.

// Use Wolfram Alpha to convert radians to MOA easily.

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

		class Single : Mode_SemiAuto {
			dispersion = 0.000800; // radians. Equal to 2.75 MOA.
			// Based on widely cited 2 MOA figure for new 5.56 ACR.
		};
		class FullAuto : Mode_FullAuto {
			dispersion = 0.00147; // radians. Equal to 5.1 MOA.
		};
	};

	class arifle_MX_SW_Base_F : arifle_MX_Base_F {
		class Single : Single {
			dispersion = 0.000800; // radians. Equal to 2.75 MOA.
			// Based on widely cited 2 MOA figure for new 5.56 ACR.
		};
		class manual : FullAuto {
			dispersion = 0.00147; // radians. Equal to 5.1 MOA.
		};
	};

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

	class arifle_MXM_Base_F : arifle_MX_Base_F {
		class Single : Single {
			dispersion = 0.00029; // radians. Equal to 1 MOA.
			// 6.5mm is easily capable of this in a half-tuned rifle.
		};
		class FullAuto : FullAuto {
			dispersion = 0.000800; // radians. Equal to 2.75 MOA.
		};
	};

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

		class Single : Mode_SemiAuto {
			dispersion = 0.000800; // radians. Equal to 2.75 MOA.
			// Based on widely cited 2 MOA figure for new 5.56 ACR?
			// Use your imagination for fictional weapons!
		};
		class FullAuto : Mode_FullAuto {
			dispersion = 0.00147; // radians. Equal to 5.1 MOA.
		};
	};


	/* Other */

	class LMG_Mk200_F : Rifle_Long_Base_F {
		class manual : Mode_FullAuto {
			dispersion = 0.00175; // radians. Equal to 6 MOA.
		};
		class Single : manual {
			dispersion = 0.00175; // radians. Equal to 6 MOA.
		};
	};

	class LMG_Zafir_F : Rifle_Long_Base_F {
		class FullAuto : Mode_FullAuto {
			dispersion = 0.00175; // radians. Equal to 6 MOA.
		};
		class Single : Mode_SemiAuto {
			dispersion = 0.00175; // radians. Equal to 6 MOA.
		};
	};

	class Tavor_base_F : Rifle_Base_F {
		class Single : Mode_SemiAuto {
			dispersion = 0.000727; // radians. Equal to 2.5 MOA, about the limit of mass-produced M855.
			// 
		};
		class FullAuto : Mode_FullAuto {
			dispersion = 0.00147; // radians. Equal to 5.1 MOA.
		};
	};

	class mk20_base_F : Rifle_Base_F {
		class Single : Mode_SemiAuto {
			dispersion = 0.0008727; // radians. Equal to 3 MOA, about the limit of mass-produced M855 plus
			// some extra for these worn out Greek Army service rifles.
		};
		class FullAuto : Mode_FullAuto {
			dispersion = 0.00147; // radians. Equal to 5.1 MOA.
		};
	};

	class SDAR_base_F : Rifle_Base_F {
		class Single : Mode_SemiAuto {
			dispersion = 0.0008727; // radians. Equal to 3 MOA, about the limit of mass-produced M855 plus
			// some extra because Kel-Tec.
		};
		class FullAuto : Mode_FullAuto {
			dispersion = 0.00147; // radians. Equal to 5.1 MOA.
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
