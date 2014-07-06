// by commy2

AGM_Interaction_isOpeningDoor = false;
AGM_Dancing = false;

addMissionEventHandler ["Draw3D", {
	_target = cursorTarget;
	if (!isNil "_target" && {profileNamespace getVariable ["AGM_showPlayerNames", true]} && {side _target == side player}) then {
		_name = _target getVariable ["AGM_Name", ""];

		_height = [1.25, 0.75, 0.25, 1.5, 1] select (["STAND", "CROUCH", "PRONE", "UNDEFINED", ""] find stance _target);

		_position = visiblePosition _target;
		_position = _position vectorAdd [0, 0, _height];

		_alpha = 5 - (player distance _target);
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
