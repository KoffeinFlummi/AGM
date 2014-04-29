// by commy2

AGM_isSpeedLimiter = false;

AGM_SpeedLimiter_keyInput = compile preprocessFile "\bwa3_speedlimiter\scripts\keyInput.sqf";
AGM_SpeedLimiter_speedLimiter = compile preprocessFile "\bwa3_speedlimiter\scripts\speedLimiter.sqf";

(findDisplay 46) displayAddEventHandler ["KeyUp", "_this call AGM_SpeedLimiter_keyInput"];
