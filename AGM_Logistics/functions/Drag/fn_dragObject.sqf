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

#define ANIM_CARRY ["amovpercmstpslowwrfldnon_acinpknlmwlkslowwrfldb_2", "amovpercmstpsraswpstdnon_acinpknlmwlksnonwpstdb_2", "amovpercmstpsnonwnondnon_acinpknlmwlksnonwnondb_2", "acinpknlmstpsraswrfldnon", "acinpknlmstpsnonwpstdnon", "acinpknlmstpsnonwnondnon"];

_this spawn {
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
	//_unit selectWeapon (primaryWeapon _unit);

	[_unit, _draggedObject] call AGM_Core_fnc_claim;

	_unit setVariable ["AGM_isDragging", true];
	_unit setVariable ["AGM_carriedItem", _draggedObject, true];

	_draggedObject setVariable ["AGM_lockStatus", locked _draggedObject, true];
	_draggedObject lock true;

	_unit playActionNow "grabDrag";
	waitUntil {animationState _unit in ANIM_CARRY};

	// exit here if the player releases the jerry can before the animation is finished
	if !(_unit getVariable ["AGM_isDragging", false]) exitWith {
		_unit playAction "released";
	};

	_attachPoint = [0,1.2, ((_draggedObject modelToWorld [0,0,0]) select 2) - ((_unit modelToWorld [0,0,0]) select 2)];
	_draggedObject attachTo [_unit, _attachPoint];

	AGM_Drag_CurrentHeightChange = 0;
};
