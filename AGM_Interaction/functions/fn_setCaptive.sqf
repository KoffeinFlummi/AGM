// by commy2, Nic547
// Makes a civilian unable to move
private ["_unit"];

_unit = _this select 0;
if (captive _unit) then {
	_unit setCaptive 0;
	_unit playMoveNow "AmovPercMstpSnonWnonDnon_EaseOut";
}
else {
	_unit setCaptive 1;
	while {captive _unit;} do {
		_unit playMove "AmovPercMstpSnonWnonDnon_Ease";
	};
};