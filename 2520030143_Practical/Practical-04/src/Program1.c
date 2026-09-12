#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
int pid;
pid=fork();
if(pid==0)
{
printf("child process %d\n",getpid());
exit(0);
}
else
{
printf("parent process %d\n",getpid());
sleep(30);
//wait(NULL);// collecting the status of the child 
printf("parent process completed\n");
}
}

