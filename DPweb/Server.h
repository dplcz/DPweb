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
//����GET����
int GetMethodSolve(ClientSolver* client, RequestText* text, int methodIndex);

