// by commy2

#define COLOR_ON [0.2941, 0.8745, 0.2157, 1.0]
#define COLOR_OFF [0.2941, 0.2941, 0.2941, 1.0]

private "_state";

_state = missionNamespace getVariable ["AGM_Disposable_modeJavelin", 0];

_state = [1, 0] select _state;

AGM_Disposable_modeJavelin = _state;

playSound "AGM_Sound_Click";

disableSerialization;
_ctrlJavelinMode = (uiNamespace getVariable ["AGM_dlgJavelinOptics", displayNull]) displayCtrl 1006;

_ctrlJavelinMode ctrlSetTextColor ([COLOR_OFF, COLOR_ON] select _state);
