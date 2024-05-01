#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<pthread.h>
#include<semaphore.h>
#include<mysql/mysql.h>
#define MERROR -1
#define OK 1
#define CONSUMER 1
#define PRODUCER 2
//����MySQL��
#pragma comment(lib,"libmysql")
//����Socket��----------------
#pragma comment(lib,"ws2_32.lib")
//������̰߳�
#pragma comment(lib,"pthreadVC2.lib")

//����������Ӷ���
#define MAX_CONNECTION_QUEUE 128

//�������ӿ���
#define MAX_API_COUNT 10
//�����̳߳ش�С
#define MAX_THREAD_COUNT 96
//������������������
#define MAX_TASK_COUNT 5000


//����״̬
typedef int Status;

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in claddr;

//����ʽ
typedef enum { GET = 1000, POST = 1100, HEAD = 1200 }METHODTYPE;
//��Ӧ��ʽ
typedef enum { TEXT = 0, HTML = 10, XML = 20, JS = 30, JSON = 40, CSS = 50,  JPG = 60, JPEG = 60, JPE = 60, JFIF = 60, PNG = 70 }RESPONSETYPE;
//��Ӧ״̬��
typedef enum { SUCCESS = 200, CREATED = 201, BADREQUEST = 400, NOTFOUND = 404 }STATUSCODE;

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
	char* directory;
	int param_len;
	int if_static;
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


typedef struct ThreadLock {
	pthread_mutex_t lock;
	int flag;
}ThreadLock;
//�������
typedef struct TaskQueue {
	ClientSolver* taskQueue[MAX_TASK_COUNT + 1];
	int head;
	int tail;
}TaskQueue;
//�߳�
typedef struct Thread{
	pthread_t _thread;
	int _taskCount;
	int _threadId;
}Thread;

//�̳߳�
typedef struct ThreadPool{
	Thread pool[MAX_THREAD_COUNT];
	TaskQueue task;
	ThreadLock _lock;
	pthread_cond_t _cond;
	sem_t _sem_items;
	sem_t _sem_blanks;
	sem_t _mutex;
}ThreadPool;

typedef struct app {
	SERVER* serverM;
	claddr client;
	int cllen;
	RequestMethod requestM;
	ThreadPool* pool;
}APP;

//�̳߳ز���
typedef struct ThreadArgs {
	APP* app;
	ThreadPool* pool;
	Thread* thisThread;
}ThreadArgs;

//ClientControl�̲߳���
typedef struct ClientControlArgs {
	APP* app;
	int pool_flag;
}ClientControlArgs;

typedef struct Header {
	char* key;
	char* value;
}Header;

typedef struct MainHeader {
	char* method;
	char* url;
	char* version;
}MainHeader;

typedef struct Data {
	char name[20];
	char filename[50];
	char type[50];
	char data[50 * 1024];
}Data;

typedef struct PostData {
	char* boundary;
	Data* data;
	int length;
}PostData;

typedef struct Request {
	MainHeader head;
	Header *headers;
	int headers_len;
	PARAMS *params;
	int param_len;
	PostData post_data;
}RequestText;

typedef struct ResData {
	int is_file;
	char* data;
}ResData;

//��Ӧ
typedef struct Response {
	RESPONSETYPE type;
	STATUSCODE code;
	Header *headers;
	int headers_len;
	ResData data;
}Response;



