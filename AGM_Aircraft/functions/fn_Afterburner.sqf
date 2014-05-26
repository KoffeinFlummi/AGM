//script to animate and simulate afterburners on FA-18 
//to activate use "SeagullFastForward" key or useraction in action menu
//original authors: Gnat and lethal
//modified to for use on this addon by John_Spartan (with Gnat's permission)

if (ab_switch) exitwith 
{ 
ab_switch = false;
 hint "afterburner off";

if (fuel _vehicle > 0) then {_vehicle setFuel ((fuel _vehicle)-((1/_fueldrag)*(1*_looptime)))}; 
 };
if !(ab_switch) exitwith { 

private ["_MaxIntensity","_Boost","_Intensity","_looptime", "_vehicle"];

_MaxIntensity = 1;
_Boost = 0.6;
_Intensity = 0.4;
_maxspeed = 1200;
_vehicle = _this select 0;
_fueldrag = 2000;

sleep 0.5;
_looptime = 0.1;
_runtime = 200;



 hint "afterburner false";
ab_switch = true;
while {(alive _vehicle)} do {
if (isengineon _vehicle) then 
{
if (((getpos _vehicle) select 2)<5) then {_Boost = 0.0;} else {_Boost = 0.6;};
if (_Intensity < _MaxIntensity) then {_Intensity = _Intensity + 0.1*(15*_looptime)};
if ((speed _vehicle) < _maxspeed) then {_vehicle setVelocity [(velocity _vehicle select 0)+((vectordir _vehicle) select 0)*((_Boost*_Intensity/2)*(15*_looptime)),(velocity _vehicle select 1)+((vectordir _vehicle) select 1)*((_Boost*_Intensity/2)*(15*_looptime)),(velocity _vehicle select 2)+((vectordir _vehicle) select 2)*((_Boost*_Intensity/2)*(15*_looptime))]};
if (fuel _vehicle > 0) then {_vehicle setFuel ((fuel _vehicle)-((1/_fueldrag)*(3*_looptime)))};
} 
else {if (_Intensity > 0) then {_Intensity = _Intensity - 0.2*(15*_looptime)}};


sleep 0.05;
_runtime = _runtime - 1;
};

sleep 3;



};
