// by commy2

if (dialog) exitWith {
	closeDialog 0;
};

if (isNull (findDisplay 1713999)) then {
	"" call AGM_Interaction_fnc_openMenu;
	setMousePosition [0.5, 0.5];
} else {
	(findDisplay 1713999) closeDisplay 1;
};

[_player, "InteractionMenuOpened", [_player, AGM_Interaction_Target, 0]] call AGM_Core_fnc_callCustomEventHandlers;
