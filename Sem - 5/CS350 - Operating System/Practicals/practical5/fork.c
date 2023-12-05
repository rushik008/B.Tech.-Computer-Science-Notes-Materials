
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  
    // make two process which run same
    // program after this instruction
    printf("Calling fork() to create child process\n");
    printf("Made by : 20DCS102\n");
    int pid;
    pid = fork();
  
     if (pid == 0)
    {
        printf ( "\nParent Process id : %d \n",getpid() );
        printf ( "\nChild Process with parent id : %d\n", getppid() );
    }    
    return 0;
}
