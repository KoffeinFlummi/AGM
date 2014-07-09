/*
Author: eRazeri

Turn IR Strobe On/Off

Arguments:
none

Return Value:
none
*/
// Strobe on, turning it off and adding item
if (AGM_IR_Strobe_ON) exitWith {
    _count = count items player;
    player addItem "AGM_IR_Strobe_Item";

    if (count items player > _count) then {
        [localize "STR_AGM_IrStrobe_Off"] call AGM_Core_fnc_displayTextStructured;
        deleteVehicle AGM_IR_Strobe;
        AGM_IR_Strobe_ON = false;
    } else { // inventory full
        [localize "STR_AGM_IrStrobe_Inventory_Full"] call AGM_Core_fnc_displayTextStructured;
    };
};


// Strobe off, turning it on and removing item
if ("AGM_IR_Strobe_Item" in items player && AGM_IR_Strobe_Available) exitWith {
    player removeItem "AGM_IR_Strobe_Item";

    [localize "STR_AGM_IrStrobe_On"] call AGM_Core_fnc_displayTextStructured;

    if !(AGM_IR_Strobe_ON) then {
        AGM_IR_Strobe = "AGM_IR_Strobe_Effect" createVehicle [0,0,0];
        AGM_IR_Strobe attachTo [player,[0,-0.07,0.22],"neck"];//0,-0.05,0.19 looks good without helmet, 0,-0.07,0.22 looks good with helmet
        AGM_IR_Strobe_ON = true;
    };
};

//Not available
if !(AGM_IR_Strobe_Available) then {
    [localize "STR_AGM_IrStrobe_NotAvailable"] call AGM_Core_fnc_displayTextStructured;
};
//Don`t have the item
if !("AGM_IR_Strobe_Item" in items player) then {
    [localize "STR_AGM_IrStrobe_NoItem"] call AGM_Core_fnc_displayTextStructured;
};