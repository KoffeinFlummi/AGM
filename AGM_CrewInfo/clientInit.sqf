
if (!hasInterface) exitWith {};


#include "macros.sqf"
#include "dialogDefines.sqf"


//GVAR(isHidden) = true;
GVAR(timeToHide) = -1;


GVAR(onMouseZChanged) = {
	private["_player"];
	_player = call AGM_Core_fnc_player;
	if(vehicle _player != _player && {!(vehicle _player isKindOf "ParachuteBase")}) then {
		if(GVAR(timeToHide) < time) then {
			GVAR(timeToHide) = time + 1;
		} else {
			GVAR(timeToHide) = GVAR(timeToHide) + 0.5;
		};
		call GVAR(show);	
	} else {
		GVAR(timeToHide) = -1;
		//call GVAR(hide);	
	};
};

[{_this call GVAR(onMouseZChanged)}] call AGM_Core_fnc_addScrollWheelEventHandler;
//(findDisplay 46) displayAddEventHandler ["MouseZChanged", {_this call GVAR(onMouseZChanged)}];


GVAR(setText) = {
	private["_text", "_ctrl"];
	disableSerialization;
	_text = _this select 0;
	_ctrl = (uiNamespace getVariable QGVAR(dialog)) displayCtrl AGM_CrewInfo_TextIDC;
	_ctrl ctrlSetStructuredText parseText _text;
	_ctrl ctrlCommit 0; 
};


GVAR(canShow) = {
	private["_player"];
	_player = call AGM_Core_fnc_player;
	GVAR(timeToHide) > time && {vehicle _player != _player} && {!(vehicle _player isKindOf "ParachuteBase")};
};


//GVAR(hide) = {
	//GVAR(isHidden) = true;
	/*if(!GVAR(isHidden)) then {
		GVAR(isHidden) = true;
		cutRsc [QGVAR(dialog), "PLAIN", 1, false]; 
		[""] call GVAR(setText);
	};*/
//};


#define COMMANDER_IMG QUOTE(a3\ui_f\data\IGUI\Cfg\Actions\getincommander_ca.paa)
#define GUNNER_IMG QUOTE(a3\ui_f\data\IGUI\Cfg\Actions\getingunner_ca.paa)
#define DRIVER_IMG QUOTE(a3\ui_f\data\IGUI\Cfg\Actions\getindriver_ca.paa)
#define CARGO_IMG QUOTE(a3\ui_f\data\IGUI\Cfg\Actions\getincargo_ca.paa)

#define LINE(UNIT, IMAGE) format["<t size='1.5' shadow='true'>%1</t> <t size='1.3'><img image='%2'></t><br/>", name UNIT, IMAGE]

GVAR(show) = {
	private["_text", "_vehicle", "_crew", "_config", "_role", "_player"];
	//GVAR(isHidden) = false;
	_text = "";	 
	_player = call AGM_Core_fnc_player;
	_vehicle = vehicle _player;
	_crew = crew _vehicle;
	_config = configFile >> "CfgVehicles" >> (typeOf _vehicle);
	_text= _text + format["<t size='1.4'><img image='%1'></t> <t size='1.7' shadow='true'>%2</t><br/>", getText(_config>>"picture"), getText (_config >> "DisplayName")];

	{
		if(alive _x && {format["%1", name _x] != ""} && {format["%1", name _x] != "Error: No unit"}) then {

			_role = assignedVehicleRole _x;
			switch (_x) do {				
				case commander _vehicle: {
					_text = _text + LINE(_x, COMMANDER_IMG);
				};
				case gunner _vehicle: {
					_text = _text + LINE(_x, GUNNER_IMG);
				};					
				case driver _vehicle: {	 
					_text = _text + LINE(_x, DRIVER_IMG);
				};					
				default {
					if(format["%1", (_role select 0)] != "Turret") then {
						_text = _text + LINE(_x, CARGO_IMG);
					} else {
						if(count (_vehicle weaponsTurret (_role select 1)) == 0) then {
							_text = _text + LINE(_x, DRIVER_IMG);
						} else {
							_text = _text + LINE(_x, GUNNER_IMG);
						};
					};
				};
			};

		};
	} forEach _crew;

	cutRsc [QGVAR(dialog), "PLAIN", 1, false];
	[_text] call GVAR(setText);	
};




[] spawn {

	while {true} do {

		waitUntil {
			sleep 1;
			call GVAR(canShow);
		};

		while {call GVAR(canShow)} do {
			call GVAR(show);
			sleep 0.1;
		};

		GVAR(timeToHide) = -1;
		//call GVAR(hide);

	};

};

