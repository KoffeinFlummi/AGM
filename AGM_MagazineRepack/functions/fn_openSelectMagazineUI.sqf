// by commy2

private ["_magazines", "_repackTime", "_listIDC", "_count", "_index", "_magazine", "_time", "_displayName", "_picture"];

_magazines = _this select 0;
_repackTime = _this select 1;

_count = count _magazines;

_listIDC = [localize "STR_AGM_MagazineRepack_SelectMagazineMenu", localize "STR_AGM_MagazineRepack_SelectMagazine", "_data = call compile lbData [8866, lbCurSel 8866]; closeDialog 0; if (isNil '_data') exitWith {}; [_data select 1, _data, 'AGM_MagazineRepack_fnc_magazineRepackCallback', localize 'STR_AGM_MagazineRepack_RepackingMagazine'] call AGM_Core_fnc_progressBar; [player] call AGM_core_fnc_goKneeling;"] call AGM_Interaction_fnc_openSelectMenu;

for "_index" from 0 to (_count - 1) do {
	_magazine = _magazines select _index;
	_time = _repackTime select _index;

	_displayName = getText (configFile >> "CfgMagazines" >> _magazine >> "displayName");
	_picture = getText (configFile >> "CfgMagazines" >> _magazine >> "picture");

	_index = lbAdd [_listIDC, _displayName];
	lbSetData [_listIDC, _index, str [_magazine, _time]];
	lbSetPicture [_listIDC, _index, _picture];
};

lbSetCurSel [_listIDC, 0];
