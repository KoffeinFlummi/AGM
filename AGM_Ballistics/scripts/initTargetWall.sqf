// by commy2

_wall = _this select 0;

_paper = "UserTexture_1x2_F" createVehicleLocal position _wall;
_paper attachTo [_wall, [0,-0.02,0.6]];
_paper setDir getDir _wall;
_paper setObjectTexture [0, "\AGM_Ballistics\textures\target_ca.paa"];

_hole1 = "UserTexture_1x2_F" createVehicleLocal position _wall;
_hole1 attachTo [_wall, [0,-0.02,0.6]];
_hole1 setDir getDir _wall;
_hole1 setObjectTexture [0, "\AGM_Ballistics\textures\hole1_ca.paa"];
