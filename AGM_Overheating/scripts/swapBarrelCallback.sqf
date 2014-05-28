// by commy2

_weapon = _this select 0;

player removeItem "AGM_SpareBarrel";

[formatText ["%1%2%3", parseText "<img size='2' color='#ffffff' image='\AGM_Overheating\UI\spare_barrel_ca.paa'/>", lineBreak, localize "STR_AGM_Overheating_SwappedBarrel"]] call AGM_Core_fnc_displayText;

player setVariable [format ["AGM_Overheating_%1", _weapon], [0, 0], false];
