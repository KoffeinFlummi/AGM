/*
	Name: AGM_Explosives_fnc_TriggerType
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Gets the types of triggers associated with the explosive
	
	Parameters:
		0: String - Explosive magazine
	
	Returns:
		ARRAY
			0 - Clacker support
			1 - Timer support
			2 - Cellphone support
	
	Example:
		_supports = ["SatchelCharge_Remote_Mag"] call AGM_Explosives_fnc_TriggerType;
*/
private ["_binary"];
_binary = [getNumber(configFile >> "CfgMagazines" >> (_this select 0) >> "AGM_Trigger"), 4] call AGM_Core_fnc_binarizeNumber;
_binary set [0, "X"];
_binary = _binary - ["X"];

_binary