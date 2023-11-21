#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int  main()
{
      pid_t pid;
      pid=fork();
      printf("before System call fork() : %d\n",pid);
      
      if(pid<0)
      {
            perror("Child Not create  \n");
      }
      else if(pid==0)
      {
      sleep(3);
            printf("After fork() : %d pid and %d ppid .\n",getpid(),getppid());
       }
       else
       {
            
            printf("Parent Process : %d pid and %d ppid .\n",getpid(),getppid());
       }   
      return 0;
}
