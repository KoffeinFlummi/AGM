// by commy2

_key = _this select 0;
_shft = _this select 1;
_ctrl = _this select 2;
_alt = _this select 3;
_isInput = false;

if (_key == 54) then {
	BWA3_Interaction_keyDown = true;
	_isInput = true;
};

if (_key == 221) then {
	if !dialog then {
		call ([BWA3_Interaction_fnc_openMenu, BWA3_Interaction_fnc_openMenuSelf] select _ctrl);
	};
	_isInput = true;
};
_isInput
