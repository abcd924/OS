#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
      pid_t  p1,p2;
      p1=fork();
      if(p1==-1)
      {
            perror("Child Process Not create.");
       }
       else if(p1==0)
       {
            printf("Child Process : \n");
            printf("Child Id : %d\n ",getpid());
            printf("Parent Id : %d\n",getppid());
        }
        else
        {
            sleep(1);
            //wait(NULL);
            printf("Parent Processs : \n");
            printf("Parent Id : %d\n",getpid());
            printf("Child Id : %d\n",p1);
        }
        
        
        return 0;
}
         
