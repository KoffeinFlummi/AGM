_fence = _this select 0;

if (alive AGM_player) then {
  _fence setDamage 1;
  [localize "STR_AGM_FenceCut"] call AGM_Core_fnc_displayTextStructured;
  [AGM_player, "AmovPknlMstpSrasWrflDnon", 1] call AGM_Core_fnc_doAnimation;
};
