//as the number of threads or threshold increase, it takes more time

#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>

int count = 0;

pthread_mutex_t counter_lock = PTHREAD_MUTEX_INITIALIZER;

void *counter()
{
	pthread_mutex_lock(&counter_lock);
	for(;count<1000000; count++);
	pthread_mutex_unlock(&counter_lock);
}

int main()
{
	struct timeval start, end;
	double gap;
	int count = 0, th_cnt = 10000, i;
	pthread_t *thread;

	thread = (pthread_t*)malloc(sizeof(pthread_t)*th_cnt);
	
	gettimeofday(&start, NULL);
	for(i=0; i<th_cnt; i++)
	{
		pthread_create(&thread[i], NULL, counter, NULL);
		pthread_join(thread[i], NULL);
	}
	gettimeofday(&end, NULL);

	gap = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec)*0.000001;

	printf("thread : %d, time : %lf\n", th_cnt, gap);

	return 0;
}
