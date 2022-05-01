
#ifndef LIGHT_INDICATE_H
#define LIGHT_INDICATE_H

#include <drivers/gpio.h>

#define LED0 DT_ALIAS(led0)
#define LED1 DT_ALIAS(led1)
#define LED2 DT_ALIAS(led2)

#define DELAY_MS_LED0 1000
#define DELAY_MS_LED1 100
#define DELAY_MS_LED2 20

	struct led_name_alias {
		struct gpio_dt_spec spec;
		const char *pgio_pin_name;
	};

	void led_thread(const struct led_name_alias *led, int32_t ms);



#endif