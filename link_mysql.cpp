#include <stdio.h>
#include <windows.h>
#include <mysql.h>
#pragma comment (lib,"libmysql.lib")

void insert();
MYSQL *mysql;
void main()
{
	MYSQL *mysql = mysql_init(0);
	if (!mysql_real_connect(mysql, "localhost", "137960391", "dh19941004", "studentsinf", 0, 0, 0))
	{
		printf("����ʧ��%s\n",mysql_error(mysql));
		mysql_close(mysql);
	}
	else
	{
		printf("���ӳɹ�\n");
		mysql_set_character_set(mysql, "gbk");
	}

	if (mysql_query(mysql, "insert into StudentsInformation (�ɼ�) values ('100')"))
	{
		printf("����ʧ�ܣ�%s", mysql_error(mysql));
	}
	else
	{
		printf(" ");
	}

	getchar();
}

void insert()
{
	if (mysql_query(mysql, "insert into StudentsInformation (name,num) values ('����','108')"))
	{
		printf("����ʧ�ܣ�%s", mysql_error(mysql));
	}
	else
	{
		printf("����ɹ�");
	}
}