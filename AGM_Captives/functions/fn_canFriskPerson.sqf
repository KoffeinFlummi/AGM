/*
 * By: jodav
 *
 * Checks the conditions for being able to frisk a unit
 *
 * Arguments:
 * 0: caller (player) (Object)
 * 1: target (Object)
 *
 * Return Value:
 * Boolean
 */
 
private ["_unit", "_target"];

_unit = _this select 0;
_target = _this select 1;

// all the stuff to check!
// "isCaptive" Or "Handcuffed" Or "isSearchable" Or ("Unconscious" And different side)

/*
alive _unit 
&& weaponLowered _unit 
&& alive _target 
&& ((_target getVariable["AGM_isCaptive", false]) || (_target getVariable["AGM_Handcuffed", false]) || (_target getVariable["AGM_isSearchable", false]) || ((_target getVariable ["AGM_Unconscious", false]) && side _target != side _unit))
*/

_target getVariable["AGM_isCaptive", false] || {_target getVariable["AGM_isSearchable", false]} || {_target getVariable ["AGM_Unconscious", false]}
