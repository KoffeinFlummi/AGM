// by commy2

_weapon = _this select 0;

player playMoveNow "amovpknlmstpsraswrfldnon";
player playActionNow "GestureDismountMuzzle";
player removeItem "AGM_SpareBarrel";

sleep 2.5;

player playActionNow "GestureMountMuzzle";

sleep 2.5;

["Swapped barrel"] call AGM_Core_fnc_displayText;

player setVariable [format ["AGM_Overheat_%1", _weapon], [0, 0], false];
AGM_isWeaponJammed = false;
