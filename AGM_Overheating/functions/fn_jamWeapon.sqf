// based on KK_fnc_playerWeaponMulfunction from KillzoneKid

private ["_unit", "_weapon", "_jammedWeapons", "_actionID"];

_unit = _this select 0;
_weapon = _this select 1;

// don't jam a weapon with no rounds left
if (_unit ammo _weapon == 0) exitWith {};

_jammedWeapons = _unit getVariable ["AGM_Overheating_jammedWeapons", []];
_jammedWeapons set [count _jammedWeapons, _weapon];

_unit setVariable ["AGM_Overheating_jammedWeapons", _jammedWeapons];

// this is to re-activate the 'DefaultAction', so you can jam a weapon while full auto shooting
[_unit, _weapon] spawn {
	_unit = _this select 0;
	_weapon = _this select 1;

	_ammo = _unit ammo _weapon;

	_frame = diag_frameno;

	if (_ammo > 0) then {
		_unit setAmmo [_weapon, 0];

		waitUntil {_frame < diag_frameno};

		_unit setAmmo [_weapon, _ammo];
		//[localize "STR_AGM_Overheating_WeaponJammed"] call AGM_Core_fnc_displayTextStructured;
	};
};

// only display the hint once, after you try to shoot an already jammed weapon
AGM_Overheating_knowAboutJam = false;

_actionID = _unit addAction [
	"",
	{
		playSound3D ['a3\sounds_f\weapons\Other\dry9.wss', _this select 0];

		if (!(missionNamespace getVariable ["AGM_Overheating_knowAboutJam", false]) && {player ammo currentWeapon player > 0}) then {
			[localize "STR_AGM_Overheating_WeaponJammed"] call AGM_Core_fnc_displayTextStructured;
			AGM_Overheating_knowAboutJam = true;
		};
	},
	"",
	0,
	false,
	true,
	"DefaultAction",
	"player == vehicle player && {currentWeapon player in (player getVariable ['AGM_Overheating_jammedWeapons', []])}"
];

_unit setVariable ["AGM_JammingActionID", _actionID];
