#include <unistd.h>
#include <stdio.h>
#include "rbgpio.h"

int leds[] = {77, 81, 83};
int switch_pin = 76;

int main() {
    gpio_export(switch_pin);
    gpio_set_direction(switch_pin, "in");

    for (int i = 0; i < 3; i++) {
        gpio_export(leds[i]);
        gpio_set_direction(leds[i], "out");
        gpio_write(leds[i], 0); // Ensure all LEDs start off
    }

    int prev_state = gpio_read(switch_pin);

    while (1) {
        int curr_state = gpio_read(switch_pin);

        if (curr_state != prev_state && curr_state == 1) {
            static int led_state = 0;
            led_state = !led_state;

            for (int i = 0; i < 3; i++) {
                gpio_write(leds[i], led_state);
            }

            printf("🔁 Toggled LEDs to %s\n", led_state ? "ON" : "OFF");
        }

        prev_state = curr_state;
        usleep(200000); // debounce delay
    }

    return 0;
}

