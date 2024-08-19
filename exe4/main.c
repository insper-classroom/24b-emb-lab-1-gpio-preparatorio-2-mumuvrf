#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int RED_LED_PIN = 5;
const int PURPLE_LED_PIN = 7;
const int BLUE_LED_PIN = 10;
const int YELLOW_LED_PIN = 13;

const int BTN_PIN = 28;

int main() {
  stdio_init_all();

  gpio_init(RED_LED_PIN);
  gpio_set_dir(RED_LED_PIN, GPIO_OUT);

  gpio_init(PURPLE_LED_PIN);
  gpio_set_dir(PURPLE_LED_PIN, GPIO_OUT);

  gpio_init(BLUE_LED_PIN);
  gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);

  gpio_init(YELLOW_LED_PIN);
  gpio_set_dir(YELLOW_LED_PIN, GPIO_OUT);

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  while (true) {
    // Use delay de 300 ms entre os estados!
    if (!gpio_get(BTN_PIN)) {
      gpio_put(RED_LED_PIN, 1);
      sleep_ms(300);

      gpio_put(RED_LED_PIN, 0);
      gpio_put(PURPLE_LED_PIN, 1);
      sleep_ms(300);

      gpio_put(PURPLE_LED_PIN, 0);
      gpio_put(BLUE_LED_PIN, 1);
      sleep_ms(300);

      gpio_put(BLUE_LED_PIN, 0);
      gpio_put(YELLOW_LED_PIN, 1);
      sleep_ms(300);

      gpio_put(YELLOW_LED_PIN, 0);
      sleep_ms(300);

      while (!gpio_get(BTN_PIN)) {
      };
    }
  }
}
