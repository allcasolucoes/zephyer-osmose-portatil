#include "light_indicator.h"

static const struct gpio_dt_spec  led1 = GPIO_DT_SPEC_GET(LED1, gpios);

	 void led_thread(const struct led_name_alias *led, int32_t ms) {
	const struct gpio_dt_spec *spec = &led->spec;
	int ret;
	if(!z_device_is_ready(spec->port)) {
		printk("Erro port led.port");
		return;
	}
	ret = gpio_pin_configure_dt(spec, GPIO_OUTPUT_ACTIVE);
	
	if(ret < 0) {
		printk("ret < 0");
		return;
	}

	while(1) {
		ret = gpio_pin_toggle_dt(spec);

		if(ret < 0) {
			printk("ret < 0, while");
			return;
		}
		k_msleep(ms);

	}
	} 