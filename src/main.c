#include <zephyr.h>
#include <zephyr/kernel.h>
#include <drivers/gpio.h>

#include "light_indicator.h"

#define MY_STACK_SIZE 512
#define MY_PRIORITY 5


static const struct led_name_alias led0 = {
	.spec = GPIO_DT_SPEC_GET_OR(LED0, gpios, {0}),
};

static const struct led_name_alias led1 = {
	.spec = GPIO_DT_SPEC_GET_OR(LED1, gpios, {0}),
};

static const struct led_name_alias led2 = {
	.spec = GPIO_DT_SPEC_GET_OR(LED2, gpios, {0}),
};

void main(void) {


	
} // end main

void blink1(void) {
	led_thread(&led0, 500);
}

 void blink2(void) {
	led_thread(&led1, 250);
}
 void blink3(void) {
	led_thread(&led2, 30);
} 


K_THREAD_DEFINE(name_process_led1, MY_STACK_SIZE,
                blink1, NULL, NULL, NULL,
                MY_PRIORITY, 0, 0);


 K_THREAD_DEFINE(name_process_led2, MY_STACK_SIZE,
blink2, NULL, NULL, NULL,
MY_PRIORITY, 0, 0);

K_THREAD_DEFINE(name_process_led3, MY_STACK_SIZE,
blink3, NULL, NULL, NULL,
MY_PRIORITY, 0, 0); 
