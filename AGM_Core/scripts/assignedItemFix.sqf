// by commy2

if (isNil "AGM_itemFix") then {
	AGM_isMapEnabled     = call {_config = missionConfigFile >> "ItemMap";     !isNumber _config || {getNumber _config == 1}};
	AGM_isCompassEnabled = call {_config = missionConfigFile >> "ItemCompass"; !isNumber _config || {getNumber _config == 1}};
	AGM_isWatchEnabled   = call {_config = missionConfigFile >> "ItemWatch";   !isNumber _config || {getNumber _config == 1}};
	AGM_isRadioEnabled   = call {_config = missionConfigFile >> "ItemRadio";   !isNumber _config || {getNumber _config == 1}};
	AGM_isGPSEnabled     = call {_config = missionConfigFile >> "ItemGPS";     !isNumber _config || {getNumber _config == 1}};

	AGM_itemFix = ["AGM_itemFix", "onEachFrame", {
		_player = call AGM_Core_fnc_player;
		showMap     (AGM_isMapEnabled     && {"ItemMap"     in assignedItems _player});
		showCompass (AGM_isCompassEnabled && {"ItemCompass" in assignedItems _player});
		showWatch   (AGM_isWatchEnabled   && {"ItemWatch"   in assignedItems _player});
		showRadio   (AGM_isRadioEnabled   && {"ItemRadio"   in assignedItems _player});
		showGPS     (AGM_isGPSEnabled     && {"ItemGPS"     in assignedItems _player});
	}] call BIS_fnc_addStackedEventHandler;
};
