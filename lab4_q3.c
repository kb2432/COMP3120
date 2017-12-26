//instead wait, use sleep or for loop

#include <stdio.h>
#include <unistd.h>

int main()
{
	int x = 0;
	int pid = fork();

	if(pid == 0)
	{
		printf("child say : hello\n");
	//	for(x=0; x<10000000; x++);
	}
	else
	{
		sleep(1);		
		printf("parent say : goodbye\n");
	}

	return 0;
}
