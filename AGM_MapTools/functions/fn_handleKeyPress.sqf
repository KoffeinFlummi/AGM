// #define DEBUG_MODE_FULL
#include "script_component.hpp"
#include "keyMacros.hpp"

PARAMS_2(_dir,_params);

private ["_display", "_code", "_shiftKey", "_ctrlKey", "_altKey", "_handled", "_pos", "_pos2", "_clickRadius", "_currentMarker", "_newMarker", "_markerName", "_markerPos", "_markerIsVisible", "_size", "_side", "_angle"];

_display  = _params select 0;
_code     = _params select 1;
_shiftKey = _params select 2;
_ctrlKey  = _params select 3;
_altKey   = _params select 4;

_handled = false;

#define IDC_MAP    51
_pos               = ((finddisplay GVAR(idd)) displayctrl IDC_MAP) ctrlMapScreenToWorld [0.5, 0.5];
_pos2              = ((finddisplay GVAR(idd)) displayctrl IDC_MAP) ctrlMapScreenToWorld [0.5 + 0.012 * safezoneW, 0.5];
_clickRadius       = (_pos2 select 0) - (_pos select 0);

if (_code == CONFIGURE_KEY && _dir == 1) then
{
	[] call FUNC(createNMDialog);
	_handled = true;
};

if (!_handled && GVAR(dragging) == 0 && _dir == 1 && _code == DIK_V && _ctrlKey) then
{
	if (count(GVAR(NMcopiedMarker)) > 0) then
	{
		// Paste NM
		TRACE_1("Client: Paste NM", GVAR(mousePos));
		GVAR(mousePos) call FUNC(pasteNMarker);
		_handled = true;
	} else {
		if (count(GVAR(EMcopiedMarker)) > 0) then
		{
			// Paste EM
			//TODO
			TRACE_1("Client: Paste EM", GVAR(mousePos));
			GVAR(mousePos) call FUNC(pasteEMarker);
			_handled = true;
		};
	};
};

