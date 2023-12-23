/*
   Spin motor using potentiometer dial

   This file is part of Teensy-OneShot125.

   Teensy-OneShot125 is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the Free
   Software Foundation, either version 3 of the License, or (at your option)
   any later version.

   Teensy-OneShot125 is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
   more details.

   You should have received a copy of the GNU General Public License along with
   Teensy-OneShot125. If not, see <https://www.gnu.org/licenses/>.
 */

#include <oneshot125.hpp>

static const uint8_t INPUT_PIN = A9;
static const uint8_t MOTOR_PIN = 0;

static auto esc = OneShot125(MOTOR_PIN);

static uint16_t getInput(void)
{
    return analogRead(INPUT_PIN);
}

void setup() 
{
    // Spin-wait until potentiometer reads zero
    while (getInput() > 0) {
    }

    esc.arm(); 
}

void loop() 
{
    // Serial.println(map(getInput(), 0, 1024, 125, 250));
    esc.set(map(getInput(), 0, 1024, 125, 250));
}