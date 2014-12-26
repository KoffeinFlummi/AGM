Advanced Mortars (Effected by wind, drag, powder temp)

Adds:
  Vehicles:
    "B_AGM_advancedMortar"
  Backpacks:
    "B_AGM_Artillery_backpack_tube"
    "B_AGM_Artillery_backpack_baseplate"
  Items:
    "AGM_RangeTable_81mm"

Open rangetable with agm action (under Equipment)

Mortar has several options changeable by setVariables.  (Note the Artilery Computer is completly custom, so this will ignore the enableEngineArtillery setting command)
  "AGM_Artillery_mapComputerEnabled" - BOOL: (default false) controls if a Map Artilery Computer is available.  Different, but similar to A3 aComp (click on map OR enter map cords to compute)
  "AGM_Artillery_rangefinderEnabled" - BOOL: (default false) controls if a rangefinder computer is available.  Similar to A3 mortar gunner view (hold tab and relase to compute)
  "AGM_Artillery_digialDisplayEnabled" - BOOL: (default true) Simple digital dispaly of elevation and azimuth in MILs.  Just makes it easier to quickly read current settings.
  
Default key to range is TAB - (WIP on integration with FCS???)