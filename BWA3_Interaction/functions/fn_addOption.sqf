// by commy2

#define DEFAULT_PRIORITY 1.5

if (isNil "BWA3_Interaction_Actions") then {
	BWA3_Interaction_Actions = [];
	BWA3_Interaction_Commands = [];
};

private ["_action", "_command", "_index"];

_action = _this select 0;
_command = + _this select 1;

if (_action in BWA3_Interaction_Actions) exitWith {};

if (count _command < 3) then {_command set [3, DEFAULT_PRIORITY]};
if (count _command < 4) then {_command set [4, true]};

_index = count BWA3_Interaction_Actions;

BWA3_Interaction_Actions set [_index, _action];
BWA3_Interaction_Commands set [_index, _command];
