#include <unistd.h>
#include <stdio.h>
#include "servo.h"

int main() {
    setup_pwm();

    for (int i = 0; i <= 180; i += 45) {
        set_servo_angle(i);
        sleep(1);
    }

    return 0;
}

