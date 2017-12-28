#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void *readfile(char *pid)
{
	int i=0, j=0, total=0;
	FILE *f1, *f2;
	char filename[50] = "/proc/", filename2[50] = {0,};
	char fc[2][50] = {0,}, fm[50] = {0,};

	strcat(filename, pid);
	strcat(filename, "/stat");
	strcat(filename2, filename);
	strcat(filename2, "us");

	while(1)
	{
		j=0;		
		f1 = fopen(filename, "r");
	
		for(i=0; i<15; i++)
		{
			fscanf(f1, "%s", fc[j]);
			if(i==13 || i==14) {
				j++;
			}
		}
	
		total = (atoi(fc[0]) + atoi(fc[1]))*100;
		printf("cpu usage time  :  %d\n", total);
	
		f2 = fopen(filename2, "r");  //memory usage
	
		while(1)
		{
			fgets(fm, 50, f2);
			if( strstr(fm, "VmSize")) break;
		}
	
		printf("%s\n", fm);
	
		fclose(f1);
		fclose(f2);

		sleep(2);
	}
}

int main(int argc, char *argv[])
{
	pthread_t *thread;

	if(argc != 2) 
	{
		printf("usage : ./profile <pid>\n");
		return 0;
	}


	pthread_create(&thread, NULL, readfile, argv[1]);
	pthread_join(thread, NULL);
	
	return 0;
}
