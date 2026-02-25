#include "sapi.h"

int main(void) {
    // Initialize the board
    boardConfig();

    // RGB LEDs mapping
    gpioMap_t colors[] = {LEDR, LEDG, LEDB};
    int color_index = 0;

    while (1) {
        // Turn off all RGB components
        gpioWrite(LEDR, OFF);
        gpioWrite(LEDG, OFF);
        gpioWrite(LEDB, OFF);

        // Turn on the current color
        gpioWrite(colors[color_index], ON);

        // Wait 500ms
        delay(500);

        // Move to the next color
        color_index = (color_index + 1) % 3;
    }

    return 0;
}
