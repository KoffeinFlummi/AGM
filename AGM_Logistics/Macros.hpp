
#define MACRO_LOADABLE \
	class AGM_loadItem { \
		displayName = "Load Item"; \
		distance = 4; \
		condition = "[AGM_Interaction_Target] call AGM_Logistics_fnc_canLoadItem"; \
		statement = "[AGM_Interaction_Target, AGM_Logistics_targetVehicle] call AGM_Logistics_fnc_openLoadUI"; \
		showDisabled = 1; \
		priority = 2.26; \
	};

#define MACRO_DRAGABLE \
	class AGM_DragItem { \
		displayName = $STR_AGM_Drag_StartDrag; \
		distance = 4; \
		condition = "!(player call AGM_Drag_fnc_isDraggingObject) AND {[AGM_Interaction_Target, player] call AGM_Drag_fnc_isDraggable}"; \
		statement = "[AGM_Interaction_Target, player] call AGM_Drag_fnc_dragObject"; \
		showDisabled = 1; \
		priority = 3; \
	}; \
	class AGM_ReleaseItem { \
		displayName = $STR_AGM_Drag_EndDrag; \
		distance = 4; \
		condition = "player call AGM_Drag_fnc_isDraggingObject"; \
		statement = "player call AGM_Drag_fnc_releaseObject"; \
		exceptions[] = {"AGM_Drag_isNotDragging"}; \
		showDisabled = 0; \
		priority = 3; \
	};

#define MACRO_NOT_DRAGABLE \
	class AGM_DragItem { \
		condition = "false"; \
	};

#define MACRO_GETIN_STATIC \
	class AGM_GetIn { \
		displayName = "$STR_AGM_StaticWeapons_GetIn"; \
		distance = 4; \
		condition = "[AGM_Interaction_Target] call AGM_StaticWeapons_fnc_canGetIn"; \
		statement = "[AGM_Interaction_Target] call AGM_StaticWeapons_fnc_getIn"; \
		showDisabled = 0; \
		priority = 1; \
	}; \
	class AGM_RotateClockwise { \
		displayName = "$STR_AGM_StaticWeapons_RotateClockwise"; \
		distance = 4; \
		condition = "[AGM_Interaction_Target, true] call AGM_StaticWeapons_fnc_canRotate"; \
		statement = "[AGM_Interaction_Target, true] call AGM_StaticWeapons_fnc_rotate"; \
		showDisabled = 1; \
		priority = 2.1; \
	}; \
	class AGM_RotateCounterclockwise { \
		displayName = "$STR_AGM_StaticWeapons_RotateCounterclockwise"; \
		distance = 4; \
		condition = "[AGM_Interaction_Target, false] call AGM_StaticWeapons_fnc_canRotate"; \
		statement = "[AGM_Interaction_Target, false] call AGM_StaticWeapons_fnc_rotate"; \
		showDisabled = 1; \
		priority = 2; \
	};

#define MACRO_CUTWIRE \
	class AGM_Wirecutter_cut { \
		displayName = "$STR_AGM_CutFence"; \
		distance = 4; \
		condition = "'ToolKit' in items player && {alive AGM_Interaction_Target}"; \
		statement = "[5, AGM_Interaction_Target] call AGM_Wirecutter_fnc_cutDownFence"; \
		showDisabled = 1; \
		priority = 2.1; \
	};

#define MACRO_CUTWIRE_LONG \
	class AGM_Wirecutter_cut { \
		displayName = "$STR_AGM_CutFence"; \
		distance = 4; \
		condition = "'ToolKit' in items player && {alive AGM_Interaction_Target}"; \
		statement = "[5, AGM_Interaction_Target] call AGM_Wirecutter_fnc_cutDownFence"; \
		showDisabled = 1; \
		priority = 2.1; \
	};
