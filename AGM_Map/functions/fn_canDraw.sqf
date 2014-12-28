// by CAA-Picard

(missionNameSpace getVariable ["AGM_Map_syncMarkers", true] && {AGM_Map_EveryoneCanDrawOnBriefing > 0}) ||
{(!isNull player) && {"AGM_MapTools" in items player}}
