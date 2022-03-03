/*

 */
#include "version.h"

#include "gdb_packet.h"
#include "gdb_main.h"
#include "target.h"
#include "exception.h"
#include "gdb_packet.h"
#include "morse.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define GPIO_OUTPUT_PIN_SEL  ((1<<SWCLK_PIN) | (1<<SWDIO_PIN) | (1<<TMS_PIN) | (1<<TDI_PIN) | (1<<TDO_PIN) | (1<<TCK_PIN))


void pins_init() {
}

void platform_init()
{
}

void platform_srst_set_val(bool assert)
{

}

bool platform_srst_get_val(void)
{
   return false;
 }

const char *platform_target_voltage(void)
{

}

uint32_t platform_time_ms(void)
{
	int64_t time_milli=esp_timer_get_time()/1000;
	return((uint32_t)time_milli);
}

#define vTaskDelayMs(ms)	vTaskDelay((ms)/portTICK_PERIOD_MS)

void platform_delay(uint32_t ms)
{
	vTaskDelayMs(ms);
}

int platform_hwversion(void)
{
	return 0;
}

/* This is a transplanted main() from main.c */
void main_task(void *parameters)
{
	(void) parameters;

	platform_init();

	while (true) {

		volatile struct exception e;
		TRY_CATCH(e, EXCEPTION_ALL) {
			gdb_main();
		}
		if (e.type) {
			gdb_putpacketz("EFF");
			target_list_free();
			morse("TARGET LOST.", 1);
		}
	}

	/* Should never get here */
}

void user_init(void)
{
	xTaskCreate(&main_task, "main", 4*256, NULL, 2, NULL);
}