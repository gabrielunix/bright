#include "bright.h"
#include <stdint.h>
#include <stdio.h>
int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "%s <params: <brightness>>\n", argv[0]);
    return 1;
  }
  int16_t max_bright = get_max_value();
  int16_t bright = 0;
  if (0 == (parse_arguments(argv[1], &bright))) {
    puts("error: parse arguments");
    return 1;
  }
  if (1 == (update_bright(bright, max_bright))) {
    puts("error: update_bright");
    return 1;
  }
  return 0;
}
