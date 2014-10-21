// by commy2

private "_dlgVectorOptics";

disableSerialization;
_dlgVectorOptics = uiNamespace getVariable ['AGM_dlgVectorOptics', displayNull];

[
	round parseNumber ctrlText (_dlgVectorOptics displayCtrl 156),
	round parseNumber ctrlText (_dlgVectorOptics displayCtrl 182)
]

/*
_position = ATLToASL positionCameraToWorld [0, 0, 0];
_direction = ATLToASL positionCameraToWorld [0, 0, 1];

_azimuth = ((_direction select 0) - (_position select 0)) atan2 ((_direction select 1) - (_position select 1));
_inclination = asin ((_direction select 2) - (_position select 2));

if (_azimuth < 0) then {_azimuth = _azimuth + 360};

[_azimuth, _inclination]
*/
