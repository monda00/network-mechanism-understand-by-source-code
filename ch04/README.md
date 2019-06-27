# TCP機能の基本機能を追加しよう

## 実現する機能

- 宛先IPアドレスとポート番号を指定してTCP接続を確立する
- 待ち受けるポート番号を指定し、TCP接続を受付、接続を確立する
- 確立したTCP接続でデータを送信し、受信したデータを表示する
- 確立したTCP接続を切断する

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
- tcp.c, tcp.h
  - TCP関連
- dhcp.c, dhcp.h
  - DHCP関連
- cmd.c, cmd.h
  - コマンド処理関連
- Makefile
  - makeファイル

