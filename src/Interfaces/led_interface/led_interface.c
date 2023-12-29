#include <stdint.h>
#include "led_interface.h"

void set_status_led(uint8_t mode) {

  digitalWrite(13, mode);

  return;
}