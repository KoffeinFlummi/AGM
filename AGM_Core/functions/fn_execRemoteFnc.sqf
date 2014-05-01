// by commy2

private ["_arguments", "_function", "_unit", "_ownerID"];

_arguments = _this select 0;
_function = _this select 1;
_unit = _arguments select 0;

if (local _unit) then {
	_arguments call _function;
} else {
	AGM_Core_remoteFnc = [_arguments, _function];

	if (isServer) then {
		_ownerID = owner _unit;
		_ownerID publicVariableClient "AGM_Core_remoteFnc";
	} else {
		publicVariableServer "AGM_Core_remoteFnc";
	};
};
