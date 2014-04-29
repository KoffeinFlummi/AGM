/*
 * Author: KoffeinFlummi (not at all stolen from commy)
 *
 * Opens the "CommyRose" with the given menu items.
 *
 * Arguments:
 * 0: array with the menu items
 *
 * Return Values:
 * None
 */

#define HSPACE 0.3
#define VSPACE 0.3
#define BORDER 0.1

_menuSubitems = _this select 0;
_countSubitems = count _menuSubitems - 1;

closeDialog 0;
createDialog "AGM_CommyRose_Dialog";

disableSerialization;
_dlgMenuDialog = uiNamespace getVariable "AGM_Menu_Dialog";

for "_a" from 0 to (_countSubitems - 1) do {
  _menuSubitem = _menuSubitems select (_a + 1);

  _ctrlMenuDialogX = _dlgMenuDialog displayCtrl (10 + _a);
  _ctrlMenuDialogX ctrlShow true;
  _ctrlMenuDialogX ctrlSetText (_menuSubitem select 0);

  AGM_Menu_Button set [_a, _menuSubitem select 1];
  uiNamespace setVariable ["AGM_Menu_Control_" + str(_a), _ctrlMenuDialogX];
};