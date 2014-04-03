// by commy2

#define RSC_INDEX 127
#define DISTANCE 5
#define DELAY 1

while {true} do {
	sleep DELAY;
	_cursorTarget = cursorTarget;
	_visibleName = false;
	if (vehicle player == player && {isPlayer _cursorTarget} && {player distance _cursorTarget < DISTANCE}) then {
		_name = name _cursorTarget;
		RSC_INDEX cutText [_name, "PLAIN", 0.1];
		_visibleName = true;
	} else {
		if (_visibleName) then {
			RSC_INDEX cutText ["", "PLAIN", 0.1];
			_visibleName = false;
		};
	};
};
