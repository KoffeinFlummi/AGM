// by commy2

private ["_magazines", "_repackTime", "_listIDC", "_count", "_index", "_magazine", "_time", "_displayName", "_picture"];

_magazines = _this select 0;
_repackTime = _this select 1;

_count = count _magazines;

_actions = [localize "STR_AGM_MagazineRepack_SelectMagazineMenu", localize "STR_AGM_MagazineRepack_SelectMagazine"] call AGM_Interaction_fnc_prepareSelectMenu;
for "_index" from 0 to (_count - 1) do {
	_magazine = _magazines select _index;
	_time = _repackTime select _index;
	_displayName = getText (configFile >> "CfgMagazines" >> _magazine >> "displayName");
	_picture = getText (configFile >> "CfgMagazines" >> _magazine >> "picture");
	_actions = [
		_actions,
		_displayName,
		_picture,
		[_magazine, _time]
	] call AGM_Interaction_fnc_AddSelectableItem;
};

[
	_actions,
	{
		call AGM_Interaction_fnc_hideMenu;_data = _this;
		if (isNil "_data") exitWith {};
		_data set [1, parseNumber (_data select 1)];
		[_data select 1, _data, "AGM_MagazineRepack_fnc_magazineRepackCallback", localize "STR_AGM_MagazineRepack_RepackingMagazine"] call AGM_Core_fnc_progressBar;
		[player] call AGM_core_fnc_goKneeling;
	},
	{"Default" call AGM_Interaction_fnc_openMenu;}
] call AGM_Interaction_fnc_openSelectMenu;
