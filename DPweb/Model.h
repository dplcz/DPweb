#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<pthread.h>
#define ERROR -1
#define OK 1

//����Socket��----------------
#pragma comment(lib,"ws2_32.lib")
//������̰߳�
#pragma comment(lib,"pthreadVC2.lib")

//����������Ӷ���
#define MAX_CONNECTION_QUEUE 8

//�������ӿ���
#define MAX_API_COUNT 10

//����״̬
typedef int Status;

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in claddr;

//����ʽ
typedef enum { GET = 1000, POST = 2000, HEAD = 3000 }METHODTYPE;
//��Ӧ��ʽ
typedef enum { TEXT = 10, HTML = 20, XML = 30, JS = 40, JSON = 50, JPG = 60, JPEG = 60, JPE = 60, JFIF = 60, PNG = 70 }RESPONSETYPE;

typedef char* URI;
typedef char* NAME;
typedef char* DATA;
typedef char* DEFAULT;

typedef struct SERVER {
	SOCKET server;
	Status flag;
}SERVER;

//���ղ���
typedef struct PARAMS {
	NAME name;
	DATA data;
	DEFAULT default_data;
}PARAMS;

//�ص�����
typedef void*(*CALLBACKFUNC)(PARAMS* args);

//�����ṹ��
typedef struct Method {
	METHODTYPE type;
	URI uri;
	CALLBACKFUNC callback;
	PARAMS *params;
	int param_len;
}Method;

//�����б�ṹ��
typedef struct RequestMethod {
	Method methods[MAX_API_COUNT];
	int method_len;
}RequestMethod;

typedef struct ClientSolver {
	SOCKET* client;
	RequestMethod method;
}ClientSolver;

typedef struct app {
	SERVER* serverM;
	claddr client;
	int cllen;
	RequestMethod requestM;
}APP;

typedef struct Header {
	char* key;
	char* value;
}Header;

typedef struct MainHeader {
	char* method;
	char* url;
	char* version;
}MainHeader;


typedef struct Request {
	MainHeader head;
	Header *headers;
	int headers_len;
	PARAMS *params;
	int param_len;
}RequestText;

//��Ӧ
typedef struct Response {
	RESPONSETYPE type;
	Header *headers;
	char* filename;
}Response;



