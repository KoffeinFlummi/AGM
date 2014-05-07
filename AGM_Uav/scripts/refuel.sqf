_target = _this select 0;
_caller = _this select 1;

hint format ["1%", _target];

if(fuel _target < 1) then {
	if((magazines _caller) find "Laserbatteries" > -1) then {
		_target setFuel 1;
		_caller removeMagazine "Laserbatteries";
		sleep 2;
		hint format ["1%", fuel _target];
	} else {hint "You need a Laserbatterie to refuel."};
} else {hint "Your drone is already full."};

/*
stringtable.xml is coming soon.
*/
