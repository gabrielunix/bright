#pragma once
#include <stdint.h>
#include <time.h>

int8_t update_bright(uint16_t bright_value, uint16_t bright_value_max);
int8_t parse_arguments(const char *bright_str, int16_t *second);
int16_t get_max_value();
