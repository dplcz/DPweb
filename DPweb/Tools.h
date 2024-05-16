#pragma once
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
ClientSolver* GetTask(MyThreadPool* pool,int block);
//��������
int PutTask(MyThreadPool* pool, ClientSolver* task, int block);
//��ȡ�߳�
ThreadTask* GetThread(MyThreadPool* pool);
//��ȡ���г���
int TaskLength(TaskQueue* queue);
//�����߳�
MyThread CreateMyThread(thread_func_t func, void* args);
//��ʼ���̳߳�
void InitThreadPool(MyThreadPool* pool, APP* app, thread_func_t func, ThreadArgs* args);
//��ʼ���߳�
void InitThread(ThreadTask* thread, int threadId);
//�̼߳���
//int GetThreadLock(ThreadLock* lock, int block);
//�߳̽���
//int ReleaseThreadLock(ThreadLock* lock, int USER);
//��ʾ�߳�״̬
void ShowThreadStatus(MyThreadPool pool);
//�����ź���
void WaitSemaphore(Sem sem);
//�ͷ��ź���
void PostSemaphore(Sem sem);
