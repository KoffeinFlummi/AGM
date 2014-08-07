/*
	Name: AGM_Interaction_fnc_openSelectMenu
	
	Author: Garth de Wet (LH)
	
	Description:
		Opens the select menu UI and sets up the UI
	
	Parameters: 
		0: TEXT - Header text
		1: TEXT - Approve button text
		2: TEXT - Code (as text) to run when approve button is selected
	
	Returns:
		Nothing
	
	Example:
		["Select Explosive", "Place", "_selectedExplosive = lbData [8866, lbCurSel 8866];"] call AGM_Interaction_fnc_openSelectMenu;
		// Check AGM_explosives_fnc_openPlaceUI for actual use.
*/
private ["_buttonAction", "_header", "_buttonText", "_cancelButton"];
_header = _this select 0;
_buttonText = _this select 1;
_buttonAction = _this select 2;
_cancelButton = "closeDialog 0;";
if (count _this > 3) then {
	_cancelButton = _this select 3;
};

if (isNil "_buttonText" or {_buttonText == ""}) then {
	_buttonText = localize "STR_AGM_Interaction_MakeSelection";
};

createDialog "RscAGM_SelectAnItem";

buttonSetAction [8860, _buttonAction];
buttonSetAction [8855, _cancelButton];
ctrlSetText [8860, _buttonText];
ctrlSetText [8870, _header];

lbClear 8866;

8866