// by commy2

_keyCode = [_this select 1, _this select 2, _this select 3, _this select 4] call AGM_Core_fnc_convertKeyCode;
_vehicle = vehicle player;
_isInput = false;

if (_keyCode == profileNamespace getVariable "AGM_Key_openInteractionMenu") then {
	if !dialog then {
		"" call AGM_Interaction_fnc_openMenu;
	} else {
		closeDialog 0;
	};
	_isInput = true;
};

if (_keyCode == profileNamespace getVariable "AGM_Key_openInteractionMenuSelf") then {
	if !dialog then {
		"" call AGM_Interaction_fnc_openMenuSelf;
	} else {
		closeDialog 0;
	};
	_isInput = true;
};
_isInput
