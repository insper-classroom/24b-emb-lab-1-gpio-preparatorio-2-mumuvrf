#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int RED_LED_PIN = 4;
const int GREEN_LED_PIN = 6;

const int RED_BTN_PIN = 28;
const int GREEN_BTN_PIN = 26;

int main() {
  stdio_init_all();
  int green_led_state = 0;
  int red_led_state = 0;

  gpio_init(RED_LED_PIN);
  gpio_set_dir(RED_LED_PIN, GPIO_OUT);

  gpio_init(GREEN_LED_PIN);
  gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);

  gpio_init(RED_BTN_PIN);
  gpio_set_dir(RED_BTN_PIN, GPIO_IN);
  gpio_pull_up(RED_BTN_PIN);

  gpio_init(GREEN_BTN_PIN);
  gpio_set_dir(GREEN_BTN_PIN, GPIO_IN);
  gpio_pull_up(GREEN_BTN_PIN);

  while (true) {
    if(!gpio_get(RED_BTN_PIN)) {
      red_led_state = !red_led_state;
      gpio_put(RED_LED_PIN, red_led_state);
      sleep_ms(250);
      while (!gpio_get(RED_BTN_PIN)) {
      };
    }

    if(!gpio_get(GREEN_BTN_PIN)) {
      green_led_state = !green_led_state;
      gpio_put(GREEN_LED_PIN, green_led_state);
      sleep_ms(250);
      while (!gpio_get(RED_BTN_PIN)) {
      };
    }
  }
}
