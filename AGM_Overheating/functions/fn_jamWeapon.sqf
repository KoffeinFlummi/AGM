// based on KK_fnc_playerWeaponMulfunction from KillzoneKid

private ["_unit", "_weapon", "_jammedWeapons"];

_unit = _this select 0;
_weapon = _this select 1;

_jammedWeapons = _unit getVariable ["AGM_Overheating_jammedWeapons", []];
_jammedWeapons set [count _jammedWeapons, _weapon];

_unit setVariable ["AGM_Overheating_jammedWeapons", _jammedWeapons];

[_unit, _weapon] spawn {
	_unit = _this select 0;
	_weapon = _this select 1;

	_ammo = _unit ammo _weapon;

	_frame = diag_frameno;

	if (_ammo > 0) then {
		_unit setAmmo [_weapon, 0];

		waitUntil {_frame < diag_frameno};

		_unit setAmmo [_weapon, _ammo];
		[localize "STR_AGM_Overheating_WeaponJammed"] call AGM_Core_fnc_displayTextStructured;
	};
};

AGM_JammingActionID = _unit addAction [
	"",
	{playSound3D ['a3\sounds_f\weapons\Other\dry9.wss', _this select 0]},
	"",
	0,
	false,
	true,
	"DefaultAction",
	"player == vehicle player && {currentWeapon player in (player getVariable ['AGM_Overheating_jammedWeapons', []])}"
];
