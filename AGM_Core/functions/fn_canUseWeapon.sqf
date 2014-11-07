// by commy2

private ["_unit", "_config"];

_unit = _this select 0;

_config = configFile >> "CfgMovesMaleSdr" >> "States" >> animationState _unit;

isClass _config
&& {getNumber (_config >> "canPullTrigger") == 1}
