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

void* SolveClient(ClientSolver* client);


