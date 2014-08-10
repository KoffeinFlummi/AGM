// by commy2

private ["_magazines", "_repackTime", "_listIDC", "_count", "_index", "_magazine", "_time", "_displayName", "_picture"];

_magazines = _this select 0;
_repackTime = _this select 1;

_count = count _magazines;

_actions = [];
for "_index" from 0 to (_count - 1) do {
	_magazine = _magazines select _index;
	_time = _repackTime select _index;
	_displayName = getText (configFile >> "CfgMagazines" >> _magazine >> "displayName");
	_picture = getText (configFile >> "CfgMagazines" >> _magazine >> "picture");

	_action = [_displayName,
		{call AGM_Interaction_fnc_hideMenu;_data = _this select 5;
			if (isNil "_data") exitWith {};
			[_data select 1, _data, "AGM_MagazineRepack_fnc_magazineRepackCallback", localize "STR_AGM_MagazineRepack_RepackingMagazine"] call AGM_Core_fnc_progressBar;
			[player] call AGM_core_fnc_goKneeling;
		},
		{true}, 0,
		_picture,
		[_magazine, _time]
	];
	_actions set [count _actions, _action];
};

[_actions, {"Default" call AGM_Interaction_fnc_openMenu;}] call AGM_Interaction_fnc_openSelectMenu;