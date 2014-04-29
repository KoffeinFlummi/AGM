// by commy2

#define DEFAULT_PLAY_SOUND false
#define DEFAULT_DELAY 2
#define DEFAULT_PRIORITY 0

if (isNil "BWA3_Core_lastHint") then {
	BWA3_Core_lastHint = [0, 0];
};

_this resize 4;

_this spawn {
	private ["_text", "_sound", "_delay", "_priority", "_lastHintTime", "_lastHintPriority", "_time"];

	_text = _this select 0;
	_sound = _this select 1;
	_delay = _this select 2;
	_priority = _this select 3;

	_lastHintTime = BWA3_Core_lastHint select 0;
	_lastHintPriority = BWA3_Core_lastHint select 1;

	if (typeName _text != "STRING") then {_text = str _text};
	if (isNil "_sound") then {_sound = DEFAULT_PLAY_SOUND};
	if (isNil "_delay") then {_delay = DEFAULT_DELAY};
	if (isNil "_priority") then {_priority = DEFAULT_PRIORITY};

	_time = time;
	if (_time > _lastHintTime + _delay || {_priority >= _lastHintPriority}) then {
		hintSilent _text;
		if (_sound) then {playSound "BWA3_click"};
		BWA3_Core_lastHint set [0, _time];
		BWA3_Core_lastHint set [1, _priority];

		sleep _delay;
		if (_time == BWA3_Core_lastHint select 0) then {hintSilent ""};
	};
};
