// by commy2

private ["_vectorDir", "_vectorUp", "_direction", "_pitch", "_bank"];

_vectorDir = vectorDir _this;
_vectorUp = vectorUp _this;

_direction = (_vectorDir select 0) atan2 (_vectorDir select 1);
_pitch = (_vectorDir select 2) atan2 ((_vectorDir select 0) * sin _direction + (_vectorDir select 1) * cos _direction);
_bank = ((_vectorUp select 0) * cos _direction - (_vectorUp select 1) * sin _direction) atan2 (_vectorUp select 2);

if ((_vectorUp select 2) < 0) then {
	_bank = _bank + ([180, -180] select (_bank < 0));
};

[_direction, _pitch, _bank]
