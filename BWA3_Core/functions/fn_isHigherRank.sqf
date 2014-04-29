/*
 * Author: KoffeinFlummi
 *
 * Compares the ranks of two units.
 *
 * Arguments:
 * 0: Unit 1
 * 1: Unit 2
 *
 * Return Value:
 * bool (true for 1>2, false for 1<=2)
 */

private ["_unit1", "_unit2", "_rankNo1", "_rankNo2"];

_unit1 = _this select 0;
_unit2 = _this select 1;

_rankNo1 = switch (rank _unit1) do {
  case "PRIVATE": {0};
  case "CORPORAL": {1};
  case "SERGEANT": {2};
  case "LIEUTENANT": {3};
  case "CAPTAIN": {4};
  case "MAJOR": {5};
  case "COLONEL": {6};
};
_rankNo2 = switch (rank _unit2) do {
  case "PRIVATE": {0};
  case "CORPORAL": {1};
  case "SERGEANT": {2};
  case "LIEUTENANT": {3};
  case "CAPTAIN": {4};
  case "MAJOR": {5};
  case "COLONEL": {6};
};

_rankNo1 > _rankNo2