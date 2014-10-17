//ctrlShow [1612, true];
//ctrlShow [1613, true];

player setVariable ["AGM_Pos_onDbl", _this];
_posx = _this select 0;
_posy = _this select 1;

((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1612) ctrlSetPosition [_posx - 0.1, _posy + 0.05];
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1613) ctrlSetPosition [_posx + 0.05, _posy + 0.05];
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1614) ctrlSetPosition [_posx - 0.097, _posy - 0.05];
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1615) ctrlSetPosition [_posx - 0.11, _posy - 0.25];
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1616) ctrlSetPosition [_posx - 0.097, _posy - 0.17];
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1617) ctrlSetPosition [_posx - 0.097, _posy - 0.23];
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1618) ctrlSetPosition [_posx - 0.097, _posy - 0.11];

{
	((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1616) lbAdd _x;
} forEach ["Black", "Yellow", "BLUFOR", "OPFOR", "INDEPENDENT", "CIVILIAN"];
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1616) lbSetSelected [0, true];

{
	((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1617) lbAdd _x;
} forEach ["Dot", "Infantery", "Armored", "Aircraft", "Pick Up", "Ambush", "Destroy"];
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1617) lbSetSelected [0, true];

((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1618) sliderSetRange [0, 360];

((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1612) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1613) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1614) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1615) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1616) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1617) ctrlCommit 0;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1618) ctrlCommit 0;

((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1612) ctrlShow true;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1613) ctrlShow true;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1614) ctrlShow true;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1615) ctrlShow true;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1616) ctrlShow true;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1617) ctrlShow true;
((uiNamespace getVariable "AGM_tablet_dlg") displayCtrl 1618) ctrlShow true;