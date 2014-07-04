/*
* Author: marc_book
* This script isn't working correctly.
* Will be fixed as soon as possible.
*/

_vehicle = _this select 0;
_string = "";

if ((damage _vehicle) > 0.001) then {
	if((_vehicle getHitPointDamage "HitLFWheel") > 0.01) then {
		_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_LFWheel_check";
	};
	 if ((_vehicle getHitPointDamage "HitLF2Wheel") > 0.01) then {
	 	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_LBWheel_check";
	};
	 if ((_vehicle getHitPointDamage "HitRFWheel") > 0.01) then {
		_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_RFWheel_check";
	};
	if ((_vehicle getHitPointDamage "HitRF2Wheel") > 0.01) then {
		_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_RBWheel_check";
	};
	if ((_vehicle getHitPointDamage "HitEngine") > 0.01) then {
		_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_Engine_check";
	};
	if ((_vehicle getHitPointDamage "HitFuel") > 0.01) then {
		_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_Fuel_check";
	};
	if ((_vehicle getHitPointDamage "HitBody") > 0.01) then {
		_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_Body_check";
	};
} else {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_Nothing";
};

[composeText [lineBreak, parseText _string]] call AGM_Core_fnc_displayTextStructured;