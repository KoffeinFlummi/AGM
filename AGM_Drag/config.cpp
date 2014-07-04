class CfgPatches {
	class AGM_Drag {
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.60;
		requiredAddons[] = {AGM_Core, AGM_Interaction, A3_Weapons_F_Ammoboxes};
		version = "0.92";
		versionStr = "0.92";
		versionAr[] = {0,92,0};
		author[] = {"Garth 'L-H' de Wet"};
		authorUrl = "https://github.com/corruptedheart/";
	};
};

class CfgFunctions
{
	class AGM_Drag {
		class Drag {
			file="AGM_Drag\functions";
			class initialise{postInit = 1;};
			class InitialiseDragable{};
			class dragObject{};
			class releaseObject{};
			class isDraggingObject{};
			class handleScrollWheel{};
			class setupDragObject{};
			class isDraggable{};
			class GetWeight{};
		};
	};
};

#define AGM_DragSupport 		class AGM_Actions { \
			class AGM_DragItem { \
				displayName = $STR_AGM_Drag_StartDrag; \
				distance = 4; \
				condition = "!(player call AGM_Drag_fnc_isDraggingObject) AND {[AGM_Interaction_Target, player] call AGM_Drag_fnc_isDraggable}"; \
				statement = "[AGM_Interaction_Target, player] call AGM_Drag_fnc_dragObject;"; \
				showDisabled = 1; \
				priority = 2.2; \
			}; \
			class AGM_ReleaseItem { \
				displayName = $STR_AGM_Drag_EndDrag; \
				distance = 4; \
				condition = "(player call AGM_Drag_fnc_isDraggingObject)"; \
				statement = "player call AGM_Drag_fnc_releaseObject;"; \
				showDisabled = 0; \
				priority = 2.1; \
			}; \
		};
		
#define AGM_NoDragSupport 		class AGM_Actions { \
			class AGM_DragItem { \
				condition = "false"; \
			}; \
		};

class CfgVehicles {
	class Man;

	class CAManBase: Man {
		class AGM_SelfActions {
			// Sometimes it is not possible to target an object that you are dragging
			// particularly noticeable on Stratis on the dock wall.
			// Adding a self option to release will fix this.
			class AGM_ReleaseItem {
				displayName = $STR_AGM_Drag_EndDrag;
				condition = "(player call AGM_Drag_fnc_isDraggingObject)";
				statement = "player call AGM_Drag_fnc_releaseObject;";
				showDisabled = 0;
				priority = 2.1;
			};
		};
	};
	
	class LandVehicle;
	class StaticWeapon:LandVehicle{
		AGM_DragSupport
	};
	
	class StaticMortar;
	class Mortar_01_base_F:StaticMortar{
		AGM_DragSupport
	};
	
	class ReammoBox_F;
	class EAST_Box_Base:ReammoBox_F{
		AGM_DragSupport
	};
	class IND_Box_Base:ReammoBox_F{
		AGM_DragSupport
	};
	class NATO_Box_Base:ReammoBox_F{
		AGM_DragSupport
	};
	// Remove Larger crate dragging support.
	// Would be better to allow some sort of joint push/drag functionality
	// Requiring 2 units to access the larger crates and attaching them together (a crappy method of doing it)
	// in order to move the bigger ones. Currently simply remove support.
	// I believe these crates are currently broken (hitbox doesn't work or something) in 1.22 (2014-07-04)
	class Box_East_AmmoVeh_F:EAST_Box_Base{
		AGM_NoDragSupport
	};
	class Box_NATO_AmmoVeh_F:NATO_Box_Base{
		AGM_NoDragSupport
	};
	class Box_IND_AmmoVeh_F:IND_Box_Base{
		AGM_NoDragSupport
	};
};