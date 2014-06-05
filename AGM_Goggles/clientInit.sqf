// by commy2

AGM_Goggles_ppEffectGoggles = ppEffectCreate ["ColorCorrections", 1234];
AGM_Goggles_ppEffectGoggles ppEffectEnable true;

player addEventHandler ["Init", {call AGM_Goggles_fnc_gogglesEffect}];
player addEventHandler ["Respawn", {call AGM_Goggles_fnc_gogglesEffect}];
player addEventHandler ["Put", {call AGM_Goggles_fnc_gogglesEffect}];
player addEventHandler ["Take", {call AGM_Goggles_fnc_gogglesEffect}];

call AGM_Goggles_fnc_gogglesEffect;
