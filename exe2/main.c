#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 26;
const int SCND_BTN_PIN = 7;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(SCND_BTN_PIN);
  gpio_set_dir(SCND_BTN_PIN, GPIO_IN);
  gpio_pull_up(SCND_BTN_PIN);

  while (true) {
    if (!gpio_get(BTN_PIN)) {
      printf("Botao 1\n");
      sleep_ms(250);
      while (!gpio_get(BTN_PIN)) {
      };
    } else if(!gpio_get(SCND_BTN_PIN)){
      printf("Botao 2\n");
      sleep_ms(250);
      while (!gpio_get(SCND_BTN_PIN)) {
      };
    }
  }
}
