// by commy2

#define DISTANCE 5
#define DELAY 1

_rscLayer = ["AGM_showPlayerNames"] call BIS_fnc_rscLayer;

while {true} do {
	sleep DELAY;
	_cursorTarget = cursorTarget;
	_visibleName = false;
	if (vehicle player == player && {isPlayer _cursorTarget} && {player distance _cursorTarget < DISTANCE}) then {
		_name = name _cursorTarget;
		_rscLayer cutText [_name, "PLAIN", 0.1];
		_visibleName = true;
	} else {
		if (_visibleName) then {
			_rscLayer cutText ["", "PLAIN", 0.1];
			_visibleName = false;
		};
	};
};
