_vehicle = _this select 0;
_string = name _vehicle;

if ((damage _vehicle) > 0.001) then {
	if((_vehicle getHitPointDamage "HitLFWheel") > 0.01) then {
		_string = _string + "<br/><br/>LF Wheel is damaged";
	};
	 if ((_vehicle getHitPointDamage "HitLF2Wheel") > 0.01) then {
	 	_string = _string + "<br/><br/>LB Wheel is damaged";
	};
	 if ((_vehicle getHitPointDamage "HitRFWheel") > 0.01) then {
		_string = _string + "<br/><br/>RF Wheel is damaged";
	};
	if ((_vehicle getHitPointDamage "HitRF2Wheel") > 0.01) then {
		_string = _string + "<br/><br/>RB Wheel is damaged";
	};
} else {
	_string = _string + "<br/><br/>Everything is OK";
};

hintSilent parseText format ["%1", _string];