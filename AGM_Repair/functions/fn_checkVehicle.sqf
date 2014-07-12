/*
* Author: marc_book
* This script isn't working correctly.
* Will be fixed as soon as possible.
*/

_vehicle = _this select 0;
_height = 1;
_string = format ["<t align='center' size='0.8'>%1: %2", localize "STR_AGM_Repair_Object", getText (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "displayName")];

if((_vehicle getHitPointDamage "HitLFWheel") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_L1Wheel_check";
	_height = _height + 0.5;
};

 if ((_vehicle getHitPointDamage "HitLF2Wheel") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_L2Wheel_check";
	_height = _height + 0.5;
};

 if ((_vehicle getHitPointDamage "HitRFWheel") > 0.1) then {
 	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_R1Wheel_check";
	_height = _height + 0.5;
};

if ((_vehicle getHitPointDamage "HitRF2Wheel") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_R2Wheel_check";
	_height = _height + 0.5;
};

if((_vehicle getHitPointDamage "HitLMWheel") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_L3Wheel_check";
	_height = _height + 0.5;
};

 if ((_vehicle getHitPointDamage "HitLBWheel") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_L4Wheel_check";
	_height = _height + 0.5;
};

 if ((_vehicle getHitPointDamage "HitRMWheel") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_R3Wheel_check";
	_height = _height + 0.5;
};

if ((_vehicle getHitPointDamage "HitRBWheel") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_R4Wheel_check";
	_height = _height + 0.5;
};

if ((_vehicle getHitPointDamage "HitEngine") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_Engine_check";
	_height = _height + 0.5;
};

if ((_vehicle getHitPointDamage "HitFuel") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_Fuel_check";
	_height = _height + 0.5;
};

if ((_vehicle getHitPointDamage "HitBody") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_Body_check";
	_height = _height + 0.5;
};

if ((_vehicle getHitPointDamage "HitHull") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_Body_check";
	_height = _height + 0.5;
};

if ((_vehicle getHitPointDamage "HitLTrack") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_LTrack_check";
	_height = _height + 0.5;
};

if ((_vehicle getHitPointDamage "HitRTrack") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_RTrack_check";
	_height = _height + 0.5;
};

if ((_vehicle getHitPointDamage "HitTurret") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_Turret_check";
	_height = _height + 0.5;
};

if ((_vehicle getHitPointDamage "HitGun") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_Gun_check";
	_height = _height + 0.5;
};

if ((_vehicle getHitPointDamage "HitAvionics") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_Avionics_check";
	_height = _height + 0.5;
};

if ((_vehicle getHitPointDamage "HitHRotor") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_HRotor_check";
	_height = _height + 0.5;
};

if ((_vehicle getHitPointDamage "HitVRotor") > 0.1) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_VRotor_check";
	_height = _height + 0.5;
};

if (_string == format ["<t align='center' size='0.8'>%1: %2", localize "STR_AGM_Repair_Object", getText (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "displayName")]) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_Nothing";
	_height = 1.5;
};

_string = _string + "</t>";
[composeText [lineBreak, parseText _string], _height] call AGM_Core_fnc_displayTextStructured;