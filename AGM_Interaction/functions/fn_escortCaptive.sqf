//author : Nic547
//Attaches a Captive to the player

private ["_unit", "_state"];

_unit = _this select 0;
_state = _this select 1;

if !("AGM_Handcuffed" in ([_unit] call AGM_Interaction_fnc_getCaptivityStatus)) exitWith {
	[localize "STR_AGM_Interaction_NoCaptive"] call AGM_Core_fnc_displayTextStructured;
};

if (_state) then {
	if (player getVariable ["AGM_isEscorting", false]) exitWith {};

	[player, _unit] call AGM_Core_fnc_claim;
	player setVariable ["AGM_isEscorting", true, true];

	_unit attachTo [player, [0, 1, 0]];
	_unit spawn {
		while {player getVariable ["AGM_isEscorting", false]} do {
			sleep 0.2;

			if (!alive _this || {!alive player} || {!canStand _this} || {!canStand player}) then {
				player setVariable ["AGM_isEscorting", false, true];
			};
		};
		[objNull, _this] call AGM_Core_fnc_claim;

		detach _this;
	};
} else {
	player setVariable ["AGM_isEscorting", false, true];
};
