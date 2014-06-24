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

_text = switch (typeName _text) do {
	case "STRING" : {text _text};
	case "TEXT" : {_text};
	default {text str _text};
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
