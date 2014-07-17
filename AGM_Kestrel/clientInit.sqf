// by commy2

AGM_isKestrel = false;
AGM_isKestrelWheel = false;

0 spawn {
	waitUntil {preloadTitleRsc ["AGM_Kestrel", "PLAIN"]};
	waitUntil {preloadTitleRsc ["AGM_KestrelWheel", "PLAIN"]};
	waitUntil {preloadTitleRsc ["AGM_KestrelWheel_Preload", "PLAIN"]};
};
