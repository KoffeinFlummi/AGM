/*
Author: eRazeri

Checks for conditions for the IR Strobe

Arguments:
none

Return Value:
none
*/
if ((vehicle player == player && alive player)) then {
    AGM_IR_Strobe_Available = true;
    if (AGM_IR_Strobe_was_ON) then {
        call AGM_IrStrobe_fnc_irstrobe;
        AGM_IR_Strobe_was_ON = false;
    };
} else {
    AGM_IR_Strobe_Available = false;
    if (AGM_IR_Strobe_ON) then {
        call AGM_IrStrobe_fnc_irstrobe;
        AGM_IR_Strobe_was_ON = true;
    };
};