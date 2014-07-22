/*
 * Author: commy2
 *
 * Abhocken! Unit goes kneeling if not prone already and lowers weapon. Try, throw, catch because I'm bored.
 * 
 * Argument:
 * 0: Unit (Object)
 * 
 * Return value:
 * None.
 */

private "_unit";

_unit = _this select 0;

try {
	if (_unit == vehicle _unit) then {
		switch (currentWeapon _unit) do {
			case "" : {throw "AmovPknlMstpSnonWnonDnon"};
			case (primaryWeapon _unit) : {throw "AmovPknlMstpSlowWrflDnon"};
			case (secondaryWeapon _unit) : {throw "AmovPknlMstpSrasWlnrDnon"};
			case (handgunWeapon _unit) : {throw "AmovPknlMstpSlowWpstDnon"};
			case ([_unit] call AGM_Core_fnc_getBinocular) : {throw "AmovPknlMstpSoptWbinDnon"};
		};
	};
} catch {
	if (stance _unit != "PRONE") then {
		[[_unit, _exception], "{(_this select 0) playMove (_this select 1)}", _unit] call AGM_Core_fnc_execRemoteFnc;
	};
};
