#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <poll.h>
#include <sys/ioctl.h>
//#include <netinet/ip_icmp.h>
#include <netinet/if_ether.h>
#include <net/if.h> // 代わりになる？？
//#include <linux/if.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "sock.h"
#include "ether.h"
#include "arp.h"
#include "ip.h"
#include "icmp.h"
#include "param.h"
#include "cmd.h"

int EndFlag = 0;
int DeviceSoc;
PARAM Param;

/* mainからスレッド起動される関数
 * PF_PACKETのDeviceSocを監視し、受信レディになったら、
 * イーサネットフレーム解析する
 */
void *MyEthThread(void *arg)
{
  int nready;
  struct pollfd targets[1];
  u_int8_t buf[2048];
  int len;

  targets[0].fd = DeviceSoc;
  targets[0].events = POLLIN|POLLERR;

  while(EndFlag==0){
    switch((nready = poll(targets, 1, 1000))){
      case -1:
        if(errno != EINTR){
          perror("poll");
        }
        break;
      case 0:
        break;
      default:
        if(targets[0].revents & (POLLIN|POLLERR)){
          if((len = read(DeviceSoc, buf, sizeof(buf))) <= 0){
            perror("read");
          }
          else{
            EtherRecv(DeviceSoc, buf, len);
          }
        }
        break;
    }
  }

  return(NULL);
}

/* mainからスレッド起動される関数
 * 標準入力を監視し、読み込みレディになったらfgetsで１行読み込み
 * コマンド処理をする
 */
void *StdInThread(void *arg)
{
  int nready;
  struct pollfd targets[1];
  char buf[2048];

  targets[0].fd = fileno(stdin);
  targets[0].events = POLLIN|POLLERR;

  while(EndFlag == 0){
    switch((nready = poll(targets, 1, 1000))){
      case -1:
        if(errno != EINTR){
          perror("poll");
        }
        break;
      case 0:
        break;
      default:
        if(targets[0].revents & (POLLIN|POLLERR)){
          fgets(buf, sizeof(buf), stdin);
          DoCmd(buf);
        }
        break;
    }
  }

  return(NULL);
}

/* 終了関連のシグナルハンドラ
 * EndFlagを1にする
 */
void sig_term(int sig)
{
  EndFlag = 1;
}

/* EndFlagが1になったらmainから実行される
 * DeviceSocのプロミスキャスモードを解除し、ディスクリプタをクローズ
 */
int ending()
{
  struct ifreq if_req;

  printf("ending\n");

  if(DeviceSoc != -1){
    strcpy(if_req.ifr_name, Param.device);
    if(ioctl(DeviceSoc, SIOCGIFFLAGS, &if_req) < 0){
      perror("ioctl");
    }

    if_req.ifr_flags = if_req.ifr_flags & ~IFF_PROMISC;
    if(ioctl(DeviceSoc, SIOCGIFFLAGS, &if_req) < 0){
      perror("ioctl");
    }

    close(DeviceSoc);
    DeviceSoc = -1;
  }

  return(0);
}

int main(void){

  return 0;
}
