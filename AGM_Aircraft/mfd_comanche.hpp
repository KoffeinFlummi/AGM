class MFD {
  class AirplaneHUD {
    bottomLeft = "HUD_bottom_left";
    borderLeft = 0;
    borderRight = 0;
    borderTop = 0;
    borderBottom = 0;
    color[] = {0.15000001,1,0.15000001,1};
    enableParallax = 0;
    helmetMountedDisplay = 1;
    helmetPosition[] = {-0.035,0.035,0.1};
    helmetRight[] = {0.070000001,0,0};
    helmetDown[] = {-0,-0.070000001,0};
    topLeft = "HUD_top_left";
    topRight = "HUD_top_right";
    class Bones {
      class PlaneOrientation {
        type = "fixed";
        pos[] = {0.5,0.54};
      };
      class GunnerAim: Pos10Vector {
        source = "weapon";
        pos0[] = {0,-0.0024999999};
        pos10[] = {0.0099999998,-0.0024999999};
      };
      class Target: Pos10Vector {
        source = "target";
      };
      class Velocity {
        type = "vector";
        source = "velocity";
        pos0[] = {0.5,0.5};
        pos10[] = {0.65,0.65};
      };
      class Level0 {
        type = "horizon";
        pos0[] = {0.5,0.52999997};
        pos10[] = {1.5,1.53};
        angle = 0;
      };
      class TerrainBone {
        type = "linear";
        source = "altitudeAGL";
        sourceScale = 1;
        min = 0;
        max = 200;
        minPos[] = {0,0.66600001};
        maxPos[] = {0,0.40000001};
      };
    };
    class Draw {
      color[] = {0.15000001,1,0.15000001};
      alpha = 0.40000001;
      condition = "on";
      class Horizont {
        clipTL[] = {0.25,0.25};
        clipBR[] = {0.75,0.75};
        class Dimmed {
          class Level00 {
            type = "line";
            width = 4;
            points[] =  {
              {
                "Level0",
                {
                  "-0.200 * 1.4",
                  "0 * 1.4"
                },
                1
              },
              {
                "Level0",
                {
                  "-0.125 * 1.4",
                  "0 * 1.4"
                },
                1
            },{},
              {
                "Level0",
                {
                  "-0.045 * 1.4",
                  "0 * 1.4"
                },
                1
              },
              {
                "Level0",
                {
                  "-0.005 * 1.4",
                  "0 * 1.4"
                },
                1
            },{},
              {
                "Level0",
                {
                  "0.005 * 1.4",
                  "0 * 1.4"
                },
                1
              },
              {
                "Level0",
                {
                  "0.045 * 1.4",
                  "0 * 1.4"
                },
                1
            },{},
              {
                "Level0",
                {
                  "0.125 * 1.4",
                  "0 * 1.4"
                },
                1
              },
              {
                "Level0",
                {
                  "0.200 * 1.4",
                  "0 * 1.4"
                },
                1
              }
            };
          };
          class Level2M5: Level00 {
            type = "line";
            points[] =  {
              {
                "Level0",
                {
                  "-0.200 * 1.4",
                  "-1.0 / 10 * 5"
                },
                1
              },
              {
                "Level0",
                {
                  "-0.125 * 1.4",
                  "-1.0 / 10 * 5"
                },
                1
            },{},
              {
                "Level0",
                {
                  "+0.125 * 1.4",
                  "-1.0 / 10 * 5"
                },
                1
              },
              {
                "Level0",
                {
                  "+0.200 * 1.4",
                  "-1.0 / 10 * 5"
                },
                1
              }
            };
          };
          class VALM2_1_5 {
            type = "text";
            source = "static";
            text = 5;
            align = "center";
            scale = 1;
            sourceScale = 1;
            pos[] =  {
              "Level0",
              {
                "0.000 * 1.4",
                "-0.020 * 1.4 - 1.0 / 10 * 5"
              },
              1
            };
            right[] =  {
              "Level0",
              {
                "0.050 * 1.4",
                "-0.020 * 1.4 - 1.0 / 10 * 5"
              },
              1
            };
            down[] =  {
              "Level0",
              {
                "0.000 * 1.4",
                "+0.020 * 1.4 - 1.0 / 10 * 5"
              },
              1
            };
          };
          class Level2P5: Level00 {
            type = "line";
            points[] =  {
              {
                "Level0",
                {
                  "-0.200 * 1.4",
                  "+1.0 / 10 * 5"
                },
                1
              },
              {
                "Level0",
                {
                  "-0.125 * 1.4",
                  "+1.0 / 10 * 5"
                },
                1
            },{},
              {
                "Level0",
                {
                  "+0.125 * 1.4",
                  "+1.0 / 10 * 5"
                },
                1
              },
              {
                "Level0",
                {
                  "+0.200 * 1.4",
                  "+1.0 / 10 * 5"
                },
                1
              }
            };
          };
          class VALP2_1_5 {
            type = "text";
            source = "static";
            text = -5;
            align = "center";
            scale = 1;
            sourceScale = 1;
            pos[] =  {
              "Level0",
              {
                "0.000 * 1.4",
                "-0.020 * 1.4 + 1.0 / 10 * 5"
              },
              1
            };
            right[] =  {
              "Level0",
              {
                "0.050 * 1.4",
                "-0.020 * 1.4 + 1.0 / 10 * 5"
              },
              1
            };
            down[] =  {
              "Level0",
              {
                "0.000 * 1.4",
                "+0.020 * 1.4 + 1.0 / 10 * 5"
              },
              1
            };
          };
          class Level2M10: Level00 {
            type = "line";
            points[] =  {
              {
                "Level0",
                {
                  "-0.200 * 1.4",
                  "-1.0 / 10 * 10"
                },
                1
              },
              {
                "Level0",
                {
                  "-0.125 * 1.4",
                  "-1.0 / 10 * 10"
                },
                1
            },{},
              {
                "Level0",
                {
                  "+0.125 * 1.4",
                  "-1.0 / 10 * 10"
                },
                1
              },
              {
                "Level0",
                {
                  "+0.200 * 1.4",
                  "-1.0 / 10 * 10"
                },
                1
              }
            };
          };
          class VALM2_1_10 {
            type = "text";
            source = "static";
            text = 10;
            align = "center";
            scale = 1;
            sourceScale = 1;
            pos[] =  {
              "Level0",
              {
                "0.000 * 1.4",
                "-0.020 * 1.4 - 1.0 / 10 * 10"
              },
              1
            };
            right[] =  {
              "Level0",
              {
                "0.050 * 1.4",
                "-0.020 * 1.4 - 1.0 / 10 * 10"
              },
              1
            };
            down[] =  {
              "Level0",
              {
                "0.000 * 1.4",
                "+0.020 * 1.4 - 1.0 / 10 * 10"
              },
              1
            };
          };
          class Level2P10: Level00 {
            type = "line";
            points[] =  {
              {
                "Level0",
                {
                  "-0.200 * 1.4",
                  "+1.0 / 10 * 10"
                },
                1
              },
              {
                "Level0",
                {
                  "-0.125 * 1.4",
                  "+1.0 / 10 * 10"
                },
                1
            },{},
              {
                "Level0",
                {
                  "+0.125 * 1.4",
                  "+1.0 / 10 * 10"
                },
                1
              },
              {
                "Level0",
                {
                  "+0.200 * 1.4",
                  "+1.0 / 10 * 10"
                },
                1
              }
            };
          };
          class VALP2_1_10 {
            type = "text";
            source = "static";
            text = -10;
            align = "center";
            scale = 1;
            sourceScale = 1;
            pos[] =  {
              "Level0",
              {
                "0.000 * 1.4",
                "-0.020 * 1.4 + 1.0 / 10 * 10"
              },
              1
            };
            right[] =  {
              "Level0",
              {
                "0.050 * 1.4",
                "-0.020 * 1.4 + 1.0 / 10 * 10"
              },
              1
            };
            down[] =  {
              "Level0",
              {
                "0.000 * 1.4",
                "+0.020 * 1.4 + 1.0 / 10 * 10"
              },
              1
            };
          };
          class Level2M15: Level00 {
            type = "line";
            points[] =  {
              {
                "Level0",
                {
                  "-0.200 * 1.4",
                  "-1.0 / 10 * 15"
                },
                1
              },
              {
                "Level0",
                {
                  "-0.125 * 1.4",
                  "-1.0 / 10 * 15"
                },
                1
            },{},
              {
                "Level0",
                {
                  "+0.125 * 1.4",
                  "-1.0 / 10 * 15"
                },
                1
              },
              {
                "Level0",
                {
                  "+0.200 * 1.4",
                  "-1.0 / 10 * 15"
                },
                1
              }
            };
          };
          class VALM2_1_15 {
            type = "text";
            source = "static";
            text = 15;
            align = "center";
            scale = 1;
            sourceScale = 1;
            pos[] =  {
              "Level0",
              {
                "0.000 * 1.4",
                "-0.020 * 1.4 - 1.0 / 10 * 15"
              },
              1
            };
            right[] =  {
              "Level0",
              {
                "0.050 * 1.4",
                "-0.020 * 1.4 - 1.0 / 10 * 15"
              },
              1
            };
            down[] =  {
              "Level0",
              {
                "0.000 * 1.4",
                "+0.020 * 1.4 - 1.0 / 10 * 15"
              },
              1
            };
          };
          class Level2P15: Level00 {
            type = "line";
            points[] =  {
              {
                "Level0",
                {
                  "-0.200 * 1.4",
                  "+1.0 / 10 * 15"
                },
                1
              },
              {
                "Level0",
                {
                  "-0.125 * 1.4",
                  "+1.0 / 10 * 15"
                },
                1
            },{},
              {
                "Level0",
                {
                  "+0.125 * 1.4",
                  "+1.0 / 10 * 15"
                },
                1
              },
              {
                "Level0",
                {
                  "+0.200 * 1.4",
                  "+1.0 / 10 * 15"
                },
                1
              }
            };
          };
          class VALP2_1_15 {
            type = "text";
            source = "static";
            text = -15;
            align = "center";
            scale = 1;
            sourceScale = 1;
            pos[] =  {
              "Level0",
              {
                "0.000 * 1.4",
                "-0.020 * 1.4 + 1.0 / 10 * 15"
              },
              1
            };
            right[] =  {
              "Level0",
              {
                "0.050 * 1.4",
                "-0.020 * 1.4 + 1.0 / 10 * 15"
              },
              1
            };
            down[] =  {
              "Level0",
              {
                "0.000 * 1.4",
                "+0.020 * 1.4 + 1.0 / 10 * 15"
              },
              1
            };
          };
        };
      };
      class PlaneOrientationCrosshair {
        type = "line";
        width = 4;
        points[] =  {
          {
            "PlaneOrientation",{-0.125,0},
            1
          },
          {
            "PlaneOrientation",{-0.050000001,0},
            1
          },
          {
            "PlaneOrientation",{-0.025,0.050000001},
            1
          },
          {
            "PlaneOrientation",{0,0},
            1
          },
          {
            "PlaneOrientation",{0.025,0.050000001},
            1
          },
          {
            "PlaneOrientation",{0.050000001,0},
            1
          },
          {
            "PlaneOrientation",{0.125,0},
            1
          }
        };
      };
      class WeaponName {
        type = "text";
        source = "weapon";
        sourceScale = 1;
        align = "right";
        scale = 1;
      pos[] = {{0.029999999,0.94},
          1
        };
      right[] = {{0.079999998,0.94},
          1
        };
      down[] = {{0.029999999,0.98000002},
          1
        };
      };
      class Static {
        clipTL[] = {0,0.1};
        clipBR[] = {1,0};
        type = "line";
        width = 4;
        points[] = { {
            {
              "0.5-0.1",
              "0.9-0.04"
            },
            1
          },
          {
            {
              "0.5-0.1",
              "0.9+0.04"
            },
            1
          },
          {
            {
              "0.5+0.1",
              "0.9+0.04"
            },
            1
          },
          {
            {
              "0.5+0.1",
              "0.9-0.04"
            },
            1
          },
          {
            {
              "0.5-0.1",
              "0.9-0.04"
            },
            1
        },{},
          {
            {
              "0.5-0.1",
              0.89999998
            },
            1
          },
          {
            {
              "0.5-0.092",
              0.89999998
            },
            1
        },{},
          {
            {
              "0.5+0.1",
              0.89999998
            },
            1
          },
          {
            {
              "0.5+0.092",
              0.89999998
            },
            1
        },{},
          {
            {
              0.5,
              "0.9-0.04"
            },
            1
          },
          {
            {
              0.5,
              "0.9-0.032"
            },
            1
        },{},
          {
            {
              0.5,
              "0.9+0.04"
            },
            1
          },
          {
            {
              0.5,
              "0.9+0.032"
            },
            1
        },{}
        };
      };
      class Gunner {
        type = "line";
        width = 4;
        points[] =  {
          {
            "GunnerAim",
            {
              "0.5-0.015",
              "0.9-0.008"
            },
            1
          },
          {
            "GunnerAim",
            {
              "0.5-0.015",
              "0.9+0.008"
            },
            1
          },
          {
            "GunnerAim",
            {
              "0.5+0.015",
              "0.9+0.008"
            },
            1
          },
          {
            "GunnerAim",
            {
              "0.5+0.015",
              "0.9-0.008"
            },
            1
          },
          {
            "GunnerAim",
            {
              "0.5-0.015",
              "0.9-0.008"
            },
            1
          }
        };
      };
      class AmmoCount {
        type = "text";
        source = "ammo";
        sourceScale = 1;
        align = "right";
        scale = 1;
      pos[] = {{0.029999999,0.88999999},
          1
        };
      right[] = {{0.079999998,0.88999999},
          1
        };
      down[] = {{0.029999999,0.93000001},
          1
        };
      };
      class LightsGroup {
        type = "group";
        condition = "lights";
        class LightsText {
          type = "text";
          source = "static";
          text = "LIGHTS";
          align = "right";
          scale = 1;
          pos[] =  {
            {
              0.029999999,
              "0.53 + 0.055"
            },
            1
          };
          right[] =  {
            {
              0.079999998,
              "0.53 + 0.055"
            },
            1
          };
          down[] =  {
            {
              0.029999999,
              "0.53 + 0.095"
            },
            1
          };
        };
      };
      class CollisionLightsGroup {
        type = "group";
        condition = "collisionlights";
        class CollisionLightsText {
          type = "text";
          source = "static";
          text = "A-COL";
          align = "right";
          scale = 1;
          pos[] =  {
            {
              0.029999999,
              "0.53 + 0.105"
            },
            1
          };
          right[] =  {
            {
              0.079999998,
              "0.53 + 0.105"
            },
            1
          };
          down[] =  {
            {
              0.029999999,
              "0.53 + 0.145"
            },
            1
          };
        };
      };
      class RangeNumber {
        type = "text";
        source = "targetDist";
        sourceScale = 1;
        align = "right";
        scale = 1;
      pos[] = {{0.50999999,0.94},
          1
        };
      right[] = {{0.56,0.94},
          1
        };
      down[] = {{0.50999999,0.98000002},
          1
        };
      };
      class RangeText {
        type = "text";
        source = "static";
        text = "RNG";
        align = "left";
        scale = 1;
      pos[] = {{0.49000001,0.94},
          1
        };
      right[] = {{0.54000002,0.94},
          1
        };
      down[] = {{0.49000001,0.98000002},
          1
        };
      };
      class SpeedNumber {
        type = "text";
        align = "right";
        scale = 1;
        source = "speed";
        sourceScale = 3.5999999;
      pos[] = {{0.059999999,0.47},
          1
        };
      right[] = {{0.12,0.47},
          1
        };
      down[] = {{0.059999999,0.51999998},
          1
        };
      };
      class HeadingNumber: SpeedNumber {
        source = "heading";
        sourceScale = 1;
        align = "center";
      pos[] = {{0.5,0},
          1
        };
      right[] = {{0.57999998,0},
          1
        };
      down[] = {{0.5,0.050000001},
          1
        };
      };
      class AltNumber: SpeedNumber {
        align = "left";
        source = "altitudeAGL";
        sourceScale = 1;
      pos[] = {{0.84,0.47},
          1
        };
      right[] = {{0.9,0.47},
          1
        };
      down[] = {{0.84,0.51999998},
          1
        };
      };
      class ASLText {
        type = "text";
        source = "static";
        text = "ASL";
        align = "left";
        scale = 1;
      pos[] = {{0.85000002,0.1},
          1
        };
      right[] = {{0.89999998,0.1},
          1
        };
      down[] = {{0.85000002,0.14},
          1
        };
      };
      class ASLNumber {
        type = "text";
        source = "altitudeASL";
        sourceScale = 1;
        align = "left";
        scale = 1;
      pos[] = {{0.85000002,0.14},
          1
        };
      right[] = {{0.89999998,0.14},
          1
        };
      down[] = {{0.85000002,0.18000001},
          1
        };
      };
      class AltitudeArrow {
        type = "line";
        width = 4;
        points[] =  {
          {
            {
              "0.88 + 0.018",
              "0.40 - 0.016"
            },
            1
          },
        {{0.88,0.40000001},
            1
          },
          {
            {
              "0.88 + 0.018",
              "0.40 + 0.016"
            },
            1
          }
        };
      };
      class AltitudeLine {
        type = "line";
        width = 4;
        points[] =  {
        {{0.87,0.60000002},
            1
          },
        {{0.87,0.2},
            1
          }
        };
      };
      class AltitudeScale {
        type = "scale";
        horizontal = 0;
        source = "altitudeAGL";
        sourceScale = 1;
        width = 4;
        top = 0.60000002;
        center = 0.40000001;
        bottom = 0.2;
        lineXleft = 0.88;
        lineYright = 0.88999999;
        lineXleftMajor = 0.88;
        lineYrightMajor = 0.89999998;
        majorLineEach = 5;
        numberEach = 5;
        step = 5;
        stepSize = "(0.60 - 0.20) / 15";
        align = "right";
        scale = 1;
        pos[] = {0.91000003,0.57999998};
        right[] = {0.95999998,0.57999998};
        down[] = {0.91000003,0.62};
      };
      class ClimbNumber {
        type = "text";
        source = "vspeed";
        sourceScale = 1;
        align = "right";
        scale = 1;
      pos[] = {{0.88999999,0.94},
          1
        };
      right[] = {{0.94,0.94},
          1
        };
      down[] = {{0.88999999,0.98000002},
          1
        };
      };
      class ClimbText {
        type = "text";
        source = "static";
        text = "CLIMB";
        align = "left";
        scale = 1;
      pos[] = {{0.87,0.94},
          1
        };
      right[] = {{0.92000002,0.94},
          1
        };
      down[] = {{0.87,0.98000002},
          1
        };
      };
      class ClimbArrow {
        type = "line";
        width = 4;
        points[] =  {
          {
            {
              "0.88 + 0.018",
              "0.80 - 0.016"
            },
            1
          },
        {{0.88,0.80000001},
            1
          },
          {
            {
              "0.88 + 0.018",
              "0.80 + 0.016"
            },
            1
          }
        };
      };
      class ClimbLine {
        type = "line";
        width = 4;
        points[] =  {
        {{0.87,0.92500001},
            1
          },
        {{0.87,0.67500001},
            1
          }
        };
      };
      class ClimbScale {
        type = "scale";
        horizontal = 0;
        source = "vspeed";
        sourceScale = 1;
        width = 4;
        top = 0.92500001;
        center = 0.80000001;
        bottom = 0.67500001;
        lineXleft = 0.88;
        lineYright = 0.88999999;
        lineXleftMajor = 0.88;
        lineYrightMajor = 0.89999998;
        majorLineEach = 5;
        numberEach = 5;
        step = 1; // 20
        stepSize = "(0.925 - 0.675) / 15";
        align = "right";
        scale = 1;
        pos[] = {0.91000003,0.90499997};
        right[] = {0.95999998,0.90499997};
        down[] = {0.91000003,0.94499999};
      };
      class HeadingArrow {
        type = "line";
        width = 3;
        points[] =  {
          {
            {
              "0.5 - 0.02",
              "0.11 - 0.02"
            },
            1
          },
        {{0.5,0.11},
            1
          },
          {
            {
              "0.5 + 0.02",
              "0.11 - 0.02"
            },
            1
          }
        };
      };
      class HeadingLine {
        type = "line";
        width = 4;
        points[] =  {
        {{0.30000001,0.12},
            1
          },
        {{0.69999999,0.12},
            1
          }
        };
      };
      class HeadingScale {
        type = "scale";
        horizontal = 1;
        source = "heading";
        sourceScale = 1;
        width = 4;
        top = 0.30000001;
        center = 0.5;
        bottom = 0.69999999;
        lineXleft = "0.06 + 0.05";
        lineYright = "0.05 + 0.05";
        lineXleftMajor = "0.06 + 0.05";
        lineYrightMajor = "0.04 + 0.05";
        majorLineEach = 5;
        numberEach = 5;
        step = "18 / 9";
        stepSize = "(0.70 - 0.3) / 15";
        align = "center";
        scale = 1;
        pos[] =  {
          0.30000001,
          "0.0 + 0.05"
        };
        right[] =  {
          0.34999999,
          "0.0 + 0.05"
        };
        down[] =  {
          0.30000001,
          "0.04 + 0.05"
        };
      };
    };
    class Pos10Vector {
      type = "vector";
      pos0[] = {0.5,0.5};
      pos10[] = {0.85,0.85};
    };
  };
  class LittleHUD {
    bottomLeft = "HUD_bottom_left";
    borderLeft = 0;
    borderRight = 0;
    borderTop = 0;
    borderBottom = 0;
    color[] = {0.15000001,1,0.15000001,1};
    enableParallax = 0;
    helmetMountedDisplay = 1;
    helmetPosition[] = {-0.025,0.025,0.1};
    helmetRight[] = {0.050000001,0,0};
    helmetDown[] = {-0,-0.050000001,0};
    topLeft = "HUD_top_left";
    topRight = "HUD_top_right";
    class Bones {
      class PlaneOrientation {
        type = "fixed";
        pos[] = {0.5,0.58};
      };
      class Velocity {
        type = "vector";
        source = "velocity";
        pos0[] = {0.5,0.5};
        pos10[] = {0.85,0.85};
      };
    };
    class Draw {
      color[] = {0.15000001,1,0.15000001};
      alpha = 0.40000001;
      condition = "on";
      class PlaneMovementCrosshair {
        type = "line";
        width = 4;
        points[] =  {
          {
            "Velocity",{0,-0.02},
            1
          },
          {
            "Velocity",{0.0099999998,-0.01732},
            1
          },
          {
            "Velocity",{0.01732,-0.0099999998},
            1
          },
          {
            "Velocity",{0.02,0},
            1
          },
          {
            "Velocity",{0.01732,0.0099999998},
            1
          },
          {
            "Velocity",{0.0099999998,0.01732},
            1
          },
          {
            "Velocity",{0,0.02},
            1
          },
          {
            "Velocity",{-0.0099999998,0.01732},
            1
          },
          {
            "Velocity",{-0.01732,0.0099999998},
            1
          },
          {
            "Velocity",{-0.02,0},
            1
          },
          {
            "Velocity",{-0.01732,-0.0099999998},
            1
          },
          {
            "Velocity",{-0.0099999998,-0.01732},
            1
          },
          {
            "Velocity",{0,-0.02},
            1
        },{},
          {
            "Velocity",{0.039999999,0},
            1
          },
          {
            "Velocity",{0.02,0},
            1
        },{},
          {
            "Velocity",{-0.039999999,0},
            1
          },
          {
            "Velocity",{-0.02,0},
            1
        },{},
          {
            "Velocity",{0,-0.039999999},
            1
          },
          {
            "Velocity",{0,-0.02},
            1
          }
        };
      };
      class RadarTargets {
        type = "radar";
        pos0[] = {0.5,0.5};
        pos10[] = {0.85,0.85};
        width = 2.5;
        points[] =  {
        {{-0.02,-0.02},
            1
          },
        {{0.02,-0.02},
            1
          },
        {{0.02,0.02},
            1
          },
        {{-0.02,0.02},
            1
          },
        {{-0.02,-0.02},
            1
          }
        };
      };
    };
    class Pos10Vector {
      type = "vector";
      pos0[] = {0.5,0.5};
      pos10[] = {0.85,0.85};
    };
  };
};
