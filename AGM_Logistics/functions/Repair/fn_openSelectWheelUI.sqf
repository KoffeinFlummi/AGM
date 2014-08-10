// by commy2

private ["_vehicle", "_wheels", "_listIDC", "_count", "_index", "_wheel", "_name", "_picture", "_lbIndex"];

_vehicle = _this select 0;
//_wheels = _this select 1;

_wheels = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_Wheels");

_wheels = [_wheels, {AGM_Interaction_Target getHitPointDamage _this > 0}] call AGM_Core_fnc_filter;
_count = count _wheels;

_actions = [];
for "_index" from 0 to (_count - 1) do {
	_wheel = _wheels select _index;
	//_name = [_wheel] call AGM_Repair_fnc_getHitPointName;
	_name = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_WheelsLocalized") select (getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "AGM_Wheels") find _wheel);
	_picture = "AGM_Interaction\UI\IconInteraction_ca.paa";

	if (_vehicle getHitPointDamage _wheel == 1) then {
		_action = [_name,
			{call AGM_Interaction_fnc_hideMenu;_vehicle = AGM_Interaction_Target;_wheel = _this select 5;[_vehicle, _wheel] call AGM_Repair_fnc_repairWheel;},
			{true}, 0,
			_picture,
			_wheel
		];
		_actions set [count _actions, _action];	
	};
};

[_actions, {"Default" call AGM_Interaction_fnc_openMenu;}] call AGM_Interaction_fnc_openSelectMenu;