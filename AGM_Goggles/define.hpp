// Control types
#define CT_STATIC           0
#define ST_PICTURE        0x30

////////////////
//Base Classes//
////////////////

class RscPicture
{
    access = 0;
    idc = -1;
    type = CT_STATIC;
    style = ST_PICTURE;
    colorBackground[] = {0,0,0,0};
    colorText[] = {1,1,1,1};
    font = "puristaMedium";
    sizeEx = 0;
    lineSpacing = 0;
    fixedWidth = 0;
    shadow = 0;
	text = "";
	x = safezoneX;
	y = safezoneY;
	w = safezoneW;
	h = safezoneH;
};
