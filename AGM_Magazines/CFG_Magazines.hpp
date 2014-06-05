
// NEW CLASSES
/*
AGM_30Rnd_65x39_caseless_mag_Tracer_Dim
AGM_30Rnd_65x39_caseless_mag_SD
AGM_30Rnd_65x39_caseless_mag_AP

AGM_30Rnd_65x39_caseless_green_mag_Tracer_Dim
AGM_30Rnd_65x39_caseless_green_mag_SD
AGM_30Rnd_65x39_caseless_green_mag_AP

AGM_30Rnd_556x45_Stanag_Tracer_Dim
AGM_30Rnd_556x45_Stanag_SD
AGM_30Rnd_556x45_Stanag_AP

AGM_20Rnd_762x51_Mag_Tracer
AGM_20Rnd_762x51_Mag_Tracer_Dim
AGM_20Rnd_762x51_Mag_SD
AGM_20Rnd_762x51_Mag_AP
*/

class CfgMagazines {

	/* 6.5x39mm Grendel - MX */

	class 30Rnd_65x39_caseless_mag;
	class 30Rnd_65x39_caseless_mag_Tracer;

	class AGM_30Rnd_65x39_caseless_mag_Tracer_Dim : 30Rnd_65x39_caseless_mag_Tracer {
		ammo = "AGM_B_65x39_Caseless_Tracer_Dim";
		displayName = "$STR_AGM_30Rnd_65x39_caseless_mag_Tracer_DimName";
		displayNameShort = "$STR_AGM_30Rnd_65x39_caseless_mag_Tracer_DimNameShort";
		descriptionShort = "$STR_AGM_30Rnd_65x39_caseless_mag_Tracer_DimDescription";
		picture = "\A3\weapons_f\data\ui\m_30stanag_caseless_yellow_CA.paa";
	};
	class AGM_30Rnd_65x39_caseless_mag_SD : 30Rnd_65x39_caseless_mag {
		ammo = "AGM_B_65x39_Caseless_SD";
		displayName = "$STR_AGM_30Rnd_65x39_caseless_mag_SDName";
		displayNameShort = "$STR_AGM_30Rnd_65x39_caseless_mag_SDNameShort";
		descriptionShort = "$STR_AGM_30Rnd_65x39_caseless_mag_SDDescription";
		picture = "\A3\weapons_f\data\ui\m_30stanag_caseless_green_CA.paa";
		initSpeed = 320;
	};
	class AGM_30Rnd_65x39_caseless_mag_AP : 30Rnd_65x39_caseless_mag {
		ammo = "AGM_B_65x39_Caseless_AP";
		displayName = "$STR_AGM_30Rnd_65x39_caseless_mag_APName";
		displayNameShort = "$STR_AGM_30Rnd_65x39_caseless_mag_APNameShort";
		descriptionShort = "$STR_AGM_30Rnd_65x39_caseless_mag_APDescription";
	};


	/* 6.5x39mm Grendel - Katiba */

	class 30Rnd_65x39_caseless_green;
	class 30Rnd_65x39_caseless_green_mag_Tracer;

	class AGM_30Rnd_65x39_caseless_green_mag_Tracer_Dim : 30Rnd_65x39_caseless_green_mag_Tracer {
		ammo = "AGM_B_65x39_Caseless_Tracer_Dim";
		displayName = "$STR_AGM_30Rnd_65x39_caseless_green_mag_Tracer_DimName";
		displayNameShort = "$STR_AGM_30Rnd_65x39_caseless_green_mag_Tracer_DimNameShort";
		descriptionShort = "$STR_AGM_30Rnd_65x39_caseless_green_mag_Tracer_DimDescription";
	};
	class AGM_30Rnd_65x39_caseless_green_mag_SD : 30Rnd_65x39_caseless_green {
		ammo = "AGM_B_65x39_Caseless_SD";
		displayName = "$STR_AGM_30Rnd_65x39_caseless_green_mag_SDName";
		displayNameShort = "$STR_AGM_30Rnd_65x39_caseless_green_mag_SDNameShort";
		descriptionShort = "$STR_AGM_30Rnd_65x39_caseless_green_mag_SDDescription";
		initSpeed = 320;
	};
	class AGM_30Rnd_65x39_caseless_green_mag_AP : 30Rnd_65x39_caseless_green {
		ammo = "AGM_B_65x39_Caseless_AP";
		displayName = "$STR_AGM_30Rnd_65x39_caseless_green_mag_APName";
		displayNameShort = "$STR_AGM_30Rnd_65x39_caseless_green_mag_APNameShort";
		descriptionShort = "$STR_AGM_30Rnd_65x39_caseless_green_mag_APDescription";
	};


