#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int  main()
{
      pid_t pid;
      pid=fork();
    //  printf("before System call fork() : %d\n",pid);
      
      if(pid>0)
      {
            printf("Parent Process  : "); 
            printf("Parent Id  : %d ",getpid()); 
      }
      else if(pid==0)
      {
                  printf("Child Process   :   \n " );
                  printf("Child id :  %d ",getpid());
                  printf("parent Id  :  %d",getppid());
                  
       }
       else
       {
            printf("faled To Create Child...");
       }   
      return 0;
}
