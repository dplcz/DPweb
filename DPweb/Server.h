#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<WinSock2.h>
#include<WS2tcpip.h>

//����Socket��----------------
#pragma comment(lib,"ws2_32.lib")
//����������Ӷ���
#define MAX_CONNECTION_QUEUE 8

typedef struct sockaddr sockaddr;

//�������
int merror(int redata, int error, char* showTips);

//����һ��socket
SOCKET createServer(WSADATA wsaData, int v1, int v2, int internetwork, int transmission, int protocol);

//ȷ��socket�汾��Ϣ�����windows socket��ʼ����Ϣ
WSADATA wsa_data;








