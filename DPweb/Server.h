#pragma once

#include"Model.h"
//����һ��socket
APP* CreateServerIPV4(ULONG host, int port);
//��������
Status RunServer(APP *app, int pool_flag);
//���������ָ��
void* ServerControl(APP* app);
//�����ͻ�������
void* ClientControl(ClientControlArgs clientArgs);
//����ͻ��˱���
void* SolveClient(ClientSolver* client, int threadId);
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
//�̳߳ؼ�������
void ThreadListen(ThreadArgs args);
