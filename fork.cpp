
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    printf("--beginning of program\n");
    int counter = 0;
    pid_t pid = fork();
    if (pid == 0)
    { printf("i am child \n");
    int x=   execlp ("bin/ls", "ls", "-l", (char *)0);
      printf("values of  x is %d",x);
    }
    else if (pid > 0)
    {
        // parent process
        int j = 0;
        for (; j < 5; ++j)
        {
            printf("parent process: counter=%d\n", ++counter);
        }
    }
    else
    {
        // fork failed
        printf("fork() failed!\n");
        return 1;
    }
    printf("--end of program--\n");
    return 0;
}
