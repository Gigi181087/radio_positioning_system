#include "src/Submodules/gp_led_controller/gp_led_controller.h"
#include "src/Submodules/gp_rfm95/gp_rfm95.h"
#include "src/Submodules/gp_debounced_button/gp_debounced_button.h"

gp_led_t* status_led = NULL;
gp_debounced_button_t* button = NULL;

void set_status_led(uint8_t);
void on_push();

void setup() {
  // Initializing Peripheri
  gp_debounced_button_init(&button);
  gp_debounced_button_add_action_to_short_push(button, onpush);
  gp_led_controller_init(&status_led, set_status_led)

  Serial.begin(115200);
  pinMode(13, OUTPUT);
  Serial.println("Setting up!");
  delay(100);
  Serial.print("Init:          ");
  Serial.println(gp_ledController_init(&status_led, set_status_led));

  //Serial.print("Set Blinking:  ");
  Serial.println(gp_ledController_setBlinking(status_led, 10));
  //Serial.println(gp_ledController_setOn(status_led));
  delay(5000);
}

void loop() {
  gp_debounced_button_handle(button, millis());
  gp_led_controller_handle(status_led, millis());
  Serial.print("Status:       ");
  Serial.println(gp_ledController_getStatus(status_led));
}

void set_status_led(uint8_t mode) {

  digitalWrite(13, mode);

  return;
}

void SendSpi(uint8_t* send_param, uint8_t* recv_param, uint8_t len_param) {


  return;
}

void on_push() {
  // Non Blocking connection handling


  return;
}

float read_battery() {

  return measurement = (float)analogRead(A7) * 6.6 / 1024;
}