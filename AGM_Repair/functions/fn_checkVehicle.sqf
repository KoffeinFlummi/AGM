/*
* Author: marc_book
* This script isn't working correctly.
* Will be fixed as soon as possible.
*/

_vehicle = _this select 0;
_height = 1;
_string = format ["<t align='center' size='0.8'>%1: %2", localize "STR_AGM_Repair_Object", getText (configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "displayName")];

if((_vehicle getHitPointDamage "HitLFWheel") > 0.01) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_LFWheel_check";
	_height = _height + 0.5;
};
 if ((_vehicle getHitPointDamage "HitLF2Wheel") > 0.01) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_LBWheel_check";
	_height = _height + 0.5;
};
 if ((_vehicle getHitPointDamage "HitRFWheel") > 0.01) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_RFWheel_check";
	_height = _height + 0.5;
};
if ((_vehicle getHitPointDamage "HitRF2Wheel") > 0.01) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_RBWheel_check";
	_height = _height + 0.5;
};
if ((_vehicle getHitPointDamage "HitEngine") > 0.01) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_Engine_check";
	_height = _height + 0.5;
};
if ((_vehicle getHitPointDamage "HitFuel") > 0.01) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_Fuel_check";
	_height = _height + 0.5;
};
if ((_vehicle getHitPointDamage "HitBody") > 0.01) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_Body_check";
	_height = _height + 0.5;
};
if ((damage _vehicle) > 0.05) then {
	_string = _string + "<br/><br/>" + localize "STR_AGM_Repair_Nothing";
	_height = _height + 0.5;
};
_string = _string + "</t>";
[composeText [lineBreak, parseText _string], _height] call AGM_Core_fnc_displayTextStructured;