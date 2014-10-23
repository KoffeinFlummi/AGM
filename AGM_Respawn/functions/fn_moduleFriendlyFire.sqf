/*
 * Author: commy2
 *
 * Initializes the Friendly Fire Messages module.
 *
 * Arguments:
 * Whatever the module provides. (I dunno.)
 *
 * Return Value:
 * None
 */

_this spawn {
	_logic = _this select 0;
	_units = _this select 1;
	_activated = _this select 2;

	if !(_activated) exitWith {};

	//_mode = parseNumber (_logic getVariable "Action");

	if (hasInterface) then {
		waitUntil {!isNull player};
	};

	// if no units are selected, do this for all units
	if (count _units == 0) then {
		_units = allUnits + vehicles + allDead;
	};

	// add MPkilled eventhandler to all selected units
	if (isServer) then {
		{
			if (!isPlayer _x && {isNil {_x getVariable "AGM_FirendlyFire_MPkilled_EHID"}}) then {
				_ehid = _x addMPEventHandler ["MPKilled", {
					_unit = _this select 0;
					_killer = _this select 1;

					if (side group _unit in [playerSide, civilian] && {_unit != _killer} && {side group _killer == playerSide}) then {
						systemChat format ["%1 was killed by %2", name _unit, name _killer];
					};

					[_unit, "FriendlyFire", [_unit, _killer]] call AGM_Core_fnc_callCustomEventHandlers;
				}];

				_x setVariable ["AGM_FirendlyFire_MPkilled_EHID", _ehid, true];
			};
		} forEach _units;
	};

	if (!isDedicated) then {
		if (player in _units && {isNil {player getVariable "AGM_FirendlyFire_MPkilled_EHID"}}) then {
			_ehid = player addMPEventHandler ["MPKilled", {
				_unit = _this select 0;
				_killer = _this select 1;

				if (side group _unit in [playerSide, civilian] && {_unit != _killer} && {side group _killer == playerSide}) then {
					systemChat format ["%1 was killed by %2", name _unit, name _killer];
				};

				[_unit, "FriendlyFire", [_unit, _killer]] call AGM_Core_fnc_callCustomEventHandlers;
			}];

			player setVariable ["AGM_FirendlyFire_MPkilled_EHID", _ehid, true];
		};
	};

	AGM_FriendlyFire_moduleInitialized = true;

	diag_log text "[AGM]: Friendly Fire Messages Module Initialized.";
};
