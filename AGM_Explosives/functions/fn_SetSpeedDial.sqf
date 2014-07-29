/*
	Name: AGM_Explosives_fnc_SetSpeedDial
	
	Author(s):
		Garth de Wet (LH)
	
	Description:
		Enables cycling through the speed dial of the player.
	
	Parameters:
		NUMBER - Whether to increase or decrease speed dial
	
	Returns:
		Nothing
	
	Example:
		// Decrease
		-1 call AGM_Explosives_fnc_SetSpeedDial;
		// Increase
		1 call AGM_Explosives_fnc_SetSpeedDial;
*/
if (count AGM_Explosives_Phone_SpeedDial == 0) exitWith{};
AGM_Explosives_CurrentSpeedDial = AGM_Explosives_CurrentSpeedDial + _this;
AGM_Explosives_CurrentSpeedDial = if(AGM_Explosives_CurrentSpeedDial < 0)then{(count AGM_Explosives_Phone_SpeedDial)-1}else{AGM_Explosives_CurrentSpeedDial};
AGM_Explosives_CurrentSpeedDial = if(AGM_Explosives_CurrentSpeedDial >= (count AGM_Explosives_Phone_SpeedDial))then{0}else{AGM_Explosives_CurrentSpeedDial};
ctrlSetText [1400,(AGM_Explosives_Phone_SpeedDial select AGM_Explosives_CurrentSpeedDial) select 1];
ctrlSetText [1401,(AGM_Explosives_Phone_SpeedDial select AGM_Explosives_CurrentSpeedDial) select 0];