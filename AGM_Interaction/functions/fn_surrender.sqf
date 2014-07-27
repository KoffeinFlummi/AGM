// by commy2

private ["_unit", "_state"];

_unit = _this select 0;
_state = _this select 1;

if (_state) then {
	if (_unit getVariable ["AGM_isSurrender", false]) exitWith {};

	_unit setVariable ["AGM_isSurrender", true, true];

	_unit spawn {
		while {_this getVariable ["AGM_isSurrender", false]} do {
			_this playMove "amovpercmstpsnonwnondnon_amovpercmstpssurwnondnon";

			if (!alive _this) then {
				_this setVariable ["AGM_isSurrender", false, true];
			};
		};
		_this playMoveNow "AmovPercMstpSsurWnonDnon_AmovPercMstpSnonWnonDnon";
	};
} else {
	_unit setVariable ["AGM_isSurrender", false, true];
};
