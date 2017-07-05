#1194

Advanced Mortars (Effected by wind, drag, powder temp)

Adds:
-Vehicles:
   `B_AGM_advancedMortar`
-Backpacks:
    `B_AGM_Artillery_backpack_tube`
    `B_AGM_Artillery_backpack_baseplate`
-Items:
  `AGM_RangeTable_81mm`

Model is the just the A3 Mk6 mortar, but has a completely new HUD and interface e.g.: Actually shows current Charge (amount of propellant which effects muzzle velocity)

Open range table with AGM self-interaction (under Equipment submenu)

Mortar has several options changeable by setVariables.  (Note the Artillery Computer is completely custom, so this will ignore the enableEngineArtillery setting command)

  `AGM_Artillery_mapComputerEnabled` - BOOL: (default false) controls if a Map Artillery Computer is available.  Different, but similar to A3 aComp (click on map OR enter map cords to compute)

  `AGM_Artillery_rangefinderEnabled` - BOOL: (default false) controls if a rangefinder computer is available.  Similar to A3 mortar gunner view (hold tab and relase to compute)

  `AGM_Artillery_digialDisplayEnabled` - BOOL: (default true) Simple digital display of elevation and azimuth in MILS.  Just makes it easier to quickly read current settings.
  
Default key to range is TAB - (WIP on integration with FCS???)


