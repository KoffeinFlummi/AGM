// by commy2

// don't show the watch if it isn't equipped!
if (isNil "AGM_isWatchEnabled") then {
	AGM_isWatchEnabled = call {_config = missionConfigFile >> "showWatch"; !isNumber _config || {getNumber _config == 1}};

	AGM_Parachute_actionWatchCondition = {
		showWatch (AGM_isWatchEnabled && {"ItemWatch" in assignedItems (_this select 0)});
		true
	};

	AGM_Parachute_actionWatch = {
		// Show altimeter if it is instead!
		if ("AGM_Altimeter" in assignedItems (_this select 0)) then {
			// Toggle on off
			if (isNull (missionNamespace getVariable ["AGM_Parachute_AltimeterFnc", scriptNull])) then {
				[_this select 1] call AGM_Parachute_fnc_showAltimeter;
			} else {
				call AGM_Parachute_fnc_hideAltimeter;
			};
		};
	};
};

[_this select 0, "Watch", AGM_Parachute_actionWatchCondition, AGM_Parachute_actionWatch] call AGM_Core_fnc_addActionEventHandler;
