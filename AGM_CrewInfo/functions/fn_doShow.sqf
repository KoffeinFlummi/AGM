/*
	Author: aeroson
	
	Description:
	
	Parameters: 
		None
	
	Returns:
		Nothing
*/

#define QUOTE(A) #A

#define COMMANDER_IMG QUOTE(a3\ui_f\data\IGUI\Cfg\Actions\getincommander_ca.paa)
#define GUNNER_IMG QUOTE(a3\ui_f\data\IGUI\Cfg\Actions\getingunner_ca.paa)
#define DRIVER_IMG QUOTE(a3\ui_f\data\IGUI\Cfg\Actions\getindriver_ca.paa)
#define CARGO_IMG QUOTE(a3\ui_f\data\IGUI\Cfg\Actions\getincargo_ca.paa)

#define LINE(UNIT, IMAGE) format["<t size='1.5' shadow='true'>%1</t> <t size='1.3'><img image='%2'></t><br/>", name UNIT, IMAGE]

private["_text", "_vehicle", "_crew", "_config", "_role", "_player"];

_text = "";	 
_player = call AGM_Core_fnc_player;
_vehicle = vehicle _player;
_crew = crew _vehicle;
_config = configFile >> "CfgVehicles" >> (typeOf _vehicle);
_text = _text + format["<t size='1.4'><img image='%1'></t> <t size='1.7' shadow='true'>%2</t><br/>", getText(_config>>"picture"), getText (_config >> "DisplayName")];

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

cutRsc ["AGM_CrewInfo_dialog", "PLAIN", 1, false];
[_text] call AGM_CrewInfo_fnc_setText;	


