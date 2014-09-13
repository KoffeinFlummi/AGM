// by commy2

private ["_count", "_index", "_action", "_statement", "_condition", "_conditionShow", "_exceptions", "_distance"];

_count = count AGM_Interaction_Buttons;
_index = call AGM_Interaction_fnc_getSelectedButton;

_action = if (_index != -1 && {_index < _count}) then {
	AGM_Interaction_Buttons select _index
} else {
	["", {}, {false}, 0, [], "", "", {false}, [], 0]
};

(findDisplay 1713999) closeDisplay 1;
closeDialog 0;
















_statement = _action select 1;
_condition = _action select 2;
_conditionShow = _action select 7;
_exceptions = _action select 8;//
_distance = _action select 9;

if ((_distance == 0 || {[AGM_Interaction_Target, _distance] call AGM_Interaction_fnc_isInRange}) && _condition && _conditionShow) then {
	call _statement;
};
