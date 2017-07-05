/*
	Name: AGM_Interaction_fnc_HandleInventoryClick
	
	Author:
		Garth de Wet (LH)
	
	Description:
		Handles when the player double clicks in the inventory, checks the object and calls AGM_Action class on the object.
	
	Parameters:
		0: NUMBER - Clicked IDC
		1: NUMBER - Index selected in the IDC
	
	Returns:
		BOOLEAN - Handled by the object.
	
	Example:
		((findDisplay 602) displayCtrl 633) ctrlAddEventHandler ["LBDblClick", "_this call AGM_Interaction_fnc_HandleInventoryClick;"];
*/
private ["_class", "_idc", "_selectedIndex", "_player", "_item"];
_player = call AGM_Core_fnc_player;
_idc = ctrlIDC (_this select 0);
_selectedIndex = _this select 1;
_item = (lbData [_idc, _selectedIndex]);
_class = configFile >> "CfgMagazines" >> _item >> "AGM_Action";
_result = false;

if ((lbData [_idc, _selectedIndex]) == "") then {
  private ["_fncSort"];
  _fncSort = {
    private ["_newArray"];
    _newArray = [];
    {
      if !(_x in _newArray) then {
        _newArray pushBack _x;
      };
      false
    } count _this;
    _newArray
  };
  _item = "";
  switch (_idc) do {
  // Uniform
    case 633:{
      _item = ((uniformItems _player) call _fncSort) select _selectedIndex;
    };
  // Backpack
    case 619:{
      _item = ((backpackItems _player) call _fncSort) select _selectedIndex;
    };
  // Vest
    case 638:{
      _item = ((vestItems _player) call _fncSort) select _selectedIndex;
    };
  };
  _class = ConfigFile >> "CfgWeapons" >> _item >> "AGM_Action";
};
if (isClass(_class)) exitWith {
// Not sure how this is supposed to integrate yet.
//_exceptions = getArray (_action >> "exceptions");
  if ([_player, vehicle _player, _item] call (compile getText(_class >> "condition"))) then {
    [_player, vehicle _player, _item] call (compile getText(_class >> "statement"));
    true
  } else {
    false
  };
};
false