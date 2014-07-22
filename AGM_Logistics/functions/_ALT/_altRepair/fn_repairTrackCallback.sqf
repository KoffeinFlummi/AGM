_vehicle = _this select 0;
_repairSelectionName = _this select 1;
_wheels = _this select 2;
deleteVehicle (_wheels select 0);
_vehicle setHit [_repairSelectionName, 0];
player playMoveNow "AmovPknlMstpSrasWrflDnon";