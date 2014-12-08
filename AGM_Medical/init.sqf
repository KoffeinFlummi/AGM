// by commy2, handle AI

0 spawn {
  while {true} do {
    sleep 10;

    _allGroups = [allGroups, {local _this}] call AGM_Core_fnc_filter;

    {
      {
        _unit = _x;
        _task = _unit call AGM_Medical_fnc_checkRequiredTreatment;
        if !(_task isEqualTo false) then {
          //systemChat format ["%1 needs %2", _unit, _task];
          if ([_unit, _unit, _task] call AGM_Medical_fnc_aiCanTreat) then {
            //systemChat format ["%1 : %2", [_unit, _unit, _need] call AGM_Medical_fnc_aiTreat, [_unit, _unit, _need]];
            //systemChat format ["%1 heals itself", _unit];
            [_unit, _unit, _task] call AGM_Medical_fnc_aiTreat;
          } else {
            // if not, then find close units that can treat instead
            _list = _unit nearEntities ["Man", 5];
            _medic_found = false;
            {
              if ([_x, _unit, _task] call AGM_Medical_fnc_aiCanTreat) then {
                //systemChat format ["%1 : %2", [_unit, _unit, _need] call AGM_Medical_fnc_aiTreat, [_unit, _unit, _need]];
                if (side _x != side _unit) then {
                  if (_unit getVariable ["AGM_isUnconscious", false]) exitWith {
                    //systemChat format ["%1 : %2 : %3", _x, _unit, _task];
                    removeAllWeapons _unit;
                    _medic_found = true;
                    [_x, _unit, _task] call AGM_Medical_fnc_aiTreat;
                    //[_unit, true] call AGM_Captive_surrender;
                    _unit allowFleeing 0;
                    doStop _unit;
                    _unit action ["Surrender", _unit];
                    _unit setCaptive true;
                  };
                } else {
                  if (true) exitWith {
                    //systemChat format ["%1 : %2 : %3", _x, _unit, _task];
                    _medic_found = true;
                    [_x, _unit, _task] call AGM_Medical_fnc_aiTreat;
                  };
                };
              };
            } foreach _list;

            // if reached that point, there is no close help, call support. Player must order medic himself to the position
            if (!_medic_found && ((AGM_player != leader _unit) || (AGM_player getVariable ["AGM_isUnconscious", false])) ) then {
              //systemChat format ["calling support, %1, %2", _unit, _task];
              [_unit, _task] call AGM_Medical_fnc_aiInitTask;
            };
          };
        };
      } forEach units _x
    } forEach _allGroups;
  };
};
