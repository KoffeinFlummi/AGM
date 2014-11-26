// by commy2

AGM_player = player;

if (hasInterface) then {
	["AGM_CheckForPlayerChange", "onEachFrame", {
		if (AGM_player != missionNamespace getVariable ["BIS_fnc_moduleRemoteControl_unit", player]) then {
			_this = AGM_player;

			AGM_player = missionNamespace getVariable ["BIS_fnc_moduleRemoteControl_unit", player];
			uiNamespace setVariable ["AGM_player", AGM_player];

			[missionNamespace, "AGM_Core_playerChanged", [AGM_player, _this]] call AGM_Core_fnc_callCustomEventHandlers;
		};
	}] call BIS_fnc_addStackedEventHandler;
};
