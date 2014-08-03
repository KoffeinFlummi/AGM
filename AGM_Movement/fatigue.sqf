// by commy2

#define GETTING_TIRED_FACTOR 0.1
#define RECOVER_RATE_FACTOR 0.1
#define THRESHOLD_1 0.8
#define THRESHOLD_2 0.9
#define THRESHOLD_3 0.99

_fatigue = getFatigue player;

_handleRecoil = 0 spawn {};
_handleBlinking = 0 spawn {};
_handleHeartbeat = 0 spawn {};
_handleStumble = 0 spawn {};

while {true} do {
	if (_fatigue > THRESHOLD_1) then {
		if (scriptDone _handleHeartbeat) then {
			_handleHeartbeat = call AGM_Movement_fnc_heartbeat;
		};
		if (_fatigue > THRESHOLD_2) then {
			if (scriptDone _handleBlinking) then {
				_handleBlinking = call AGM_Movement_fnc_blinking;
			};

			if (_fatigue > THRESHOLD_3) then {
				if (scriptDone _handleStumble) then {
					_handleStumble = call AGM_Movement_fnc_stumble;
				};
			};
		};
	};

	sleep 0.5;

	_fatigueNew = getFatigue player;hint str _fatigueNew;

	if (_fatigueNew > _fatigue) then {
		_fatigue = _fatigue + GETTING_TIRED_FACTOR * (_fatigueNew - _fatigue);
		if !(isNil "AGM_Fatigue_CoefFatigue") then {
			_fatigue = _fatigue * AGM_Fatigue_CoefFatigue;
		};
	} else {
		_fatigue = _fatigue - RECOVER_RATE_FACTOR * (_fatigue - _fatigueNew);
		if !(isNil "AGM_Fatigue_CoefRecover") then {
			_fatigue = _fatigue * AGM_Fatigue_CoefRecover;
		};
	};
	player setFatigue _fatigue;
};
