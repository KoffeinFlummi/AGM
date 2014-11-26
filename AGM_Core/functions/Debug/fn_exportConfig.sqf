// by commy2

/*
	usage:

	(configFile >> "CfgAmmo") call AGM_Debug_fnc_exportConfig;
*/

private "_fnc_logEntries";

_fnc_logEntries = {
  private ["_c", "_d", "_p", "_t", "_e"];

  _c = _this select 0;
  _d = _this select 1;

  _p = inheritsFrom _c;

  _t = format [["class %1: %2 {", "class %1 {"] select (configName _p == ""), configName _c, configName _p];
  for "_a" from 1 to _d do {
    _t = "  " + _t;
  };
  diag_log text _t;

  _e = [];
  for "_i" from 0 to (count _c - 1) do {
    private ["_e1, _e2"];
    _e1 = _c select _i;

    _e2 = switch (true) do {
      case (isNumber _e1): {getNumber _e1};
      case (isText _e1): {getText _e1};
      case (isArray _e1): {getArray _e1};
      case (isClass _e1): {[_e1, _d + 1] call _fnc_logEntries; false};
    };

    if (typeName _e2 != "BOOL") then {
      _t = format ["%1 = %2;", configName _e1, str _e2];
      for "_a" from 0 to _d do {
        _t = "  " + _t;
      };
      diag_log text _t;
    };
  };

  _t = "};";
  for "_a" from 1 to _d do {
    _t = "  " + _t;
  };
  diag_log text _t;
  diag_log text "";

};

[_this, 0] call _fnc_logEntries;
