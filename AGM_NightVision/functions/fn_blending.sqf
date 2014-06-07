// by commy2

if (currentVisionMode player != 1) exitWith {};

private ["_unit", "_weapon", "_ammo", "_magazine", "_silencer", "_visibleFireCoef", "_visibleFireTimeCoef", "_visibleFire", "_visibleFireTime", "_nvgBrightnessCoef", "_fnc_isTracer"];

_unit = _this select 0;
_weapon = _this select 1;
_ammo = _this select 4;
_magazine = _this select 6;

if (player != _unit && {!(_weapon in (_unit weaponsTurret ([player] call AGM_Core_fnc_getTurretIndex)))}) exitWith {};

_silencer = switch (_weapon) do {
	case (primaryWeapon player) : {primaryWeaponItems player select 0};
	case (secondaryWeapon player) : {secondaryWeaponItems player select 0};
	case (handgunWeapon player) : {handgunItems player select 0};
	default {""};
};

_visibleFireCoef = 1;
_visibleFireTimeCoef = 1;
if (_silencer != "") then {
	_visibleFireCoef = getNumber (configFile >> "CfgWeapons" >> _silencer >> "ItemInfo" >> "AmmoCoef" >> "visibleFire");
	_visibleFireTimeCoef = getNumber (configFile >> "CfgWeapons" >> _silencer >> "ItemInfo" >> "AmmoCoef" >> "visibleFireTime");
};

_visibleFire = getNumber (configFile >> "CfgAmmo" >> _ammo >> "visibleFire");
_visibleFireTime = getNumber (configFile >> "CfgAmmo" >> _ammo >> "visibleFireTime");

_nvgBrightnessCoef = 1 + (player getVariable ["AGM_NVGBrightness", 0]) / 4;

_fnc_isTracer = {
	private ["_indexShot", "_lastRoundsTracer", "_tracersEvery"];

	if (getNumber (configFile >> "CfgAmmo" >> _ammo >> "nvgOnly") > 0) exitWith {false};

	_indexShot = (player ammo _weapon) + 1;

	_lastRoundsTracer = getNumber (configFile >> "CfgMagazines" >> _magazine >> "lastRoundsTracer");

	if (_indexShot <= _lastRoundsTracer) exitWith {true};

	_tracersEvery = getNumber (configFile >> "CfgMagazines" >> _magazine >> "tracersEvery");

	if (_tracersEvery == 0) exitWith {false};

	(_indexShot - _lastRoundsTracer) % _tracersEvery == 0
};

if (call _fnc_isTracer) then {
	_visibleFire = _visibleFire + 2;
	_visibleFireTime = _visibleFireTime + 2;
};

_visibleFire = _visibleFireCoef * _visibleFire * _nvgBrightnessCoef / 10;
_visibleFireTime = _visibleFireTimeCoef * _visibleFireTime * _nvgBrightnessCoef / 10;

if (!isNil "AGM_Debug" && {AGM_Debug == "NightVision"}) then {
    systemChat format ["visibleFire: %1", _visibleFire];
    systemChat format ["visibleFireTime: %1", _visibleFireTime];
};

AGM_NightVision_ppEffectMuzzleFlash ppEffectAdjust [1, 1, _visibleFire, [0, 0, 0, 0], [0, 0, 0, 1], [0, 0, 0, 1]];
AGM_NightVision_ppEffectMuzzleFlash ppEffectCommit 0;

AGM_NightVision_ppEffectMuzzleFlash ppEffectAdjust [1, 1, 0, [0, 0, 0, 0], [0, 0, 0, 1], [0, 0, 0, 1]];
AGM_NightVision_ppEffectMuzzleFlash ppEffectCommit _visibleFireTime;
