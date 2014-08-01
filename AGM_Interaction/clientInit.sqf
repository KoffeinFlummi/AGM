// by commy2

#define TEXTURES_RANKS [ \
	"", \
    "\A3\Ui_f\data\GUI\Cfg\Ranks\private_gs.paa", \
    "\A3\Ui_f\data\GUI\Cfg\Ranks\corporal_gs.paa", \
    "\A3\Ui_f\data\GUI\Cfg\Ranks\sergeant_gs.paa", \
    "\A3\Ui_f\data\GUI\Cfg\Ranks\lieutenant_gs.paa", \
    "\A3\Ui_f\data\GUI\Cfg\Ranks\captain_gs.paa", \
    "\A3\Ui_f\data\GUI\Cfg\Ranks\major_gs.paa", \
    "\A3\Ui_f\data\GUI\Cfg\Ranks\colonel_gs.paa" \
]

if (!hasInterface) exitWith {};

AGM_Interaction_isOpeningDoor = false;
AGM_Dancing = false;

addMissionEventHandler ["Draw3D", {
	_target = effectiveCommander cursorTarget;
	if (!isNull _target && {profileNamespace getVariable ["AGM_showPlayerNames", true]} && {side group _target == playerSide}) then {

		_name = if (alive _target) then {
			name _target
		} else {
			_target getVariable ["AGM_Name", ""]
		};

		_rank = TEXTURES_RANKS select ((["PRIVATE", "CORPORAL", "SERGEANT", "LIEUTENANT", "CAPTAIN", "MAJOR", "COLONEL"] find rank _target) + 1);
		_size = [0, 1] select (profileNamespace getVariable ["AGM_showPlayerRanks", true]);

		_height = [2, 1.5, 1, 1.5, 1] select (["STAND", "CROUCH", "PRONE", "UNDEFINED", ""] find stance _target);

		_position = visiblePosition _target;
		_position = _position vectorAdd [0, 0, _height];

		_alpha = AGM_Interaction_PlayerNamesViewDistance - (player distance _target) min 0.95;

		_color = if !(group _target == group player) then {[0.85, 0.85, 0.85, _alpha]} else {
			[[1, 1, 1, _alpha], [1, 0, 0, _alpha], [0, 1, 0, _alpha], [0, 0, 1, _alpha], [1, 1, 0, _alpha]] select (["MAIN", "RED", "GREEN", "BLUE", "YELLOW"] find assignedTeam _target) max 0
		};

		drawIcon3D [
			_rank,
			_color,
			_position,
			_size,
			_size,
			0,
			_name,
			2,
			0.033,
			"PuristaMedium"
		];
	};
}];
