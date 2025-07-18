#ifndef RB_GPIO_H
#define RB_GPIO_H

int gpio_export(int pin);
int gpio_unexport(int pin);
int gpio_set_direction(int pin, const char *direction);
int gpio_write(int pin, int value);
int gpio_read(int pin);

#endif

