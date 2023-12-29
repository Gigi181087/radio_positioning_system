#include "src/Submodules/gp_led_controller/gp_led_controller.h"
#include "src/Submodules/gp_rfm95/gp_rfm95.h"
#include "src/Submodules/gp_debounced_button/gp_debounced_button.h"
#include "src/Interfaces/led_interface/led_interface.h"
#include "src/Interfaces/button_interface/button_interface.h"

#define BUTTONPIN       5

uint64_t step = 0;
uint8_t freq = 1;

gp_led_controller_t* status_led = NULL;
gp_debounced_button_t* button = NULL;

void setup() {
  // Initializing Peripheri
  gp_debounced_button_init(&button);
  gp_debounced_button_add_action(button, push_types::LONG, 3000, on_connection_button_long_push);
  gp_led_controller_init(&status_led, set_status_led);

  Serial.begin(115200);
  pinMode(13, OUTPUT);
}

void loop() {
  gp_debounced_button_handle(button, (gp_push_state_t)digitalRead(BUTTONPIN), millis());
  gp_led_controller_handle(status_led, millis());

}

void SendSpi(uint8_t* send_param, uint8_t* recv_param, uint8_t len_param) {


  return;
}

