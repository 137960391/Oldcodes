#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <process.h>
#include <pthread.h>
#pragma comment(lib,"pthreadVC2.lib")
typedef struct sum
{
	int id;
	long s[2];
	int first;
	int end;
	char flag[124];
}SUM;

void* fun(void *p)
{
	SUM *id = (SUM *)p;
	
	for (int i = id->first+1; i <= id->end; i++)
	{
		id->s[id->id] += (long)i;
	}
	printf("线程%s,%d得到数据%ld\n", id->flag,id->id + 1, id->s[id->id]);
	return NULL;
}
int main()
{
	SUM num = {0};
	for (int i = 0; i < 2; i++)
	{
		
		num.first = i * 2500;
		num.end = (i + 1) * 2500;
		num.id = i ;
		memcpy(num.flag, "_beginthread", strlen("_beginthread"));
		_beginthread((void *)fun, 0, &num);
		Sleep(30);
		pthread_t pth;
		memset(num.flag, 0, 124);
		memcpy(num.flag, "pthread_create", strlen("pthread_create"));
		pthread_create(&pth, 0, fun, &num);
		Sleep(30);
	}
	Sleep(30);
	printf("线程1+线程2得到数据%ld\n", num.s[0] + num.s[1]);
#ifdef _WIN32
	//system("pause");
#endif
	return 0;
}