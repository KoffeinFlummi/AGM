/*
 * Author: jodav
 *
 * hides the corpse
 *
 * Arguments:
 * The body
 *
 * Return Value:
 * None 
 */

hint "start hiding body";

_body = _this select 0;

_body spawn {
  sleep 5;
  hint "hiding body now";
  hideBody _this;
};