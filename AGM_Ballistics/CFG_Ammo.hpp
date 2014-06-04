
// NEW CLASSES
/*
AGM_B_65x39_Caseless_Tracer_Dim
AGM_B_65x39_Caseless_SD
AGM_B_65x39_Caseless_AP

AGM_B_65x39_Case_Tracer_Dim
AGM_B_65x39_Case_SD
AGM_B_65x39_Case_AP

AGM_B_556x45_Ball_Tracer_Dim
AGM_B_556x45_Ball_SD
AGM_B_556x45_Ball_AP

AGM_B_762x51_Tracer_Dim
AGM_B_762x51_Ball_SD
AGM_B_762x51_Ball_AP
AGM_B_762x51_M118LR
*/

class CfgAmmo {
	class BulletBase;

	/* 6.5x39mm Grendel */

	class B_65x39_Caseless : BulletBase {
		// Nosler 120gr Ballistic Tip
		// http://www.nosler.com/ballistic-tip/
		// 0.264 bullet diameter
		// BC 0.458
		// SD 0.246
		// Fired from 14.5 in barrel
		// Ref data calculated by Shooter Android app at alt: 0ft, hg: 29.92, temp 80 F, 0% humidity

		// Pretend MX has 1:7.5 twist barrel

		typicalSpeed = 724;

		// Determining experimentally with arma_bal.py (best match to subsonic using Shooter)
		airFriction = -0.000915;
	};

	// IR Dim
	class B_65x39_Caseless_yellow;
	class AGM_B_65x39_Caseless_Tracer_Dim : B_65x39_Caseless_yellow {
		nvgOnly = 1;
	};
	class B_65x39_Case_yellow;
	class AGM_B_65x39_Case_Tracer_Dim : B_65x39_Case_yellow {
		nvgOnly = 1;
	};

	// sub sonic
	class AGM_B_65x39_Caseless_SD : B_65x39_Caseless {
		airFriction = -0.00054;
		hit = 8.75;
		supersonicCrackFar[] = {};
		supersonicCrackNear[] = {};
		typicalSpeed = 320;
		audibleFire = 0.8;
		visibleFire = 2.5;
	};
	class B_65x39_Case;
	class AGM_B_65x39_Case_SD : B_65x39_Case {
		airFriction = -0.00054;
		hit = 8.75;
		supersonicCrackFar[] = {};
		supersonicCrackNear[] = {};
		typicalSpeed = 320;
		audibleFire = 0.8;
		visibleFire = 2.5;
	};

	// armor piercing
	class AGM_B_65x39_Caseless_AP : B_65x39_Caseless {
		caliber = 1.8;
		hit = 10.5;
	};
	class AGM_B_65x39_Case_AP : B_65x39_Case {
		caliber = 1.8;
		hit = 10.5;
	};


	/* 5.56x45mm NATO */

	class B_556x45_Ball : BulletBase {
		// SS109 bullet steel core light penetrator
		// M855 load data
		// Muzzle velocity based on 16" barrel (standard for F2000)
		typicalSpeed = 911; // http://counterstrikefox.freeservers.com/mv.htm
		airFriction = -0.001335;
	};

	// IR Dim
	class B_556x45_Ball_Tracer_Red;
	class AGM_B_556x45_Ball_Tracer_Dim : B_556x45_Ball_Tracer_Red {
		nvgOnly = 1;
	};

	// sub sonic
	class AGM_B_556x45_Ball_SD : B_556x45_Ball {
		airFriction = -0.0006;
		hit = 7;
		supersonicCrackFar[] = {};
		supersonicCrackNear[] = {};
		typicalSpeed = 320;
		audibleFire = 0.6;
		visibleFire = 2.0;
	};

	// armor piercing
	class AGM_B_556x45_Ball_AP : B_556x45_Ball {
		caliber = 1.4;
		hit = 8.4;
	};


	/* 7.62x51mm NATO */

	class B_762x51_Ball: BulletBase {
		typicalSpeed = 853; // Typical muzzle velocity of M240

		// TODO: Correct airfriction for 7.62x51mm M80
	};

	// IR Dim
	class B_762x51_Tracer_Red;
	class AGM_B_762x51_Tracer_Dim : B_762x51_Tracer_Red {
		nvgOnly = 1;
	};

	// sub sonic
	class AGM_B_762x51_Ball_SD : B_762x51_Ball {
		airFriction = -0.00048;
		hit = 10.5;
		supersonicCrackFar[] = {};
		supersonicCrackNear[] = {};
		typicalSpeed = 320;
		audibleFire = 0.9;
		visibleFire = 3.0;
	};

	// armor piercing
	class AGM_B_762x51_Ball_AP : B_762x51_Ball {
		caliber = 2.4;
		hit = 12.6;
	};

	// long range
	class AGM_B_762x51_M118LR : B_762x51_Ball {
		// http://www.snipercentral.com/m118.phtml
		// 175gr Sierra HPBT MatchKing
		// 1:12" rifling twist (probably, some civilian shooters like 1:10" for heavies)
		// Mk14 Mod 1 barrel velocity of about 2600fps (18")
		// http://www.militaryfactory.com/smallarms/detail.asp?smallarms_id=377

		typicalspeed = 792;

		// Determining experimentally with arma_bal.py (close match at 500m to ballistic calc data)
		airfriction = -0.0008577;
	};


	/* Other */

	// I will never understand WTF BI was thinking when they did this 9x21mm IMI bullshit.
	class B_9x21_Ball;
	class B_9x19_Ball : B_9x21_Ball {
		// Cartridge: 9mm US M882 ball
		// Bullet weight: 124 grains
		// Bullet velocity: 1251fps +/- 25
		// BC 0.160 123 gr round nose FMJ

		typicalSpeed = 381;

		// Determined with armabal.py (close ballistic match at 100 meters)
		airfriction = -0.00213;
	};

	class B_45ACP_Ball: BulletBase {
		// 230 gr (15 g) US Army Ball FMJ	830 ft/s (250 m/s)

		// 230gr round nose FMJ
		// Ballistic Coefficient (G1)	0.184
		// Sectional Density	0.162
		typicalSpeed = 250;

		// Determined with armabal.py (close ballistic match at 100 meters)
		airfriction = -0.0009;
	};
};
