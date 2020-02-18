
/***************************************************************************************************
										   ��Ŀ����ѧ������ϵͳ
											���ߣ�137960391
											�汾��1.0
***************************************************************************************************/

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <mysql.h>
#include <string.h>
#include <math.h>
#pragma comment(lib, "libmysql.lib")
int loading=0;                 //���ڱ�����ؽ�������ݣ�����ֵ�ﵽ100ʱ����˵�ҳ��
int IsLoadingSeccess = 0;
char input;  //����һ�������
MYSQL *mysql;          //����һ�����ݿ����
int DataBaseIsOk;      //�ж����ݿ��Ƿ���سɹ�
int LoadDateBase();       //���ݿ����Ӻ���
void head();                   //�����ͷ
void EnterScreens();           //��ʾ���ڡ��������˵�
void ChoiceMainMenu();             //ѡ��˵�
void ChoiceScoreMenu();       //�ɼ�����ģ��˵�
void ChoiceInformationMenu();    //��Ϣ����˵�ģ��
void AddScore(int i);                //�ɼ�¼��ģ��
void QueryScore();                    //�ɼ���ѯģ��
void FindMaxScore();                  //��ѯ��߷�
void ReturnMenu(int i);                   //�����ϼ��˵�
void gotoxy(int x, int y);     //ˢ����Ļ������
void HideCursor();             //���ع��

int main()
{
	DataBaseIsOk= LoadDateBase();
	srand(time(NULL));
	while (1)
	{
		if(IsLoadingSeccess==0)EnterScreens();
		else ChoiceMainMenu();
		
	}
	getchar();
	return 0;

}

int LoadDateBase()
{
	mysql = mysql_init(0);  //��ʼ��mysql
	if (!mysql_real_connect(mysql, "localhost", "137960391", "dh19941004", "studentinformationmanage", 0, 0,0)) return 0;
	else
	{
		mysql_set_character_set(mysql, "gbk");
		return 1;
	}
}

void EnterScreens()
{
	head();
	if (loading < 100)
	{
		printf("\n                                                         ���ݿ����ڼ����У�loading......%d%%", loading);
	}
	else if (loading >= 100 && loading < 200 && DataBaseIsOk==1)
	{
		printf("\n                                                                  ���ݿ������ɡ���ӭʹ�� ");
		loading = 200;
		IsLoadingSeccess = 1;
	}
	else if (DataBaseIsOk == 0)
	{
		printf("\n                                                                        ���ݿ����ʧ�ܣ�ллʹ��");
		Sleep(1000);
		exit(0);
	}

	Sleep(1000);
}

void head()
{
	HideCursor();
	gotoxy(0, 0);                //ʹ���λ�ڣ�0,0������ˢ����Ļ
	loading = loading + 10 + rand() % 50;           //������ֵ
	if (loading > 100 && loading < 200)loading = 100;     //�жϼ�������
	else if (loading >= 200)loading = 200;
	//system("cls");
	int minute, hour, year, second, month, day;    //�����ꡢ�¡���
	time_t timer;                      //����һ��ʱ��ṹtime_t
	timer = time(NULL);                //ȡ��ǰʱ����--����
	second = localtime(&timer)->tm_sec;      //localtime ��time_t�ṹ ת��Ϊ tm �ṹ��
	minute = localtime(&timer)->tm_min;
	hour = localtime(&timer)->tm_hour;
	year = 1900 + localtime(&timer)->tm_year;
	month = 1 + localtime(&timer)->tm_mon;
	day = localtime(&timer)->tm_mday;
	printf("\n\n\n");
	printf("                          ****************************************************************\n");
	printf("                          *                                                              *\n");
	printf("                          *                         ѧ������ϵͳ                         *\n");
	printf("                          *                                                              *\n");
	printf("                          *                                                              *\n");
	printf("                          *                                   ���ߣ�137960391            *\n");
	printf("                          *                                                              *\n");
	printf("                          *                                   �汾�ţ�v1.0               *\n");
	printf("                          *                                                              *\n");
	if (second >= 10 && minute >= 10 && hour >= 10)printf("                          *                      ��ǰϵͳʱ�䣺%d��%d��%d��%d:%d:%d    \n", year, month, day, hour, minute, second);
	else if (second < 10 && minute >= 10 && hour >= 10)          printf("                          *                       ��ǰϵͳʱ�䣺%d��%d��%d�� %d:%d:0%d      \n", year, month, day, hour, minute, second);
	else if (second < 10 && minute < 10 && hour >= 10)           printf("                          *                       ��ǰϵͳʱ�䣺%d��%d��%d�� %d:0%d:0%d    \n", year, month, day, hour, minute, second);
	else if (second < 10 && minute < 10 && hour < 10)            printf("                          *                        ��ǰϵͳʱ�䣺%d��%d��%d�� 0%d:0%d:0%d   \n", year, month, day, hour, minute, second);
	else if (second >= 10 && minute < 10 && hour >= 10)          printf("                          *                       ��ǰϵͳʱ�䣺%d��%d��%d�� %d:0%d:%d    \n", year, month, day, hour, minute, second);
	else if (second >= 10 && minute >= 10 && hour <10)           printf("                          *                        ��ǰϵͳʱ�䣺%d��%d��%d�� 0%d:%d:%d   \n", year, month, day, hour, minute, second);
	else if (second <10 && minute >= 10 && hour <10)             printf("                          *                        ��ǰϵͳʱ�䣺%d��%d��%d�� 0%d:%d:0%d   \n", year, month, day, hour, minute, second);
	else if (second >10 && minute < 10 && hour <10)              printf("                          *                        ��ǰϵͳʱ�䣺%d��%d��%d�� 0%d:0%d:%d   \n", year, month, day, hour, minute, second);
	printf("                          ****************************************************************\n");
}

