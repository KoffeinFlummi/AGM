
class CfgVehicles {
  class LandVehicle;
  class Tank: LandVehicle {
    AGM_enableCamshake = 1;
  };
  class Car: LandVehicle {
    AGM_enableCamshake = 1;
  };
  class StaticWeapon: LandVehicle {
    AGM_enableCamshake = 1;
  };

  class Allvehicles;
  class Air: Allvehicles {
    AGM_enableCamshake = 1;
  };
};
