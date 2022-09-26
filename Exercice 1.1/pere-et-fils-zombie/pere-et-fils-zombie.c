// Pour compiler: gcc pere-et-fils-zombie.c -o pere-et-fils-zombie
// Pour executer: ./pere-et-fils-zombie

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main (int argc, char* argv[])
{
    pid_t pid = fork();

    if (pid) {
        int status;
        // char* argv_ps[3] = {"ps", "--forest", NULL};
        sleep(3);
        // au moment où parent process arrive ici, le child a déjà terminé son exécution,
        // mais le parent peut toujours voir son pid
        printf("je m'appelle %d et je suis le père de %d\n", getpid(), pid);
        // execv("/bin/ps", argv);
    }
    else {
        printf("je m'appelle %d et je suis le fils de %d\n", getpid(), getppid());
    }
}