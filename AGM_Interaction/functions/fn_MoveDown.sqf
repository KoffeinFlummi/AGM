/*
	Name: AGM_Interaction_fnc_MoveDown
	
	Author: Garth de Wet (LH)
	
	Description:
		Depending on the passed value, either scrolls down through the list or up.
	
	Parameters: 
		NUMBER - Amount to increase current interaction target
	
	Returns:
		Nothing
	
	Example:
		1 call AGM_Interaction_fnc_MoveDown;
		-1 call AGM_Interaction_fnc_MoveDown;
*/
#define CLAMP(x,low,high) (if(x > high)then{high}else{if(x < low)then{low}else{x}})
if (isNil "AGM_Interaction_MainButton") exitWith{};
if (isNil "AGM_Interaction_Buttons") exitWith{};
_count = (count AGM_Interaction_Buttons)- 1;
AGM_Interaction_Current = CLAMP(AGM_Interaction_Current + _this, 0, _count);

disableSerialization;
_dlgInteractionDialog = uiNamespace getVariable "Interaction_Display";
_middle = AGM_Interaction_current - 2;
_i = 0;
while {_i <= 4} do {
	_index =_i + _middle;
	_ctrl = _dlgInteractionDialog displayCtrl (1200 + _i);
	if (_index >= 0 && {_index <= _count}) then {
		_action = AGM_Interaction_Buttons select _index;
		_ctrl ctrlShow true;
		_ctrl ctrlSetText (_action select 4);
		if (!call (_action select 2)) then {
			_ctrl ctrlSetTextColor [0.3,0.3,0.3,0.8];
		};
	}else{
		_ctrl ctrlShow false;
	};
	_i = _i + 1;
};

_ctrl = _dlgInteractionDialog displayCtrl 1000;
_ctrl ctrlSetText ((AGM_Interaction_Buttons select AGM_Interaction_Current) select 0);
_ctrl = _dlgInteractionDialog displayCtrl 1100;
_current = (AGM_Interaction_Buttons select AGM_Interaction_Current);
if (!call (_current select 2)) then {
	_ctrl ctrlSetText "Unavailable";
}else {
	_ctrl ctrlSetText "";
};