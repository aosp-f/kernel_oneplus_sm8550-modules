// SPDX-License-Identifier: GPL-2.0-only
/* Copyright (c) 2021, The Linux Foundation. All rights reserved.
 * Copyright (c) 2022 Qualcomm Innovation Center, Inc. All rights reserved.
 *
 * RMNET WLAN connection management framework
 *
 */

#include <linux/types.h>
#include <linux/skbuff.h>
#include <linux/netdevice.h>
#include <linux/spinlock.h>
#include <linux/rcupdate.h>
#include <linux/hashtable.h>
#include <linux/if_ether.h>
#include <linux/hrtimer.h>
#include <net/ip.h>
#include <net/ipv6.h>
#include <net/dst.h>
#include <net/netfilter/nf_conntrack.h>
#include "rmnet_module.h"
#include "rmnet_wlan.h"
#include "rmnet_wlan_connection.h"
#include "rmnet_wlan_stats.h"
#define DATARMNET5da8c68c19 (2000000000)
#define DATARMNET8fc07fbb24 ((0xeb7+1158-0x132d))
#define DATARMNETeaf0945284 \
	(const_ilog2(DATARMNET8fc07fbb24))
extern void(*rmnet_wlan_ll_tuple_hook)(struct sk_buff*DATARMNET543491eb0f);
struct DATARMNET4f49486833{struct hlist_node DATARMNETe8608dd267;struct rcu_head
 DATARMNET28bfe9e6ad;struct hrtimer DATARMNET9f31ce5d2d;struct 
DATARMNET0ca9d8ead7 DATARMNET54338da2ff;struct DATARMNET8d3c2559ca 
DATARMNET7ed5754a5c;};static DEFINE_SPINLOCK(DATARMNET820642743b);static 
DEFINE_HASHTABLE(DATARMNET5413d6f8ec,DATARMNETeaf0945284);static bool 
DATARMNET5f3c9ed4da(struct DATARMNET0ca9d8ead7*DATARMNET75decd6f60,struct 
DATARMNET0ca9d8ead7*DATARMNET6745cad668){if(DATARMNET75decd6f60->
DATARMNET0d956cc77a!=DATARMNET6745cad668->DATARMNET0d956cc77a)return false;if(
DATARMNET75decd6f60->DATARMNET0d956cc77a==(0xd11+230-0xdf3))return 
DATARMNET75decd6f60->DATARMNETdfe430c2d6==DATARMNET6745cad668->
DATARMNETdfe430c2d6&&DATARMNET75decd6f60->DATARMNET2cb607d686==
DATARMNET6745cad668->DATARMNET2cb607d686;return!ipv6_addr_cmp(&
DATARMNET75decd6f60->DATARMNET815cbb4bf5,&DATARMNET6745cad668->
DATARMNET815cbb4bf5)&&!ipv6_addr_cmp(&DATARMNET75decd6f60->DATARMNETc3f31215b7,&
DATARMNET6745cad668->DATARMNETc3f31215b7);}static enum hrtimer_restart 
DATARMNET299a8a08b5(struct hrtimer*DATARMNET6e4292679f){struct 
DATARMNET4f49486833*DATARMNET63b1a086d5;unsigned long DATARMNETfb0677cc3c;
spin_lock_irqsave(&DATARMNET820642743b,DATARMNETfb0677cc3c);DATARMNET63b1a086d5=
container_of(DATARMNET6e4292679f,struct DATARMNET4f49486833,DATARMNET9f31ce5d2d)
;hash_del_rcu(&DATARMNET63b1a086d5->DATARMNETe8608dd267);kfree_rcu(
DATARMNET63b1a086d5,DATARMNET28bfe9e6ad);spin_unlock_irqrestore(&
DATARMNET820642743b,DATARMNETfb0677cc3c);return HRTIMER_NORESTART;}static 
rx_handler_result_t DATARMNETc9ed97754a(struct sk_buff*DATARMNET543491eb0f,
uint8_t DATARMNET1a901c3d09){if(DATARMNET543491eb0f->dev&&(DATARMNET543491eb0f->
protocol==htons(ETH_P_IP))&&DATARMNET1a901c3d09==DATARMNET9bfbc31cd6){struct 
iphdr*DATARMNET86f1f2cdc9,DATARMNETbf6548198e;struct net_device*
DATARMNET813ca18d06=NULL;struct flowi4 DATARMNET099aa93adc={};struct rtable*
DATARMNET066b8bd537;struct neighbour*DATARMNET3f85732c70;int DATARMNET268a8314cf
=(0xd2d+202-0xdf7);DATARMNET86f1f2cdc9=skb_header_pointer(DATARMNET543491eb0f,
(0xd2d+202-0xdf7),sizeof(*DATARMNET86f1f2cdc9),&DATARMNETbf6548198e);if(!
DATARMNET86f1f2cdc9){DATARMNET17f6bc1be5(DATARMNET15454f969d);goto 
DATARMNETc1174a0f45;}DATARMNET813ca18d06=dev_get_by_name_rcu(&init_net,
DATARMNET934406764d());if(!DATARMNET813ca18d06){DATARMNET17f6bc1be5(
DATARMNETfa4b3dd44a);goto DATARMNETc1174a0f45;}DATARMNET543491eb0f->dev=
DATARMNET813ca18d06;memcpy(&DATARMNET099aa93adc.saddr,&DATARMNET86f1f2cdc9->
saddr,sizeof(__be32));memcpy(&DATARMNET099aa93adc.daddr,&DATARMNET86f1f2cdc9->
daddr,sizeof(__be32));DATARMNET099aa93adc.flowi4_oif=DATARMNET813ca18d06->
ifindex;DATARMNET099aa93adc.flowi4_flags=FLOWI_FLAG_KNOWN_NH;DATARMNET066b8bd537
=ip_route_output_key(&init_net,&DATARMNET099aa93adc);if(IS_ERR(
DATARMNET066b8bd537)){DATARMNET17f6bc1be5(DATARMNET72ab5e86d8);goto 
DATARMNETc1174a0f45;}DATARMNET3f85732c70=dst_neigh_lookup(&DATARMNET066b8bd537->
dst,&DATARMNET099aa93adc.daddr);ip_rt_put(DATARMNET066b8bd537);if(!
DATARMNET3f85732c70){DATARMNET17f6bc1be5(DATARMNET0e6bd55b8b);goto 
DATARMNETc1174a0f45;}if(DATARMNET3f85732c70->dev!=DATARMNET543491eb0f->dev||!
DATARMNET3f85732c70->dev->header_ops){DATARMNET17f6bc1be5(DATARMNET64aecaa865);
neigh_release(DATARMNET3f85732c70);goto DATARMNETc1174a0f45;}DATARMNET268a8314cf
=neigh_resolve_output(DATARMNET3f85732c70,DATARMNET543491eb0f);neigh_release(
DATARMNET3f85732c70);if(likely(DATARMNET268a8314cf==NET_XMIT_SUCCESS||
DATARMNET268a8314cf==NET_XMIT_CN)){DATARMNET17f6bc1be5(DATARMNETc1b437465b);}
else{DATARMNET17f6bc1be5(DATARMNET43a65c0be7);}return RX_HANDLER_CONSUMED;}else 
if(DATARMNET543491eb0f->dev&&(DATARMNET543491eb0f->protocol==htons(ETH_P_IPV6))
&&DATARMNET1a901c3d09==DATARMNET9bfbc31cd6){struct ipv6hdr*DATARMNETbf55123e5b,
DATARMNETcf1d9e2c1e;struct net_device*DATARMNET813ca18d06=NULL;struct flowi6 
DATARMNET8fbe36a2fa={};struct neighbour*DATARMNET3f85732c70;struct dst_entry*dst
;int DATARMNET268a8314cf=(0xd2d+202-0xdf7);DATARMNETbf55123e5b=
skb_header_pointer(DATARMNET543491eb0f,(0xd2d+202-0xdf7),sizeof(*
DATARMNETbf55123e5b),&DATARMNETcf1d9e2c1e);if(!DATARMNETbf55123e5b){
DATARMNET17f6bc1be5(DATARMNET72f4fdd48a);goto DATARMNETc1174a0f45;}
DATARMNET813ca18d06=dev_get_by_name_rcu(&init_net,DATARMNET934406764d());if(!
DATARMNET813ca18d06){DATARMNET17f6bc1be5(DATARMNET9cff15f94d);goto 
DATARMNETc1174a0f45;}DATARMNET543491eb0f->dev=DATARMNET813ca18d06;memcpy(&
DATARMNET8fbe36a2fa.saddr,&DATARMNETbf55123e5b->saddr,sizeof(struct in6_addr));
memcpy(&DATARMNET8fbe36a2fa.daddr,&DATARMNETbf55123e5b->daddr,sizeof(struct 
in6_addr));DATARMNET8fbe36a2fa.flowi6_oif=DATARMNET813ca18d06->ifindex;
DATARMNET8fbe36a2fa.flowi6_flags=FLOWI_FLAG_KNOWN_NH;dst=ipv6_stub->
ipv6_dst_lookup_flow(&init_net,NULL,&DATARMNET8fbe36a2fa,NULL);if(IS_ERR(dst)){
DATARMNET17f6bc1be5(DATARMNETbf6e6853f9);goto DATARMNETc1174a0f45;}
DATARMNET3f85732c70=dst_neigh_lookup(dst,&DATARMNET8fbe36a2fa.daddr);dst_release
(dst);if(!DATARMNET3f85732c70){DATARMNET17f6bc1be5(DATARMNETa0da722329);goto 
DATARMNETc1174a0f45;}if(DATARMNET3f85732c70->dev!=DATARMNET543491eb0f->dev||!
DATARMNET3f85732c70->dev->header_ops){DATARMNET17f6bc1be5(DATARMNET729e252fb9);
neigh_release(DATARMNET3f85732c70);goto DATARMNETc1174a0f45;}DATARMNET268a8314cf
=neigh_resolve_output(DATARMNET3f85732c70,DATARMNET543491eb0f);neigh_release(
DATARMNET3f85732c70);if(likely(DATARMNET268a8314cf==NET_XMIT_SUCCESS||
DATARMNET268a8314cf==NET_XMIT_CN)){DATARMNET17f6bc1be5(DATARMNET04311361a2);}
else{DATARMNET17f6bc1be5(DATARMNET13bbe5f5c5);}return RX_HANDLER_CONSUMED;}else 
if(DATARMNET543491eb0f->dev&&(DATARMNET543491eb0f->protocol==htons(ETH_P_IP))&&
DATARMNET1a901c3d09==DATARMNET45ee632553){struct iphdr*DATARMNET86f1f2cdc9,
DATARMNETbf6548198e;struct net_device*DATARMNET813ca18d06=NULL;struct flowi4 
DATARMNET099aa93adc={};struct dst_entry*DATARMNETb5af46179c;struct rtable*
DATARMNET066b8bd537;struct net_device*DATARMNET39542b437e=NULL;
DATARMNET86f1f2cdc9=skb_header_pointer(DATARMNET543491eb0f,(0xd2d+202-0xdf7),
sizeof(*DATARMNET86f1f2cdc9),&DATARMNETbf6548198e);if(!DATARMNET86f1f2cdc9){
DATARMNET17f6bc1be5(DATARMNET7803c877c0);goto DATARMNETc1174a0f45;}
DATARMNET813ca18d06=dev_get_by_name_rcu(&init_net,DATARMNETe447822105());if(!
DATARMNET813ca18d06){DATARMNET17f6bc1be5(DATARMNET0978ff973f);goto 
DATARMNETc1174a0f45;}memcpy(&DATARMNET099aa93adc.daddr,&DATARMNET86f1f2cdc9->
daddr,sizeof(__be32));DATARMNET099aa93adc.flowi4_oif=DATARMNET813ca18d06->
ifindex;DATARMNET099aa93adc.flowi4_flags=FLOWI_FLAG_KNOWN_NH;DATARMNET066b8bd537
=ip_route_output_key(&init_net,&DATARMNET099aa93adc);if(IS_ERR(
DATARMNET066b8bd537)){DATARMNET17f6bc1be5(DATARMNET666fc9a664);
DATARMNET39542b437e=dev_get_by_name_rcu(&init_net,"dummy0");if(!
DATARMNET39542b437e){DATARMNET17f6bc1be5(DATARMNET521b065310);goto 
DATARMNETc1174a0f45;}DATARMNET099aa93adc.flowi4_oif=DATARMNET39542b437e->ifindex
;DATARMNET099aa93adc.flowi4_flags=FLOWI_FLAG_KNOWN_NH;DATARMNET066b8bd537=
ip_route_output_key(&init_net,&DATARMNET099aa93adc);if(IS_ERR(
DATARMNET066b8bd537)){DATARMNET17f6bc1be5(DATARMNET8a15bcdcc7);goto 
DATARMNET74b365f6cc;}}memcpy(&DATARMNET099aa93adc.saddr,&DATARMNET86f1f2cdc9->
saddr,sizeof(__be32));DATARMNETb5af46179c=xfrm_lookup(&init_net,&
DATARMNET066b8bd537->dst,flowi4_to_flowi(&DATARMNET099aa93adc),NULL,
(0xd2d+202-0xdf7));DATARMNET066b8bd537=(struct rtable*)DATARMNETb5af46179c;if(
IS_ERR(DATARMNET066b8bd537)){DATARMNET17f6bc1be5(DATARMNETddb1bc27cb);goto 
DATARMNETc1174a0f45;}skb_dst_set(DATARMNET543491eb0f,DATARMNETb5af46179c);
dst_output(&init_net,NULL,DATARMNET543491eb0f);DATARMNET17f6bc1be5(
DATARMNETc730640bf7);return RX_HANDLER_CONSUMED;}else if(DATARMNET543491eb0f->
dev&&(DATARMNET543491eb0f->protocol==htons(ETH_P_IPV6))&&DATARMNET1a901c3d09==
DATARMNET45ee632553){struct ipv6hdr*DATARMNETbf55123e5b,DATARMNETcf1d9e2c1e;
struct flowi6 DATARMNET8fbe36a2fa={};struct dst_entry*dst=NULL,*
DATARMNETb5af46179c;struct rtable*DATARMNET066b8bd537;struct net_device*
DATARMNET39542b437e=NULL;DATARMNETbf55123e5b=skb_header_pointer(
DATARMNET543491eb0f,(0xd2d+202-0xdf7),sizeof(*DATARMNETbf55123e5b),&
DATARMNETcf1d9e2c1e);if(!DATARMNETbf55123e5b){DATARMNET17f6bc1be5(
DATARMNET0b9541c9b3);goto DATARMNETc1174a0f45;}memcpy(&DATARMNET8fbe36a2fa.saddr
,&DATARMNETbf55123e5b->saddr,sizeof(struct in6_addr));memcpy(&
DATARMNET8fbe36a2fa.daddr,&DATARMNETbf55123e5b->daddr,sizeof(struct in6_addr));
dst=ipv6_stub->ipv6_dst_lookup_flow(&init_net,NULL,&DATARMNET8fbe36a2fa,NULL);if
(IS_ERR(dst)){DATARMNET17f6bc1be5(DATARMNET0078f1d36d);DATARMNET39542b437e=
dev_get_by_name_rcu(&init_net,"\x64\x75\x6d\x6d\x79\x30");if(!
DATARMNET39542b437e){DATARMNET17f6bc1be5(DATARMNET7c6c30b7d2);goto 
DATARMNETc1174a0f45;}DATARMNET8fbe36a2fa.flowi6_oif=DATARMNET39542b437e->ifindex
;DATARMNET8fbe36a2fa.flowi6_flags=FLOWI_FLAG_KNOWN_NH;dst=ipv6_stub->
ipv6_dst_lookup_flow(&init_net,NULL,&DATARMNET8fbe36a2fa,NULL);if(IS_ERR(dst)){
DATARMNET17f6bc1be5(DATARMNET39d80cc483);goto DATARMNET74b365f6cc;}}
DATARMNETb5af46179c=xfrm_lookup(&init_net,dst,flowi6_to_flowi(&
DATARMNET8fbe36a2fa),NULL,(0xd2d+202-0xdf7));DATARMNET066b8bd537=(struct rtable*
)DATARMNETb5af46179c;if(IS_ERR(DATARMNET066b8bd537)){DATARMNET17f6bc1be5(
DATARMNET661bdeccd4);goto DATARMNETc1174a0f45;}skb_dst_set(DATARMNET543491eb0f,
DATARMNETb5af46179c);dst_output(&init_net,NULL,DATARMNET543491eb0f);
DATARMNET17f6bc1be5(DATARMNET28e7704d13);return RX_HANDLER_CONSUMED;}else if(
DATARMNET543491eb0f->dev&&(DATARMNET543491eb0f->protocol==htons(ETH_P_IP))&&
DATARMNET1a901c3d09==DATARMNET356f2a237e){struct iphdr*DATARMNET86f1f2cdc9,
DATARMNETbf6548198e;struct flowi4 DATARMNET099aa93adc={};struct net_device*
DATARMNET813ca18d06=NULL;struct dst_entry*DATARMNETb5af46179c;struct net_device*
DATARMNET39542b437e=NULL;struct rtable*DATARMNET066b8bd537;DATARMNET86f1f2cdc9=
skb_header_pointer(DATARMNET543491eb0f,(0xd2d+202-0xdf7),sizeof(*
DATARMNET86f1f2cdc9),&DATARMNETbf6548198e);if(!DATARMNET86f1f2cdc9){
DATARMNET17f6bc1be5(DATARMNET15454f969d);goto DATARMNETc1174a0f45;}
DATARMNET813ca18d06=dev_get_by_name_rcu(&init_net,DATARMNET934406764d());if(!
DATARMNET813ca18d06){DATARMNET17f6bc1be5(DATARMNET4c5aeeb476);goto 
DATARMNETc1174a0f45;}memcpy(&DATARMNET099aa93adc.daddr,&DATARMNET86f1f2cdc9->
daddr,sizeof(__be32));DATARMNET099aa93adc.flowi4_oif=DATARMNET813ca18d06->
ifindex;DATARMNET099aa93adc.flowi4_flags=FLOWI_FLAG_KNOWN_NH;DATARMNET066b8bd537
=ip_route_output_key(&init_net,&DATARMNET099aa93adc);if(IS_ERR(
DATARMNET066b8bd537)){DATARMNET17f6bc1be5(DATARMNET9bdb1c4072);
DATARMNET39542b437e=dev_get_by_name_rcu(&init_net,"\x64\x75\x6d\x6d\x79\x30");if
(!DATARMNET39542b437e){DATARMNET17f6bc1be5(DATARMNET5abdc89190);goto 
DATARMNETc1174a0f45;}DATARMNET099aa93adc.flowi4_oif=DATARMNET39542b437e->ifindex
;DATARMNET099aa93adc.flowi4_flags=FLOWI_FLAG_KNOWN_NH;DATARMNET066b8bd537=
ip_route_output_key(&init_net,&DATARMNET099aa93adc);if(IS_ERR(
DATARMNET066b8bd537)){DATARMNET17f6bc1be5(DATARMNET101af46c1c);goto 
DATARMNET74b365f6cc;}}memcpy(&DATARMNET099aa93adc.saddr,&DATARMNET86f1f2cdc9->
saddr,sizeof(__be32));DATARMNETb5af46179c=xfrm_lookup(&init_net,&
DATARMNET066b8bd537->dst,flowi4_to_flowi(&DATARMNET099aa93adc),NULL,
(0xd2d+202-0xdf7));DATARMNET066b8bd537=(struct rtable*)DATARMNETb5af46179c;if(
IS_ERR(DATARMNET066b8bd537)){DATARMNET17f6bc1be5(DATARMNET9a57ef32d3);goto 
DATARMNETc1174a0f45;}skb_dst_set(DATARMNET543491eb0f,DATARMNETb5af46179c);
dst_output(&init_net,NULL,DATARMNET543491eb0f);DATARMNET17f6bc1be5(
DATARMNET9a940d93dc);return RX_HANDLER_CONSUMED;}else if(DATARMNET543491eb0f->
dev&&(DATARMNET543491eb0f->protocol==htons(ETH_P_IPV6))&&DATARMNET1a901c3d09==
DATARMNET356f2a237e){struct ipv6hdr*DATARMNETbf55123e5b,DATARMNETcf1d9e2c1e;
struct flowi6 DATARMNET8fbe36a2fa={};struct dst_entry*dst=NULL,*
DATARMNETb5af46179c;struct rtable*DATARMNET066b8bd537;struct net_device*
DATARMNET39542b437e=NULL;DATARMNETbf55123e5b=skb_header_pointer(
DATARMNET543491eb0f,(0xd2d+202-0xdf7),sizeof(*DATARMNETbf55123e5b),&
DATARMNETcf1d9e2c1e);if(!DATARMNETbf55123e5b){DATARMNET17f6bc1be5(
DATARMNET6b0ed53aab);goto DATARMNETc1174a0f45;}memcpy(&DATARMNET8fbe36a2fa.saddr
,&DATARMNETbf55123e5b->saddr,sizeof(struct in6_addr));memcpy(&
DATARMNET8fbe36a2fa.daddr,&DATARMNETbf55123e5b->daddr,sizeof(struct in6_addr));
dst=ipv6_stub->ipv6_dst_lookup_flow(&init_net,NULL,&DATARMNET8fbe36a2fa,NULL);if
(IS_ERR(dst)){DATARMNET17f6bc1be5(DATARMNET22ac945cae);DATARMNET39542b437e=
dev_get_by_name_rcu(&init_net,"\x64\x75\x6d\x6d\x79\x30");if(!
DATARMNET39542b437e){DATARMNET17f6bc1be5(DATARMNETf326b7c906);goto 
DATARMNETc1174a0f45;}DATARMNET8fbe36a2fa.flowi6_oif=DATARMNET39542b437e->ifindex
;DATARMNET8fbe36a2fa.flowi6_flags=FLOWI_FLAG_KNOWN_NH;dst=ipv6_stub->
ipv6_dst_lookup_flow(&init_net,NULL,&DATARMNET8fbe36a2fa,NULL);if(IS_ERR(dst)){
DATARMNET17f6bc1be5(DATARMNET544d78ede7);goto DATARMNET74b365f6cc;}}
DATARMNETb5af46179c=xfrm_lookup(&init_net,dst,flowi6_to_flowi(&
DATARMNET8fbe36a2fa),NULL,(0xd2d+202-0xdf7));DATARMNET066b8bd537=(struct rtable*
)DATARMNETb5af46179c;if(IS_ERR(DATARMNET066b8bd537)){DATARMNET17f6bc1be5(
DATARMNET97b44d0c09);goto DATARMNETc1174a0f45;}skb_dst_set(DATARMNET543491eb0f,
DATARMNETb5af46179c);dst_output(&init_net,NULL,DATARMNET543491eb0f);
DATARMNET17f6bc1be5(DATARMNETf954265acb);return RX_HANDLER_CONSUMED;}
DATARMNET74b365f6cc:return RX_HANDLER_PASS;DATARMNETc1174a0f45:kfree_skb(
DATARMNET543491eb0f);return RX_HANDLER_CONSUMED;}static rx_handler_result_t 
DATARMNET68fe094884(struct sk_buff**DATARMNET89946cec52){struct 
DATARMNET0ca9d8ead7 DATARMNETa76763310b={};struct DATARMNET4f49486833*
DATARMNET63b1a086d5;struct sk_buff*DATARMNET543491eb0f=*DATARMNET89946cec52;
unsigned long DATARMNETfb0677cc3c;struct DATARMNET8d3c2559ca DATARMNET2d4b4cfc9e
;struct DATARMNET41b426061d*DATARMNET8184934307;uint8_t DATARMNET1a901c3d09=
DATARMNETdcafdec32a;if(!DATARMNET543491eb0f||DATARMNET543491eb0f->pkt_type==
PACKET_LOOPBACK)return RX_HANDLER_PASS;if(DATARMNET543491eb0f->protocol==htons(
ETH_P_IP)){struct iphdr*DATARMNET86f1f2cdc9,DATARMNETbf6548198e;
DATARMNET86f1f2cdc9=skb_header_pointer(DATARMNET543491eb0f,(0xd2d+202-0xdf7),
sizeof(*DATARMNET86f1f2cdc9),&DATARMNETbf6548198e);if(!DATARMNET86f1f2cdc9)goto 
DATARMNETbf4095f79e;DATARMNET2d4b4cfc9e.DATARMNET0dc14167a1=DATARMNET86f1f2cdc9
->saddr;DATARMNET2d4b4cfc9e.DATARMNET0d956cc77a=(0xd11+230-0xdf3);}else if(
DATARMNET543491eb0f->protocol==htons(ETH_P_IPV6)){struct ipv6hdr*
DATARMNETbf55123e5b,DATARMNETcf1d9e2c1e;DATARMNETbf55123e5b=skb_header_pointer(
DATARMNET543491eb0f,(0xd2d+202-0xdf7),sizeof(*DATARMNETbf55123e5b),&
DATARMNETcf1d9e2c1e);if(!DATARMNETbf55123e5b)goto DATARMNETbf4095f79e;memcpy(&
DATARMNET2d4b4cfc9e.DATARMNET5700daac01,&DATARMNETbf55123e5b->saddr,sizeof(
DATARMNET2d4b4cfc9e.DATARMNET5700daac01));DATARMNET2d4b4cfc9e.
DATARMNET0d956cc77a=(0xd03+244-0xdf1);}else{goto DATARMNETbf4095f79e;}
rcu_read_lock();DATARMNET8184934307=DATARMNETcc0a01df2a(&DATARMNET2d4b4cfc9e);
rcu_read_unlock();if(!DATARMNET8184934307)goto DATARMNETbf4095f79e;
DATARMNET1a901c3d09=DATARMNET8184934307->DATARMNET7ed5754a5c.DATARMNET9954a624ac
;if(DATARMNET1a901c3d09==DATARMNETdcafdec32a)goto DATARMNETbf4095f79e;if(
DATARMNET543491eb0f->dev&&DATARMNET1a901c3d09==DATARMNET9bfbc31cd6)nf_ct_set(
DATARMNET543491eb0f,NULL,IP_CT_UNTRACKED);if(DATARMNET543491eb0f->protocol==
htons(ETH_P_IP)){struct iphdr*DATARMNET86f1f2cdc9,DATARMNETbf6548198e;
DATARMNET86f1f2cdc9=skb_header_pointer(DATARMNET543491eb0f,(0xd2d+202-0xdf7),
sizeof(*DATARMNET86f1f2cdc9),&DATARMNETbf6548198e);if(!DATARMNET86f1f2cdc9)goto 
DATARMNETbf4095f79e;if(DATARMNET86f1f2cdc9->protocol==IPPROTO_TCP)goto 
DATARMNET9b3d23a43b;if(DATARMNET86f1f2cdc9->protocol!=IPPROTO_ICMP)goto 
DATARMNETbf4095f79e;DATARMNETa76763310b.DATARMNETdfe430c2d6=DATARMNET86f1f2cdc9
->saddr;DATARMNETa76763310b.DATARMNET2cb607d686=DATARMNET86f1f2cdc9->daddr;
DATARMNETa76763310b.DATARMNET0d956cc77a=(0xd11+230-0xdf3);}else if(
DATARMNET543491eb0f->protocol==htons(ETH_P_IPV6)){struct ipv6hdr*
DATARMNETbf55123e5b,DATARMNETcf1d9e2c1e;__be16 frag_off;u8 DATARMNET65293f17c4;
DATARMNETbf55123e5b=skb_header_pointer(DATARMNET543491eb0f,(0xd2d+202-0xdf7),
sizeof(*DATARMNETbf55123e5b),&DATARMNETcf1d9e2c1e);if(!DATARMNETbf55123e5b)goto 
DATARMNETbf4095f79e;DATARMNET65293f17c4=DATARMNETbf55123e5b->nexthdr;if(
ipv6_skip_exthdr(DATARMNET543491eb0f,sizeof(*DATARMNETbf55123e5b),&
DATARMNET65293f17c4,&frag_off)<(0xd2d+202-0xdf7))goto DATARMNETbf4095f79e;if(
frag_off&&DATARMNET65293f17c4==NEXTHDR_FRAGMENT)goto DATARMNETbf4095f79e;if(
DATARMNET65293f17c4==IPPROTO_TCP)goto DATARMNET9b3d23a43b;if(DATARMNET65293f17c4
!=IPPROTO_ICMPV6)goto DATARMNETbf4095f79e;memcpy(&DATARMNETa76763310b.
DATARMNET815cbb4bf5,&DATARMNETbf55123e5b->saddr,sizeof(DATARMNETa76763310b.
DATARMNET815cbb4bf5));memcpy(&DATARMNETa76763310b.DATARMNETc3f31215b7,&
DATARMNETbf55123e5b->daddr,sizeof(DATARMNETa76763310b.DATARMNETc3f31215b7));
DATARMNETa76763310b.DATARMNET0d956cc77a=(0xd03+244-0xdf1);}else{goto 
DATARMNETbf4095f79e;}rcu_read_lock();hash_for_each_possible_rcu(
DATARMNET5413d6f8ec,DATARMNET63b1a086d5,DATARMNETe8608dd267,DATARMNETa76763310b.
DATARMNET2cb607d686){if(!DATARMNET5f3c9ed4da(&DATARMNET63b1a086d5->
DATARMNET54338da2ff,&DATARMNETa76763310b))continue;if(likely(hrtimer_is_queued(&
DATARMNET63b1a086d5->DATARMNET9f31ce5d2d)))hrtimer_start(&DATARMNET63b1a086d5->
DATARMNET9f31ce5d2d,DATARMNET5da8c68c19,HRTIMER_MODE_REL);rcu_read_unlock();goto
 DATARMNETbf4095f79e;}rcu_read_unlock();spin_lock_irqsave(&DATARMNET820642743b,
DATARMNETfb0677cc3c);DATARMNET63b1a086d5=kzalloc(sizeof(*DATARMNET63b1a086d5),
GFP_ATOMIC);if(!DATARMNET63b1a086d5){spin_unlock_irqrestore(&DATARMNET820642743b
,DATARMNETfb0677cc3c);goto DATARMNETbf4095f79e;}INIT_HLIST_NODE(&
DATARMNET63b1a086d5->DATARMNETe8608dd267);memcpy(&DATARMNET63b1a086d5->
DATARMNET54338da2ff,&DATARMNETa76763310b,sizeof(DATARMNETa76763310b));
DATARMNET63b1a086d5->DATARMNET7ed5754a5c.DATARMNET57656f6f2f=DATARMNET543491eb0f
->dev;hrtimer_init(&DATARMNET63b1a086d5->DATARMNET9f31ce5d2d,CLOCK_MONOTONIC,
HRTIMER_MODE_REL);DATARMNET63b1a086d5->DATARMNET9f31ce5d2d.function=
DATARMNET299a8a08b5;hrtimer_start(&DATARMNET63b1a086d5->DATARMNET9f31ce5d2d,
DATARMNET5da8c68c19,HRTIMER_MODE_REL);hash_add_rcu(DATARMNET5413d6f8ec,&
DATARMNET63b1a086d5->DATARMNETe8608dd267,DATARMNETa76763310b.DATARMNET2cb607d686
);spin_unlock_irqrestore(&DATARMNET820642743b,DATARMNETfb0677cc3c);
DATARMNETbf4095f79e:return DATARMNETc9ed97754a(DATARMNET543491eb0f,
DATARMNET1a901c3d09);DATARMNET9b3d23a43b:DATARMNET7ca470d54b(DATARMNET543491eb0f
,TCP_FLAG_SYN);return DATARMNETc9ed97754a(DATARMNET543491eb0f,
DATARMNET1a901c3d09);}static void DATARMNETbc6bd11f47(struct net_device*
DATARMNET00dcb79bc4){struct DATARMNET4f49486833*DATARMNET63b1a086d5;int 
DATARMNET5c2fd31d7b;rcu_read_lock();hash_for_each_rcu(DATARMNET5413d6f8ec,
DATARMNET5c2fd31d7b,DATARMNET63b1a086d5,DATARMNETe8608dd267){if(
DATARMNET63b1a086d5->DATARMNET7ed5754a5c.DATARMNET57656f6f2f==
DATARMNET00dcb79bc4)hrtimer_cancel(&DATARMNET63b1a086d5->DATARMNET9f31ce5d2d);}
rcu_read_unlock();}static int DATARMNET81ab4de243(struct notifier_block*
DATARMNET272c159b3c,unsigned long DATARMNET7f045a1e6e,void*data){struct 
net_device*DATARMNET00dcb79bc4=netdev_notifier_info_to_dev(data);if(!
DATARMNET00dcb79bc4||strncmp(DATARMNET00dcb79bc4->name,
"\x72\x5f\x72\x6d\x6e\x65\x74\x5f\x64\x61\x74\x61",(0xd19+238-0xdfb)))return 
NOTIFY_DONE;switch(DATARMNET7f045a1e6e){case NETDEV_UNREGISTER:
netdev_rx_handler_unregister(DATARMNET00dcb79bc4);DATARMNETbc6bd11f47(
DATARMNET00dcb79bc4);break;case NETDEV_REGISTER:if(netdev_rx_handler_register(
DATARMNET00dcb79bc4,DATARMNET68fe094884,NULL))pr_err(
"\x25\x73\x28\x29\x3a\x20\x52\x65\x67\x69\x73\x74\x65\x72\x69\x6e\x67\x20\x68\x61\x6e\x64\x6c\x65\x72\x20\x6f\x6e\x20\x25\x73\x20\x66\x61\x69\x6c\x65\x64" "\n"
,__func__,DATARMNET00dcb79bc4->name);break;default:break;}return NOTIFY_DONE;}
static struct notifier_block DATARMNET61d0113123={.notifier_call=
DATARMNET81ab4de243,};struct DATARMNET8d3c2559ca*DATARMNET07f0e0f286(struct 
DATARMNET0ca9d8ead7*DATARMNET54338da2ff)__must_hold(RCU){struct 
DATARMNET4f49486833*DATARMNET63b1a086d5;hash_for_each_possible_rcu(
DATARMNET5413d6f8ec,DATARMNET63b1a086d5,DATARMNETe8608dd267,DATARMNET54338da2ff
->DATARMNET2cb607d686){if(!DATARMNET5f3c9ed4da(&DATARMNET63b1a086d5->
DATARMNET54338da2ff,DATARMNET54338da2ff))continue;return&DATARMNET63b1a086d5->
DATARMNET7ed5754a5c;}return NULL;}void DATARMNETf4e1a29dbc(void){struct 
DATARMNET4f49486833*DATARMNET63b1a086d5;int DATARMNET5c2fd31d7b;rcu_read_lock();
hash_for_each_rcu(DATARMNET5413d6f8ec,DATARMNET5c2fd31d7b,DATARMNET63b1a086d5,
DATARMNETe8608dd267)hrtimer_cancel(&DATARMNET63b1a086d5->DATARMNET9f31ce5d2d);
rcu_read_unlock();}void DATARMNET6f73df41cd(struct sk_buff*DATARMNET543491eb0f){
int protocol=-(0xd26+209-0xdf6);struct DATARMNETe117226f58*DATARMNET3396919a68=
rcu_dereference(DATARMNETcde6e442f5);if(!DATARMNET3396919a68)return;if(
DATARMNET543491eb0f->protocol==htons(ETH_P_IP)){struct iphdr*DATARMNET86f1f2cdc9
,DATARMNETbf6548198e;DATARMNET86f1f2cdc9=skb_header_pointer(DATARMNET543491eb0f,
(0xd2d+202-0xdf7),sizeof(*DATARMNET86f1f2cdc9),&DATARMNETbf6548198e);if(!
DATARMNET86f1f2cdc9)return;if(DATARMNET86f1f2cdc9->version!=DATARMNET3396919a68
->DATARMNET0d956cc77a&&DATARMNET86f1f2cdc9->saddr!=DATARMNET3396919a68->
DATARMNETdfe430c2d6&&DATARMNET86f1f2cdc9->daddr!=DATARMNET3396919a68->
DATARMNET2cb607d686)return;protocol=DATARMNET86f1f2cdc9->protocol;}else if(
DATARMNET543491eb0f->protocol==htons(ETH_P_IPV6)){struct ipv6hdr*
DATARMNETbf55123e5b,DATARMNETcf1d9e2c1e;DATARMNETbf55123e5b=skb_header_pointer(
DATARMNET543491eb0f,(0xd2d+202-0xdf7),sizeof(*DATARMNETbf55123e5b),&
DATARMNETcf1d9e2c1e);if(!DATARMNETbf55123e5b)return;if(DATARMNETbf55123e5b->
version!=DATARMNET3396919a68->DATARMNET0d956cc77a&&ipv6_addr_cmp(&
DATARMNETbf55123e5b->saddr,&DATARMNET3396919a68->DATARMNET815cbb4bf5)&&
ipv6_addr_cmp(&DATARMNETbf55123e5b->daddr,&DATARMNET3396919a68->
DATARMNETc3f31215b7))return;protocol=DATARMNETbf55123e5b->nexthdr;}if(protocol==
IPPROTO_UDP){if(udp_hdr(DATARMNET543491eb0f)->source==DATARMNET3396919a68->
DATARMNET08e913477e&&udp_hdr(DATARMNET543491eb0f)->dest==DATARMNET3396919a68->
DATARMNETda7f7fa492)goto DATARMNET9573fcc9c6;}return;DATARMNET9573fcc9c6:
DATARMNET543491eb0f->priority=2607612160;DATARMNET5ca94dbc3c(DATARMNETc2cade1d75
);}static const struct rmnet_module_hook_register_info DATARMNETd0b5ecd937={.
hooknum=RMNET_MODULE_HOOK_WLAN_FLOW_MATCH,.func=DATARMNET6f73df41cd,};void 
DATARMNET333c107558(void){rcu_assign_pointer(rmnet_wlan_ll_tuple_hook,
DATARMNET6f73df41cd);rmnet_module_hook_register(&DATARMNETd0b5ecd937,
(0xd26+209-0xdf6));}void DATARMNET4c08c7210c(void){rcu_assign_pointer(
rmnet_wlan_ll_tuple_hook,NULL);rmnet_module_hook_unregister(&DATARMNETd0b5ecd937
,(0xd26+209-0xdf6));}int DATARMNET9f106ed933(void){int DATARMNET268a8314cf;
DATARMNET268a8314cf=register_netdevice_notifier(&DATARMNET61d0113123);if(
DATARMNET268a8314cf)pr_err(
"\x25\x73\x28\x29\x3a\x20\x6e\x6f\x74\x69\x66\x69\x65\x72\x20\x66\x61\x69\x6c\x65\x64" "\n"
,__func__);return DATARMNET268a8314cf;}int DATARMNETf56cbaa2b1(void){int 
DATARMNET268a8314cf;DATARMNET268a8314cf=unregister_netdevice_notifier(&
DATARMNET61d0113123);if(DATARMNET268a8314cf)pr_err(
"\x25\x73\x28\x29\x3a\x20\x6e\x6f\x74\x69\x66\x65\x72\x20\x66\x61\x69\x6c\x65\x64" "\n"
,__func__);return DATARMNET268a8314cf;}
