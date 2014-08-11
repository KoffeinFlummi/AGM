/*
	Name: AGM_Explosives_fnc_Place_Approve
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Approves placement of the explosive, releases the placement object for it to settle in a location suitable for the explosive to be created.
	
	Parameters:
		Nothing
	
	Returns:
		Nothing
	
	Example:
		spawn AGM_Explosives_fnc_Place_Approve;
*/
if (AGM_Explosives_pfeh_running) then {
	["AGM_Explosives_Placement","OnEachFrame"] call BIS_fnc_removeStackedEventHandler;
	AGM_Explosives_pfeh_running = false;
};
private ["_mag", "_setup"];
_setup = AGM_Explosives_Setup;
AGM_Explosives_Setup = objNull;
player forceWalk false;
if ((_setup getVariable ["AGM_Class", ""]) != "") then {
	_dir = (getDir _setup);
	if (_dir > 180) then {
		_dir = _dir - 180;
	} else {
		_dir = 180 + _dir;
	};
	_setup setVariable ["AGM_Dir", _dir];
	player setVariable ["AGM_PlantingExplosive", true];
	_setup addEventHandler ["EpeContactStart", {
		if (!((_this select 0) getVariable ["AGM_Handled", false])) then {
			(_this select 0) setVariable ["AGM_Handled", true];
			player setVariable ["AGM_PlantingExplosive", false];
			_attachTo = objNull;
			if (!isNull (_this select 1) && {(_this select 1) isKindOf "AllVehicles"}) then {
				_attachTo = (_this select 1);
			};
			[(_this select 0),_attachTo] spawn {
				private ["_mag", "_setup", "_dir"];
				_setup = _this select 0;
				_mag = _setup getVariable ["AGM_Class", ""];
				_dir = _setup getVariable ["AGM_Dir", 0];
				
				sleep getNumber(ConfigFile >> "CfgMagazines" >> _mag >> "AGM_DelayTime");
				_explosive = [player, GetPosATL _setup, _dir, _mag, _setup getVariable "AGM_Trigger", [_setup getVariable "AGM_Timer"], isNull (_this select 1)] call AGM_Explosives_fnc_PlaceExplosive;
				deleteVehicle _setup;
				if (!isNull(_explosive)) then {
					player RemoveMagazine _mag;
					sleep 0.2;
					if (!isNull (_this select 1)) then {
						_explosive attachTo [(_this select 1)];
						_dir = _dir - (getDir (_this select 1));
						[[_explosive, _dir, 0], "AGM_Explosives_fnc_setPos"] call AGM_Core_fnc_execRemoteFnc;
					};
				};
			};
		};
	}];
	_setup enableSimulationGlobal true;
	player playActionNow "MedicOther";
	[_setup] spawn {
		sleep 10;
		if (!isNull (_this select 0)) then {
			player setVariable ["AGM_PlantingExplosive", false];
			deleteVehicle (_this select 0);
		};
	};
}else{
	deleteVehicle _setup;
};