// by commy2

if (!hasInterface) exitWith {};

AGM_Interaction_isOpeningDoor = false;
AGM_Dancing = false;

addMissionEventHandler ["Draw3D", {
	_target = effectiveCommander cursorTarget;
	if (!isNil "_target" && {profileNamespace getVariable ["AGM_showPlayerNames", true]} && {side _target == side player}) then {

		_name = if (alive _target) then {
			_rank = ["Pvt.", "Cpl.", "Sgt.", "Lt.", "Cpt.", "Maj.", "Col."] select (["PRIVATE", "CORPORAL", "SERGEANT", "LIEUTENANT", "CAPTAIN", "MAJOR", "COLONEL"] find rank _target) max 0;
			format ["%1 %2", _rank, name _target]
		} else {nil};

		if (isNil "_name") then {
			_name = _target getVariable ["AGM_Name", ""];
		};

		_height = [2, 1.5, 1, 1.5, 1] select (["STAND", "CROUCH", "PRONE", "UNDEFINED", ""] find stance _target);

		_position = visiblePosition _target;
		_position = _position vectorAdd [0, 0, _height];

		_alpha = AGM_Interaction_PlayerNamesViewDistance - (player distance _target);
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
