//both child and parent access file descriptor and write

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int x, pid;

	x = open("file.txt", O_CREAT|O_RDWR, 00777);
	
	pid = fork();

	if( pid == 0 )
	{
		write(x, "child writing...\n", 17);
	}
	else
	{
		write(x, "parent writing...\n", 18);
	}

	return 0;
}
