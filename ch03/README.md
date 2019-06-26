# ３章：UDP通信に対応させ、DHCPクライアント昨日を実装しよう

## 実現する機能

- 宛先IPアドレスとポート番号を指定してUDPパケットを送信する
- 待ち受けるポート番号を指定し、受信したUDPパケットを表示する
- 起動時にDHCPにより自身のIPアドレス、ネットマスク、デフォルトゲートウェイを取得し、設定する
- DHCPリース時間に応じてリース延長を行う
- プログラム終了時にはDHCPでリリース処理を行う

## ソースファイルの構成

- main.c
  - メイン処理関連
- param.c, param.h
  - パラメータ読み込み関連
- sock.c, sock.h
  - チェックサムなどユーティリティ関数関連
- ether.c, ether.h
  - イーサ関連
- arp.c, arp.h
  - ARP関連
- ip.c, ip.h
  - IP関連
- icmp.c, icmp.h
  - ICMP関連
- udp.c, udp.h
  - UDP関連
- dhcp.c, dhcp.h
  - DHCP関連
- cmd.c, cmd.h
  - コマンド処理関連
- Makefile
  - makeファイル

