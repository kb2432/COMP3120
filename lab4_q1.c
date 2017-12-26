#include <stdio.h>

int main(void)
{
	int x = 100;
	int pid = fork();
	
	if( pid == 0 )
	{
		printf("child process: x=%d\n",x);
		x = 50;
		printf("changed x=%d\n",x);
	}
	else
	{
		wait();
		printf("parent process, pid=%d, x=%d\n", pid,x);
		x = 150;
		printf("changed x=%d\n",x);
	}
}
