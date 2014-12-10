// by commy2

_this spawn {
	_unit = _this select 0;

	_fnc_playAnim = {
		if (getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> animationState _this >> "AGM_isLadder") == 1) then {
			_this action ["LadderOff", nearestObject [position _this, "House"]];
		};

		if !([_this] call AGM_Core_fnc_inTransitionAnim) exitWith {};

		waitUntil {isTouchingGround _this};

		if !([_this] call AGM_Core_fnc_inTransitionAnim) exitWith {};

		if (vehicle _this != _this) exitWith {[_this] call AGM_Medical_fnc_animUnconscious};

		if (_this getVariable ["AGM_isUnconscious", false]) then {
			_this switchMove "Unconscious";
		};
	};

	if (vehicle _unit != _unit) then {
		_unit setVariable ["AGM_OriginalAnim", animationState _unit, True];
		_animation = getArray (configFile >> "CfgMovesMaleSdr" >> "States" >> animationState _unit >> "interpolateTo") select 0;

		if (_unit getVariable ["AGM_isUnconscious", false]) then {
			_unit switchMove _animation;
		};

		// handle parachute
		if (vehicle _unit isKindOf "ParachuteBase") then {
			_unit spawn _fnc_playAnim;
		};
	} else {
		_unit spawn _fnc_playAnim;
	};
};
