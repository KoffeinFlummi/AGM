/*
 * Author: commy2
 *
 * Check if the player can open the interact menu or use a key
 * 
 * Argument:
 * All exceptions, that don't get checked (Array of Strings, optional)
 * 
 * Return value:
 * Can the player interact? (Bool)
 */

#define ALL_REASONS [ \
	"AGM_CannotTreat" \
	"AGM_Unconscious" \
	"AGM_Overdosing" \
]

private ["_exceptions", "_canInteract", "_variable"];

_exceptions = + _this;

if (isNil "_exceptions") then {_exceptions = []};

if (!alive _unit) exitWith {false};

_canInteract = true;

{
	_variable = player getVariable [_x, false];

	_canInteract = !_variable && {!(_variable in _exceptions)}

	if !(_canInteract) exitWith {};
} forEach ALL_REASONS;

_canInteract
