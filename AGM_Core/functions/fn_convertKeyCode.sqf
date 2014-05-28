/*
 * Author: commy2
 *
 * Get a key code used in AGM key input eh.
 * 
 * Argument:
 * 0: Arma DIK code (Number)
 * 1: Key state for shift left and shift right key (Bool)
 * 2: Key state for ctrl left and ctrl right key (Bool)
 * 3: Key state for alt and alt gr key (Bool)
 * 
 * Return value:
 * Key code (Number)
 */

private "_key";

_key = _this select 0;

if (_this select 1) then {_key = _key + 0.1};
if (_this select 2) then {_key = _key + 0.2};
if (_this select 3) then {_key = _key + 0.4};

_key
