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
	case 1 : {"NNE"};
	case 2 : {"NE"};
	case 3 : {"ENE"};
	case 4 : {"E"};
	case 5 : {"ESE"};
	case 6 : {"SE"};
	case 7 : {"SSE"};
	case 8 : {"S"};
	case 9 : {"SSW"};
	case 10 : {"SW"};
	case 11 : {"WSW"};
	case 12 : {"W"};
	case 13 : {"WNW"};
	case 14 : {"NW"};
	case 15 : {"NNW"};
	default {"N"};
}
