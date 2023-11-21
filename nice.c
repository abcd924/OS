#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int  main()
{
      pid_t pid;
      int retnice;
      pid=fork();
      
      if(pid<0)
      {
            printf("Child  Not Create.....");
      }
      
      else if(pid==0)
      { 
            retnice=nice(5);
            printf("Child Prcess : \n");
            printf("Higher CPU priority : %d\n",retnice);
            printf("Child Id   : %d",getpid());
            sleep(2);
      }
      
      else
      {   
            retnice=nice(4);
            printf("Parent Process  :  \n");
            printf("Lower Cpu Priority :%d \n",retnice);
            printf("Parent Id : %d\n",getpid());
            sleep(2);
       }
       
       return 0;
}



            