if (!_handled && GVAR(dragging) == 0 && _dir == 1) then 
{
	for "_i" from 0 to ((count GVAR(Nmarkers)) - 1) do
	{
		scopeName "loop";
		_currentMarker = (GVAR(Nmarkers) select _i);
		_newMarker     = + _currentMarker;
		_markerName    = _currentMarker select 0;
		_markerPos     = _currentMarker select 1;
		_markerIsVisible = (_currentMarker select 6) == GVAR(playerSide);
		if ((_markerIsVisible) && (GVAR(mousePos) distance _markerPos < _clickRadius)) then
		{
			// We are over a marker
			if (_code == DIK_DELETE) then 
			{
				// Remove marker
				[QGVAR(removeNMarker), _markerName] call CBA_fnc_GlobalEvent;
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_C && _ctrlKey) then {
				// Copy NM
				GVAR(NMcopiedMarker) = + _currentMarker;
				GVAR(EMcopiedMarker) = [];
				TRACE_1("Client: Copy NM", GVAR(NMcopiedMarker));
				_handled = true;
				breakOut "loop";				
			};
			if (_code == DIK_UP) then 
			{
				// Increase size
				_size = _currentMarker select 4;
				
				if (_size < 3) then
				{
					_newMarker set [4, _size + 1];
					[_currentMarker, _newMarker] call FUNC(updateNMarker);
				};
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_DOWN) then 
			{
				// Decrease size
				_size = _currentMarker select 4;
				
				if (_size > 0) then
				{
					_newMarker set [4, _size - 1];
					[_currentMarker, _newMarker] call FUNC(updateNMarker);
				};
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_RIGHT) then 
			{
				// Cicle side
				_side = _currentMarker select 2;
				
				if (_side < 3) then
				{
					_newMarker set [2, _side + 1];
					[_currentMarker, _newMarker] call FUNC(updateNMarker);
				};
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_LEFT) then 
			{
				// Cicle side
				_side = _currentMarker select 2;
				
				if (_side > 0) then
				{
					_newMarker set [2, _side - 1];
					[_currentMarker, _newMarker] call FUNC(updateNMarker);
				};
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_NUMPAD1) then // && _shiftKey) then 
			{
				[_newMarker, 0] call FUNC(toggleGroup);
				[_currentMarker, _newMarker ] call FUNC(updateNMarker);
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_NUMPAD2) then // && _shiftKey) then 
			{
				[_newMarker, 1] call FUNC(toggleGroup);
				[_currentMarker, _newMarker ] call FUNC(updateNMarker);
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_NUMPAD3) then // && _shiftKey) then 
			{
				[_newMarker, 2] call FUNC(toggleGroup);
				[_currentMarker, _newMarker] call FUNC(updateNMarker);
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_NUMPAD4) then // && _shiftKey) then 
			{
				[_newMarker, 3] call FUNC(toggleGroup);
				[_currentMarker, _newMarker] call FUNC(updateNMarker);
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_NUMPAD5) then // && _shiftKey) then 
			{
				[_newMarker, 4] call FUNC(toggleGroup);
				[_currentMarker, _newMarker] call FUNC(updateNMarker);
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_NUMPAD6) then // && _shiftKey) then 
			{
				[_newMarker, 5] call FUNC(toggleGroup);
				[_currentMarker, _newMarker] call FUNC(updateNMarker);
				_handled = true;
				breakOut "loop";
			};

			if (_code == DIK_NUMPAD7) then // && _shiftKey) then 
			{
				[_newMarker, 6] call FUNC(toggleGroup);
				[_currentMarker, _newMarker] call FUNC(updateNMarker);
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_NUMPAD8) then // && _shiftKey) then 
			{
				[_newMarker, 7] call FUNC(toggleGroup);
				[_currentMarker, _newMarker] call FUNC(updateNMarker);
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_NUMPAD9) then // && _shiftKey) then 
			{
				[_newMarker, 8] call FUNC(toggleGroup);
				[_currentMarker, _newMarker] call FUNC(updateNMarker);
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_NUMPAD0) then // && _shiftKey) then 
			{
				[_newMarker, 9] call FUNC(toggleGroup);
				[_currentMarker, _newMarker] call FUNC(updateNMarker);
				_handled = true;
				breakOut "loop";
			};				
		};
	};
};
if (!_handled && GVAR(dragging) == 0 && _dir == 1) then 
{
	for "_i" from 0 to ((count GVAR(EMmarkers)) - 1) do
	{
		scopeName "loop";
		_currentMarker = (GVAR(EMmarkers) select _i);
		_newMarker     = + _currentMarker;
		_markerName    = _currentMarker select 0;
		_markerPos     = _currentMarker select 1;
		_markerIsVisible = (_currentMarker select 7) == GVAR(playerSide);
		if ((_markerIsVisible) && (GVAR(mousePos) distance _markerPos < _clickRadius)) then
		{
			// We are over a marker
			if (_code == DIK_DELETE) then 
			{
				// Remove marker
				[QGVAR(removeEMarker), _markerName] call CBA_fnc_GlobalEvent;
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_C && _ctrlKey) then {
				// Copy EM
				GVAR(EMcopiedMarker) = + _currentMarker;
				GVAR(NMcopiedMarker) = [];
				TRACE_1("Client: Copy EM", GVAR(NMcopiedMarker));
				_handled = true;
				breakOut "loop";				
			};
			if (_code == DIK_UP) then 
			{
				// Increase size
				_size = _currentMarker select 4;
				_newMarker set [4, [(_size select 0)*1.1,(_size select 1)*1.1]];
				[_currentMarker, _newMarker] call FUNC(updateEMarker);
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_DOWN) then 
			{
				// Decrease size
				_size = _currentMarker select 4;
				_newMarker set [4, [(_size select 0)/1.1,(_size select 1)/1.1]];
				[_currentMarker, _newMarker] call FUNC(updateEMarker);
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_RIGHT) then 
			{
				// Increase angle
				_angle = (_currentMarker select 5) + 15;
				if (_angle > 360) then 
				{
					_angle = _angle - 360;
				};
				_newMarker set [5, _angle];
				[_currentMarker, _newMarker] call FUNC(updateEMarker);
				_handled = true;
				breakOut "loop";
			};
			if (_code == DIK_LEFT) then 
			{
				// Decrease angle
				_angle = (_currentMarker select 5) - 15;
				if (_angle < 0) then 
				{
					_angle = _angle + 360;
				};
				_newMarker set [5, _angle];
				[_currentMarker, _newMarker] call FUNC(updateEMarker);
				_handled = true;
				breakOut "loop";
			};			
		};
	};
};
_handled