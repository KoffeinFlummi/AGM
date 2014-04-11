// by commy2
_key = _this select 0;
_shft = [0, 1] select (_this select 1);
_ctrl = [0, 1] select (_this select 2);
_alt = [0, 1] select (_this select 3);

_keyMenu = getNumber(configFile >> "BWA3_Realism_Keys" >> "BWA3_Interaction_Menu" >> "key");
_ctrlMenu = getNumber(configFile >> "BWA3_Realism_Keys" >> "BWA3_Interaction_Menu" >> "ctrl");
_altMenu = getNumber(configFile >> "BWA3_Realism_Keys" >> "BWA3_Interaction_Menu" >> "alt");
_shiftMenu = getNumber(configFile >> "BWA3_Realism_Keys" >> "BWA3_Interaction_Menu" >> "shift");
if (_key == _keyMenu and _ctrl == _ctrlMenu and _shft == _shiftMenu and _alt == _altMenu) exitWith {
  if !dialog then {
    "" call BWA3_Interaction_fnc_openMenu;
  } else {
    closeDialog 0;
  };
  true
};

_keyMenuSelf = getNumber(configFile >> "BWA3_Realism_Keys" >> "BWA3_Interaction_Menu_Self" >> "key");
_ctrlMenuSelf = getNumber(configFile >> "BWA3_Realism_Keys" >> "BWA3_Interaction_Menu_Self" >> "ctrl");
_altMenuSelf = getNumber(configFile >> "BWA3_Realism_Keys" >> "BWA3_Interaction_Menu_Self" >> "alt");
_shiftMenuSelf = getNumber(configFile >> "BWA3_Realism_Keys" >> "BWA3_Interaction_Menu_Self" >> "shift");
if (_key == _keyMenuSelf and _ctrl == _ctrlMenuSelf and _shft == _shiftMenuSelf and _alt == _altMenuSelf) exitWith {
  if !dialog then {
    "" call BWA3_Interaction_fnc_openMenuSelf;
  } else {
    closeDialog 0;
  };
  true
};

false