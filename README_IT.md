<p align="center">
  <img src="https://raw.githubusercontent.com/KoffeinFlummi/AGM/master/.devfiles/Assets/Logo/agm_logo_black_transparent.png" />
</p>

---

[![](http://img.shields.io/badge/current_version-v0.93-green.png)](https://github.com/KoffeinFlummi/AGM/releases) [![](http://img.shields.io/badge/download-10.5_MB-blue.png)](https://github.com/KoffeinFlummi/AGM/releases/download/v0.93/AGM_v0.93.rar) [![](http://img.shields.io/badge/license-GPL-red.png)](https://github.com/KoffeinFlummi/AGM/blob/master/LICENSE) <a href="https://github.com/KoffeinFlummi/AGM/issues"><img src="http://img.shields.io/github/issues/KoffeinFlummi/AGM.png" /></a>

Una mod il cui scopo è aumentare il realismo e l'autenticità di Arma 3, parzialmente basata sul lavoro di Taosenai con  [TMR](https://github.com/Taosenai/tmr).

**BIF Thread:** http://forums.bistudio.com/showthread.php?178253-Authentic-Gameplay-Modification

Questa mod è completamente **open-source**, e chiunque è libero di proporre cambiamenti piuttosto che mantenerli per sé, sempre nel rispetto della GNU General Public License (per maggiori informazioni controlla il file sulla licenza nel progetto)

La mod è **costruita modularmente**; Ogni PBO (con qualche eccezione) può essere rimosso, in modo tale da permettere ad ogni gruppo di mantenere le configurazioni ad esso affini dell'AGM, escludendo quindi le componenti che non sono apprezzate, piuttosto che sostituirle con altre mod. 
I componenti presi singolarmente, come l'implementazione del sistema di cure, include anche delle opzioni di personalizzazione interne, proprio per facilitare i creatori delle missioni a migliorare la loro esperienza.

Maggiori informazioni sui singoli scopi dei diversi componenti dell'AGM, e a quali questi ultimi si riferiscono possono essere trovate [qui](https://github.com/KoffeinFlummi/AGM/wiki#features).

[![](https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif)](https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&hosted_button_id=HPAXPTVCNLDZS)

## Funzionalità

*   Sistema sanitario migliorato
*   Sistema di logistica, inclusi i trasporti di carichi di vario tipo e il mantenimento dei veicoli
*   Sistema di esplosivi che include differenti tipologia di trigger
*   Sistema di schiavizzazione (traduzione letterale riferita al comportamento di IA tenute in ostaggio, da "captivity")
*   Nomi realistici per armi e veicoli
*   Ballistica migliorata, inclusi venti ed umidità.
*   Simulazione di danni collaterali causati dal fuoco di lanciatori (nel cono posteriore ad esso)
*   Possibilità di appoggiare l'arma ad ogni oggetto e di usare il bipiede
*   Un sistema di controllo avanzato per il tiro con carri armati ed elicotteri
e molto altro ancora...

Per una lista completa, visita il [wiki](https://github.com/KoffeinFlummi/AGM/wiki).

## Guide & Come iniziare

Hai installato AGM, ma non hai idea di come funzione, o da dove partire?

Parti da [qui](https://github.com/KoffeinFlummi/AGM/wiki/Getting-Started).

## Contribuire

Se vuoi aiutarce risolvendo un bug o aggiungendo una funzionalità, forka questa repo e crea una richiesta di pull. Sentiti libero di aggiungerti all'array degli autori di ogni .pbo che hai editato.

Se trovi un bug o vuoi richiedere una funzionalità, ti preghiamo di usare l'[Issue Tracker](https://github.com/KoffeinFlummi/AGM/issues).

Sei un creatore di contenuti e vorresti sapere come rendere le tue armi o i tuoi veicoli compatibili con AGM? Guarda qui [qui](https://github.com/KoffeinFlummi/AGM/wiki/For-Addon-Makers) page.

## Testando e Costruendo

Se vuoi aiutare il progetto testando e riportando bug, sentiti libero di scaricare la versione attuale di questa repo anche usando git (se sai cosa stai facendo) o semplicemente usando il pulsante di download che puoi trovare sulla destra.

Per binarizzare l'addon per il testing, puoi usare il `binarizer.exe` nella cartella principale, oppure se hai già installato [Python 3](https://www.python.org/), utilizza lo script in python per maggiori opzioni. Alternativamente puoi binarizzare manualmente ogni PBO usando l'Addon Builder od un qualsiasi altro binarizzatore. Tutti questi metodi richiedono l'installazione di Arma 3 Tools, che può essere trovato su steam nel pannello strumenti. 

Per consentire una corretta binarizzazione delle addon, hai bisogno di escludere i seguenti filytypes dalla binarizzazione (lo script binarizzatore svolge questo compitono autonomamente):
```
*.pac;*.paa;*.sqf;*.sqs;*.bikb;*.fsm;*.wss;*.ogg;*.wav;*.fxy;*.csv;*.html;*.lip;*.txt;*.wrp;*.bisurf;*.xml;*.hqf
```

---

"LA NUOVA SPECIALITA' DI ARMA 3"
~ An0n3
~ Tradotto in italiano da Ricciardino
