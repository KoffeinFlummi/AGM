// by commy2

private "_name";

_name = name (_this select 0);

[-2, {
	if (serverCommandAvailable "#kick") then {
		serverCommand format["#kick %1", _this];
	};
}, _name] call CBA_fnc_globalExecute;
