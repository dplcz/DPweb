#include "Server.h"
#include "Model.h"

int merror(int redata, int error, char* showTips) {
	if (redata == error)
	{
		perror(showTips);
		printf("\n");
		getchar();
		return -1;
	}
	return 1;
}

SOCKET createServerIPV4(ULONG host, int port) {
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
	return server;
}