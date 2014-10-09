private ["_unit"];
_unit = _this select 0;

["theMapClick", "onMapSingleClick", {
  [_this, _pos, _shift, _alt] call AGM_SwitchUnits_fnc_handleMapClick;
}, [_unit]] call BIS_fnc_addStackedEventHandler;