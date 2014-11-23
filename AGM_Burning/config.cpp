class CfgPatches {
  class AGM_Burning {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {AGM_Core};
    version = "0.94.1";
    versionStr = "0.94.1";
    versionAr[] = {0,94,1};
    author[] = {"commy2"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Burning {
    class AGM_Burning {
      file = "\AGM_Burning\functions";
      class burn;
      class initHuman;
    };
  };
};

class Extended_Init_EventHandlers {
  class CAManBase {
    class AGM_Burning_InitHuman {
      init = "_this call AGM_Burning_fnc_initHuman;";
    };
  };
};

class CfgCloudlets {
  class AGM_FXFire {
    interval = 0.02;  //0.01;
    circleRadius = 0;
    circleVelocity[] = {0,0,0};
    particleFSNtieth = 16;
    particleFSIndex = 10;
    particleFSFrameCount = 32;
    particleFSLoop = 1;
    angle = 0;
    angleVar = 0.1;

    particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
    animationName = "";
    particleType = "Billboard";

    timerPeriod = 1;
    lifeTime = 2.3;
    lifeTimeVar = 0.5;

    position[] = {0,0,0};
    positionVar[] = {0.3,0.3,0.3};
    positionVarConst[] = {0,0,0};

    moveVelocity[] = {0,1,0};
    moveVelocityVar[] = {0.1,0.5,0.1};
    MoveVelocityVarConst[] = {0,0,0};

    rotationVelocity = 0;
    rotationVelocityVar = 10;
    weight = 0.045;
    volume = 0.04;
    rubbing = 0.05;

    size[] = {2.4,0,3};  //{"1.2 * intensity + 1.8",0.3};  //{"1.2 * intensity + 1.8","0.1 * intensity + 0.3"};
    sizeCoef = 1;
    sizeVar = 0.5;

    color[] = {{1,1,1,-1}};
    colorCoef[] = {1,1,1,1};
    colorVar[] = {0.1,0.1,0.1,0};

    animationSpeed[] = {0.5,1};
    animationSpeedCoef = 1;

    randomDirectionPeriod = 0;
    randomDirectionPeriodVar = 0;
    randomDirectionIntensity = 0;
    randomDirectionIntensityVar = 0;

    onTimerScript = "";
    beforeDestroyScript = "";

    coreIntensity = 1.25;
    coreDistance = 3;
    damageTime = 0.1;
    constantDistance = 2;
    damageType = "Fire";
  };

  class AGM_FXFireTiny {
    interval = 0.1;
    circleRadius = 0;
    circleVelocity[] = {0,0,0};
    particleFSNtieth = 16;
    particleFSIndex = 10;
    particleFSFrameCount = 32;
    particleFSLoop = 1;
    angle = 0;
    angleVar = 1;

    particleShape = "\A3\data_f\ParticleEffects\Universal\Universal";
    animationName = "";
    particleType = "Billboard";

    timerPeriod = 3;
    lifeTime = 0.4;
    lifeTimeVar = 0.3;

    position[] = {0,0,0};
    positionVar[] = {0.01,0.02,0.01};
    positionVarConst[] = {0,0,0};
 
    moveVelocity[] = {0,0,0};
    moveVelocityVar[] = {0.01,0.01,0.01};
    MoveVelocityVarConst[] = {0,0,0};

    rotationVelocity = 0;
    rotationVelocityVar = 0;
    weight = 0.0515;
    volume = 0.04;
    rubbing = 0;

    size[] = {0.15,0};
    sizeCoef = 1;
    sizeVar = 0.06;

    color[] = {{1,0.8,0.8,-80},{1,0.8,0.8,-80},{0,0,0,0}};
    colorCoef[] = {1,1,1,1};
    colorVar[] = {0.1,0.1,0.1,0};

    animationSpeed[] = {1};
    animationSpeedCoef = 1;

    randomDirectionPeriod = 0;
    randomDirectionPeriodVar = 0;
    randomDirectionIntensity = 0;
    randomDirectionIntensityVar = 0;

    onTimerScript = "";
    beforeDestroyScript = "";
  };

  class AGM_FXFireSmall: AGM_FXFireTiny {
    positionVar[] = {0.1,0.05,0.1};

    rotationVelocityVar = 5;

    size[] = {0.3,0.05};
    sizeVar = 0.04;

    animationSpeed[] = {0.5,1};
    lifeTimeVar = 0.2;

    coreIntensity = 0.75;
    coreDistance = 0.25;
    damageTime = 0.1;
    constantDistance = 0.25;
    damageType = "Fire";
  };

  class AGM_FXFireMedium: AGM_FXFireSmall {
    interval = 0.015;
    angleVar = 0.1;

    timerPeriod = 1;
    lifeTime = 0.6;
    lifeTimeVar = 0.15;

    positionVar[] = {0.3,0.1,0.3};

    moveVelocity[] = {0,0.7,0};
    moveVelocityVar[] = {0.05,0.15,0.05};

    rotationVelocityVar = 10;
    weight = 0.045;
    rubbing = 0.05;

    size[] = {0.65,0.05};
    sizeVar = 0.03;

    color[] = {{1,1,1,-1}};

    animationSpeed[] = {0.5,1};

    coreIntensity = 1.25;
    coreDistance = 1;
    damageTime = 0.1;
    constantDistance = 1;
    damageType = "Fire";
  };

  class AGM_FXFireBig: AGM_FXFireMedium {
    interval = 0.01;

    lifeTimeVar = 0.3;

    size[] = {1.3,0.1};
    sizeVar = 0.05;
  };

  class AGM_FXFireLarge: AGM_FXFireMedium {
    interval = 0.01;

    lifeTime = 1.5;
    lifeTimeVar = 0.4;

    positionVar[] = {0.3,0.3,0.3};

    moveVelocity[] = {0,1,0};
    moveVelocityVar[] = {0.1,0.5,0.1};

    size[] = {1.8,0.12};
    sizeVar = 0.1;
  };
};
