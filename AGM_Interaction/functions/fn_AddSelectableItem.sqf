/*
	Name: AGM_Interaction_fnc_AddSelectableItem
	
	Author: Garth de Wet (LH)
	
	Description:
		Adds an item to the select menu
	
	Parameters:
		0: ARRAY/NUMBER - List container
		1: String - Display Name
		2: String - Picture
		3: String/code - data
		
	Returns:
		ARRAY/Number
	
	Example:
*/
_container = _this select 0;
_displayName = _this select 1;
_picture = _this select 2;
_data = _this select 3;

if (_picture == "" || _picture == "PictureThing") then {
	_picture = "AGM_Interaction\UI\dot_ca.paa";
};

if ((profileNamespace getVariable ["AGM_Interaction_FlowMenu", false])) then {
	_container set [count _container, [_displayName, nil, {true}, 0,[], _picture, _data]];
}else{
	_index = lbAdd [_container, _displayName];
	lbSetData [_container, _index, str _data];
	lbSetPicture [_container, _index, _picture];
};

_container