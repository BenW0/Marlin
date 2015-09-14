# Marlin 3D Printer Firmware with Simple DLP Panel
<img align="right" src="Documentation/Logo/Marlin%20Logo%20GitHub.png" />

 Documentation has moved to [marlinfirmware.org](http://www.marlinfirmware.org).

This is Marlin (1.0.2-1, August 2015), modified to work with a simple, 3-button panel for DLP projectors.
 
Additionally, the printer motherboard is set to Printrboard (which is the only motherboard currently supported -- see below), and both thermistors have been disabled.

The three-button interface lets you move the stage up and down and home without
touching the computer. To use it with the Printrboard, wire the following pins to ground via a normally open switch:
* Up: Pin 33 = PE1 = Pin 11 on EXP2
* Down: Pin 28 = PD4 = Pin 5 on EXP2
* Home: Pin 30 = PD6 = Pin 7 on EXP2
Note that Pin 14 of EXP1 is Ground. "Pin 1" on EXP1 is towards the outer edge of the board, on the end closest to the end stops.

To adapt this for other printers, add these constants to your board in pins.h:
 #ifdef SIMPLE_DLP_PANEL
	 #define SIMPLE_DLP_PANEL_UP_PIN     ___
	 #define SIMPLE_DLP_PANEL_DOWN_PIN   ___
	 #define SIMPLE_DLP_PANEL_HOME_PIN   ___
 #endif //SIMPLE_DLP_PANEL
filling ___ in with the appropriate pin numbers.
 
## Release Branch

The Release branch contains the latest tagged version of Marlin (currently 1.0.2-1 – January 2015). It also includes a version 1.0.1 (December 2014). Any version of Marlin before 1.0.1 (when we started tagging versions) can be collectively referred to as Marlin 1.0.0.

## Patches - 1.0.x Branch

Any patches developed for this family of releases will be found on the [1.0.x branch](https://github.com/MarlinFirmware/Marlin/tree/1.0.x) of this repository.

## This Repository is Not For Feature Development

Development of future versions of Marlin is ongoing. However, to keep issues separate, that effort takes place in a companion [Development Repository](https://github.com/MarlinFirmware/MarlinDev/). Please make all suggestions for future features in that project. Issues raised here should be restricted to errors in the tagged releases.

## Current Status: In Development

Marlin development is being accelerated to catch up with a long list of issues. Check the Issues and Pull Requests links on the right to to see what we are currently working on.

[![Coverity Scan Build Status](https://scan.coverity.com/projects/2224/badge.svg)](https://scan.coverity.com/projects/2224)
[![Travis Build Status](https://travis-ci.org/MarlinFirmware/Marlin.svg)](https://travis-ci.org/MarlinFirmware/Marlin)

##### [RepRap.org Wiki Page](http://reprap.org/wiki/Marlin)

## Contact

__Google Hangout:__ <a href="https://plus.google.com/hangouts/_/gxn3wrea5gdhoo223yimsiforia" target="_blank">. Hangout</a> We have a hangout every 2 weeks. Search the issue list for "Hangout" to determine the time and date of the next event.

## Credits

The current Marlin dev team consists of:

 - Scott Lahteine [@thinkyhead] - English
 - Andreas Hardtung [@AnHardt] - Deutsch, English
 - [@Wurstnase] - Deutsch, English
 - [@fmalpartida] - English, Spanish
 - [@CONSULitAS] - Deutsch, English
 - [@maverikou]
 - Chris Palmer [@nophead]
 - [@paclema]
 - [@epatel]
 - Erik van der Zalm [@ErikZalm]
 - David Braam [@daid]
 - Bernhard Kubicek [@bkubicek]
 - Richard Wackerbarth [@Wackerbarth] - English
 - Roxanne Neufeld [@Roxy-3DPrintBoard] - English

More features have been added by:
  - Alberto Cotronei [@MagoKimbra]
  - Lampmaker,
  - Bradley Feldman,
  - and others...

## License

Marlin is published under the [GPL license](/COPYING.md) because we believe in open development. The GPL comes with both rights and obligations. Whether you use Marlin firmware as the driver for your open or closed-source product, you must keep Marlin open, and you must provide your compatible Marlin source code to end users upon request. The most straightforward way to comply with the Marlin license is to make a fork of Marlin on Github, perform your modifications, and direct users to your modified fork.

While we can't prevent the use of this code in products (3D printers, CNC, etc.) that are closed source or crippled by a patent, we would prefer that you choose another firmware or, better yet, make your own.

[![Flattr this git repo](http://api.flattr.com/button/flattr-badge-large.png)](https://flattr.com/submit/auto?user_id=ErikZalm&url=https://github.com/MarlinFirmware/Marlin&title=Marlin&language=&tags=github&category=software)
