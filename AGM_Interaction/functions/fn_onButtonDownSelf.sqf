// by commy2

if (isNull (findDisplay 1713999) && {!dialog}) then {
	"" call AGM_Interaction_fnc_openMenuSelf;
} else {
	(findDisplay 1713999) closeDisplay 1;
	closeDialog 0;
};
