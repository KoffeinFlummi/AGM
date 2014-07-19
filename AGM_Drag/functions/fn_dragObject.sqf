/*
 	Name: AGM_Drag_fnc_dragObject
 	
 	Author(s):
		L-H

 	Description:
		Prepares the passed unit to drag the passed weapon.
	
	Parameters:
		0: OBJECT - Dragged weapon
		1: OBJECT - Unit dragging
 	
 	Returns:
		Nothing
 	
 	Example:
		[StaticWeapon3, player] call AGM_Drag_fnc_dragObject;
*/
private ["_draggedObject", "_unit", "_attachPoint", "_ableToDrag"];
_draggedObject = _this select 0;
_unit = _this select 1;
if (_draggedObject getVariable ["AGM_disableDrag", false]) exitWith {};
_ableToDrag = true;

if ((typeOf _draggedObject) isKindOf "StaticWeapon") then {
	if !(isNull(gunner _draggedObject) AND {!alive (gunner _draggedObject)}) then {
		(gunner _draggedObject) setPosATL (GetPosATL(gunner _draggedObject));
	};
} else { // Crate handling
	if (_draggedObject getVariable ["AGM_useWeight", true]) then {
		_ableToDrag = ((_draggedObject call AGM_Drag_fnc_GetWeight) <= AGM_Drag_MaxWeight);
	};
};
if (!_ableToDrag) exitWith { [localize "STR_AGM_Drag_UnableToDrag"] call AGM_Core_fnc_displayTextStructured;};
if (primaryWeapon _unit == "") then {
	_unit addWeapon "AGM_FakePrimaryWeapon";
};
_unit selectWeapon (primaryWeapon _unit);

_unit playActionNow "grabDrag";
_attachPoint = [0,1.2, ((_draggedObject modelToWorld [0,0,0]) select 2) - ((_unit modelToWorld [0,0,0]) select 2)];
_draggedObject attachTo [_unit, _attachPoint];

_draggedObject setVariable ["AGM_inUse", true, true];
_unit setVariable ["AGM_isDragging", true];
_unit setVariable ["AGM_carriedItem", _draggedObject, true];
_draggedObject setOwner (owner _unit);
_draggedObject setVariable ["AGM_lockStatus", locked _draggedObject, true];
_draggedObject lock true;

AGM_Drag_CurrentHeightChange = 0;