void ChoiceMainMenu()
{

	system("cls");
	while (1)
	{
	head();
	printf("\n                                                                                            \n\n");
	printf("                                                       1��  �ɼ�����   \n\n");
	printf("                                                       2��  ��Ϣ����     \n\n");
	printf("                                                       3��  �˳�ϵͳ     \n\n\n\n");
	printf("                                                 ��ʹ�����ּ�1��2��3��ѡ��     \n\n");

		if (kbhit())
	   {
		input = getch();
		if (input == 49)
		{
			ChoiceScoreMenu(); break;
		}
		else if (input == 50)
		{	
			ChoiceInformationMenu();
			break;
		}
		else if (input==51) exit(0);

		}
	}

}

void ChoiceScoreMenu()
{
	system("cls");
	while (1)
	{

		head();
		//printf("\n                                                                                 ");
		printf("\n                                                                                 \n");
		//printf("\n                                                                                            \n");
		printf("                                                       1��  ���Ƴɼ�¼��   \n\n");
		printf("                                                       2��  ������߷�     \n\n");
		printf("                                                       3��  �ɼ���ѯ    \n\n");
		printf("                                                       4��  ���Ƴɼ�¼��    \n\n");
		printf("                                                       5��  ����    \n\n");
		printf("                                                 ��ʹ�����ּ�1��2��3��4��5��ѡ��     \n\n");
		if (kbhit())
		{
			input = getch();
			if (input == 53) ChoiceMainMenu();
			else if(input == 49) AddScore(1);
			else if (input == 51) QueryScore();
			else if (input == 52)AddScore(2);
			else if (input == 50)FindMaxScore();

		}
		
	}
}

void ChoiceInformationMenu()
{
	system("cls");
	while (1)
	{

		head();
		//printf("\n                                                                                 ");
		printf("\n                                                                                 \n");
		//printf("\n                                                                                            \n");
		printf("                                                       1��  ��Ϣ��ѯ   \n\n");
		printf("                                                       2��  ɾ��ѧ����Ϣ��¼     \n\n");
		printf("                                                       3��  ���ѧ����Ϣ��¼    \n\n");
		printf("                                                       4��  �޸�ѧ����Ϣ��¼    \n\n");
		printf("                                                       5��  ����    \n\n");
		printf("                                                 ��ʹ�����ּ�1��2��3��4��5��ѡ��     \n\n");
		if (kbhit())
		{
			input = getch();
			if (input == 53) ChoiceMainMenu();
			else if (input == 51)break;

       
		}

	}
}

void AddStudentsInformation()
{
	
}

