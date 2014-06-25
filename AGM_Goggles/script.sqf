#define GLASSESDEFAULT [false,[false,0,0,0],[false,0,0],false]

#define DIRT 0
#define DUST 1
#define LRAIN 2
#define BROKEN 3

#define GETDIRT (AGM_Goggles_Effects select DIRT)
#define GETDUST (AGM_Goggles_Effects select DUST)
#define GETRAIN (AGM_Goggles_Effects select LRAIN)
#define GETRAINT(type) ((AGM_Goggles_Effects select LRAIN) select type)
#define GETBROKEN (AGM_Goggles_Effects select BROKEN)
#define GETDUSTT(type) ((AGM_Goggles_Effects select DUST) select type)

#define SETDUST(type,value) (AGM_Goggles_Effects select DUST) set [type, value]
#define SETLRAIN(type,value) (AGM_Goggles_Effects select LRAIN) set [type, value]

#define DACTIVE 0
#define DTIME 1
#define DBULLETS 2
#define DAMOUNT 3

#define RACTIVE 0
#define RAMOUNT 1
#define RTIME 2

#define GLASSDISPLAY (uiNamespace getVariable ["AGM_Goggles_Display", displayNull])

#define CLAMP(x,low,high) (if(x > high)then{high}else{if(x < low)then{low}else{x}})