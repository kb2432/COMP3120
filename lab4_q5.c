//wait() returns -1, wait() in child : parent->child execute

#include <stdio.h>
#include <unistd.h>

int main()
{
	int pid = fork();

	if(pid == 0)
	{
//		printf("child\n");
		printf("child, wait return %d\n", wait());
	}
	else
	{
		printf("parent\n");
		//printf("parent wait return %d\n", wait());
	}

	return 0;
}