	/* 5.56x45mm NATO */

	class 30Rnd_556x45_Stanag;
	class 30Rnd_556x45_Stanag_Tracer_Red;	//picture = "\A3\weapons_f\data\ui\m_30stanag_red_ca.paa";

	class AGM_30Rnd_556x45_Stanag_Tracer_Dim : 30Rnd_556x45_Stanag_Tracer_Red {
		ammo = "AGM_B_556x45_Ball_Tracer_Dim";
		displayName = "$STR_AGM_30Rnd_556x45_mag_Tracer_DimName";
		displayNameShort = "$STR_AGM_30Rnd_556x45_mag_Tracer_DimNameShort";
		descriptionShort = "$STR_AGM_30Rnd_556x45_mag_Tracer_DimDescription";
		picture = "\A3\weapons_f\data\ui\m_30stanag_yellow_ca.paa";
	};
	class AGM_30Rnd_556x45_Stanag_SD : 30Rnd_556x45_Stanag {
		ammo = "AGM_B_556x45_Ball_SD";
		displayName = "$STR_AGM_30Rnd_556x45_mag_SDName";
		displayNameShort = "$STR_AGM_30Rnd_556x45_mag_SDNameShort";
		descriptionShort = "$STR_AGM_30Rnd_556x45_mag_SDDescription";
		initSpeed = 320;
		picture = "\A3\weapons_f\data\ui\m_30stanag_green_ca.paa";
	};
	class AGM_30Rnd_556x45_Stanag_AP : 30Rnd_556x45_Stanag {
		ammo = "AGM_B_556x45_Ball_AP";
		displayName = "$STR_AGM_30Rnd_556x45_mag_APName";
		displayNameShort = "$STR_AGM_30Rnd_556x45_mag_APNameShort";
		descriptionShort = "$STR_AGM_30Rnd_556x45_mag_APDescription";
	};


	/* 7.62x51mm NATO */

	class 20Rnd_762x51_Mag;

	class AGM_20Rnd_762x51_Mag_Tracer : 20Rnd_762x51_Mag {	//@todo Green tracers for opfor and yellow tracers for independent
		ammo = "B_762x51_Tracer_Red";
		displayName = "$STR_AGM_20Rnd_762x51_mag_TracerName";
		displayNameShort = "$STR_AGM_20Rnd_762x51_mag_TracerNameShort";
		descriptionShort = "$STR_AGM_20Rnd_762x51_mag_TracerDescription";
		tracersEvery = 1;
	};
	class AGM_20Rnd_762x51_Mag_Tracer_Dim : AGM_20Rnd_762x51_Mag_Tracer {
		ammo = "AGM_B_762x51_Tracer_Dim";
		displayName = "$STR_AGM_20Rnd_762x51_mag_Tracer_DimName";
		displayNameShort = "$STR_AGM_20Rnd_762x51_mag_Tracer_DimNameShort";
		descriptionShort = "$STR_AGM_20Rnd_762x51_mag_Tracer_DimDescription";
	};
	class AGM_20Rnd_762x51_Mag_SD : 20Rnd_762x51_Mag {
		ammo = "AGM_B_762x51_Ball_SD";
		displayName = "$STR_AGM_20Rnd_762x51_mag_SDName";
		displayNameShort = "$STR_AGM_20Rnd_762x51_mag_SDNameShort";
		descriptionShort = "$STR_AGM_20Rnd_762x51_mag_SDDescription";
		initSpeed = 320;
	};
	class AGM_20Rnd_762x51_Mag_AP : 20Rnd_762x51_Mag {
		ammo = "AGM_B_762x51_Ball_AP";
		displayName = "$STR_AGM_20Rnd_762x51_mag_APName";
		displayNameShort = "$STR_AGM_20Rnd_762x51_mag_APNameShort";
		descriptionShort = "$STR_AGM_20Rnd_762x51_mag_APDescription";
	};


	/* Other */

	class 30Rnd_9x21_Mag;
	class 16Rnd_9x21_Mag;
	class 30Rnd_45ACP_Mag_SMG_01;
	class 9Rnd_45ACP_Mag;
};
