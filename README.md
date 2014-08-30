Authentic Gameplay Mod
======================

<p align="center">
  <img src="http://puu.sh/9XcYf/99a85ec2f4.png" />
</p>

[![](http://img.shields.io/badge/current_version-v0.93-green.png)](https://github.com/KoffeinFlummi/AGM/releases) [![](http://img.shields.io/badge/download-10.5_MB-blue.png)](https://github.com/KoffeinFlummi/AGM/releases/download/v0.93/AGM_v0.93.rar) [![](http://img.shields.io/badge/license-GPL-red.png)](https://github.com/KoffeinFlummi/AGM/blob/master/LICENSE) <a href="https://github.com/KoffeinFlummi/AGM/issues"><img src="http://img.shields.io/github/issues/KoffeinFlummi/AGM.png" /></a>

A modular authenticism/realism mod for Arma 3, partly based on Taosenai's work with [TMR](https://github.com/Taosenai/tmr).

**BIF Thread:** http://forums.bistudio.com/showthread.php?178253-Authentic-Gameplay-Modification

This mod is entirely **open-source**, and everyone is free to propose changes or maintain their own, customized version as long as they make their changes open to the public in accordance with the GNU General Public License (for more information check the license file attached to this project).

It is **built modularly**; Every PBO (with some exceptions) can be removed, so that groups can maintain their own configurations of AGM, excluding components that they don't like, or that might clash with other addons.
The components themselves, like the medical system, also include various customization options, allowing mission designers to tweak the experience.

More information on the purpose of the different components of AGM and which ones they rely on can be found [here](https://github.com/KoffeinFlummi/AGM/wiki#features).


[![](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=HPAXPTVCNLDZS)

## Features

*   Improved medical system
*   Logistics system including cargo transport and vehicle maintenance
*   Explosives system including different trigger types
*   Captivity system
*   Realistic names for vehicles and weapons
*   Realistic ballistics including wind and humidity
*   Backblast simulation
*   Weapon resting and bipod deployment
*   A fire control system for armored vehicles and helicopters  
and more...

For a full list, look at the [wiki](https://github.com/KoffeinFlummi/AGM/wiki).

## Guides & How-Tos

You installed AGM, but you have no idea how it works, or where to start?

Get started [here](https://github.com/KoffeinFlummi/AGM/wiki/Getting-Started).

## Contributing

If you want to help out by fixing a bug or adding a feature, fork this repo and create a pull request. Also feel free to add yourself to the author array of any .pbo you might be editing.

If you find a bug or want to request a feature, please use the [Issue Tracker](https://github.com/KoffeinFlummi/AGM/issues).

You are a content creator and want to know how to make your weapons or vehicles compatible with AGM? Check out [this](https://github.com/KoffeinFlummi/AGM/wiki/Compatibility) page.

## Testing & Building

If you want to help development by testing and reporting bugs, feel free to download the current version of this repository either using git (if you know what you're doing) or using the download button on the right.

To binarize the addon for testing you can use the `binarizer.exe` in the main folder or, if you have [Python 3](https://www.python.org/) installed, use the python script for some more options. Alternatively you can manually binarize every PBO using Addon Builder or any other binarizer. All of those methods require the Arma 3 Tools to be installed, which can be found on Steam.

In order for the addons to be correctly binarized, you need to exclude the following filytypes from binarization (the binarizer script does this for you):
```
*.pac;*.paa;*.sqf;*.sqs;*.bikb;*.fsm;*.wss;*.ogg;*.wav;*.fxy;*.csv;*.html;*.lip;*.txt;*.wrp;*.bisurf;*.xml;*.hqf
```

---

"THE NEW HOTNESS FOR ARMA3"
~ An0n3
