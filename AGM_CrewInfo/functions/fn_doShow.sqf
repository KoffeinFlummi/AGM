/*
	Author: aeroson
	
	Description:
		Shows the actual text and sets text the crew info
		What really does make difference for the engine is simulation of CfgAmmo
		Priority of roles is: gunner, codriver, commander, ffv, cargo
	
	Parameters: 
		None
	
	Returns:
		Nothing
*/


private["_text", "_vehicle", "_vehicleConfig", "_crew", "_config", "_role", "_player", "_isAir", "_vehicle","_text","_roleImages"];

#define CARGO 0
#define _PILOT 1
#define _DRIVER 2
#define COMMANDER 3
#define GUNNER 4
#define FFV 5
#define DEFAULT 6
#define DRIVER ( if(_isAir) then {_PILOT} else {_DRIVER} )
#define CODRIVER DRIVER


_roleImages = [
	"a3\ui_f\data\IGUI\Cfg\Actions\getincargo_ca.paa",
	"a3\ui_f\data\IGUI\Cfg\Actions\getinpilot_ca.paa",
	"a3\ui_f\data\IGUI\Cfg\Actions\getindriver_ca.paa",
	"a3\ui_f\data\IGUI\Cfg\Actions\getincommander_ca.paa",
	"a3\ui_f\data\IGUI\Cfg\Actions\getingunner_ca.paa",

	"a3\ui_f\data\IGUI\Cfg\Actions\reammo_ca.paa", //FFV
	"a3\ui_f\data\IGUI\Cfg\Actions\refuel_ca.paa" //DEFAULT DEBUG
];




_player = call AGM_Core_fnc_player;
_vehicle = vehicle _player;
_type = typeOf _vehicle;
_config = configFile >> "CfgVehicles" >> _type;
_text = format["<t size='1.4'><img image='%1'></t> <t size='1.7' shadow='true'>%2</t><br/>", getText(_config>>"picture"), getText (_config >> "DisplayName")];






getDataForType = {

	private ["_type", "_varName", "_data"];


	_type = _this select 0;


	_varName = format ["AGM_CrewInfo_Cache_%1", _type];
	_data = + (uiNamespace getVariable _varName);

	if (!isNil "_data") exitWith {
		_data
	};

	_data = [];


	private ["_isAir", "_config", "_fnc_addTurret", "_fnc_addTurretUnit"];


	_isAir = false;


	_config = configFile >> "CfgVehicles" >> (typeOf _vehicle);
	while{configName _config != "Air" && configName _config != "All"} do {
		_config = inheritsFrom _config;
	};
	if(configName _config == "Air") then {
		_isAir = true;
	};


	_fnc_addTurretUnit = {

		private  ["_config", "_path", "_role", "_simulationEmpty", "_simulationLaserDesignate", "_simulationOther"];

		_config = _this select 0;
		_path = _this select 1;
		_role = CARGO;

		_simulationEmpty = 0;
		_simulationLaserDesignate = 0;
		_simulationOther = 0;
		{
			{
				_magazine = configFile >> "CfgMagazines" >> _x;
				_ammo = configfile >> "CfgAmmo" >> getText (_magazine >> "ammo");
				_simulation = getText (_ammo >> "simulation");

				if(_simulation=="") then {
					_simulationEmpty = _simulationEmpty + 1;
				} else {
					if(_simulation=="laserDesignate") then {
						_simulationLaserDesignate = _simulationLaserDesignate + 1;
					} else {
						_simulationOther = _simulationOther + 1;
					};
				};

			} forEach getArray (configfile >> "CfgWeapons" >> _x >> "magazines");
		} forEach getArray (_config	>> "weapons");

		if(_simulationOther>0) then {
			_role = GUNNER;
		};
		if (_role == CARGO && {getNumber (_config >> "isCopilot") == 1}) then {
			_role = CODRIVER;
		};
		if (_role == CARGO && {_simulationLaserDesignate>0 || getNumber (_config >> "primaryObserver") == 1}) then {
			_role = COMMANDER;
		};
		if (_role == CARGO && {getNumber (_config >> "isPersonTurret") == 1}) then {
			_role = FFV;
		};

		_data pushBack [_path, _role];	

	};


	_fnc_addTurret = {

		private ["_config", "_path", "_count", "_offset", "_index", "_turretPath", "_turretConfig"];

		_config = _this select 0;
		_path = _this select 1;

		_config = _config >> "Turrets";
		_count = count _config;


		_offset = 0;	

		for "_index" from 0 to (_count - 1) do {
			_turretPath = _path + [_index - _offset];
			_turretConfig = _config select _index;
			if (isClass _turretConfig) then {			
		 		[_turretConfig, _turretPath] call _fnc_addTurretUnit;
				[_turretConfig, _turretPath] call _fnc_addTurret;
			} else {
				_offset = _offset + 1;
			};

		};

	};


	_config = configFile >> "CfgVehicles" >> _type;
	[_config, []] call _fnc_addTurret;

	_data = [_isAir, _data];
	uiNamespace setVariable [_varName, _data];

	_data

};






private ["_data", "_isAir"];

_data = [_type] call getDataForType;

_isAir = _data select 0;
_data = _data select 1;


turretUnits = [_data, { _vehicle turretUnit (_x select 0) } ] call AGM_Core_fnc_map;
turretRoleTypes = [_data, { _x select 1 } ] call AGM_Core_fnc_map;







private["_index", "_cargoIndex", "_cargoIsCoDriver", "_roleType"];

_cargoIsCoDriver = getArray (_config >> "cargoIsCoDriver");

{
	if(alive _x && {format["%1", name _x] != ""} && {format["%1", name _x] != "Error: No unit"}) then {

		_roleType = DEFAULT;		

		switch (_x) do {				
			case commander _vehicle: {
				_roleType = COMMANDER;
			};
			case gunner _vehicle: {
				_roleType = GUNNER;
			};					
			case driver _vehicle: {	 
				_roleType = DRIVER;
			};					
			default {
				_index = turretUnits find _x;
				if(_index !=-1 ) then {
					_roleType = turretRoleTypes select _index;
				} else {
					_roleType = CARGO;
				};
			};
		};

		_text = _text + format["<t size='1.5' shadow='true'>%1</t> <t size='1.3'><img image='%2'></t><br/>", name _x, _roleImages select _roleType];
	};
} forEach crew _vehicle;


cutRsc ["AGM_CrewInfo_dialog", "PLAIN", 1, false];
[_text] call AGM_CrewInfo_fnc_setText;