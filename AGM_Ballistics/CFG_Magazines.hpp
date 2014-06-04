
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
AGM_20Rnd_762x51_Mag_LR
*/

class CfgMagazines {
	class CA_Magazine;

	/* 6.5x39mm Grendel - MX */

	class 30Rnd_65x39_caseless_mag : CA_Magazine {
		initSpeed = 724; // initial MV for 14.5in barrel
	};

	class 30Rnd_65x39_caseless_mag_Tracer;

	class 100Rnd_65x39_caseless_mag : CA_Magazine {
		initSpeed = 724; // initial MV for 14.5in barrel
		// TODO: the MX SW has a longer barrel so should have a higher initial MV
	};

	class 200Rnd_65x39_cased_Box : 100Rnd_65x39_caseless_mag {
		initSpeed = 691; // initial MV for 12.5in barrel (estimated)
	};

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

	class 30Rnd_65x39_caseless_green : 30Rnd_65x39_caseless_mag {
		initSpeed = 724; // initial MV for 14.5in barrel
	};

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

	class 30Rnd_556x45_Stanag : CA_Magazine {
		initSpeed = 911; // Initial MV for a 16" barrel
	};

	class 30Rnd_556x45_Stanag_Tracer_Red;
		//picture = "\A3\weapons_f\data\ui\m_30stanag_red_ca.paa";
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

	class 20Rnd_762x51_Mag: CA_Magazine {
		ammo = "B_762x51_Ball";
		initSpeed = 853; // Typical MV for M240
	};

	class 150Rnd_762x51_Box : CA_Magazine {
		ammo = "B_762x51_Ball";
		initSpeed = 853; // Typical MV for M240
	};

	class AGM_20Rnd_762x51_Mag_Tracer : 20Rnd_762x51_Mag {
		ammo = "B_762x51_Tracer_Red";
		//displayName = "$STR_BWA3_G36MagTracerDimName";
		//displayNameShort = "$STR_BWA3_G36MagTracerDimNameShort";
		//descriptionShort = "$STR_BWA3_G36MagTracerDimDescription";
		tracersEvery = 1;
	};
	class AGM_20Rnd_762x51_Mag_Tracer_Dim : AGM_20Rnd_762x51_Mag_Tracer {
		ammo = "AGM_B_762x51_Tracer_Dim";
		//displayName = "$STR_BWA3_G36MagTracerDimName";
		//displayNameShort = "$STR_BWA3_G36MagTracerDimNameShort";
		//descriptionShort = "$STR_BWA3_G36MagTracerDimDescription";
	};
	class AGM_20Rnd_762x51_Mag_SD : 20Rnd_762x51_Mag {
		ammo = "AGM_B_762x51_Ball_SD";
		//displayName = "$STR_BWA3_G36MagSDName";
		//displayNameShort = "$STR_BWA3_G36MagSDNameShort";
		//descriptionShort = "$STR_BWA3_G36MagSDDescription";
		initSpeed = 320;
	};
	class AGM_20Rnd_762x51_Mag_AP : 20Rnd_762x51_Mag {
		ammo = "AGM_B_762x51_Ball_AP";
		//displayName = "$STR_BWA3_G36MagAPName";
		//displayNameShort = "$STR_BWA3_G36MagAPNameShort";
		//descriptionShort = "$STR_BWA3_G36MagAPDescription";
	};

	class AGM_20Rnd_762x51_Mag_LR : 20Rnd_762x51_Mag {
		descriptionshort = "$STR_AGM_Ballistics_20Rnd_762x51_Mag_Description";
		initSpeed = 792; // 18" M14 EBR barrel
		ammo = "AGM_B_762x51_M118LR"; // Use M118LR
	};


	/* Other */

	// Override the 9x21 mags to have 9x19 in them. Banish 9x21 to hell.
	class 30Rnd_9x21_Mag : CA_Magazine {
		ammo = "B_9x19_Ball";
		initSpeed = 370; // Scorpion Evo 3A1 muzzle velocity according to CZ's manual
		// Why is it so low, lower than a Glock? I'm not sure, but I have no choice but to believe them...!
		// Maybe they are shooting some heavier bullet and not saying.
	};

	class 16Rnd_9x21_Mag : CA_Magazine {
		ammo = "B_9x19_Ball";
		// M9 initial MV. Close enough for horseshoes and handguns.
		initSpeed = 381;
	};

	class 30Rnd_45ACP_Mag_SMG_01 : CA_Magazine {
		initSpeed = 259; // From Vector manual (5.5" barrel)
	};

	class 9Rnd_45ACP_Mag : 30Rnd_45ACP_Mag_SMG_01 {
		initSpeed = 250; // 1911
	};
};
