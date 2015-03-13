// by commy2

private ["_vehicle", "_item"];

_vehicle = _this select 0;

for "_x" from 1 to (missionNamespace getVariable ["AGM_Logistics_SpareTrackNumber",2]) do {
  _item = ['AGM_SpareTrack', [-1000, -1000, 100]] call AGM_Logistics_fnc_spawnObject;
  [_vehicle, _item] call AGM_Logistics_fnc_initLoadedObject;
};

