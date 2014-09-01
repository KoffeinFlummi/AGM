/*
	Name: AGM_Goggles_fnc_RainEffect
	
	Author: Garth de Wet (LH)
	
	Description:
		
	
	Parameters: 
		Nothing
	
	Returns:
		Nothing
	
	Example:
		[] spawn AGM_Goggles_fnc_RainEffect;
*/
#include "\AGM_Goggles\script.sqf"
if (isNull(uiNamespace getVariable ["AGM_Goggles_Rain", displayNull])) then {
	101 cutRsc["RscAGM_RainEffects", "PLAIN",0, false];
};
AGM_Goggles_RainDrops = [];
for "_i" from 0 to 7 do {
	AGM_Goggles_RainDrops pushBack [((uiNamespace getVariable ["AGM_Goggles_Rain", displayNull]) displayCtrl (10670 + _i)), false, 0, 0];
	((AGM_Goggles_RainDrops select _i) select 0) ctrlShow false;
};
_fnc_underCover = {
	private ["_pos"];
	_pos = eyePos (_this select 0);

	(lineIntersects [_pos, _pos vectorAdd [0,0,15], player])
};
while {alive player} do {
	sleep 0.25;
	if (true) then {
		// Detect if curator interface is open and disable effects
		if (!isNull(findDisplay 312)) exitWith {};
		// Ignore if player is under water
		if (!AGM_Goggles_EffectsActive ||{underwater player}) exitWith{call AGM_Goggles_fnc_removeRainEffect;};
		// cleanup "dead drops"
		{
			if ((_x select 1) && {time >= (_x select 2)}) then {
				(_x select 0) ctrlShow false;
				_x set [1, false];
			};
		} count AGM_Goggles_RainDrops;
		// Rain is happening
		if (rain > 0.05 && {!([player] call _fnc_underCover)}) exitWith {
			_limit = ceil(rain * (count AGM_Goggles_RainDrops)) max 1;
			_done = 0;
			{
				if(_done == _limit) exitWith{};
				// Droplet is not active, it can be used
				if (!(_x select 1) && {time >= (_x select 3)}) then {
					_x set [1, true];
					_x set [2, ((random 1) * 2.5) max 1];
					
					_xAxis = safezoneX + ((random 1) * SafezoneW);
					_yAxis = safezoneY + ((random 1) * SafezoneH);
					_amount = sunOrMoon max 0.5;
					_color = [_amount,_amount,_amount,random 0.8 max 0.5];
					_size = 0.06 + (random 0.03);
					disableSerialization;
					_ctrl = _x select 0;
					
					_ctrl ctrlSetPosition [_xAxis, _yAxis, _size, _size];
					_ctrl ctrlCommit 0;
					_ctrl ctrlShow true;
					_ctrl ctrlSetTextColor _color;
					
					_ctrl ctrlSetPosition [_xAxis, _yAxis, (_size + (random 0.02)), (_size + (random 0.02))];
					_ctrl ctrlCommit (_x select 2);
					_x set [2, time + (_x select 2)];
					_x set [3, (_x select 2) + 1 + random 1];
					_done = _done + 1;
				}else { // droplet is currently active
					_done = _done + 1;
				};
			} count AGM_Goggles_RainDrops;
		};
	};
};