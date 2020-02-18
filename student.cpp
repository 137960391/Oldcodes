
/***************************************************************************************************
										   项目名：学生管理系统
											作者：137960391
											版本：1.0
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
int loading=0;                 //用于保存加载界面的数据，当数值达到100时进入菜单页面
int IsLoadingSeccess = 0;
char input;  //定义一个输入符
MYSQL *mysql;          //定义一个数据库变量
int DataBaseIsOk;      //判断数据库是否加载成功
int LoadDateBase();       //数据库连接函数
void head();                   //界面表头
void EnterScreens();           //显示窗口、加载主菜单
void ChoiceMainMenu();             //选择菜单
void ChoiceScoreMenu();       //成绩管理模块菜单
void ChoiceInformationMenu();    //信息管理菜单模块
void AddScore(int i);                //成绩录入模块
void QueryScore();                    //成绩查询模块
void FindMaxScore();                  //查询最高分
void ReturnMenu(int i);                   //返回上级菜单
void gotoxy(int x, int y);     //刷新屏幕、不闪
void HideCursor();             //隐藏光标

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
	mysql = mysql_init(0);  //初始化mysql
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
		printf("\n                                                         数据库正在加载中：loading......%d%%", loading);
	}
	else if (loading >= 100 && loading < 200 && DataBaseIsOk==1)
	{
		printf("\n                                                                  数据库加载完成、欢迎使用 ");
		loading = 200;
		IsLoadingSeccess = 1;
	}
	else if (DataBaseIsOk == 0)
	{
		printf("\n                                                                        数据库加载失败，谢谢使用");
		Sleep(1000);
		exit(0);
	}

	Sleep(1000);
}

void head()
{
	HideCursor();
	gotoxy(0, 0);                //使光标位于（0,0）处，刷新屏幕
	loading = loading + 10 + rand() % 50;           //加载数值
	if (loading > 100 && loading < 200)loading = 100;     //判断加载条件
	else if (loading >= 200)loading = 200;
	//system("cls");
	int minute, hour, year, second, month, day;    //定义年、月、日
	time_t timer;                      //定义一个时间结构time_t
	timer = time(NULL);                //取当前时间数--毫秒
	second = localtime(&timer)->tm_sec;      //localtime 将time_t结构 转换为 tm 结构体
	minute = localtime(&timer)->tm_min;
	hour = localtime(&timer)->tm_hour;
	year = 1900 + localtime(&timer)->tm_year;
	month = 1 + localtime(&timer)->tm_mon;
	day = localtime(&timer)->tm_mday;
	printf("\n\n\n");
	printf("                          ****************************************************************\n");
	printf("                          *                                                              *\n");
	printf("                          *                         学生管理系统                         *\n");
	printf("                          *                                                              *\n");
	printf("                          *                                                              *\n");
	printf("                          *                                   作者：137960391            *\n");
	printf("                          *                                                              *\n");
	printf("                          *                                   版本号：v1.0               *\n");
	printf("                          *                                                              *\n");
	if (second >= 10 && minute >= 10 && hour >= 10)printf("                          *                      当前系统时间：%d年%d月%d日%d:%d:%d    \n", year, month, day, hour, minute, second);
	else if (second < 10 && minute >= 10 && hour >= 10)          printf("                          *                       当前系统时间：%d年%d月%d日 %d:%d:0%d      \n", year, month, day, hour, minute, second);
	else if (second < 10 && minute < 10 && hour >= 10)           printf("                          *                       当前系统时间：%d年%d月%d日 %d:0%d:0%d    \n", year, month, day, hour, minute, second);
	else if (second < 10 && minute < 10 && hour < 10)            printf("                          *                        当前系统时间：%d年%d月%d日 0%d:0%d:0%d   \n", year, month, day, hour, minute, second);
	else if (second >= 10 && minute < 10 && hour >= 10)          printf("                          *                       当前系统时间：%d年%d月%d日 %d:0%d:%d    \n", year, month, day, hour, minute, second);
	else if (second >= 10 && minute >= 10 && hour <10)           printf("                          *                        当前系统时间：%d年%d月%d日 0%d:%d:%d   \n", year, month, day, hour, minute, second);
	else if (second <10 && minute >= 10 && hour <10)             printf("                          *                        当前系统时间：%d年%d月%d日 0%d:%d:0%d   \n", year, month, day, hour, minute, second);
	else if (second >10 && minute < 10 && hour <10)              printf("                          *                        当前系统时间：%d年%d月%d日 0%d:0%d:%d   \n", year, month, day, hour, minute, second);
	printf("                          ****************************************************************\n");
}

void ChoiceMainMenu()
{

	system("cls");
	while (1)
	{
	head();
	printf("\n                                                                                            \n\n");
	printf("                                                       1、  成绩管理   \n\n");
	printf("                                                       2、  信息管理     \n\n");
	printf("                                                       3、  退出系统     \n\n\n\n");
	printf("                                                 请使用数字键1、2、3来选择     \n\n");

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
		printf("                                                       1、  单科成绩录入   \n\n");
		printf("                                                       2、  查找最高分     \n\n");
		printf("                                                       3、  成绩查询    \n\n");
		printf("                                                       4、  两科成绩录入    \n\n");
		printf("                                                       5、  返回    \n\n");
		printf("                                                 请使用数字键1、2、3、4、5来选择     \n\n");
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
		printf("                                                       1、  信息查询   \n\n");
		printf("                                                       2、  删除学生信息记录     \n\n");
		printf("                                                       3、  添加学生信息记录    \n\n");
		printf("                                                       4、  修改学生信息记录    \n\n");
		printf("                                                       5、  返回    \n\n");
		printf("                                                 请使用数字键1、2、3、4、5来选择     \n\n");
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
	int StudentIsExist = 0;  //判断学生是否在数据库中有数据
	while (1)
	{

		if (i == 1)         //如果i=1,则表示单科成绩录入
		{
			head();
			
			printf("\n                                 请输入要录入成绩的学生姓名：\n\n");
			printf("                                                       姓名:");
			scanf("%s", &name);
			printf("\n                                 请输入要录入成绩的学科名字：\n\n");
			printf("                                                       学科:");
			scanf("%s", &subject1);
			printf("\n                                 请输入要录入成绩的学科成绩：\n\n");
			printf("                                                       成绩:");
			scanf("%s", &score1);
			char sqladd[100] = {0};          //sql增加语句
			char sqlupdate[100] = {0};       //sql更新数据语句
			char sqlselect[100] = {0};     //sql查询语句
		
			sprintf(sqladd, "insert into information (姓名,%s) values ('%s','%s')", subject1,name, score1);  //拼接字符串
			sprintf(sqlupdate, "update information set  %s='%s' where 姓名='%s'", subject1, score1,name);
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
					if (!strcmp(name, names)) StudentIsExist = 1;     //name==names比较的是内存地址是否一致，strcmp()比较字符串是否相等
				}
			}
			
			if (StudentIsExist == 1)
			{
				if (mysql_query(mysql, sqlupdate))
				{
					printf("\n\n录入失败，请重新输入:  %s\n,你有两秒时间按esc返回上级目录", mysql_error(mysql)); ReturnMenu(1);
				}
				else
				{
					printf("\n\n录入成功,,你有两秒时间按esc返回上级目录");
					ReturnMenu(1);
				}

			}
			else
			{
				printf("\n\n没有该学生信息，系统将自动加入该学生信息:  ");
				if (mysql_query(mysql, sqladd)){ printf("\n\n录入失败,请重新输入:  %s\n,你有两秒时间按esc返回上级目录", mysql_error(mysql)); ReturnMenu(1); }
				else
				{
					printf("\n\n录入成功,你有两秒时间按esc返回上级目录");
					ReturnMenu(1);
					
				}
			}		
		}

		if (i == 2)
		{
			head();
			printf("\n                                 请输入要录入成绩的学生姓名：\n\n");
			printf("                                                       姓名:");
			scanf("%s", &name);
			printf("\n                              请输入要录入成绩的两个学科名字：\n\n");
			printf("                                                       学科:");
			scanf("%s %s", &subject1,&subject2);
			printf("\n                              请输入要录入成绩的两个学科成绩：\n\n");
			printf("                                                       成绩:");
			scanf("%s %s", &score1,&score2);
			//printf("%s %s %s %s", subject1, score1, subject2, score2);
			char sqladd[100] = { 0 };          //sql增加语句
			char sqlupdate[100] = { 0 };       //sql更新数据语句
			char sqlselect[100] = { 0 };     //sql查询语句

			sprintf(sqladd, "insert into information (姓名,%s，%s) values ('%s','%s','%s')", subject1, subject2, name,score1,score2);  //拼接字符串
			sprintf(sqlupdate, "update information set  %s='%s', %s='%s' where 姓名='%s'", subject1, score1,subject2,score2,name);
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
					if (!strcmp(name, names)) StudentIsExist = 1;     //name==names比较的是内存地址是否一致，strcmp()比较字符串是否相等
				}
			}

			if (StudentIsExist == 1)
			{
				if (mysql_query(mysql, sqlupdate))
				{
					printf("\n\n录入失败，请重新输入:  %s\n,你有两秒时间按esc返回上级目录", mysql_error(mysql)); ReturnMenu(2);
				}
				else
				{
					printf("\n\n录入成功,,你有两秒时间按esc返回上级目录");
					ReturnMenu(2);
				}

			}
			else
			{
				printf("\n\n没有该学生信息，系统将自动加入该学生信息:  ");
				if (mysql_query(mysql, sqladd)){ printf("\n\n录入失败,请重新输入:  %s\n,你有两秒时间按esc返回上级目录", mysql_error(mysql)); ReturnMenu(2); }
				else
				{
					printf("\n\n录入成功,你有两秒时间按esc返回上级目录");
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
		printf("                           姓名       数学      语文       英语 \n");
		//printf("\n                                 请输入要查询成绩的学生姓名：\n\n");
		//printf("                                                       姓名:");
		//scanf("%s", &name);
		char sqlselect[100] = { 0 };     //sql查询语句
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
		

			//if (!strcmp(name, names)) break;     //name==names比较的是内存地址是否一致，strcmp()比较字符串是否相等
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
		printf("\n\n                                  请输入你要查询的最该分科目：");
		scanf("%s",&score);
		char sqlselect[100] = { 0 };     //sql查询语句
		sprintf(sqlselect, "select %s,%s from information","姓名",score);
		if (mysql_query(mysql, sqlselect))
		{
			printf("\n\n查询失败");
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
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
	SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}