#pragma once
#include<stdio.h>
#include<stdlib.h>

#include "Model.h"

//�������
int merror(int redata, int error, char* showTips);
//��ȡ״̬���ַ���
char* GetStatusCode(STATUSCODE code);
//ƴ����Ӧͷ�ļ�ֵ
char* GetHeader(char* key, char* value);
//�ж��ļ�����
int JudgeType(char* path);
