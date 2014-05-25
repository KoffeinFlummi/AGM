// by commy2

#define VERSION 1.0

if (isServer) then {
  AGM_serverVersion = VERSION;
  publicVariable "AGM_serverVersion";
} else {
  waitUntil {!isNil "AGM_serverVersion"};
  _clientVersion = VERSION;

  if (_clientVersion < AGM_serverVersion) exitWith {
    systemChat format ["Your version of AGM (%1) does not match the server version (%2).", str (_clientVersion), str (AGM_serverVersion)];
    systemChat "Please visit https://github.com/KoffeinFlummi/AGM/ to update your mod installation.";
    diag_log "AGM: Client version older than server version.";
  };

  if (_clientVersion > AGM_serverVersion) exitWith {
    systemChat format["Your version of AGM (%1) does not match the server version (%2).", str (_clientVersion), str (AGM_serverVersion)];
    systemChat "Please contact the server administrator.";
    diag_log "AGM: Client version newer than server version.";
  };
};
