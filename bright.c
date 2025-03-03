#include "bright.h"
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int8_t update_bright(uint16_t bright_value, uint16_t bright_value_max) {
  int err = 0;
  if (bright_value > bright_value_max) {
    return 1;
  }
  FILE *file_bright =
      fopen("/sys/class/backlight/intel_backlight/brightness", "w+");
  if (!file_bright) {
    return 1;
  }
  char string_bright_value[12];
  err = sprintf(string_bright_value, "%d", bright_value);
  if (err < 0) {
    return 1;
  }
  err = fprintf(file_bright, "%s", string_bright_value);
  if (err < 0) {
    return 1;
  }
  return 0;
}

int8_t parse_arguments(const char *bright_str, int16_t *bright) {
  char *endptr;
  *bright = strtol(bright_str, &endptr, 10);
  return *bright;
}

int16_t get_max_value() {
  FILE *file_bright =
      fopen("/sys/class/backlight/intel_backlight/max_brightness", "w+");
  if (!file_bright) {
    return -1;
  }
  char file_contents[24];
  fgets(file_contents, 24, file_bright);
  char *endptr;
  return strtol(file_contents, &endptr, 10);
}
