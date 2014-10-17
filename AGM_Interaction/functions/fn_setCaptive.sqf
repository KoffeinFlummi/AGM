// by commy2, Nic547
// Makes a civilian unable to move

private ["_unit", "_state", "_remote"];

_unit = _this select 0;
_state = _this select 1;
_remote = false;
if (count _this > 2) then {
	_remote = _this select 2;
};

if (!_remote and _state) then {
	player removeItem "AGM_CableTie";
};

if (!local _unit) exitWith {[_this + [true], _fnc_scriptName, _unit] call AGM_Core_fnc_execRemoteFnc};

if (_state) then {
	if (_unit getVariable ["AGM_isCaptive", false]) exitWith {};

	_unit setVariable ["AGM_isCaptive", true, true];
	[_unit, "AGM_Handcuffed", true] call AGM_Interaction_fnc_setCaptivityStatus;

	if (_unit getVariable ["AGM_isSurrender", false]) then {
		_unit setVariable ["AGM_isSurrender", false, true];
	};

	_unit spawn {
		_inputDisabled = false;

		// fix for lowered rifle animation glitch
		if (currentWeapon _this != "" && {currentWeapon _this == primaryWeapon _this} && {weaponLowered _this} && {stance _this == "STAND"}) then {
			_this playMove "amovpercmstpsraswrfldnon";
		};

		// fix grenade throwing
		_actionID = [_this, "Throw", {true}, {}] call AGM_Core_fnc_addActionEventHandler;

		while {_this getVariable ["AGM_isCaptive", false]} do {
			sleep 0.001; //sleep in UI

			if (isPlayer _this) then {showHUD false};

			waitUntil {!(_this getVariable ["AGM_Unconscious", false])};

			if (isPlayer _this) then {
				if (!_inputDisabled) then {
					if (!isNull (attachedTo _this) || {vehicle _this != _this}) then {
						[true] call AGM_Core_fnc_disableUserInput;
						_inputDisabled = true;
					};
				} else {
					if (isNull (attachedTo _this) && {vehicle _this == _this}) then {
						[false] call AGM_Core_fnc_disableUserInput;
						_inputDisabled = false;
					};
				};
			};

			if (!alive _this) then {
				_this setVariable ["AGM_isCaptive", false, true];
			} else {
				_this playMove "AmovPercMstpSnonWnonDnon_Ease";
			};
		};

		// fix grenade throwing
		[_this, "Throw", _actionID] call AGM_Core_fnc_removeActionEventHandler;

		if !(_this getVariable ["AGM_Unconscious", false]) then {
			_this playMoveNow "AmovPercMstpSnonWnonDnon_EaseOut";
		} else {
			_this playMoveNow "unconscious";
		};

		[_this, "AGM_Handcuffed", false] call AGM_Interaction_fnc_setCaptivityStatus;

		if (_inputDisabled && {isPlayer _this}) then {
			[false] call AGM_Core_fnc_disableUserInput;
		};

		if (isPlayer _this) then {showHUD true};
	};
} else {
	_unit setVariable ["AGM_isCaptive", false, true];
};
