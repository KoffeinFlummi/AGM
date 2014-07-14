// by CAA-Picard

// Read AGM_Parameters from config and set them on the mission namespace
_config = configFile >> "AGM_Parameters";
_count = count _config;
for "_index" from 0 to (_count - 1) do {
  _x = _config select _index;

  _name = configName _x;
  _value = _x call bis_fnc_getcfgdata;
  [_name, _value] call AGM_Core_fnc_setParameter;
};

// Read AGM_Parameters from mission and set them on the mission namespace, replacing defaults if necesary
_config = missionConfigFile >> "AGM_Parameters";
_count = count _config;
for "_index" from 0 to (_count - 1) do {
  _x = _config select _index;

  _name = configName _x;
  _value = _x call bis_fnc_getcfgdata;
  [_name, _value] call AGM_Core_fnc_setParameter;
};
