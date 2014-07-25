//author : Nic547
//Attaches a Captive to the player
private ["_unit","_message"];

_unit = _this select 0;
_message = localize "STR_AGM_Interaction_NoCaptive" ;

if (captive _unit) then {
  if (attachedTo _unit == player) then {
  detach _unit;
  }
  else {
	_unit attachTo [player,[0,1.0,0]];
  };
}
else {
   [_message] call AGM_Core_fnc_displayText;
};