void AddScore(int i)
{
	system("cls");
	char name[20] = {0};
	char subject1[20] = {0};
	char subject2[20] = { 0 };
	char score1[20] = {0};
	char score2[20] = { 0 };
	int StudentIsExist = 0;  //�ж�ѧ���Ƿ������ݿ���������
	while (1)
	{

		if (i == 1)         //���i=1,���ʾ���Ƴɼ�¼��
		{
			head();
			
			printf("\n                                 ������Ҫ¼��ɼ���ѧ��������\n\n");
			printf("                                                       ����:");
			scanf("%s", &name);
			printf("\n                                 ������Ҫ¼��ɼ���ѧ�����֣�\n\n");
			printf("                                                       ѧ��:");
			scanf("%s", &subject1);
			printf("\n                                 ������Ҫ¼��ɼ���ѧ�Ƴɼ���\n\n");
			printf("                                                       �ɼ�:");
			scanf("%s", &score1);
			char sqladd[100] = {0};          //sql�������
			char sqlupdate[100] = {0};       //sql�����������
			char sqlselect[100] = {0};     //sql��ѯ���
		
			sprintf(sqladd, "insert into information (����,%s) values ('%s','%s')", subject1,name, score1);  //ƴ���ַ���
			sprintf(sqlupdate, "update information set  %s='%s' where ����='%s'", subject1, score1,name);
			sprintf(sqlselect,"select * from information");
			
			if (mysql_query(mysql, sqlselect))
			{
				printf("%s", mysql_error(mysql));
			}
			else
			{
				MYSQL_RES *result = mysql_store_result(mysql);
				MYSQL_ROW row;
				while (row = mysql_fetch_row(result))
				{
					char *names=row[1];
					if (!strcmp(name, names)) StudentIsExist = 1;     //name==names�Ƚϵ����ڴ��ַ�Ƿ�һ�£�strcmp()�Ƚ��ַ����Ƿ����
				}
			}
			
			if (StudentIsExist == 1)
			{
				if (mysql_query(mysql, sqlupdate))
				{
					printf("\n\n¼��ʧ�ܣ�����������:  %s\n,��������ʱ�䰴esc�����ϼ�Ŀ¼", mysql_error(mysql)); ReturnMenu(1);
				}
				else
				{
					printf("\n\n¼��ɹ�,,��������ʱ�䰴esc�����ϼ�Ŀ¼");
					ReturnMenu(1);
				}

			}
			else
			{
				printf("\n\nû�и�ѧ����Ϣ��ϵͳ���Զ������ѧ����Ϣ:  ");
				if (mysql_query(mysql, sqladd)){ printf("\n\n¼��ʧ��,����������:  %s\n,��������ʱ�䰴esc�����ϼ�Ŀ¼", mysql_error(mysql)); ReturnMenu(1); }
				else
				{
					printf("\n\n¼��ɹ�,��������ʱ�䰴esc�����ϼ�Ŀ¼");
					ReturnMenu(1);
					
				}
			}		
		}

		if (i == 2)
		{
			head();
			printf("\n                                 ������Ҫ¼��ɼ���ѧ��������\n\n");
			printf("                                                       ����:");
			scanf("%s", &name);
			printf("\n                              ������Ҫ¼��ɼ�������ѧ�����֣�\n\n");
			printf("                                                       ѧ��:");
			scanf("%s %s", &subject1,&subject2);
			printf("\n                              ������Ҫ¼��ɼ�������ѧ�Ƴɼ���\n\n");
			printf("                                                       �ɼ�:");
			scanf("%s %s", &score1,&score2);
			//printf("%s %s %s %s", subject1, score1, subject2, score2);
			char sqladd[100] = { 0 };          //sql�������
			char sqlupdate[100] = { 0 };       //sql�����������
			char sqlselect[100] = { 0 };     //sql��ѯ���

			sprintf(sqladd, "insert into information (����,%s��%s) values ('%s','%s','%s')", subject1, subject2, name,score1,score2);  //ƴ���ַ���
			sprintf(sqlupdate, "update information set  %s='%s', %s='%s' where ����='%s'", subject1, score1,subject2,score2,name);
			printf("%s", sqlupdate);
			sprintf(sqlselect, "select * from information");
			if (mysql_query(mysql, sqlselect))
			{
				printf("%s", mysql_error(mysql));
			}
			else
			{
				MYSQL_RES *result = mysql_store_result(mysql);
				MYSQL_ROW row;
				while (row = mysql_fetch_row(result))
				{
					char *names = row[1];
					if (!strcmp(name, names)) StudentIsExist = 1;     //name==names�Ƚϵ����ڴ��ַ�Ƿ�һ�£�strcmp()�Ƚ��ַ����Ƿ����
				}
			}

			if (StudentIsExist == 1)
			{
				if (mysql_query(mysql, sqlupdate))
				{
					printf("\n\n¼��ʧ�ܣ�����������:  %s\n,��������ʱ�䰴esc�����ϼ�Ŀ¼", mysql_error(mysql)); ReturnMenu(2);
				}
				else
				{
					printf("\n\n¼��ɹ�,,��������ʱ�䰴esc�����ϼ�Ŀ¼");
					ReturnMenu(2);
				}

			}
			else
			{
				printf("\n\nû�и�ѧ����Ϣ��ϵͳ���Զ������ѧ����Ϣ:  ");
				if (mysql_query(mysql, sqladd)){ printf("\n\n¼��ʧ��,����������:  %s\n,��������ʱ�䰴esc�����ϼ�Ŀ¼", mysql_error(mysql)); ReturnMenu(2); }
				else
				{
					printf("\n\n¼��ɹ�,��������ʱ�䰴esc�����ϼ�Ŀ¼");
					ReturnMenu(2);

				}
			}

		}
	}
}


