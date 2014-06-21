// by commy2

#define DELAY 1
#define MAX_DISTANCE 5

_rscLayer = ["AGM_showPlayerNames"] call BIS_fnc_rscLayer;

while {true} do {
	sleep DELAY;
	waitUntil {profileNamespace getVariable ["AGM_showPlayerNames", true]};
	_unit = cursorTarget;
	if (player == vehicle player && {isPlayer _unit} && {alive _unit} && {player distance _unit < MAX_DISTANCE}) then {
		_rscLayer cutText [name _unit, "PLAIN", 0.1];
	};
};
