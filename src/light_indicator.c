#include "light_indicator.h"

static const struct gpio_dt_spec  led1 = GPIO_DT_SPEC_GET(LED1, gpios);

	 void led_thread0(int32_t ms) {
	
	int ret;
	if(!z_device_is_ready(led1.port)) {
		printk("Erro port led.port");
		return;
	}
	ret = gpio_pin_configure_dt(&led1, GPIO_OUTPUT_ACTIVE);
	
	if(ret < 0) {
		printk("ret < 0");
		return;
	}

	while(1) {
		ret = gpio_pin_toggle_dt(&led1);
		if(ret < 0) {
			printk("ret < 0, while");
			return;
		}
		k_msleep(ms);
	}
	} 