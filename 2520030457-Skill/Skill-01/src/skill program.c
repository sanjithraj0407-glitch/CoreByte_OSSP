#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
int pid;
pid = fork();
if (pid == 0)
    {
        printf("Child process\n");
        printf("Current PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        execl("/bin/ls", "ls", "-l", NULL);

        printf("Exec failed\n");
    }
else if (pid > 0)
    {
        printf("Parent process\n");
        printf("Child PID: %d\n", pid);
        printf("Parent PID: %d\n", getpid());

        wait(NULL);
        printf("Child process completed\n");
    }
else
    {
        printf("Fork failed\n");
    }

    return 0;
}
