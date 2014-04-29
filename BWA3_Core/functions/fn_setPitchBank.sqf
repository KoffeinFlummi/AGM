// by commy2

/*CAUTION: THIS IS INCOMPLETE AND MAY FAIL TO WORK AS EXPECTED*/

private ["_vehicle", "_pitch", "_bank", "_direction", "_vectorDir", "_vectorUp"];

_vehicle = _this select 0;
_pitch = _this select 1;
_bank = _this select 2;

_direction = 360 - (getDir _vehicle);

while {_pitch > 180} do {_pitch = _pitch - 180};
while {_pitch < -180} do {_pitch = _pitch + 180};

if (_pitch == 90) then {_pitch = 89.9};
if (_pitch == -90) then {_pitch = -89.9};

/*if (_pitch > 90) then {
	_vehicle setDir (getDir _vehicle) - 180;

	_direction = 360 - (getDir _vehicle);
	_pitch = 180 - _pitch;
	_bank = _bank + 180;
};

if (_pitch < -90) then {
	_vehicle setDir (getDir _vehicle) - 180;

	_direction = 360 - (getDir _vehicle);
	_pitch = _pitch - 180;
	_bank = _bank + 180;
};*/

_vectorDir = [
	-(cos _pitch) * sin _direction,
	(cos _pitch) * cos _direction,
	sin _pitch
];

while {_bank > 360} do {_bank = _bank - 360};
while {_bank < -360} do {_bank = _bank + 360};

/*if (_bank > 180) then {_bank = _bank - 360};
if (_bank < -180) then {_bank = 360 - _bank};*/

_vectorUp = [
	(sin _bank) * cos _direction,
	(sin _bank) * sin _direction,
	cos _bank
];

_vehicle setVectorDirAndUp [_vectorDir, _vectorUp];
