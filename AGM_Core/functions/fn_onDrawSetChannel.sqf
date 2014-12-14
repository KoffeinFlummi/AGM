// by commy2

if (ctrlText (uiNamespace getVariable ["AGM_ctrlChannel", controlNull]) != "") then {
  uiNamespace setVariable ["AGM_currentChannel", ctrlText (uiNamespace getVariable ["AGM_ctrlChannel", controlNull])];
};
