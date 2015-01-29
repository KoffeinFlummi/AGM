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
<p align="center"><sup><strong>Requiere la versión más reciente de <a href="http://www.armaholic.com/page.php?id=18767">CBA A3</a> | <a href="http://makearmanotwar.com/entry/7jnWM53S2e">Make Arma Not War</a> | <a href="http://forums.bistudio.com/showthread.php?178253-Authentic-Gameplay-Modification">BIF thread</a></strong></sup></p>

**AGM** es un mod modular de autenticidad/realismo para Arma 3, parcialmente basado en el trabajo de Taosenai con [TMR](https://github.com/Taosenai/tmr).

Este mod es completamente de **código abierto**, y todo el mundo es libre de proponer cambios o mantener su propia versión modificada, siempre y cuando hagan sus cambios abiertos al público, de acuerdo con la Licencia Pública General de GNU (Para más información visita el archivo de licencia adjunto al presente proyecto).

Se ha construido **modularmente**; cada PBO (con algunas excepciones) se puede quitar, por lo que los grupos pueden mantener sus propias configuraciones de AGM, excluyendo los componentes que no les gustan, o que podrían entrar en conflicto con otros addons.
Los componentes propios, al igual que el sistema médico, también incluyen diversas opciones de personalización, permitiendo a los diseñadores de la misiones modificar la experiencia.

Más información sobre el propósito de los diferentes componentes de AGM y de los que se basa se puede encontrar [aquí](https://github.com/KoffeinFlummi/AGM/wiki#features).

### Características
* Mejora del sistema médico
* Sistema de logística incluido el transporte de carga y mantenimiento de vehículos
* Sistema de explosivos incluyendo diferentes tipos de detonadores
* Sistema de prisioneros
* Nombres realistas para vehículos y armas
* Balísticas realistas como el viento y la humedad
* Simulación de la deflagración posterior
* Apoyo de arma y despliegue de bípode
* Un sistema de control de fuego para vehículos blindados y helicópteros<br />
  ***y mucho más ...***

Para obtener una lista completa, ver la [wiki](https://github.com/KoffeinFlummi/AGM/wiki).

### Guías y Como se
Instalaste AGM, pero no tienes ni idea de cómo funciona, o por dónde empezar?
Mira [Getting Started](https://github.com/KoffeinFlummi/AGM/wiki/Getting-Started).

### Contribuyendo
Si quieres ayudar con el desarrollo, puedes hacerlo mediante la búsqueda de los posibles errores o contribuyendo con nuevas características. Para contribuir en algo con AGM, simplemente haz "fork" en este repositorio y envia tus "pull requests" para su revisión por otros colaboradores. En el proceso, no dudes en agregarte a la matriz de autor de cualquier .pbo editando el archivo `AUTHORS.txt`.

Para informar de un fallo, proponer una característica, o sugerir un cambio a la ya existente —por favor, usa  nuestro [Issue Tracker](https://github.com/KoffeinFlummi/AGM/issues).

Para obtener información detallada sobre cómo hacer que tus armas o vehículos sean compatibles con AGM —lee [este artículo](https://github.com/KoffeinFlummi/AGM/wiki/For-Addon-Makers).

### Pruebas y construcción
Si quieres ayudar al desarrollo probando y reportando errores, no dudes en descargar la versión actual de este repositorio, ya sea usando git (si sabes lo que estás haciendo) o directamente siguiendo [este enlace](https://github.com/KoffeinFlummi/AGM/archive/master.zip).

Para binarizar el addon para probar puedes utilizar el `binarizer.exe` en la carpeta principal o, si tienes [Python 3](https://www.python.org/) instalado, utiliza el script Python para algunas opciones adicionales. Alternativamente, puedes binarizar manualmente cada PBO mediante Addon Builder o cualquier otro binarizer. Todos estos métodos requieren las Arma 3 Tools instaladas, que se pueden encontrar a través de Steam.

A fin de que los addons sean binarizados correctamente, es necesario excluir los siguientes tipos de archivos de la binarización (el script binarizer lo hace por ti):
```
*.pac;*.paa;*.sqf;*.sqs;*.bikb;*.fsm;*.wss;*.ogg;*.wav;*.fxy;*.csv;*.html;*.lip;*.txt;*.wrp;*.bisurf;*.xml;*.hqf;
```

---
<p align="center"><a href="https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&amp;hosted_button_id=HPAXPTVCNLDZS"><img src="https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif" style="max-width:100%;"></a></p>

---
- Traducido al Castellano por Viper "Cavallers del Cel – Comunitat Catalana de Simulació"
