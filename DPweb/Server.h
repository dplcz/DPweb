#pragma once

#include"Model.h"
//����һ��socket
APP* CreateServerIPV4(ULONG host, int port);
//��������
Status RunServer(APP *app);
//���������ָ��
void* ServerControl(SERVER *server);
//�����ͻ�������
void* ClientControl(APP *app);
//����ͻ��˱���
void* SolveClient(ClientSolver* client);
//�жϲ��������Ƿ�ƥ��
int JudgeParam(Method method, RequestText* text);
//����̬�ļ�����
int GetStaticSolve(ClientSolver* client, RequestText* text, int methodIndex, char* path);
//����GET����
int GetMethodSolve(ClientSolver* client, RequestText* text, int methodIndex);
//����POST����
int PostMethodSolve(ClientSolver* client, RequestText* text, int methodIndex, char* postData);
//������Ӧ����
int SolveResponse(Response* orgin, ClientSolver* client);
//��ȡ״̬���ַ���
char* GetStatusCode(STATUSCODE code);
//ƴ����Ӧͷ�ļ�ֵ
char* GetHeader(char* key, char* value);
//�ж��ļ�����
int JudgeType(char* path);
