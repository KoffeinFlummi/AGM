// by commy2

private ["_vehicle", "_magazine", "_magazines1", "_magazines2", "_index"];

_vehicle = _this select 0;
_magazine = _this select 1;

_magazines1 = getArray (configFile >> "CfgVehicles" >> typeOf _vehicle >> "Turrets" >> "MainTurret" >> "magazines");
_magazines2 = getArray (configFile >> "CfgMagazines" >> _magazine >> "AGM_Magazines");

_magazines1 pushBack "";
_magazines2 pushBack "";

_index = 0;
while {
	_magazine = _magazines2 select _index;
	!(_magazine in _magazines1)
} do {
	_index = _index + 1;
};
_magazine
