<p align="center">
  <img src="https://raw.githubusercontent.com/KoffeinFlummi/AGM/master/.devfiles/Assets/Logo/agm_logo_black_transparent.png" />
</p>

---

[![](http://img.shields.io/badge/release-0.94.1-green.svg?style=flat)](https://github.com/KoffeinFlummi/AGM/releases) [![](http://img.shields.io/badge/download-20_MB-blue.svg?style=flat)](https://github.com/KoffeinFlummi/AGM/releases/download/v0.94.1/AGM_v0.94.1.rar) [![](http://img.shields.io/badge/license-GPLv2-red.svg?style=flat)](https://github.com/KoffeinFlummi/AGM/blob/master/LICENSE) [![](http://img.shields.io/github/issues/KoffeinFlummi/AGM.svg?style=flat)](https://github.com/KoffeinFlummi/AGM/issues)

Un mod modular de autenticidad/realismo para ArmA 3, parcialmente basado en el trabajo de Taosenai con [TMR](https://github.com/Taosenai/tmr).

**Make Arma Not War:** http://makearmanotwar.com/entry/7jnWM53S2e

**Hilo BIF:** http://forums.bistudio.com/showthread.php?178253-Authentic-Gameplay-Modification

**Consigue la última versión:** https://github.com/KoffeinFlummi/AGM/releases

***Authentic Gameplay Modification requiere [CBA A3](http://www.armaholic.com/page.php?id=18767).***

Este mod es completamente de **código abierto**, y todo el mundo es libre de proponer cambios o mantener su propia versión modificada, siempre y cuando hagan sus cambios abiertos al público, de acuerdo con la Licencia Pública General de GNU (Para más información visita el archivo de licencia adjunto al presente proyecto).

Se ha construido **modularmente**; cada PBO (con algunas excepciones) se puede quitar, por lo que los grupos pueden mantener sus propias configuraciones de AGM, excluyendo los componentes que no les gustan, o que podrían entrar en conflicto con otros addons.
Los componentes propios, al igual que el sistema médico, también incluyen diversas opciones de personalización, permitiendo a los diseñadores de la misiones modificar la experiencia.

Más información sobre el propósito de los diferentes componentes de AGM y de los que se basa se puede encontrar [aquí](https://github.com/KoffeinFlummi/AGM/wiki#features).

<p align="center"><a href="https://www.paypal.com/cgi-bin/webscr?cmd=_s-xclick&amp;hosted_button_id=HPAXPTVCNLDZS"><img src="https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif" style="max-width:100%;"></a></p>

## Características

* Mejora del sistema médico
* Sistema de logística incluido el transporte de carga y mantenimiento de vehículos
* Sistema de explosivos incluyendo diferentes tipos de detonadores
* Sistema de prisioneros
* Nombres realistas para vehículos y armas
* Balísticas realistas como el viento y la humedad
* Simulación de la deflagración posterior
* Apoyo de arma y despliegue de bípode
* Un sistema de control de fuego para vehículos blindados y helicópteros
y mucho más ...

Para obtener una lista completa, ver la [wiki](https://github.com/KoffeinFlummi/AGM/wiki).

## Guías y Como se

Instalaste AGM, pero no tienes ni idea de cómo funciona, o por dónde empezar?

Empezar [aquí](https://github.com/KoffeinFlummi/AGM/wiki/Getting-Started).

## Contribuyendo

Si quieres ayudarnos mediante la corrección de un fallo, o la adición de una función, vincula esta repo y crea un pull request. También siéntete libre de agregarte como autor de la matriz de cualquier .pbo quieras editar.

Si encuentras un error o deseas solicitar una característica, por favor usa el [Issue Tracker] (https://github.com/KoffeinFlummi/AGM/issues).

Eres un creador de contenidos y quieres saber cómo hacer tus armas o vehículos compatibles con AGM? Echa un vistazo a [esta](https://github.com/KoffeinFlummi/AGM/wiki/For-Addon-Makers) pagina.

## Pruebas y construcción

Si quieres ayudar al desarrollo probando y reportando errores, no dudes en descargar la versión actual de este repositorio, ya sea usando git (si sabes lo que estás haciendo) o usando el botón de descarga a la derecha.

Para binarizar el addon para probar puedes utilizar el `binarizer.exe` en la carpeta principal o, si tienes [Python 3](https://www.python.org/) instalado, utiliza el script Python para algunas opciones adicionales . Alternativamente, puedes binarizar manualmente cada PBO mediante Addon Builder o cualquier otro binarizer. Todos estos métodos requieren las Arma 3 Tools instaladas, que se pueden encontrar a través de Steam.

A fin de que los addons sean binarizados correctamente, es necesario excluir los siguientes tipos de archivos de la binarización (el script binarizer lo hace por ti):
```
*.pac;*.paa;*.sqf;*.sqs;*.bikb;*.fsm;*.wss;*.ogg;*.wav;*.fxy;*.csv;*.html;*.lip;*.txt;*.wrp;*.bisurf;*.xml;*.hqf;
```

---

"La nueva especialidad de ArmA3"
~ An0n3

- Traducido al Castellano por Viper "Cavallers del Cel - Comunitat Catalana de Simulació"
