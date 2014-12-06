//Pabst Mirror
//AGM_Attach - Helper for finding good attach points on vehicles (based on explosive placement)


TEST_LIGHT = "B_IRStrobe" createVehicle (getpos player);
TEST_LIGHT enableSimulation false;

["asdf","OnEachFrame", {
  _pos = (ASLtoATL eyePos player) vectorAdd (positionCameraToWorld [0,0,1] vectorDiff positionCameraToWorld [0,0,0]);
  TEST_LIGHT setPosATL _pos;
  
  LightPos = cursorTarget worldToModel _pos;
  hintSilent format ["LightPos: %1", LightPos];
}] call BIS_fnc_addStackedEventHandler;

//check debug:
//typeOf cursorTarget
//LightPos