// by commy2

if (dialog) exitWith {
	closeDialog 0;
};

if (isNull (findDisplay 1713999)) then {
	"" call AGM_Interaction_fnc_openMenu;
} else {
	(findDisplay 1713999) closeDisplay 1;
};

