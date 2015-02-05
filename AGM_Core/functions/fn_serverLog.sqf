// by CAA-Picard

if (isServer) then {
  diag_log _this;
} else {
  [_this, "AGM_Core_fnc_serverLog", 1] call AGM_Core_fnc_execRemoteFnc;
};
