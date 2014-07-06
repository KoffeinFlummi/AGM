// by commy2

_this spawn {
	sleep 1;

	_unit = _this select 0;

	if (!alive _unit) exitWith {};

	_rank = ["Pvt.", "Cpl.", "Sgt.", "Lt.", "Cpt.", "Maj.", "Col."] select (["PRIVATE", "CORPORAL", "SERGEANT", "LIEUTENANT", "CAPTAIN", "MAJOR", "COLONEL"] find rank _unit);
	_name = name _unit;

	if (_unit == player) then {
		_rank = profileNamespace getVariable ["AGM_Rank", _rank];
		_name = [_name, true] call AGM_Core_fnc_sanitizeString;
	};

	_name = format ["%1 %2", _rank, _name];

	_unit setVariable ["AGM_Name", _name, true];
};
