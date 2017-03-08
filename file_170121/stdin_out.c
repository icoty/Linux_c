#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
	char szBuf[100],szBuf2[100];
	printf("Input string:");
	fflush(stdout); //要刷新标准输出流，才可以立即在屏幕上显示”Input string”
	//fflush 用于linux 中的时候，只对fflush(stdout)有效。
	int iRet=read(STDIN_FILENO,szBuf,sizeof(szBuf));
	szBuf[iRet]=0; //read 是以无类型指针方式读的数据，不会自动在缓冲区后加0 结束标记。
	sprintf(szBuf2,"The string is:%s\n",szBuf);
	puts(szBuf2);
	write(STDOUT_FILENO,szBuf2,strlen(szBuf2));
	puts(szBuf2);
	return 0;
}

