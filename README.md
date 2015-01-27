<p align="center">
  <img src="https://raw.githubusercontent.com/KoffeinFlummi/AGM/master/.devfiles/Assets/Logo/agm_logo_black_transparent.png" height="150px" /><br />
  <a href="https://github.com/KoffeinFlummi/AGM/releases">
    <img src="http://img.shields.io/badge/release-0.95.1-green.svg?style=flat"
         alt="AGM version" />
  </a>
  <a href="https://github.com/KoffeinFlummi/AGM/releases/download/v0.95.1/AGM_v0.95.1.zip">
    <img src="http://img.shields.io/badge/download-22_MB-blue.svg?style=flat"
         alt="AGM download" />
  </a>
  <a href="https://github.com/KoffeinFlummi/AGM/issues">
    <img src="http://img.shields.io/github/issues/KoffeinFlummi/AGM.svg?style=flat"
         alt="AGM issues" />
  </a>
  <a href="https://github.com/KoffeinFlummi/AGM/blob/master/LICENSE">
    <img src="http://img.shields.io/badge/license-GPLv2-red.svg?style=flat"
         alt="AGM license" />
  </a>
</p>
<p align="center"><sup><strong>Requires the latest version of <a href="http://www.armaholic.com/page.php?id=18767">CBA A3</a> | <a href="http://makearmanotwar.com/entry/7jnWM53S2e">Make Arma Not War</a> | <a href="http://forums.bistudio.com/showthread.php?178253-Authentic-Gameplay-Modification">BIF thread</a></strong></sup></p>

**AGM** is a modular authenticism/realism mod for Arma 3, partly based on Taosenai's work with [TMR](https://github.com/Taosenai/tmr).

This mod is entirely **open-source**, and everyone is free to propose changes or maintain their own, customized version as long as they make their changes open to the public in accordance with the GNU General Public License (for more information check the license file attached to this project).

The mod is **built modularly** — almost any PBO can be removed, thus a team can maintain its own tailored version of AGM, which excludes a select number of components that they don't like, or which conflict with other add-ons. Components themselves, like e.g. the medical system, also include various customization options, allowing mission designers to tweak the overall experience.

More information on the purpose of the different components of AGM and which ones they rely on can be found [here](https://github.com/KoffeinFlummi/AGM/wiki#features).

### Features
*   Improved medical system
*   Logistics system including cargo transport and vehicle maintenance
*   Explosives system including different trigger types
*   Captivity system
*   Realistic names for vehicles and weapons
*   Realistic ballistics including wind and humidity
*   Backblast simulation
*   Weapon resting and bipod deployment
*   A fire control system for armored vehicles and helicopters<br />
    ***and more...***

For a full list of current features, check [the official wiki](https://github.com/KoffeinFlummi/AGM/wiki).

#### Guides & How-Tos
If you installed AGM, but have trouble understanding how it all works, or where to start — see [Getting Started](https://github.com/KoffeinFlummi/AGM/wiki/Getting-Started).

#### Contributing
If you want to help put with the ongoing development, you can do so by looking for possible bugs or by contributing new features. To contribute something to AGM, simply fork this repository and submit your pull requests for review by other collaborators. In the process, feel free to add yourself to the author array of any .pbo you will be editing and the `AUTHORS.txt` file.

To report a bug, propose a feature, or suggest a change to the existing one — please, use our [Issue Tracker](https://github.com/KoffeinFlummi/AGM/issues).

For detailed information on how to make your weapons or vehicles compatible with AGM — read [this article](https://github.com/KoffeinFlummi/AGM/wiki/For-Addon-Makers).

#### Testing & Building
If you want to help us test the latest development changes, feel free to download our master branch, using either git — if familiar with the process — or directly, by following [this link](https://github.com/KoffeinFlummi/AGM/archive/master.zip).

To binarize the addon for testing you can use the `binarizer.exe` in the main folder or, if you have [Python 3](https://www.python.org/) installed, use the python script for some more options. Alternatively you can manually binarize every PBO using Addon Builder or any other binarizer. All of those methods require the Arma 3 Tools to be installed, which can be found on Steam.

In order for the addons to be correctly binarized, you need to exclude the following file types from binarization (the binarizer script does this for you):
```
*.pac;*.paa;*.sqf;*.sqs;*.bikb;*.fsm;*.wss;*.ogg;*.wav;*.fxy;*.csv;*.html;*.lip;*.txt;*.wrp;*.bisurf;*.xml;*.hqf;
```

---
<p align="center"><a href="https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&amp;hosted_button_id=HPAXPTVCNLDZS"><img src="https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif" style="max-width:100%;"></a></p>
