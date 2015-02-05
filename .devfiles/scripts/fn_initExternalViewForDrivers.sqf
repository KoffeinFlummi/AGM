// by commy2

if (isNil "AGM_ExternalViewForDriversInitialized") then {
  AGM_ExternalViewForDriversInitialized = 0 spawn {
    while {true} do {
      waitUntil {!isNull (findDisplay 46)};

      findDisplay 46 displayAddEventHandler ["keyDown", {
          _key = _this select 1;
          _vehicle = vehicle player;

          if (_key in actionKeys "PersonView" && {player != _vehicle} && {player == driver _vehicle}) then {
              if !(missionNamespace getVariable ["AGM_isExternalViewForDrivers", false]) then {
                  ["AGM_ExternalViewForDrivers", "onEachFrame", {
                      _vehicle = vehicle player;
                      if (player != _vehicle && {player == driver _vehicle}) then {
                          _vehicle switchCamera "EXTERNAL";
                      };
                  }] call BIS_fnc_addStackedEventHandler;

                  AGM_isExternalViewForDrivers = true;
              } else {
                  if (["AGM_ExternalViewForDrivers", "onEachFrame"] call BIS_fnc_removeStackedEventHandler) then {
                      AGM_isExternalViewForDrivers = false;
                  };
              };
              true
          } else {
              false
          }
      }];

      waitUntil {isNull (findDisplay 46)};
    };
  };
};
