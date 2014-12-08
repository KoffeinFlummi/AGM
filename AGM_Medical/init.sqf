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
          if ([_unit, _unit, _task] call AGM_Medical_fnc_aiCanTreat) then {
            //systemChat format ["%1 : %2", [_unit, _unit, _need] call AGM_Medical_fnc_aiTreat, [_unit, _unit, _need]];
            [_unit, _unit, _task] call AGM_Medical_fnc_aiTreat;
          } else {
            // if not, then find close units that can treat instead
            _list = _unit nearEntities ["Man", 5];
            {
              if ([_x, _unit, _task] call AGM_Medical_fnc_aiCanTreat) then {
                //systemChat format ["%1 : %2", [_unit, _unit, _need] call AGM_Medical_fnc_aiTreat, [_unit, _unit, _need]];
                if (side _x != side _unit) then {
                  if (_unit getVariable ["AGM_isUnconscious", false]) exitWith {
                    removeAllWeapons _unit;
                    [_x, _unit, _task] call AGM_Medical_fnc_aiTreat;
                    //[_unit, true] call AGM_Captive_surrender;
                    _unit setCaptive true;
                    _unit action ["Surrender", _unit];
                    _unit allowFleeing 0;
                    doStop _unit;
                  };
                } else {
                  if (true) exitWith { [_x, _unit, _task] call AGM_Medical_fnc_aiTreat; };
                };
              };
            } foreach _list;
          };
        };
      } forEach units _x
    } forEach _allGroups;
  };
};
