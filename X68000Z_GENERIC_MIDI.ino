/*

  X68000Z UART-MIDI to generic MIDI adapter

  Copyright (c) 2023 Prime9999
  Released under the MIT license
  https://opensource.org/licenses/mit-license.php

  Wiring:
    X68000Z UART    ESP32 development board
         RED(RX) -- IO17
        BLUE(TX) -- IO16
      GREEN(GND) -- GND

    necobit MIDI UNIT FOR GROVE    ESP32 development board
                     YELLOW(IN) -- IO18
                     WHITE(OUT) -- IO19
                       RED(VIN) -- 3V3
                     BLACK(GND) -- GND

 */
#include <Arduino.h>
#include <HardwareSerial.h>
#include <MIDI.h>

#define UART_SPEED 38400
#define UART_RX 16
#define UART_TX 17

#define MIDI_SPEED 31250
#define MIDI_RX 18
#define MIDI_TX 19

HardwareSerial uartSerial(1);
HardwareSerial midiSerial(2);

struct uartSettings : public midi::DefaultSettings
{
   static const long BaudRate = UART_SPEED;
};
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, uartSerial, uartMIDI, uartSettings);
MIDI_CREATE_INSTANCE(HardwareSerial, midiSerial, genericMIDI);

void setup() {
  // Initialize X68000Z UART-MIDI port
  uartSerial.begin(UART_SPEED, SERIAL_8N1, UART_RX, UART_TX);
  uartMIDI.begin(MIDI_CHANNEL_OMNI);
  uartMIDI.turnThruOff();

  // Initialize generic MIDI port
  midiSerial.begin(MIDI_SPEED, SERIAL_8N1, MIDI_RX, MIDI_TX);
  genericMIDI.begin(MIDI_CHANNEL_OMNI);
  genericMIDI.turnThruOff();
}

void loop() {
  // X68000Z UART-MIDI -> Generic MIDI
  if (uartMIDI.read()) {
    genericMIDI.send(.
      uartMIDI.getType(),
      uartMIDI.getData1(),
      uartMIDI.getData2(),
      uartMIDI.getChannel()
    );
  }

  // Generic MIDI -> X68000Z UART-MIDI
  if (genericMIDI.read()) {
    uartMIDI.send(
      genericMIDI.getType(),
      genericMIDI.getData1(),
      genericMIDI.getData2(),
      genericMIDI.getChannel()
    );
  }
}
