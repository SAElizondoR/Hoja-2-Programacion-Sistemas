// Pour compiler: gcc pere-et-fils-orphelin.c -o pere-et-fils-orphelin
// Pour executer: ./pere-et-fils-orphelin

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main (int argc, char* argv[])
{
    pid_t pid = fork();

    if (pid) {
        int status;
        printf("je m'appelle %d et je suis le père de %d\n", getpid(), pid);
    }
    else {
        sleep(3);
        // au moment où child process arrive ici, le parent a déjà terminé son exécution
        printf("je m'appelle %d et je suis le fils de %d\n", getpid(), getppid());
    }
}