//AGM_Captives_fnc_disarmUnit

#define ITEMS_TO_REMOVE ["ItemRadio", "AGM_Clacker", "AGM_M26_Clacker", "AGM_DeadManSwitch"]
#define TIME_MAX_WAIT 6
#define DUMMY_ITEM "ItemWatch"
//todo: find a real dummy item

_this spawn {
  _unit = _this select 0;
  _caller = _this select 1;
  // _stripOffEverything = _this select 2;
  _stripOffEverything = true;

  if (!local _unit) exitWith {
    [_this, "AGM_Captives_fnc_disarmUnit", _unit] call AGM_Core_fnc_execRemoteFnc;
  };

  _failure = false;
  _holder = objNull;
  {
    if ((_x getVariable ["AGM_Captives_holderUnit", objNull]) == _unit) then {
      _holder = _x;
    };
  } forEach ((getpos _unit) nearObjects ["WeaponHolderSimulated", 3]);

  if (isNull _holder) then {
    _dropPos = _unit modelToWorld [-0.75, 0.75, 0];
    _dropPos set [2, 0];
    _holder = createVehicle ["WeaponHolderSimulated", _dropPos, [], 0, "CAN_COLLIDE"];
    //Have to put dummy item into container or it will disapear before _unit can put first item into it; because 'PutWeapon' takes time
    _holder addItemCargoGlobal [DUMMY_ITEM, 1];
    _holder setVariable ["AGM_Captives_holderUnit", _unit, true];
  };
  if (isNull _holder) exitWith {};

  //Remove Magazines
  _mags = magazinesAmmo _unit;
  {
    _magClassname = _x select 0;
    _magAmmo = _x select 1;
    if (_magClassname != "AGM_magazine_customKey") then {
      _holder addMagazineAmmoCargo [_magClassname, 1, _magAmmo];
    };
  } forEach _mags;
  //Need to document everything first and then remove (because of partial mags)
  {
    _magClassname = _x select 0;
    _magAmmo = _x select 1;
    if (_magClassname != "AGM_magazine_customKey") then {
      _unit removeMagazine _magClassname;
    };
  } forEach _mags;

  _addToCrateClassnames = (getItemCargo _holder) select 0;
  _addToCrateCount = (getItemCargo _holder) select 1;
  //Remove Items, Assigned Items and NVG
  {
    _removeItem = _stripOffEverything || (_x in ITEMS_TO_REMOVE);
    if (!_removeItem) then {  //Double check parents (for TFR/ACRE radios)
      _parents = [(configFile >> "CfgWeapons" >> _x), true] call BIS_fnc_returnParents;
      if (({_x in ITEMS_TO_REMOVE} count _parents) > 0) then {_removeItem = true;};
    };

    if (_removeItem) then {
      if (_x in (items _unit)) then {
        _unit removeItem _x;
      } else {
        _unit unlinkItem _x;
      };
      _index = _addToCrateClassnames find _x;
      if (_index != -1) then {
        _addToCrateCount set [_index, ((_addToCrateCount select _index) + 1)];
      } else {
        _addToCrateClassnames pushBack _x;
        _addToCrateCount pushBack 1;
      };
    };
  } forEach ((assignedItems _unit) + (items _unit) + [hmd _unit]);

  _resetCaptiveAnimation = false;
  //if captive and in locked anim, we need to break out of animation
  if ((_unit getVariable ["AGM_isCaptive", false]) && ((animationState _unit) == "agm_amovpercmstpscapwnondnon")) then {
    ["AGM_Captives", format ["Breaking Captive Animation for %1 [%2]", _unit, (name _unit)], {_this}, true] call AGM_Debug_fnc_log;
    _resetCaptiveAnimation = true;
    [_unit, "AmovPercMstpSnonWnonDnon_AinvPercMstpSnonWnonDnon_Putdown", 2] spawn AGM_Core_fnc_doAnimation;
  };

  //Unconsious people take a lot longer to dump gear
  _time =  if ((animationState _unit) != "unconscious") then {time + TIME_MAX_WAIT} else {time + 2 * TIME_MAX_WAIT};

  waitUntil {
    //Remove All Weapons
    {_unit action ["DropWeapon", _holder, _x];} forEach (weapons _unit);
    //Remove the vehicle lock key
    {if (_x == "AGM_magazine_customKey") then {_unit action ["DropMagazine", _holder, _x];};} forEach (magazines _unit);
    //Remove backPack
    if ((backPack _unit) != "") then {_unit action ["DropBag", _holder, (backPack _unit)];};
    sleep 1;
    (time > _time) || (((weapons _unit) isEqualTo []) && (!("AGM_magazine_customKey" in (magazines _unit))) && ((backPack _unit) == ""))
  };

  if (_resetCaptiveAnimation) then {
    ["AGM_Captives", format ["Restarting Captive Animation for %1 [%2]", _unit, (name _unit)], {_this}, true] call AGM_Debug_fnc_log;
    [_unit, "AGM_AmovPercMstpScapWnonDnon", 0, false] spawn AGM_Core_fnc_doAnimation;
  };

  if (!((((weapons _unit) + (magazines _unit)) isEqualTo []) && ((backPack _unit) == ""))) then {
    ["AGM_Captives", format ["Failed To Remove Weapons/Magazines from %1 [%2]", _unit, (name _unit)], {_this}, true] call AGM_Debug_fnc_log;
    _failure = true;
  };

  if (_stripOffEverything) then {
    //Remove Vest (don't remove if failure, could be weapon/magazine inside)
    if ((!_failure) && {(vest _unit) != ""} && {(vestItems _unit) isEqualTo []}) then {
      _addToCrateClassnames pushBack (vest _unit);
      _addToCrateCount pushBack 1;
      removeVest _unit;
    };

    //Remove Uniform (don't remove if failure, could be weapon/magazine inside)
    if ((!_failure) && {(uniform _unit) != ""} && {(uniformItems _unit) isEqualTo []}) then {
      _addToCrateClassnames pushBack (uniform _unit);
      _addToCrateCount pushBack 1;
      removeUniform _unit;
    };

    //Remove Helmet//Hat
    if ((headgear _unit) != "") then {
      _addToCrateClassnames pushBack (headgear _unit);
      _addToCrateCount pushBack 1;
      removeHeadgear _unit;
    };
  };

  //remove items, including the dummy item
  clearItemCargoGlobal _holder;
  {
    if (_x != DUMMY_ITEM) then {
      _holder addItemCargoGlobal [(_addToCrateClassnames select _forEachIndex), (_addToCrateCount select _forEachIndex)];
    };
  } forEach _addToCrateClassnames;

  [[_caller, _unit, _failure], "AGM_Captives_fnc_disarmCallback", _caller] call AGM_Core_fnc_execRemoteFnc;
};
