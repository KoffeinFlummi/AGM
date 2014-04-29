// by commy2

#define VERSION 1.0

if (isServer) then {
	AGM_ServerVersion = VERSION;
	publicVariable "AGM_serverVersion";
} else {
	waitUntil {!isNil "AGM_serverVersion"};
	_clientVersion = VERSION;

	if (_clientVersion < AGM_serverVersion) exitWith {
		systemChat format ["Your version of BWA3 (%1) does not match the server version (%2).", str (_clientVersion), str (AGM_serverVersion)];
		systemChat "Please visit https://github.com/KoffeinFlummi/AGM_Realism/ to update your mod installation.";
		diag_log "BWA3: Client Version older than server version";
	};

	if (_clientVersion > AGM_serverVersion) exitWith {
		systemChat format["Your version of BWA3 (%1) does not match the server version (%2).", str (_clientVersion), str (AGM_serverVersion)];
		systemChat "Please contact the server administrator.";
		diag_log "BWA3: Client Version newer than server version";
	};
};
