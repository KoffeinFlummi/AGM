_unit = _this select 0;
[_unit, "AmovPercMevaSrasWrflDf_AmovPknlMstpSrasWrflDnon", 2] call AGM_Core_fnc_doAnimation;
[_unit] spawn {
	sleep 1;
	(_this select 0) playActionNow "Crouch";
	["AGM_ParachuteFix", "OnEachFrame"] call BIS_fnc_removeStackedEventHandler;
	AGM_Parachuting_PFH = false;
};