void QueryScore()
{
	char name[20] = { 0 };
	system("cls");
	while (1)
	{
		gotoxy(0,0);
		head();
		printf("                           ����       ��ѧ      ����       Ӣ�� \n");
		//printf("\n                                 ������Ҫ��ѯ�ɼ���ѧ��������\n\n");
		//printf("                                                       ����:");
		//scanf("%s", &name);
		char sqlselect[100] = { 0 };     //sql��ѯ���
		sprintf(sqlselect, "select * from information");
		if (mysql_query(mysql, sqlselect))
		{
			printf("%s", mysql_error(mysql));
		}
		else
		{
			MYSQL_RES *result = mysql_store_result(mysql);
			MYSQL_ROW row;
			while (row = mysql_fetch_row(result))
			{
			char temp = 0;
			char *name = row[1];
			char *math= row[7];
			char *chinese = row[8];
			char *english = row[9];
			if (!name) { name = &temp; }
			if (!math) { math = &temp; }
			if (!chinese) { chinese = &temp; }
			if (!english) { english = &temp; }
		

			//if (!strcmp(name, names)) break;     //name==names�Ƚϵ����ڴ��ַ�Ƿ�һ�£�strcmp()�Ƚ��ַ����Ƿ����
			char result[100];
			sprintf(result,"                           %4s       %3s        %3s       %3s \n",name,math,chinese,english);
			printf("%s", result);
			}
		}
		if (kbhit())
		{
			char inputesc;
			inputesc = getch();
			if (inputesc == 27) ChoiceScoreMenu();
		}
	}
} 

void FindMaxScore()
{
	system("cls");
	char score[10] = { 0 };
	int tempnum=0;
	int tempscore=0;
	while (1)
	{
		head();
		printf("\n\n                                  ��������Ҫ��ѯ����÷ֿ�Ŀ��");
		scanf("%s",&score);
		char sqlselect[100] = { 0 };     //sql��ѯ���
		sprintf(sqlselect, "select %s,%s from information","����",score);
		if (mysql_query(mysql, sqlselect))
		{
			printf("\n\n��ѯʧ��");
		}
		else
		{
			MYSQL_RES *result;
			MYSQL_ROW row;
			result = mysql_store_result(mysql);
			while (row = mysql_fetch_row(result))
			{
				char *name = row[0];
				char *subject = row[1];
				tempscore = (int)subject;
				tempnum++;
				printf("%s\n", tempscore);
				
			}
		}
	


	}

	
}

void ReturnMenu(int i)
{
	Sleep(2000);
	if (kbhit())
	{
		char inputesc;
		inputesc = getch();
		if (inputesc == 27) ChoiceScoreMenu();
	}
	AddScore(i);

}
void gotoxy(int x, int y) {
	COORD pos = { x, y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
	SetConsoleCursorPosition(hOut, pos);//���������ֱ���ָ���ĸ����壬����λ��
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}