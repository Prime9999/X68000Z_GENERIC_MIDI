# X68000Z UART-MIDI to generic MIDI adapter
Simple MIDI adapter implementation which converts X68000Z UART-MIDI to generic MIDI interface (DIN 5pin).

## Requirments
* X68000Z
* X68000Z UART cable
* ESP32 development board (ex. ESP32-DevKitC)
* [necobit MIDI UNIT FOR GROVE](https://necobit.com/denshi/grove-midi-unit/)
* [Grove - 4 pin Female Jumper to Grove 4 pin Conversion Cable](https://www.seeedstudio.com/Grove-4-pin-Female-Jumper-to-Grove-4-pin-Conversion-Cable-5-PCs-per-PAck.html)
* MIDI interface cable
* MIDI sound Module (ex. Roland MT-32)

## Wiring
|X6800Z UART cable|ESP32 development board|
|:-:|:-:|
|RED(RX)|IO17|
|BLUE(TX)|IO16|
|GREEN(GND)|GND|

|necobit MIDI UNIT FOR GROVE|ESP32 development board|
|:-:|:-:|
|YELLOW(IN)|IO18|
|WHITE(OUT)|IO19|
|RED(VIN)|3V3|
|BLACK(GND)|GND|

Note: necobit MIDI UNIT FOR GROVE JP1 must be shorted.

## How to use
1. Open Arduino IDE
3. Compile and write this sketch to ESP32 development board