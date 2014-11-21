// by commy2

private "_state";

_state = _this select 0;

if (_state) then {
  ["AGM_disableFiring", "onEachFrame", {
    _vehicle = vehicle (call AGM_Core_fnc_player);
    _vehicle setWeaponReloadingTime [gunner _vehicle, currentMuzzle gunner _vehicle, 0.5];
  }] call BIS_fnc_addStackedEventHandler;
} else {
  if (["AGM_disableFiring", "onEachFrame"] call BIS_fnc_removeStackedEventHandler) then {
    private "_vehicle";

    _vehicle = vehicle (call AGM_Core_fnc_player);
    _vehicle setWeaponReloadingTime [gunner _vehicle, currentMuzzle gunner _vehicle, 0];
  };
};
nil
