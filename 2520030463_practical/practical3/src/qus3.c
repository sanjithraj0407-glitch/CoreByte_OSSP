#include<stdio.h>
#include<unistd.h>
int main()
{
int pid;
pid = fork();
if(pid < 0)
{
printf("Fork failed\n");
}
else if(pid == 0)
{
printf("Child Process\n");
printf("PID: %d\n", getpid());
printf("PPID: %d\n", getppid());
printf("State: Running\n");
sleep(20);
printf("Child process completed\n");
}
else
{
printf("Parent Process\n");
printf("PID: %d\n", getpid());
printf("PPID: %d\n", getppid());
printf("Child PID: %d\n", pid);
printf("State: Running\n");
sleep(20);
}
return 0;
}