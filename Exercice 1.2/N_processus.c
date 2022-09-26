// Pour compiler: gcc N_processus.c -o N_processus
// Pour executer: ./N_processus [N]

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main (int argc, char* argv[])
{
    int N = atoi(argv[1]);

    for (int i = 0; i < N; i++)
        if (fork() == 0) {
            printf("%d\n", i);
            exit(0);
        }
    
    for (int i = 0; i < N; i++)
        wait(NULL);
}