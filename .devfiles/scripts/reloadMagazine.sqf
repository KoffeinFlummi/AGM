// by commy2

_vehicle = _this select 0;
_magazine = _this select 1;
_weapon = (_this call AGM_Logistics_getWeaponsOfMagazine) select 0;

[10, [_vehicle, _magazine, _weapon], "AGM_Logistics_reloadMagazineCallback", "Loading Magazine ..."] call AGM_Core_fnc_progressBar;
