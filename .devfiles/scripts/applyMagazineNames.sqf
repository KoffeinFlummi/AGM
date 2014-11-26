// by commy2

private ["_magazines", "_dlgInteraction", "_index", "_ctrlInteraction", "_magazine", "_displayName"];

_magazines = _this select 0;

_magazines resize 10;

disableSerialization;
_dlgInteraction = uiNamespace getVariable "AGM_Interaction_Dialog";

for "_index" from 0 to 10 do {
	_ctrlInteraction = _dlgInteraction displayCtrl (10 + _index);

	_magazine = _magazines select _index;
	_displayName = if (isNil "_magazine") then {""} else {
		getText (configFile >> "CfgMagazines" >> _magazine >> "displayName");
	};

	_ctrlInteraction ctrlSetText _displayName;
};
