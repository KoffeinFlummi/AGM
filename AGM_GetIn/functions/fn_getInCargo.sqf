// by commy2

_vehicle = _this select 0;
_index = AGM_Interaction_MenuData select 0;

player action [
	["GetInCargo", "MoveToCargo"] select (vehicle player == _vehicle),
	_vehicle,
	_index
];
