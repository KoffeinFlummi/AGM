//Author: eRazeri
if (isDedicated) exitWith {};

//default variable values
AGM_IR_Strobe_ON = false;
AGM_IR_Strobe_was_ON = false;
AGM_IR_Strobe_Available = false;
AGM_IR_Strobe = objNull;

//give out IR Strobes
_this spawn {
  waitUntil {!isNull (findDisplay 46)};
      player addItem "AGM_IR_Strobe_Item";
};

//Spawn condition loop
[] spawn {
  while {true} do {
    while {sunOrMoon < 1} do {
        call AGM_IrStrobe_fnc_condition;
        sleep 1;//A lack of proper GetInMan/GetOutMan eventhandlers results in this short sleep timer.
    };
    AGM_IR_Strobe_Available = false;
    if (AGM_IR_Strobe_ON) then {
        call AGM_IrStrobe_fnc_irstrobe;
        AGM_IR_Strobe_was_ON = true;
    };
    sleep 60;
};
};