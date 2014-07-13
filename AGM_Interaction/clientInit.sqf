// by commy2

if (!hasInterface) exitWith {};

AGM_Interaction_isOpeningDoor = false;
AGM_Dancing = false;

addMissionEventHandler ["Draw3D", {
	_target = cursorTarget;
	if (!isNil "_target" && {profileNamespace getVariable ["AGM_showPlayerNames", true]} && {side _target == side player}) then {
		_name = _target getVariable ["AGM_Name", ""];

		_height = [2, 1.5, 1, 1.5, 1] select (["STAND", "CROUCH", "PRONE", "UNDEFINED", ""] find stance _target);

		_position = visiblePosition _target;
		_position = _position vectorAdd [0, 0, _height];

		_alpha = (missionNamespace getVariable ["AGM_Interaction_PlayerNamesViewDistance", 5]) - (player distance _target);
		_color = [1, 1, 1, _alpha];

		drawIcon3D [
			"",
			_color,
			_position,
			0,
			0,
			0,
			_name,
			1,
			0.03,
			"TahomaB"
		];
	};
}];
