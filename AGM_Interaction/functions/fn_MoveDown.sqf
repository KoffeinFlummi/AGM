/*
	Name: AGM_Interaction_fnc_MoveDown
	
	Author: Garth de Wet (LH)
	
	Description:
		Depending on the passed value, either scrolls down through the list or up.
	
	Parameters: 
		BOOLEAN - Move down or move up
	
	Returns:
		Nothing
	
	Example:
		false call AGM_Interaction_fnc_MoveDown;
*/
#define CLAMP(x,low,high) (if(x > high)then{high}else{if(x < low)then{low}else{x}})
_count = (count AGM_Interaction_Buttons)-1;
if (_this) then {
	AGM_Interaction_Current = AGM_Interaction_Current + 1;
} else {
	AGM_Interaction_Current = AGM_Interaction_Current - 1;
};
AGM_Interaction_Current = CLAMP(AGM_Interaction_Current, 0, _count);

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
		_ctrl ctrlSetTextColor (if(call (_action select 2)) then {[1,1,1,1]}else{[0.5,0.5,0.5,1]});
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