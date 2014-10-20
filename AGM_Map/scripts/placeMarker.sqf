// by commy2

if (_this select 1 == 1) then {
	disableserialization;
	_display = _this select 0;

	_pos = ctrlPosition (_display displayCtrl 102);
	_pos = [
		(_pos select 0) + (_pos select 2) / 2,
		(_pos select 1) + (_pos select 3) / 2
	];
	_pos = (findDisplay 12 displayCtrl 51) ctrlMapScreenToWorld _pos;

	diag_log text str (_display displayCtrl 102);
	diag_log text str _pos;

	_pos spawn {
		/*[
			allMapMarkers select (count allMapMarkers - 1),
			[
				uiNamespace getVariable ['AGM_Map_currentMarkerShape', 0],
				uiNamespace getVariable ['AGM_Map_currentMarkerColor', 0],
				_this,
				uiNamespace getVariable ['AGM_Map_currentMarkerAngle', 0]
			]
		] call AGM_Map_fnc_setMarker;*/

		[
			[
				allMapMarkers select (count allMapMarkers - 1),
				[
					uiNamespace getVariable ['AGM_Map_currentMarkerShape', 0],
					uiNamespace getVariable ['AGM_Map_currentMarkerColor', 0],
					_this,
					uiNamespace getVariable ['AGM_Map_currentMarkerAngle', 0]
				]
			], "AGM_Map_fnc_setMarkerNetwork", 2
		] call AGM_Core_fnc_execRemoteFnc;
	};
};
