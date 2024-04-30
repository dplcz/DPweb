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
//��ȡ����
ClientSolver* GetTask(ThreadPool* pool,int block);
//��������
int PutTask(ThreadPool* pool, ClientSolver* task, int block);
//��ȡ�߳�
Thread* GetThread(ThreadPool* pool);
//��ȡ���г���
int TaskLength(TaskQueue* queue);
//��ʼ���̳߳�
void InitThreadPool(ThreadPool* pool);
//��ʼ���̳߳�
void InitThread(TaskQueue* queue);
//�̼߳���
int GetThreadLock(ThreadLock* lock, int block);
//�߳̽���
int ReleaseThreadLock(ThreadLock* lock, int USER);
