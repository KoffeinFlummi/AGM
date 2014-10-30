/*
 * Author: commy2
 *
 * Get the compass direction the wind is blowing from.
 *
 * Argument:
 * None.
 *
 * Return value:
 * Wind direction. (String)
 */

switch (round (windDir / 360 * 16)) do {
  case 1 :  {localize "STR_AGM_Core_SSW"};
  case 2 :  {localize "STR_AGM_Core_SW"};
  case 3 :  {localize "STR_AGM_Core_WSW"};
  case 4 :  {localize "STR_AGM_Core_W"};
  case 5 :  {localize "STR_AGM_Core_WNW"};
  case 6 :  {localize "STR_AGM_Core_NW"};
  case 7 :  {localize "STR_AGM_Core_NNW"};
  case 8 :  {localize "STR_AGM_Core_N"};
  case 9 :  {localize "STR_AGM_Core_NNE"};
  case 10 : {localize "STR_AGM_Core_NE"};
  case 11 : {localize "STR_AGM_Core_ENE"};
  case 12 : {localize "STR_AGM_Core_E"};
  case 13 : {localize "STR_AGM_Core_ESE"};
  case 14 : {localize "STR_AGM_Core_SE"};
  case 15 : {localize "STR_AGM_Core_SSE"};
  default   {localize "STR_AGM_Core_S"};
};
