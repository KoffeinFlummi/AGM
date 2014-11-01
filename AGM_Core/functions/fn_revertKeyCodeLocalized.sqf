/*
 * Author: commy2
 *
 * Revert a key code to a readible text.
 *
 * Argument:
 * 0: Key code (Number)
 *
 * Return value:
 * What input will result in the given key code? (String)
 */

private ["_keyCode", "_key", "_alt", "_ctrl", "_shft"];

_keyCode = _this select 0;

_key = toString ((toArray keyName floor _keyCode) - [34]);

_keyCode = round ((_keyCode % 1) * 10);

switch (_keyCode) do {
  case 8 : {format [localize "STR_AGM_Core_DoubleTapKey", _key]};
  case 9 : {format [localize "STR_AGM_Core_HoldKey", _key]};
  default {
    _keyCode = toArray ([_keyCode, 3] call AGM_Core_fnc_toBin);

    _alt = "1" == toString [_keyCode select 0];
    _ctrl = "1" == toString [_keyCode select 1];
    _shift = "1" == toString [_keyCode select 2];

    format ["%1%2%3%4",
      ["", format ["%1 + ", localize "STR_AGM_Core_Alt"]] select _alt,
      ["", format ["%1 + ", localize "STR_AGM_Core_Ctrl"]] select _ctrl,
      ["", format ["%1 + ", localize "STR_AGM_Core_Shift"]] select _shift,
      _key
    ]
  };
};
