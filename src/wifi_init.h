/* 
Configuração sos esp32 como stacao de conecxão
 */
#ifndef WIFI_INIT_H
#define WIFI_INIT_H

#include <sys/printk.h>
#include <esp_wifi.h>
#include <esp_timer.h>
#include <esp_event.h>


#include <net/net_if.h>
#include <net/net_core.h>
#include <net/net_context.h>
#include <net/net_mgmt.h>



 void handler_cb(struct net_mgmt_event_callback *cb,
		    uint32_t mgmt_event, struct net_if *iface);

#endif