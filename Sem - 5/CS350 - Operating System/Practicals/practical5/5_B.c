#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	printf("step before execl call\n");
	execl("/bin/ps", "ps", NULL);
	printf("step after execl call");
    return 0;
}

