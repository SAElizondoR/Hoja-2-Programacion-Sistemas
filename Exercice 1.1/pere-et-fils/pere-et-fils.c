// Pour compiler: gcc pere-et-fils.c -o pere-et-fils
// Pour executer: ./pere-et-fils

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main (int argc, char* argv[])
{
    pid_t pid = fork();

    if (pid) {
        int status;
        wait (&status);
        printf("je m'appelle %d et je suis le père de %d\n", getpid(), pid);
    }
    else {
        printf("je m'appelle %d et je suis le fils de %d\n", getpid(), getppid());
    }
}