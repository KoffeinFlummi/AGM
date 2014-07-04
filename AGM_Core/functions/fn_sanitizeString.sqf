/*
 * Author: CAA-Picard, based on Killzone-Kid code
 *
 * Removes html tags from text to avoid conflicts with structured text.
 *
 * Arguments:
 * Source string
 *
 * Return Value:
 * Sanitized string
 */

_string = _this;
_array = toArray _string;

_arrayNew = [];
{
    switch _x do {
        case 60 : {
            _arrayNew = _arrayNew + toArray "&lt;";
        };
        case 62 : {
            _arrayNew = _arrayNew + toArray "&gt;";
        };
        case 34 : {
        };
        case 39 : {
        };
        default {
            _arrayNew = _arrayNew + [_x];
        };
    };
} forEach _array;

toString _arrayNew
