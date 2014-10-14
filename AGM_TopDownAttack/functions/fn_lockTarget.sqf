// by commy2

#define COLOR_ON [0.2941, 0.8745, 0.2157, 1.0]
#define COLOR_OFF [0.2941, 0.2941, 0.2941, 1.0]
#define COLOR_ORANGE [0.9255, 0.5216, 0.1216, 1.0]

0 spawn {
	if (!isNull (missionNamespace getVariable ["AGM_TopDownAttack_LockedTarget", objNull]) || {cameraView != "GUNNER"}) exitWith {
		AGM_TopDownAttack_LockedTarget = objNull;
		AGM_TopDownAttack_isTargetLocked = false;
	};

	_weapon = currentWeapon player;
	AGM_TopDownAttack_LockedTarget = [2000] call AGM_Core_fnc_getTargetObject;
	AGM_TopDownAttack_isTargetLocked = false;

	if !(AGM_TopDownAttack_LockedTarget isKindOf "Tank" || {AGM_TopDownAttack_LockedTarget isKindOf "Car"}) exitWith {};

	disableSerialization;
	_dlgJavelinOptics = uiNamespace getVariable ["AGM_dlgJavelinOptics", displayNull];
	_ctrlJavelinSeek = _dlgJavelinOptics displayCtrl 1032;
	_ctrlJavelinMssl = _dlgJavelinOptics displayCtrl 1005;

	_time = time + (2 + random 1);

	_alternate = false;
	waitUntil {
		playSound "AGM_Sound_Locked2"; sleep 0.1;
		_alternate = !_alternate;
		_ctrlJavelinSeek ctrlSetTextColor ([COLOR_OFF, COLOR_ORANGE] select _alternate);
		time > _time || {[2000] call AGM_Core_fnc_getTargetObject != AGM_TopDownAttack_LockedTarget} || {currentWeapon player != _weapon} || {cameraView != "GUNNER"}
	};

	if ([2000] call AGM_Core_fnc_getTargetObject != AGM_TopDownAttack_LockedTarget || {currentWeapon player != _weapon} || {cameraView != "GUNNER"}) exitWith {
		_ctrlJavelinSeek ctrlSetTextColor COLOR_OFF;
	};

	AGM_TopDownAttack_isTargetLocked = true;

	_ctrlJavelinSeek ctrlSetTextColor COLOR_ORANGE;
	_ctrlJavelinMssl ctrlSetTextColor COLOR_ON;

	waitUntil {
		playSound "AGM_Sound_Locked1"; sleep 0.1;
		[2000] call AGM_Core_fnc_getTargetObject != AGM_TopDownAttack_LockedTarget || {currentWeapon player != _weapon} || {cameraView != "GUNNER"}
	};

	_ctrlJavelinSeek ctrlSetTextColor COLOR_OFF;
	_ctrlJavelinMssl ctrlSetTextColor COLOR_OFF;

	AGM_TopDownAttack_LockedTarget = objNull;
	AGM_TopDownAttack_isTargetLocked = false;
};
