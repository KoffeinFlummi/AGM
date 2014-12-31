// AGM_Captives_fnc_disarmCallback

_orginalCaller = _this select 0;
_disarmedUnit = _this select 1;
_failure = _this select 2;

if (AGM_player != _orginalCaller) exitWith {};
_message = if (_failure) then {
  "fail";
} else {
  "Disarmed";
};
[_message] call AGM_Core_fnc_displayTextStructured;
