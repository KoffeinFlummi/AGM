// by commy2

_brightness = 2 - call AGM_Core_fnc_ambientBrightness;
_isIR = currentVisionMode AGM_player;

if (_isIR == 2) exitWith {};

_isIR = _isIR == 1;

{
	_weapon = currentWeapon _x;

	_laser = switch (_weapon) do {
		case (""): {""};
		case (primaryWeapon _x): {
			primaryWeaponItems _x select 1;
		};
		case (secondaryWeapon _x): {
			secondaryWeaponItems _x select 1;
		};
		case (handgunWeapon _x): {
			handgunItems _x select 1;
		};
		default {""};
	};

	_laserID = ["AGM_acc_pointer_red", "AGM_acc_pointer_green"] find _laser;

	if (_laserID > -1 && {_x isFlashlightOn _weapon}) then {
		[_x, 30, _laserID == 1 || _isIR] call AGM_Laserpointer_fnc_drawLaserpoint
	};

} forEach AGM_Laserpointer_nearUnits;
