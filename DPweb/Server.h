#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<pthread.h>
#include"Model.h"
#include"Tools.h"

//����Socket��----------------
#pragma comment(lib,"ws2_32.lib")
//������̰߳�
#pragma comment(lib,"pthreadVC2.lib")
//����������Ӷ���
#define MAX_CONNECTION_QUEUE 8

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in claddr;

typedef struct SERVER {
	SOCKET server;
	Status flag;
}SERVER;

typedef struct app {
	SERVER *serverM;
	claddr client;
	int cllen;
}APP;

//����һ��socket
APP* CreateServerIPV4(ULONG host, int port);
//��������
Status RunServer(APP *app);
//���������ָ��
void* ServerControl(SOCKET *server);
//�����ͻ�������
void* ClientControl(APP *app);


