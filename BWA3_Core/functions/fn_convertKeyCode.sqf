// by commy2

private "_key";

_key = _this select 0;

if (_this select 1) then {_key = _key + 0.1};
if (_this select 2) then {_key = _key + 0.2};
if (_this select 3) then {_key = _key + 0.4};

_key
