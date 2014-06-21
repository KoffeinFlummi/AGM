// by commy2

_index = _this select 0;

_name = format ["AGM_%1", AGM_Core_OptionNames select _index];

_index1 = AGM_Core_OptionNamesNew find _name;
_state = if (_index1 == -1) then {_index1 = count AGM_Core_OptionNamesNew; !(profileNamespace getVariable _name)} else {!(AGM_Core_OptionStatesNew select _index1)};

disableSerialization;
_dlgMenuDialog = uiNamespace getVariable "AGM_Core_MenuDialog";

_control = _dlgMenuDialog displayCtrl (300 + _index);
_control ctrlSetText format ["\AGM_Core\UI\box_%1checked_ca.paa", ["un", ""] select _state];

AGM_Core_OptionNamesNew set [_index1, _name];
AGM_Core_OptionStatesNew set [_index1, _state];
