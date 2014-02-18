//by commy2

#define VERSION 1.0

if (isServer) then {
	BWA3_ServerVersion = VERSION;
	publicVariable "BWA3_serverVersion";
} else {
	waitUntil {!isNil "BWA3_serverVersion"};
	_clientVersion = VERSION;

	if (_clientVersion < BWA3_serverVersion) exitWith {
		systemChat format ["Your version of BWA3 (%1) does not match the server version (%2).", str (_clientVersion), str (BWA3_serverVersion)];
		systemChat "Please visit http://www.bwmod.de to update your mod installation.";
		diag_log "BWA3: Client Version older than server version"
	};

	if (_clientVersion > BWA3_serverVersion) exitWith {
		systemChat format["Your version of BWA3 (%1) does not match the server version (%2).", str (_clientVersion), str (BWA3_serverVersion)];
		systemChat "Please contact the server administrator.";
		diag_log "BWA3: Client Version newer than server version"
	};
};
