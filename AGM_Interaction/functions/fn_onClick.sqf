// by commy2

private ["_count", "_index", "_action", "_subMenu"];

_count = count AGM_Interaction_Buttons;
_index = call AGM_Interaction_fnc_getSelectedButton;

_action = if (_index != -1 && {_index < _count}) then {
	AGM_Interaction_Buttons select _index
} else {
	["", {false}, {}, 0, []]
};

_subMenu = _action select 4;

if (count _subMenu < 2) then {
	(findDisplay 1713999) closeDisplay 1;
	closeDialog 0;
} else {
	if (_subMenu select 1 < 1) then {
		[_subMenu select 0] call AGM_Interaction_fnc_openSubMenu;
	} else {
		[_subMenu select 0] call AGM_Interaction_fnc_openSubMenuSelf;
	};
};

if (call (_action select 2)) then {
	call (_action select 1);
};
