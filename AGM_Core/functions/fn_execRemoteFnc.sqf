// by commy2

private ["_unit", "_count", "_arguments", "_function", "_ownerID"];

_unit = _this select 0;

if (local _unit) then {
	_count = count _this;
	_arguments = + _this;
	_arguments resize (_count - 1);
	_function = _this select (_count - 1);

	_arguments call _function;
} else {
	AGM_Core_remoteFnc = _this;

	if (isServer) then {
		_ownerID = owner _unit;
		_ownerID publicVariableClient "AGM_Core_remoteFnc";
	} else {
		publicVariableServer "AGM_Core_remoteFnc";
	};
};
