#define CARGO 0
#define _PILOT 1
#define _DRIVER 2
#define COMMANDER 3
#define GUNNER 4
#define FFV 5
#define DEFAULT 6
#define DRIVER ( if(_isAir) then {_PILOT} else {_DRIVER} )
#define CODRIVER DRIVER
