#include <zephyr.h>
#include <zephyr/kernel.h>
#include <drivers/gpio.h>

#include "light_indicator.h"
#include "wifi_init.h"

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

K_FIFO_DEFINE(printk_fifo);

void main(void) {

		struct net_if *iface;

	net_mgmt_init_event_callback(&dhcp_cb, handler_cb,
				     NET_EVENT_IPV4_DHCP_BOUND);

	net_mgmt_add_event_callback(&dhcp_cb);

	iface = net_if_get_default();
	if (!iface) {
		printk("wifi interface not available");
		return;
	}

	net_dhcpv4_start(iface);

	if (!IS_ENABLED(CONFIG_ESP32_WIFI_STA_AUTO)) {
		wifi_config_t wifi_config = {
			.sta = {
				.ssid = CONFIG_ESP32_WIFI_SSID,
				.password = CONFIG_ESP32_WIFI_PASSWORD,
			},
		};

		esp_err_t ret = esp_wifi_set_mode(WIFI_MODE_STA);

		ret |= esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config);
		ret |= esp_wifi_connect();
		if (ret != ESP_OK) {
			printk("connection failed");
		}

	}

	
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
