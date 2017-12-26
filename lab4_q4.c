#include <stdio.h>
#include <unistd.h>

int main()
{
	char *s[] = {"ls", NULL};
	int pid = fork();
	
	if(pid == 0)
	{
		printf("exec ls\n");
		execvp("ls", s);
		printf("bye~\n");
	}
	else
	{
		wait();
	}

	return 0;
}
