Basic key system for locking vehicles.
Primary target would be any role play TVT, but has usues in all game types, even coops (DAC AI will steal unlocked vehicles)


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
AGM_VEHICLELOCK_defaultLockpickStrength

vehicle setVariables:
AGM_VehicleLock_type - either side [west, east...] or number [0-49] - determins what key will open it
agm_vehicleLock_pickStr - determins how long lockpicking with take