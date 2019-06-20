# ２章：pingのやりとりが可能なホストプログラムを作ろう

## 実現する機能

- 指定した仮想IPアドレス宛のARP要求に対して仮想MACアドレスを応答
- 自分宛のICMPエコー要求に応答
- ARP要求を送信し、応答を受信してRTTを表示
- 他のセグメントとの通信

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
- cmd.c, cmd.h
  - コマンド処理関連
- Makefile
  - makeファイル

