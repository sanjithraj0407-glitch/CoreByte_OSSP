#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>// used for wait() and waitpid() system calls 
#include<stdlib.h> // used for exit() systemcall 
int main()
{
int pid[3];// array of 3 for childs of 3 (initalizing)
for(int i=0; i<3; i++) // loop which runs for 3 childs 
{
pid[i]=fork(); // creating 3 childs 
if(pid[i]==0) // indicates a child proces 
{
printf("child %d pid=%d\n",i+1,getpid()); // want to print 1 , 2 , 3... so on
sleep(i+1); // giving a pause after every child 
exit(0); // exiting the standard input 
}
}
wait(NULL); // waiting for any one child 
printf("Parent :  one child is completed with wait()\n");
waitpid(pid[2],NULL,0); // waiting for specfic child delcare in pid 
printf("parent : child 3 has completed with waitpid()\n");
wait(NULL); // waitng for all childs  which are remaining 
printf("parent: all the childs are completed\n");
}

