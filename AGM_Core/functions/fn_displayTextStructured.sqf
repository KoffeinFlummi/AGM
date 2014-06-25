/*
 * Author: commy2
 *
 * Display a structured text.
 * 
 * Argument:
 * 0: Text (Anything)
 * 
 * Return value:
 * Nothing
 */

private ["_text", "_ctrlHint"];

_text = _this select 0;

if (typeName _text != "TEXT") then {
	_text = composeText [lineBreak, parseText format ["<t align='center'>%1</t>", _text]];
};

("AGM_RscHint" call BIS_fnc_rscLayer) cutRsc ["AGM_RscHint", "PLAIN", 0, true];

disableSerialization;
_ctrlHint = uiNamespace getVariable "AGM_ctrlHint";

_ctrlHint ctrlSetStructuredText _text;
_ctrlHint ctrlSetPosition [
	safeZoneW + safeZoneX - 0.2 * safezoneW,
	safeZoneY + 0.2 * safezoneH,
	0.2 * safeZoneW,
	0.1 * SafeZoneH
];
_ctrlHint ctrlCommit 0.2;
