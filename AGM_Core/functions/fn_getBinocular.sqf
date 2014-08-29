/*
 * Author: commy2
 *
 * Returns the binocular of the unit. Empty string is returned, if the unit has no binocular.
 * 
 * Argument:
 * 0: Player (Object)
 * 
 * Return value:
 * Binocular (String)
 */

private ["_unit", "_weapons"];

_unit = _this select 0;

_weapons = weapons _unit - [primaryWeapon _unit, secondaryWeapon _unit, handgunWeapon _unit];

["", _weapons select 0] select (count _weapons > 0)
