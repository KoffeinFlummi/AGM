// by commy2

player addEventHandler ["Take", {if (_this select 2 == currentMagazine player) then {[currentWeapon player, vehicle player, true] call AGM_Reload_fnc_checkAmmo}}];
