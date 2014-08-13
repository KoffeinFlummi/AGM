// by commy2

private ["_count", "_index", "_action"];

_count = count AGM_Interaction_Buttons;
_index = call AGM_Interaction_fnc_getSelectedButton;

_action = if (_index != -1 && {_index < _count}) then {
	AGM_Interaction_Buttons select _index
} else {
	["", {false}, {}, 0, ""]
};

if ((_action select 4) == "") then {
	(findDisplay 1713999) closeDisplay 1;
	closeDialog 0;
} else {
	systemChat (_action select 4);
};

if (call (_action select 2)) then {
	call (_action select 1);
};
