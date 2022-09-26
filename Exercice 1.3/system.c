// Pour compiler: gcc system.c -o system
// Pour executer: ./system [commande]


#include <sys/wait.h>
#include <unistd.h>


int System(char *command) {
    if (fork() == 0) {
        char* args[] = {command, NULL};
        execv(command, args);
        return -1;
    }
    else {
        int status;
        wait(&status);
        write(STDOUT_FILENO, "Bonjour\n", 8);
        return WEXITSTATUS(status);
    }
}


int main (int argc, char* argv[])
{
    return System(argv[1]);
}