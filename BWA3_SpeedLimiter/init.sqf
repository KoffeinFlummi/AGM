// by commy2

BWA3_isSpeedLimiter = false;

BWA3_SpeedLimiter_keyInput = compile preprocessFile "\bwa3_speedlimiter\scripts\keyInput.sqf";
BWA3_SpeedLimiter_speedLimiter = compile preprocessFile "\bwa3_speedlimiter\scripts\speedLimiter.sqf";

(findDisplay 46) displayAddEventHandler ["KeyDown", "_this call BWA3_SpeedLimiter_keyInput"];
