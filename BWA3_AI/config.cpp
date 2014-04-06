class CfgPatches {
  class BWA3_AI {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {};
    version = 1.0;
    author[] = {"KoffeinFlummi"};
    authorUrl = "https://github.com/KoffeinFlummi/";
  };
};

/* 
 * Documentation:
 * https://community.bistudio.com/wiki/AI_Sub-skills
 * 
 * The idea here is to reduce the AI's godlike aiming
 * capabilties while retaining it's high intelligence.
 * The AI should be smart enough to move through a town,
 * but also be 'human' in their reaction time and aim.
 *
 * Note: All these values can still be adjusted via
 *       scripts, these arrays just change what 0 & 1
 *       are for setSkill.
 */

class CfgAISkill {
  aimingAccuracy[] = {0,0, 1,0.8};
  aimingShake[] = {0,0, 1,0.6};
  aimingSpeed[] = {0,0, 1,0.7};
  commanding[] = {0,0, 1,0.8};
  courage[] = {0,0, 1,0.7};
  reloadSpeed[] = {0,0, 1,0.8};
  spotDistance[] = {0,0, 1,0.9};
  spotTime[] = {0,0, 1,0.7};
};
