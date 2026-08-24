#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

pid_t pid;
printf("Parent process started.\n");
printf("Parent PID: %d\n", getpid());
pid = fork();
if (pid < 0)
{
perror("fork failed");
return 1;
}
if (pid == 0)
{
printf("\nChild process created.\n");
printf("Child PID: %d\n", getpid());
printf("Parent PID from child: %d\n", getppid());
printf("Child executing 'ls' using exec().\n");
execlp("ls", "ls", "-l", NULL);
perror("exec failed");
exit(1);
}
else
{
printf("\nParent waiting for child...\n");
wait(NULL);
printf("Child process completed.\n");
printf("Parent process exiting.\n");
}
return 0;
}