/*
	Name: AGM_Goggles_fnc_RainCheck
	
	Author: Garth de Wet (LH)
	
	Description:
	Adds/removes rain drops from the screen based on whether it is raining 
	or if the player is under cover.
	
	Parameters: 
	0: BOOL - Whether it is raining or not.
	
	Returns:
	Nothing
	
	Example:
	(rain > 0) call AGM_Goggles_fnc_RainCheck;
*/
private ["_rain", "_set", "_isRaining"];
#include "\AGM_Goggles\script.sqf"
#define MAXRAIN 4

_isRaining = _this;
_set = true;

if !(_isRaining) exitWith {
	if !(GETRAINT(RACTIVE)) exitWith {};
	_rain = GETRAINT(RAMOUNT) - 1;
	if (_rain < 1) then {
		_set = false;
		_rain = 0;
	};
	SETLRAIN(RACTIVE,_set);
	SETLRAIN(RAMOUNT,_rain);
	if (_set) then {
		GETRAIN call AGM_Goggles_fnc_ApplyRainEffect;
	} else {
		call AGM_Goggles_fnc_RemoveRainEffect;
	};
};

if (player call AGM_Goggles_fnc_isGogglesVisible) then {
	_rain = GETRAINT(RAMOUNT);
	if ((goggles player) call AGM_Goggles_fnc_isDivingGoggles) then {
		if !(underwater player) then {
			_rain = _rain + 1;
			if (_rain > MAXRAIN) then {
				_set = !GETRAINT(RACTIVE);
				_rain = MAXRAIN;
			};
			SETLRAIN(RACTIVE,true);
			SETLRAIN(RAMOUNT,_rain);
		} else {
			_set = false;
		};
	} else {
		private "_playerPosition";
		_playerPosition = getPosAsl player;
		if ([player] call AGM_Core_fnc_isInBuilding) then {
			_rain = _rain - 1;
		} else {
			_rain = _rain + 1;
		};
		_rain = CLAMP(_rain, 0, MAXRAIN);
		if (_rain < 1) then {
			_set = false;
			call AGM_Goggles_fnc_RemoveRainEffect;
		};
		SETLRAIN(RACTIVE,_set);
		SETLRAIN(RAMOUNT,_rain);
	};
	if (_set) then {
		GETRAIN call AGM_Goggles_fnc_ApplyRainEffect;
	};
} else {
	if (GETRAINT(RACTIVE) && {GETRAINT(RAMOUNT) > 0}) then {
		call AGM_Goggles_fnc_RemoveRainEffect;
		AGM_Goggles_Effects set [LRAIN, [false, 0, time]];
	};
};

