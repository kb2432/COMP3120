//it can show microsecond

#include <stdio.h>
#include <sys/time.h>

int main(void)
{
	int i;
	struct timeval t1, t2;

	gettimeofday(&t1, NULL);

	for(i=0; i<99999999; i++)
		rand();

	gettimeofday(&t2, NULL);

	printf("%lf\n", t1.tv_sec + t1.tv_usec*0.000001);
	printf("%lf\n", t2.tv_sec + t2.tv_usec*0.000001);
	printf("%lf\n", (t2.tv_sec+t2.tv_usec*0.000001)-(t1.tv_sec+t1.tv_usec*0.000001));

	return 0;
}
