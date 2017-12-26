#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int pid;
	int pipe1[2], pipe2[2];
	char str[20] = "lab4 q6";
	char buf[20] = {0, };

	if( pipe(pipe1) == -1) {printf("error pipe1\n");}
	if( pipe(pipe2) == -1) {printf("error pipe2\n");}

	close(pipe2[1]);
	dup2(pipe1[0], pipe2[0]);
	close(pipe1[0]);
	
	if( (pid=fork()) == 0 )
	{
		write(pipe1[1], str, 20);
		printf("input : %s\n", str);
	}
	else
	{
		wait();
		pid = fork();
		if( pid == 0 )
		{
			read(pipe2[0], &buf, 20);
			printf("output : %s\n", buf);
		}
		else
		{
			wait();
		}
	}

	return 0;
}
