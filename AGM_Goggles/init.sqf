/*
BWA3 script, by commy2
this code is property of the ArmA 3 Bundeswehr modification
ask us nicely at http://www.bwmod.de/ if you want to re-use any of this script
we don't support changed code based on this work
*/

sleep 0.1;

AGM_ppEffectGoggles = ppEffectCreate ["colorCorrections", 1234];
AGM_ppEffectGoggles ppEffectEnable true;

player addEventHandler ["init", {call AGM_Goggles_fnc_gogglesEffect}];
player addEventHandler ["respawn", {call AGM_Goggles_fnc_gogglesEffect}];
player addEventHandler ["put", {call AGM_Goggles_fnc_gogglesEffect}];
player addEventHandler ["take", {call AGM_Goggles_fnc_gogglesEffect}];

call AGM_Goggles_fnc_gogglesEffect;
