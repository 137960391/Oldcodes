#include <stdio.h>
#include <stdlib.h>
int main()
{

	FILE* pf=fopen("C:\\Users\\lenovo\\Desktop\\bing.jpg","rb");
	FILE* destpf = fopen("C:\\Users\\lenovo\\Desktop\\1.jpg", "wb");
	char buff[1024] = { 0 };
	int num;
	//fseek(pf, 0, SEEK_END);
	//long a=ftell(pf);
	//fgets(buff, 1024, pf);
	rewind(pf);
	while (!feof(pf))
	{
		num=fread(buff, 1,1024, pf);
		fwrite(buff,1, num, destpf);
	}
	//fwrite("123", 1, 3, destpf);
	fclose(pf);
	fclose(destpf);
	system("pause");
	return 0;
}