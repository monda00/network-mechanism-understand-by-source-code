#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <netinet/ip_icmp.h>
#include <netinet/if_ether.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "sock.h"
#include "ether.h"
#include "arp.h"
#include "param.h"

extern PARAM Param;

#define ARP_TABLE_NO (16)

typedef struct{
  time_t timestamp;
  u_int8_t mac[6];
  struct in_addr ipaddr;
}ARP_TABLE;

ARP_TABLE ArpTable[ARP_TABLE_NO];

pthread_rwlock_t ArpTableLock = PTHREAD_RWLOCK_INITIALIZER;

extern u_int8_t AllZeroMac[6];
extern u_int8_t BcastMac[6];
