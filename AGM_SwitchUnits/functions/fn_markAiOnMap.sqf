/*
  Name: AGM_SwitchUnits_fnc_markAiOnMap
  
  Author(s):
    jodav
  
  Description:
    Creates markers for AI units for given side
    Marks players in a different color
  
  Parameters:
    0: OBJECT - side
  
  Returns:
    VOID
*/

private ["_sideToShow"];
_sideToShow = _this select 0;

[_sideToShow] spawn {

    private ["_allMarkerNames"];

    _allMarkerNames = [];

    while { true } do {
        sleep 1.5;

        // delete markers
        {
            deleteMarkerLocal _x;
        } forEach _allMarkerNames;


        // create markers
        {
            if ((side (group _x) == (_this select 0) && vehicle _x == _x && !(_x getVariable ["AGM_SwitchUnits_IsPlayerUnit", false])) || (_x getVariable ["AGM_SwitchUnits_IsPlayerControlled", false])) then {
                private ["_markerName", "_marker", "_markerColor"];

                //_markerName = format ["%1", (name _x)];
                _markerName = str _x;

                _marker = createMarkerLocal [_markerName, position _x];
                _markerName setMarkerTypeLocal "mil_triangle";
                _markerName setMarkerShapeLocal "ICON";
                _markerName setMarkerSizeLocal [0.5,0.7];
                _markerName setMarkerDirLocal getDir _x;

                switch ((_this select 0)) do {
                    case west: { _markerColor = "ColorWEST"; };
                    case east: { _markerColor = "ColorEAST"; };
                    case resistance: { _markerColor = "ColorGUER"; };
                    default { _markerColor = "ColorEAST"; };
                };

                if ((_x getVariable ["AGM_SwitchUnits_IsPlayerControlled", false])) then {
                    _markerName setMarkerColorLocal "ColorOrange";
                    _markerName setMarkerTextLocal (_x getVariable ["AGM_SwitchUnits_PlayerControlledName",""]);
                } else {
                    _markerName setMarkerColorLocal _markerColor;
                    _markerName setMarkerTextLocal (getText (configFile >> "CfgVehicles" >> typeOf _x >> "displayName"));
                };

                _allMarkerNames pushBack _markerName;
            }
        } forEach allUnits;

    };
};

