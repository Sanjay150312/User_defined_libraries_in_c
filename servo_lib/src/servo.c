#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "servo.h"

#define PWM_CHIP "/sys/class/pwm/pwmchip0"
#define PWM_CHANNEL "0"

void setup_pwm() {
    int fd;

    fd = open(PWM_CHIP "/export", O_WRONLY);
    if (fd >= 0) {
        write(fd, PWM_CHANNEL, strlen(PWM_CHANNEL));
        close(fd);
        usleep(100000);
    }

    fd = open(PWM_CHIP "/pwm0/period", O_WRONLY);
    if (fd >= 0) {
        write(fd, "20000000", 8); // 20ms period
        close(fd);
    }

    fd = open(PWM_CHIP "/pwm0/enable", O_WRONLY);
    if (fd >= 0) {
        write(fd, "1", 1);
        close(fd);
    }
}

void set_servo_angle(int angle) {
    int duty_ns = 1000000 + (angle * 1000000 / 180);
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%d", duty_ns);

    int fd = open(PWM_CHIP "/pwm0/duty_cycle", O_WRONLY);
    if (fd >= 0) {
        write(fd, buffer, strlen(buffer));
        close(fd);
    }

    printf("Servo set to %d°\n", angle);
}

