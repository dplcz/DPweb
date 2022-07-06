#include "Server.h"
#include "Model.h"
#include "Tools.h"


APP* CreateServerIPV4(ULONG host, int port) {
	/// <summary>
	/// Ĭ������
	/// IPV4 TCP ������
	/// 
	/// host
	/// INADDR_ANY	��������
	/// INADDR_LOOPBACK	��������
	/// </summary>
	/// <param name="addr">��ip��ַ</param>
	/// <param name="port"></param>
	/// <returns></returns>

	WSADATA wsa_data;
	// �����
	struct sockaddr_in seraddr;
	//�첽�׽�����������
	int isok = WSAStartup(MAKEWORD(2, 2), &wsa_data);
	merror(isok, WSAEINVAL, "socket����ʧ��\n");
	// Ĭ������
	// IPV4 TCP ������
	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	merror(server, INVALID_SOCKET, "socket����ʧ��\n");
	// IPV4
	seraddr.sin_family = AF_INET;
	// �󶨶˿�
	seraddr.sin_port = htons(port);
	// ��ip��ַ
	seraddr.sin_addr.s_addr = (host);
	// �󶨺���
	isok = bind(server, (sockaddr*)&seraddr, sizeof(seraddr));
	merror(isok, SOCKET_ERROR, "bind����Ϣʧ��\n");

	APP* app = (APP*)malloc(sizeof(APP));
	app->serverM = (SERVER*)malloc(sizeof(SERVER));

	//�����ͻ��ˣ���һ������Ϊ�����ߣ��ڶ�������������е���󳤶�
	isok = listen(server, MAX_CONNECTION_QUEUE);
	app->serverM->server= server;
	app->serverM->flag = 1;
	app->cllen = sizeof(app->client);
	return app;
}

Status RunServer(APP *app) {
	pthread_t th_server,th_client;
	pthread_create(&th_server, NULL, ServerControl, app->serverM);
	pthread_create(&th_client, NULL, ClientControl, app);
	while (1);

}

void* ServerControl(SERVER* serverM) {
	while (1) {
		char temp[20];
		scanf_s("%s",temp,20);
		if (strcmp(temp, "stop") == 0 || strcmp(temp, "STOP") == 0)
		{
			closesocket(serverM->server);
			serverM->flag = 0;
		}
	}
}

void* ClientControl(APP* app) {
	while (1) {
		printf("�ȴ�������...");
		SOCKET client = accept(app->serverM->server, (sockaddr*)&app->client, &app->cllen);
		if (app->serverM->flag == 0) {
			closesocket(client);
			free(app->serverM);
			free(app);
			exit(0);
		}
		//����һ����ʾ˭��������
		//��������˭���ӽ���
		//������������������Ϣ�Ľṹ���С
		//����ֵΪ���ӽ����� socket
		merror(client, INVALID_SOCKET, "����ʧ��\n");
		printf("���ӳɹ�\n");
		/*pthread_t th;
		pthread_create(&th, NULL, solve_client, client);*/
		printf("1");
		closesocket(client);
	}
}
