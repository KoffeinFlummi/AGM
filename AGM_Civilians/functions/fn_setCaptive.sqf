// by commy2, Nic547
// Makes a civilian unable to move
private ["_unit"];

_unit = _this select 0;
_unit setCaptive 1;
_unit setVariable ["AGM_isCaptive", true, true];
while {_unit getVariable "AGM_isCaptive";} do {
	_unit playMove "AmovPercMstpSnonWnonDnon_Ease";
};
