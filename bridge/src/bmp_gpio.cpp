
#include "driver/gpio.h"


extern "C" void bmp_gpio_write(int pin, int value);
extern "C" int  bmp_gpio_read(int pin);
extern "C" void bmp_gpio_drive_state(int pin, int driven);

#define BM_NB_PINS 7
// mapping of BMP gpio to the GPIO we use
const gpio_num_t _mapping[8]=
{
    GPIO_NUM_2, // 0 TMS_PIN
    GPIO_NUM_3, // 1 TDI_PIN
    GPIO_NUM_4, // 2 TDO_PIN
    GPIO_NUM_5, // 3 TCK_PIN
    GPIO_NUM_6, // 4 TRACESWO_PIN
    GPIO_NUM_7, // 5 SWDIO_PIN
    GPIO_NUM_8, // 6 SWCLK_PIN
    (gpio_num_t)-1
};

#define TRANSLATE(pin) gpio_num_t xpin; xpin=_mapping[pin&7];
/**

*/
// https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/gpio.html
void defaultPinConf(int pin)
{
  gpio_config_t conf={0,GPIO_MODE_OUTPUT,GPIO_PULLUP_DISABLE,GPIO_PULLDOWN_DISABLE,GPIO_INTR_DISABLE};
  conf.pin_bit_mask=1ULL<<_mapping[pin];
  gpio_config(&conf);

}
void bmp_gpio_init()
{
  // Focus on SWD interface for now
  // this is called only once, dont care about optimisation
  defaultPinConf(5);
  defaultPinConf(6);
}
/**
*/
void bmp_gpio_write(int pin, int value)
{
  TRANSLATE(pin);
  gpio_set_level(xpin,value);
}
/**
*/
int  bmp_gpio_read(int pin)
{
  TRANSLATE(pin);
  return gpio_get_level(xpin);
}
/**

*/
void bmp_gpio_drive_state(int pin, int driven)
{
  TRANSLATE(pin);
  if(driven)
      gpio_set_level(xpin,GPIO_MODE_OUTPUT);
  else
      gpio_set_level(xpin,GPIO_MODE_INPUT);
}
// EOF
