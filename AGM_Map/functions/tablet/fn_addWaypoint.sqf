private ["_marker", "_markerwp", "_cursorPos"];

player setVariable ["AGM_Pos_onDbl", [_this select 1, _this select 2]];
_cursorPos = ((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1201) posScreenToWorld [_this select 1, _this select 2];
_mouseButton = _this select 0;
_posx = _this select 1;
_posy = _this select 2;
_keyButton = _this select 3;

_side = side player;
_groups = [allGroups, {side leader _this == _side}] call AGM_Core_fnc_filter;

if(_mouseButton == 0 && _keyButton) then {
	((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1620) ctrlSetPosition [_posx - 0.1, _posy + 0.05];
	((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1621) ctrlSetPosition [_posx + 0.05, _posy + 0.05];
	((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1622) ctrlSetPosition [_posx - 0.097, _posy - 0.05];
	((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1619) ctrlSetPosition [_posx - 0.11, _posy - 0.25];

	AGM_Waypoint_ListBox = [];
	AGM_Waypoint_Names = [];

	{
		AGM_Waypoint_ListBox = AGM_Waypoint_ListBox + [_x]; //[]
		AGM_Waypoint_Names = AGM_Waypoint_Names + [str _x];
		((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1622) lbAdd str (_x);
	} forEach _groups;
	((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1622) lbSetSelected [0, true];

	((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1619) ctrlCommit 0;
	((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1620) ctrlCommit 0;
	((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1621) ctrlCommit 0;
	((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1622) ctrlCommit 0;

	((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1619) ctrlShow true;
	((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1620) ctrlShow true;
	((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1621) ctrlShow true;
	((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1622) ctrlShow true;
};
