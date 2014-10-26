Adds keys as an item, to lock and unlock vehicles.

Primary target would be role play or TVT, but has uses in all game types, even co-ops (DAC AI will steal unlocked vehicles)

Modules allow fast setup, or can manualy add items and set variables.

Two key modes:

Side based (Default): "AGM_item_key_west" works on any hunter. 
Unique:  "AGM_item_key_13" is only key that will open a specific vehicle.

Items Added:

AGM_item_key_lockpick
AGM_item_key_master
AGM_item_key_west
AGM_item_key_east
AGM_item_key_indp
AGM_item_key_civ
AGM_item_key_0
...
AGM_item_key_49

Global Variable: 
AGM_VEHICLELOCK_defaultLockpickStrength - Time in seconds to lock pick globaly, can also set per-vehicle (-1 would disable)

vehicle setVariables:
AGM_VehicleLock_type - either side [west, east...] or number [0-49] - determins what key will open it
agm_vehicleLock_pickStr - determins how long lockpicking with take


New to github, hopefully I didn't screw up.  Not sure if this is within AGM's scope.
PabstMirror