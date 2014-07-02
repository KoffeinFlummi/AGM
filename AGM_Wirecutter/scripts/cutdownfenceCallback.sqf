_fence = _this select 0;
AGM_Wirecutter_isCutting = false;
if(alive player)then{
	_fence setdamage 1;
	[localize "STR_AGM_FenceCut"] call AGM_Core_fnc_displayTextStructured;
	player playMoveNow "AmovPknlMstpSrasWrflDnon";
};