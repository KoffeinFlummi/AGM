// by Falke

disableSerialization;
_display = _this select 0;
_ctrl1 = _display displayCtrl 42001;
_ctrl2 = _display displayCtrl 42002;
_ctrl3 = _display displayCtrl 42003;
_ctrl4 = _display displayCtrl 42004;
_ctrl5 = _display displayCtrl 42005;
_sleep1 = 0.5;
AGM_Kestrel_wind_Head=0;
//unIFormItems PLAYER+backpackItems PLAYER+vestItems PLAYER
//assigneditems PLAYER

IF (!("AGM_ItemKestrel" in  items PLAYER )) THEN {AGM_isKestrel = FALSE;};
IF (underwater PLAYER) THEN {AGM_isKestrel = FALSE;};

WHILE {AGM_isKestrel} DO {
  _dSpotter = direction PLAYER;
  _windrarray = WIND;
  _windrA= _windrarray select 0;
  _windrB= _windrarray select 1;
  _windrC= sqrt ((_windrA * _windrA) + (_windrB * _windrB));
  _windrD= _windrA atan2 _windrB;
  _windrR = _dSpotter - _windrD;
  IF (_windrR < 0) THEN {_windrR = 360+_windrR;};
  _windrBB = _windrC * sin (_windrR);
  _windrAA = sqrt ((_windrC * _windrC) - (_windrBB * _windrBB));
  IF (_windrR < 90) THEN {_windrAA= _windrAA - (_windrAA*2);};
  IF (_windrR > 270) THEN {_windrAA= _windrAA - (_windrAA*2);};

  _OrtPLAYER = eyePos PLAYER;
  _Pos0=_OrtPLAYER select 0;
  _Pos1=_OrtPLAYER select 1;
  _Pos2=_OrtPLAYER select 2;

  // im Gebaude
  _Ort=0;
  IF (lineIntersects [_OrtPlayer, [_Pos0,_Pos1,_Pos2 + 15]]) THEN {_Ort=_Ort+1};
  /*
  if (lineIntersects [_OrtPlayer, [_Pos0,_Pos1 + 15,_Pos2]]) then {_Ort=_Ort+1};
  if (lineIntersects [_OrtPlayer, [_Pos0,_Pos1 - 15,_Pos2]]) then {_Ort=_Ort+1};
  if (lineIntersects [_OrtPlayer, [_Pos0 + 15,_Pos1,_Pos2]]) then {_Ort=_Ort+1};
  if (lineIntersects [_OrtPlayer, [_Pos0 - 15,_Pos1,_Pos2]]) then {_Ort=_Ort+1};
  */
  IF (lineIntersects [[(_Pos0) , (_Pos1), (_Pos2)], [(_Pos0) - (sin windDir) * 15, (_Pos1) - (cos windDir) * 15, (_Pos2)]]) THEN {_Ort=_Ort+1};
  IF (lineIntersects [[(_Pos0) , (_Pos1), (_Pos2)], [(_Pos0) - (sin (windDir-90)) * 15, (_Pos1) - (cos (windDir-90)) * 15, (_Pos2)]]) THEN {_Ort=_Ort+1};
  IF (lineIntersects [[(_Pos0) , (_Pos1), (_Pos2)], [(_Pos0) - (sin (windDir+90)) * 15, (_Pos1) - (cos (windDir+90)) * 15, (_Pos2)]]) THEN {_Ort=_Ort+1};
  IF (lineIntersects [[(_Pos0) , (_Pos1), (_Pos2)], [(_Pos0) - (sin (windDir+180)) * 15, (_Pos1) - (cos (windDir+180)) * 15, (_Pos2)]]) THEN {_Ort=_Ort+1};
  if (_Ort>3) then {_windrAA=99.99;_windrBB=99.99};

  // in Windrichtung
  _Ort=0;
  IF (lineIntersects [[(_Pos0) , (_Pos1), (_Pos2)], [(_Pos0) - (sin windDir) * 5, (_Pos1) - (cos windDir) * 5, (_Pos2)]]) THEN {_Ort=_Ort+1};
  IF (lineIntersects [[(_Pos0) , (_Pos1), (_Pos2)], [(_Pos0) - (sin (windDir-15)) * 5, (_Pos1) - (cos (windDir-15)) * 5, (_Pos2)]]) THEN {_Ort=_Ort+1};
  IF (lineIntersects [[(_Pos0) , (_Pos1), (_Pos2)], [(_Pos0) - (sin (windDir+15)) * 5, (_Pos1) - (cos (windDir+15)) * 5, (_Pos2)]]) THEN {_Ort=_Ort+1};
  //IF (lineIntersects [_OrtPLAYER, [_Pos0,_Pos1,_Pos2 + 10]]) THEN {_Ort=_Ort+1};
  IF (_Ort>2) THEN {_windrAA=99.99;_windrBB=99.99};

  /*
  onEachFrame {
    _OrtPLAYER = eyePos PLAYER;
    _Pos0=_OrtPLAYER select 0;
    _Pos1=_OrtPLAYER select 1;
    _Pos2=_OrtPLAYER select 2;
    drawLine3D [[(_Pos0) , (_Pos1), (_Pos2)-(getPosASL PLAYER SELECT 2)], [(_Pos0) - (sin windDir) * 5, (_Pos1) - (cos windDir) * 5, (_Pos2)-(getPosASL PLAYER SELECT 2)], [1,0,0,1]];
    drawLine3D [[(_Pos0) , (_Pos1), (_Pos2)-(getPosASL PLAYER SELECT 2)], [(_Pos0) - (sin (windDir-15)) * 5, (_Pos1) - (cos (windDir-15)) * 5, (_Pos2)-(getPosASL PLAYER SELECT 2)], [1,0,0,1]];
    drawLine3D [[(_Pos0) , (_Pos1), (_Pos2)-(getPosASL PLAYER SELECT 2)], [(_Pos0) - (sin (windDir+15)) * 5, (_Pos1) - (cos (windDir+15)) * 5, (_Pos2)-(getPosASL PLAYER SELECT 2)], [1,0,0,1]];

    drawLine3D [[(_Pos0) , (_Pos1), (_Pos2)-(getPosASL PLAYER SELECT 2)], [_Pos0,_Pos1,_Pos2 + 15-(getPosASL PLAYER SELECT 2)], [0,0,1,1]];

    drawLine3D [[(_Pos0) , (_Pos1), (_Pos2)-(getPosASL PLAYER SELECT 2)], [(_Pos0) - (sin (windDir)) * 15, (_Pos1) - (cos (windDir)) * 15, (_Pos2)-(getPosASL PLAYER SELECT 2)], [0,1,0,1]];
    drawLine3D [[(_Pos0) , (_Pos1), (_Pos2)-(getPosASL PLAYER SELECT 2)], [(_Pos0) - (sin (windDir+90)) * 15, (_Pos1) - (cos (windDir+90)) * 15, (_Pos2)-(getPosASL PLAYER SELECT 2)], [0,1,0,1]];
    drawLine3D [[(_Pos0) , (_Pos1), (_Pos2)-(getPosASL PLAYER SELECT 2)], [(_Pos0) - (sin (windDir-90)) * 15, (_Pos1) - (cos (windDir-90)) * 15, (_Pos2)-(getPosASL PLAYER SELECT 2)], [0,1,0,1]];
    drawLine3D [[(_Pos0) , (_Pos1), (_Pos2)-(getPosASL PLAYER SELECT 2)], [(_Pos0) - (sin (windDir+180)) * 15, (_Pos1) - (cos (windDir+180)) * 15, (_Pos2)-(getPosASL PLAYER SELECT 2)], [0,1,0,1]];
  };
  */
  //IF (vehicle PLAYER != PLAYER) THEN {_windrAA=0;_windrBB=0};
  IF (PLAYER != vehicle PLAYER) THEN {_windrAA=0;_windrBB=0};

  IF (_windrAA == 99.99) then {
    AGM_Kestrel_wind_Head = 0;
    _windrAA= "0.00";
    _windrBB= "0.00";
  }ELSE{
    AGM_Kestrel_wind_Head=_windrAA;
    IF (_windrAA < 0) THEN {
      _windrAA= FORMAT["-%1",[_windrAA*-1, 1, 2] call CBA_fnc_FORMATNumber];
    }ELSE{
      _windrAA= FORMAT["%1",[_windrAA, 1, 2] call CBA_fnc_FORMATNumber];
    };
    IF (_windrBB < 0) THEN {
      _windrBB= FORMAT["-%1",[_windrBB*-1, 1, 2] call CBA_fnc_FORMATNumber];
    }ELSE{
      _windrBB= FORMAT["%1",[_windrBB, 1, 2] call CBA_fnc_FORMATNumber];
    };
  };

  _ctrl2 ctrlSetText _windrAA;
  _ctrl3 ctrlSetText _windrBB;
  _ctrl4 ctrlSetText FORMAT["%1",round (direction PLAYER)];
  _ctrl5 ctrlSetText FORMAT["%1 %2",round(((getPosATL PLAYER) select 0)/10)/10,round(((getPosATL PLAYER) select 1)/10)/10];

  IF (!("AGM_ItemKestrel" in items PLAYER)) THEN {AGM_isKestrel = FALSE;};
  IF (
    underwater PLAYER ||
    //{PLAYER != vehicle PLAYER} ||
    {cameraView == "GUNNER"} ||
    {!alive PLAYER}
  ) THEN {AGM_isKestrel = FALSE;};
  IF (!AGM_isKestrel) THEN {_sleep1 = 0.01;};

  SLEEP _sleep1;
};
AGM_isKestrelWheel=False;
_ctrl1 ctrlShow false;
_ctrl2 ctrlShow false;
_ctrl3 ctrlShow false;
_ctrl4 ctrlShow false;
_ctrl5 ctrlShow false;
