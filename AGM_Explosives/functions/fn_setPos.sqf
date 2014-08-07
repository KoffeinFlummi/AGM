/*
	Name: AGM_Explosives_fnc_SetPos
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Sets the Dir and upVector to the surfaceNormal of pos
	
	Parameters:
		0: OBJECT - Object
		1: NUMBER - Direction
		2: ARRAY - Position
	
	Returns:
		Nothing
	
	Example:
		[_explosive, 150, [0,200,0]] call AGM_Explosives_fnc_SetPos;
*/
private "_ex";
_ex=_this select 0;
_ex setDir (_this select 1);
_ex setVectorUp (surfaceNormal (_this select 2));