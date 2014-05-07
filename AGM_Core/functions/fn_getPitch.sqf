// by -

private ["_vectorDir", "_direction", "_pitch"];

_vectorDir = vectorDir _this;

_direction = (_vectorDir select 0) atan2 (_vectorDir select 1);
_pitch = (_vectorDir select 2) atan2 ((_vectorDir select 0) * sin _direction + (_vectorDir select 1) * cos _direction);

_pitch
