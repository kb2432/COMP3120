#include <stdio.h>
#include <string.h>

int main()
{
	FILE * fi;
	FILE * fo;

	char input[100] = {0}; 

	fi = fopen("input.txt", "r");
	fo = fopen("output.txt", "w");

	fread(input, 100, 1, fi);
	fwrite(input, strlen(input), 1, fo);
	
	fclose(fi);
	fclose(fo);
}

	
