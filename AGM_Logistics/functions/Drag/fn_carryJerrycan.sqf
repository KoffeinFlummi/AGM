// by commy2

#define ANIM_CARRY "AmovPercMstpSnonWnonDnon"
#define ATTACH_POINT [0.01, 0, -0.19]

_this spawn {
	_unit = _this select 0;
	_target = _this select 1;

	_unit setVariable ["AGM_isDragging", true];
	_unit setVariable ["AGM_carriedItem", _target, true];
	_target setVariable ["AGM_isUsedBy", _unit, true];

	if (currentWeapon _unit != "" && {currentWeapon _unit == primaryWeapon _unit} && {weaponLowered _unit} && {stance _unit == "STAND"}) then {
		_unit playMove "amovpercmstpsraswrfldnon";
	};
	_unit action ["SwitchWeapon", _unit, _unit, 99];

	_unit playMove ANIM_CARRY;
	waitUntil {animationState _unit == ANIM_CARRY};

	// exit here if the player releases the jerry can before the animation is finished
	if !(_unit getVariable ["AGM_isDragging", false]) exitWith {};

	_target attachTo [_unit, ATTACH_POINT, "RightHand"];
	[_target, "{_this setDir 273}", _target] call AGM_Core_fnc_execRemoteFnc;	// the setPos getPos trick doesn't work for attached objects

	_unit forceWalk true;

	waitUntil {
		if (stance _unit != "STAND" || {currentWeapon _unit != ""}) exitWith {
			[_unit, _target] call AGM_Drag_fnc_dropJerrycan;
		};

		!(_unit getVariable ["AGM_isDragging", false])
	};
};
