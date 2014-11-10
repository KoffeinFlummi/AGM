// by commy2

_unit = _this select 0;

if (!alive _unit) exitWith {};

_faction = getText (configFile >> "CfgVehicles" >> typeOf _unit >> "faction");
_ranks = getArray (configFile >> "CfgFactionClasses" >> _faction >> "AGM_Ranks");
if (count _ranks < 7) then {
  _ranks = ["Pvt.", "Cpl.", "Sgt.", "Lt.", "Cpt.", "Maj.", "Col."];
};

_rank = _ranks select (["PRIVATE", "CORPORAL", "SERGEANT", "LIEUTENANT", "CAPTAIN", "MAJOR", "COLONEL"] find rank _unit) max 0;
_name = name _unit;

if (_unit == player) then {
  _rank = profileNamespace getVariable ["AGM_Rank", _rank];
  _name = [_name, true] call AGM_Core_fnc_sanitizeString;
};

//_name = format ["%1 %2", _rank, _name];

_unit setVariable ["AGM_Name", _name, true];
