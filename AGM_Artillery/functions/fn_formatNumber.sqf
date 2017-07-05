/*
Name: AGM_Artillery_fnc_formatNumber

Author: Pabst Mirror

Description:
  Converts numbers into nicely formated strings.

Parameters:
  0: NUMBER - Input number
  1: STRING - Output type (see case statement)
  2: BOOL   - If output type is mil, convert input type from deg->mil

Returns:
  STRING - Formatted number

Example:
  [45, "mil4", true] call AGM_Artillery_fnc_formatNumber = "0800"
*/

private ["_theNumber", "_inputType", "_convertToMils", "_decimalPlaces", "_integerPlaces", "_prefix", "_return"];

_theNumber = _this select 0;
_inputType = _this select 1;
_convertToMils = _this select 2;

_decimalPlaces = -1;
_integerPlaces = -1;

switch (toLower _inputType) do {
case ("meters"): {
    _decimalPlaces = 0;
    _integerPlaces = 1;
  };
case ("metersprecise"): {
    _decimalPlaces = 1;
    _integerPlaces = 1;
  };
case ("meters4"): {
    _decimalPlaces = 0;
    _integerPlaces = 4;
  };
case ("deg3precise"): {
    _decimalPlaces = 2;
    _integerPlaces = 3;
  };
case ("mil"): {
    _decimalPlaces = 0;
    _integerPlaces = 1;
    if (_convertToMils) then {
      _theNumber = _theNumber * (6400 / 360);
    };
  };
case ("mil4"): {
    _decimalPlaces = 0;
    _integerPlaces = 4;
    if (_convertToMils) then {
      _theNumber = _theNumber * (6400 / 360);
    };
  };
case ("milprecise"): {
    _decimalPlaces = 1;
    _integerPlaces = 1;
    if (_convertToMils) then {
      _theNumber = _theNumber * (6400 / 360);
    };
  };
case ("sec"): {
    _decimalPlaces = 1;
    _integerPlaces = 1;
  };
  default {systemChat format ["badtype %1", _inputType];};
};


//CBA_fnc_formatNumber is stupid:  [-9.58545, 1, 1, false] call CBA_fnc_formatNumber == "-9.-6"

_prefix = if (_theNumber < 0) then {"-"} else {""};

_return = [abs (_theNumber), _integerPlaces, _decimalPlaces, false] call CBA_fnc_formatNumber;

(_prefix + _return)
