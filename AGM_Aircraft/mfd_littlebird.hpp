
class MFD {
  class AirplaneHUD {
    borderBottom = 0;
    borderLeft = 0;
    borderRight = 0;
    borderTop = 0;
    bottomLeft = "HUD LD";
    color[] = {0,1,0,0.1};
    helmetDown[] = {-0,-0.05,0};
    helmetMountedDisplay = 1;
    helmetPosition[] = {-0.0276,0.024,0.1};
    helmetRight[] = {0.055,0,0};
    topLeft = "HUD LH";
    topRight = "HUD PH";
    class Pos10Vector {
      pos0[] = {0.502,0.49};
      pos10[] = {1.112,1.03};
      type = "vector";
    };
    class Bones {
      /*
      class GunnerAim: Pos10Vector {
        pos0[] = {0,-0.0025};
        pos10[] = {0.01,0.0025};
        source = "weapon";
      };*/
      class ILS_H {
        pos0[] = {0.5,0.49};
        pos3[] = {0.683,0.49};
        type = "ils";
      };
      class ILS_W: ILS_H {
        pos0[] = {0.5,0.49};
        pos3[] = {0.5,0.652};
        type = "ils";
      };
      class Level0: Pos10Vector {
        angle = 0;
        pos0[] = {0.5,0.49};
        pos10[] = {1.11,1.03};
        type = "horizon";
      };
      class LevelM10: Level0 {
        angle = -10;
      };
      class LevelM20: Level0 {
        angle = -20;
      };
      class LevelM30: Level0 {
        angle = -30;
      };
      class LevelM40: Level0 {
        angle = -40;
      };
      class LevelM50: Level0 {
        angle = -50;
      };
      class LevelP10: Level0 {
        angle = 10;
      };
      class LevelP20: Level0 {
        angle = 20;
      };
      class LevelP30: Level0 {
        angle = 30;
      };
      class LevelP40: Level0 {
        angle = 40;
      };
      class LevelP50: Level0 {
        angle = 50;
      };
      class PlaneW {
        pos[] = {0.502,0.49};
        type = "fixed";
      };
      class Target: Pos10Vector {
        source = "target";
      };
      class Velocity: Pos10Vector {
        pos0[] = {0.5,0.49};
        pos10[] = {1.11,1.03};
        source = "velocity";
        type = "vector";
      };
      class WeaponAim: Pos10Vector {
        source = "weapon";
      };
    };
    class Draw {
      class AAMissile {
        condition = "AAmissile";
        class Circle {
          points[] = {{"WeaponAim",{0,-0.221311},1},{"WeaponAim",{0.125,-0.192541},1},{"WeaponAim",{0.2175,-0.110656},1},{"WeaponAim",{0.25,0},1},{"WeaponAim",{0.2175,0.110656},1},{"WeaponAim",{0.125,0.192541},1},{"WeaponAim",{0,0.221311},1},{"WeaponAim",{-0.125,0.192541},1},{"WeaponAim",{-0.2175,0.110656},1},{"WeaponAim",{-0.25,0},1},{"WeaponAim",{-0.2175,-0.110656},1},{"WeaponAim",{-0.125,-0.192541},1},{"WeaponAim",{0,-0.221311},1},{},{"Target",{0,-0.0619672},1},{"Target",{0.07,0},1},{"Target",{0,0.0619672},1},{"Target",{-0.07,0},1},{"Target",{0,-0.0619672},1}};
          type = "line";
          width = 4;
        };
      };
      class SpeedNumber {
        align = "right";
        down[] = {{0.06,0.52},1};
        pos[] = {{0.06,0.47},1};
        right[] = {{"0.14-0.02",0.47},1};
        scale = 1;
        source = "speed";
        sourceScale = 3.6;
        type = "text";
      };
      class AltNumber: SpeedNumber {
        down[] = {{"0.86-0.15",0.52},1};
        pos[] = {{"0.86-0.15",0.47},1};
        right[] = {{"0.94-0.15-0.02",0.47},1};
        source = "altitudeAGL";
        sourceScale = 1;
      };
      class AltScale {
        align = "right";
        bottom = 0.2;
        center = 0.5;
        down[] = {0.86,0.87};
        horizontal = 0;
        lineXleft = 0.825;
        lineXleftMajor = 0.825;
        lineYright = 0.835;
        lineYrightMajor = 0.845;
        majorLineEach = 5;
        max = "none";
        min = "none";
        numberEach = 5;
        pos[] = {0.86,0.82};
        right[] = {"0.94-0.02",0.82};
        scale = 1;
        source = "altitudeAGL";
        sourceScale = 1;
        step = 20;
        StepSize = "(0.85- 0.2)/20";
        top = 0.85;
        type = "scale";
        width = 4;
      };
      class ammo {
        align = "right";
        down[] = {{0.1,0.97},1};
        pos[] = {{0.1,0.93},1};
        right[] = {{"0.16-0.02",0.93},1};
        scale = 0.5;
        source = "ammo";
        sourceScale = 1;
        type = "text";
      };
      class ATMissile {
        condition = "ATmissile";
        class Circle {
          points[] = {{"WeaponAim",{-0.15,-0.15},1},{"WeaponAim",{-0.15,"-0.15+0.02"},1},{},{"WeaponAim",{-0.15,0.15},1},{"WeaponAim",{-0.15,"+0.15-0.02"},1},{},{"WeaponAim",{0.15,-0.15},1},{"WeaponAim",{0.15,"-0.15+0.02"},1},{},{"WeaponAim",{0.15,0.15},1},{"WeaponAim",{0.15,"+0.15-0.02"},1},{},{"WeaponAim",{-0.15,-0.15},1},{"WeaponAim",{"-0.15+0.02",-0.15},1},{},{"WeaponAim",{-0.15,0.15},1},{"WeaponAim",{"-0.15+0.02",0.15},1},{},{"WeaponAim",{0.15,-0.15},1},{"WeaponAim",{"0.15-0.02",-0.15},1},{},{"WeaponAim",{0.15,0.15},1},{"WeaponAim",{"0.15-0.02",0.15},1},{}};
          type = "line";
          width = 4;
        };
      };
      class Bomb {
        condition = "bomb";
        class Circle {
          points[] = {{"WeaponAim",{0,-0.0885246},1},{"WeaponAim",{0.05,-0.0770164},1},{"WeaponAim",{0.087,-0.0442623},1},{"WeaponAim",{0.1,0},1},{"WeaponAim",{0.087,0.0442623},1},{"WeaponAim",{0.05,0.0770164},1},{"WeaponAim",{0,0.0885246},1},{"WeaponAim",{-0.05,0.0770164},1},{"WeaponAim",{-0.087,0.0442623},1},{"WeaponAim",{-0.1,0},1},{"WeaponAim",{-0.087,-0.0442623},1},{"WeaponAim",{-0.05,-0.0770164},1},{"WeaponAim",{0,-0.0885246},1},{},{"Velocity",0.001,"WeaponAim",{0,0},1},{"Velocity",{0,0},1},{},{"Target",{0,-0.0619672},1},{"Target",{0.07,0},1},{"Target",{0,0.0619672},1},{"Target",{-0.07,0},1},{"Target",{0,-0.0619672},1}};
          type = "line";
          width = 4;
        };
      };/*
      class Gunner {
        points[] = {{"GunnerAim",{"0.5-0.015","0.9-0.008"},1},{"GunnerAim",{"0.5-0.015","0.9+0.008"},1},{"GunnerAim",{"0.5+0.015","0.9+0.008"},1},{"GunnerAim",{"0.5+0.015","0.9-0.008"},1},{"GunnerAim",{"0.5-0.015","0.9-0.008"},1}};
        type = "line";
        width = 4;
      };*/
      class HeadingScale {
        align = "center";
        bottom = 0.7;
        center = 0.5;
        down[] = {"0.30-0.00","0.04+0.05"};
        horizontal = 1;
        lineXleft = "0.06+0.05";
        lineXleftMajor = "0.07+0.05";
        lineYright = "0.05+0.05";
        lineYrightMajor = "0.04+0.05";
        majorLineEach = 3;
        max = "none";
        min = "none";
        numberEach = 3;
        pos[] = {"0.30-0.00","0.0+0.05"};
        right[] = {"0.36-0.00","0.0+0.05"};
        scale = 1;
        source = "Heading";
        sourceScale = 1;
        step = 10;
        StepSize = "(0.70- 0.3)/15";
        top = 0.3;
        type = "scale";
        width = 4;
      };
      class HorizontalLine {
        clipBR[] = {0.8,0.96};
        clipTL[] = {0.2,0.12};
        class HorizontalLineDraw {
          points[] = {{"Level0",{"-6*0.075/2",0.02},1},{"Level0",{"-5*0.075/2",0.02},1},{},{"Level0",{"-4*0.075/2",0.02},1},{"Level0",{"-3*0.075/2",0.02},1},{},{"Level0",{"-2*0.075/2",0.02},1},{"Level0",{"-1*0.075/2",0.02},1},{},{"Level0",{"1*0.075/2",0.02},1},{"Level0",{"2*0.075/2",0.02},1},{},{"Level0",{"3*0.075/2",0.02},1},{"Level0",{"4*0.075/2",0.02},1},{},{"Level0",{"5*0.075/2",0.02},1},{"Level0",{"6*0.075/2",0.02},1}};
          source = "Level0";
          type = "line";
        };
      };
      class MGun {
        condition = "mgun";
        class Circle {
          points[] = {{"WeaponAim",{0.05,0},1},{"WeaponAim",{0.015,0},1},{},{"WeaponAim",{0,0.0442623},1},{"WeaponAim",{0,0.0132787},1},{},{"WeaponAim",{-0.05,0},1},{"WeaponAim",{-0.015,0},1},{},{"WeaponAim",{0,-0.0442623},1},{"WeaponAim",{0,-0.0132787},1},{}};
          type = "line";
          width = 4;
        };
      };
      class PlaneHeading {
        clipBR[] = {1,0};
        clipTL[] = {0,1};
        points[] = {{"Velocity",{0,-0.0177049},1},{"Velocity",{0.014,-0.0123934},1},{"Velocity",{0.02,0},1},{"Velocity",{0.014,0.0123934},1},{"Velocity",{0,0.0177049},1},{"Velocity",{-0.014,0.0123934},1},{"Velocity",{-0.02,0},1},{"Velocity",{-0.014,-0.0123934},1},{"Velocity",{0,-0.0177049},1},{},{"Velocity",{0.04,0},1},{"Velocity",{0.02,0},1},{},{"Velocity",{-0.04,0},1},{"Velocity",{-0.02,0},1},{},{"Velocity",{0,-0.0354098},1},{"Velocity",{0,-0.0177049},1},{}};
        type = "line";
        width = 4;
      };
      class PlaneW {
        clipBR[] = {1,0};
        clipTL[] = {0,1};
        points[] = {{"PlaneW",{0,-0.0177049},1},{"PlaneW",{0.014,-0.0123934},1},{"PlaneW",{0.02,0},1},{"PlaneW",{0.014,0.0123934},1},{"PlaneW",{0,0.0177049},1},{"PlaneW",{-0.014,0.0123934},1},{"PlaneW",{-0.02,0},1},{"PlaneW",{-0.014,-0.0123934},1},{"PlaneW",{0,-0.0177049},1},{}};
        type = "line";
        width = 4;
      };
      class Rockets {
        condition = "Rocket";
        class Circle {
          points[] = {{"WeaponAim",{-0.25,-0.25},1},{"WeaponAim",{-0.25,"-0.25+0.05"},1},{},{"WeaponAim",{-0.25,0.25},1},{"WeaponAim",{-0.25,"+0.25-0.05"},1},{},{"WeaponAim",{0.25,-0.25},1},{"WeaponAim",{0.25,"-0.25+0.05"},1},{},{"WeaponAim",{0.25,0.25},1},{"WeaponAim",{0.25,"+0.25-0.05"},1},{},{"WeaponAim",{-0.25,-0.25},1},{"WeaponAim",{"-0.25+0.05",-0.25},1},{},{"WeaponAim",{-0.25,0.25},1},{"WeaponAim",{"-0.25+0.05",0.25},1},{},{"WeaponAim",{0.25,-0.25},1},{"WeaponAim",{"0.25-0.05",-0.25},1},{},{"WeaponAim",{0.25,0.25},1},{"WeaponAim",{"0.25-0.05",0.25},1},{}};
          type = "line";
          width = 4;
        };
      };
      /*
      class Static {
        clipBR[] = {1,0};
        clipTL[] = {0,0.1};
        points[] = {{{0.79,0.52},1},{{0.81,0.5},1},{{0.79,0.48},1},{},{{0.52,"0.08+0.06"},1},{{0.5,"0.06+0.06"},1},{{0.48,"0.08+0.06"},1},{},{{"0.5-0.1","0.9-0.04"},1},{{"0.5-0.1","0.9+0.04"},1},{{"0.5+0.1","0.9+0.04"},1},{{"0.5+0.1","0.9-0.04"},1},{{"0.5-0.1","0.9-0.04"},1},{},{{"0.5-0.1",0.9},1},{{"0.5-0.092",0.9},1},{},{{"0.5+0.1",0.9},1},{{"0.5+0.092",0.9},1},{},{{0.5,"0.9-0.04"},1},{{0.5,"0.9-0.032"},1},{},{{0.5,"0.9+0.04"},1},{{0.5,"0.9+0.032"},1},{}};
        type = "line";
        width = 4;
      };
      */
      class weapons {
        align = "right";
        down[] = {{0.1,0.92},1};
        pos[] = {{0.1,0.88},1};
        right[] = {{"0.16-0.02",0.88},1};
        scale = 0.5;
        source = "weapon";
        sourceScale = 1;
        type = "text";
      };
    };
  };
};
