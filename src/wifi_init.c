#include "wifi_init.h"



static struct net_mgmt_event_callback dhcp_cb;

 void handler_cb(struct net_mgmt_event_callback *cb,
		    uint32_t mgmt_event, struct net_if *iface)
{


	if (mgmt_event != NET_EVENT_IPV4_DHCP_BOUND) {
		return;
	}

	char buf[NET_IPV4_ADDR_LEN];

	printk("Your address: %s",
		log_strdup(net_addr_ntop(AF_INET,
				   &iface->config.dhcpv4.requested_ip,
				   buf, sizeof(buf))));
	printk("Lease time: %u seconds",
			iface->config.dhcpv4.lease_time);
	printk("Subnet: %s",
		log_strdup(net_addr_ntop(AF_INET,
					&iface->config.ip.ipv4->netmask,
					buf, sizeof(buf))));
	printk("Router: %s",
		log_strdup(net_addr_ntop(AF_INET,
						&iface->config.ip.ipv4->gw,
						buf, sizeof(buf))));
}