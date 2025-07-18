#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "rbgpio.h"

#define SYSFS_GPIO_DIR "/sys/class/gpio"

int gpio_export(int pin) {
    char buffer[64];
    int fd = open(SYSFS_GPIO_DIR "/export", O_WRONLY);
    if (fd < 0) return -1;

    snprintf(buffer, sizeof(buffer), "%d", pin);
    write(fd, buffer, strlen(buffer));
    close(fd);
    return 0;
}

int gpio_unexport(int pin) {
    char buffer[64];
    int fd = open(SYSFS_GPIO_DIR "/unexport", O_WRONLY);
    if (fd < 0) return -1;

    snprintf(buffer, sizeof(buffer), "%d", pin);
    write(fd, buffer, strlen(buffer));
    close(fd);
    return 0;
}

int gpio_set_direction(int pin, const char *direction) {
    char path[64];
    snprintf(path, sizeof(path), SYSFS_GPIO_DIR "/gpio%d/direction", pin);
    int fd = open(path, O_WRONLY);
    if (fd < 0) return -1;

    write(fd, direction, strlen(direction));
    close(fd);
    return 0;
}

int gpio_write(int pin, int value) {
    char path[64];
    snprintf(path, sizeof(path), SYSFS_GPIO_DIR "/gpio%d/value", pin);
    int fd = open(path, O_WRONLY);
    if (fd < 0) return -1;

    write(fd, value ? "1" : "0", 1);
    close(fd);
    return 0;
}

int gpio_read(int pin) {
    char path[64], value_str[3];
    snprintf(path, sizeof(path), SYSFS_GPIO_DIR "/gpio%d/value", pin);
    int fd = open(path, O_RDONLY);
    if (fd < 0) return -1;

    read(fd, value_str, sizeof(value_str));
    close(fd);
    return atoi(value_str);
}

