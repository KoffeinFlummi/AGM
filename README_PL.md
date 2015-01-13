<p align="center">
  <img src="https://raw.githubusercontent.com/KoffeinFlummi/AGM/master/.devfiles/Assets/Logo/agm_logo_black_transparent.png" height="150px" /><br />
  <a href="https://github.com/KoffeinFlummi/AGM/releases">
    <img src="http://img.shields.io/badge/release-0.95.1-green.svg?style=flat" alt="AGM version">
  </a>
    <a href="https://github.com/KoffeinFlummi/AGM/releases/download/v0.94.1/AGM_v0.94.1.rar">
    <img src="http://img.shields.io/badge/download-22_MB-blue.svg?style=flat" alt="AGM download">
  </a>
    <a href="https://github.com/KoffeinFlummi/AGM/issues">
    <img src="http://img.shields.io/github/issues/KoffeinFlummi/AGM.svg?style=flat" alt="AGM issues">
  </a>
    <a href="https://github.com/KoffeinFlummi/AGM/blob/master/LICENSE">
    <img src="http://img.shields.io/badge/license-GPLv2-red.svg?style=flat" alt="AGM license">
  </a>
</p>
<p align="center"><sup><strong>Wymaga najnowszej wersji <a href="http://www.armaholic.com/page.php?id=18767">CBA A3</a> | <a href="http://makearmanotwar.com/entry/7jnWM53S2e">Make Arma Not War</a> | <a href="http://forums.bistudio.com/showthread.php?178253-Authentic-Gameplay-Modification">Temat na forum BIS</a></strong></sup></p>

**AGM** jest modularnym modem realizmu / autentyczności dla ArmA 3, częścowo opartym na pracy Taosenai przy [TMR](https://github.com/Taosenai/tmr).

Jest to mod **open-source**, każdy może zaproponować do niego zmiany bądź prowadzić swoją własną, zmodyfikowaną wersję dopóki zmiany, jakie ta osoba wprowadzi, będą publiczne zgodnie z licencją GNU General Public License (po więcej informacji sprawdź plik licencji dołączony do tego projektu).

Ten mod jest **zbudowany modułowo** — praktycznie każde PBO może zostać usunięte, dzięki czemu grupy mogą prowadzić swoją własną, dostosowaną pod siebie wersje AGM, która nie posiada wybranych, nie lubianych elementów, bądź konfliktujących z innymi addonami. Elementy same w sobie, jak np. system medyczny, zawierają w sobie wiele opcji konfiguracji, pozwalając mission maker-om dostosować ogólne wrażenia z gry.

Więcej informacji na temat działania i celu istnienia poszczególnych elementów AGM, oraz tego, których elementów AGM wymagają, można znaleźć [tutaj](https://github.com/KoffeinFlummi/AGM/wiki#features).

### Funkcje
*   Ulepszony system medyczny
*   System logistyczny pozwalający na transport ładunku oraz ulepszający  naprawy pojazdów za pomocą kół zapasowych, gąsienic etc.
*   System ładunków wybuchowych dodający różnego typu zapalniki
*   System jeńców pozwalający na skuwanie AI bądź graczy za pomocą kajdanek
*   Realistyczne nazwy dla pojazdów oraz broni
*   Realistyczna balistyka włączając w to wpływ wiatru oraz wilgotności powietrza
*   Symulacja backblast-u
*   Podpieranie broni oraz rozkładanie dwójnogów
*   System kontroli ognia (FCS) dla pojazdów pancernych oraz śmigłowców
    ***i wiele wiele więcej...***

W celu zdobycia pełnej listy aktualnych funkcji AGM, sprawdź [oficjalną wiki](https://github.com/KoffeinFlummi/AGM/wiki).

#### Poradniki oraz tutoriale
Jeżeli zainstalowałeś już AGM, lecz masz problem ze zrozumieniem jak on działa, lub gdzie zacząć — zobacz [podręcznik AGM](https://github.com/KoffeinFlummi/AGM/wiki/Getting-Started).

#### Współpraca
Jeżeli chcesz pomóc w pracach nad rozwojem AGM, możesz zrobić to szukając potencjalnych bugów, bądź zgłaszając propozycje nowych funkcjonalności. Aby przyczynić się do rozwoju AGM, po prostu skopiuj całe repozytorium i zgłaszaj propozycje zmian do przeglądu przez innych współpracowników. W trakcie prac, nie krępuj dodać siebie do zbioru autorów danego .pbo, który edytujesz oraz do pliku AUTHORS.txt.

Aby zgłosić bug, zaproponować nową funkcjonalność, bądź zasugerować zmianę do istniejącej funkcjonalności — proszę, użyj naszego [Bugtrackera](https://github.com/KoffeinFlummi/AGM/issues).

Po więcej informacji na temat jak sprawić, aby Twoje addony bądź pojazdy były kompatybilne z AGM — przeczytaj [ten artykuł](https://github.com/KoffeinFlummi/AGM/wiki/For-Addon-Makers).

#### Testowanie oraz kompilowanie
Jeżeli chcesz pomóc nam w testach najnowszych zmian rozwojowych, nie krępuj się pobierać najnowszy master branch, używając git — jeżeli jesteś zaznajomiony z jego obsługą — lub bezpośrednio, poprzez [ten link](https://github.com/KoffeinFlummi/AGM/archive/master.zip).

Aby zbinaryzować addon do testów, możesz uzyć programu 'binarizer.exe' w głównym folderze lub, jeżeli posiadasz zainstalowanego [Python 3](https://www.python.org/), użyć skryptu python-a w celu uzyskania większej ilości opcji. Alternatywnie, możesz zbinaryzować każde PBO własnoręcznie, korzystając z Addon Builder-a lub każdego innego binaryzera addonów. Wszystkie te metody wymagają zainstalowanego Arma 3 Tools, którego można znaleźć na Steam-ie.

Aby poprawnie zbinaryzować addon, musisz wykluczyć te typy plików z binaryzacji (dołączony binarizer zrobi to za ciebie):
```
*.pac;*.paa;*.sqf;*.sqs;*.bikb;*.fsm;*.wss;*.ogg;*.wav;*.fxy;*.csv;*.html;*.lip;*.txt;*.wrp;*.bisurf;*.xml;*.hqf;
```

---
<p align="center"><a href="https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&amp;hosted_button_id=HPAXPTVCNLDZS"><img src="https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif" style="max-width:100%;"></a></p>
