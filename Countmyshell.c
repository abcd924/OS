#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>

void count (char c,char *fn)
{
int lc=0,wc=0,cc=0,handle;
char ch;
if((handle=open(fn,O_RDONLY))==-1)
{
printf("file%s not found \n",fn);
return ;

}
while(read(handle,&ch,1)!=0)
{
   if(ch==' ')
      wc++;
   else
         if(ch=='\n')
              lc++;
         else
              cc++;
 }
 close(handle);
 switch(c)
 {
       
       case'c':
           printf("total no. of character=%d\n",cc);
           break;
           
       case'w':
          printf("total no. of words=%d\n",wc);
          break;
          
        case'l':
          printf("total no. of lines=%d\n",lc);
          break; 
          
   
}
}

int main()
{
char command[80],t1[20],t2[20],t3[20],t4[20];
char n;

system("clear");

while(1)
{
 printf("MYshell$");
 fflush(stdin);
 fgets(command,80,stdin);
 
 n=sscanf(command,"%s%s%s%s",t1,t2,t3,t4);
 
 switch(n)
    {
          case 1:
              if(!fork())
          {
               execlp(t1,NULL);
               perror(t1);
           }
           break;
       
          case 2:
             if(!fork())
          {
              execlp(t1,t2,NULL);
              perror(t1);
          }
          break;  
       
        case 3:
            if(strcmp(t1,"count")==0)
              count(t2[0],t3);
          else
          {
           if(!fork())
            {
              execlp(t1,t2,t3,NULL);
              
            }
          }
          break;
        case 4:
             if(!fork())
             {
               execlp(t1,t2,t3,t4,NULL);
               perror(t1);
               }
               
       case 5:
            if(strcmp(t1,"q")==0)
            {
              exit(0);
             }
       case 0: exit(0);
       }
      }
 
 
 
}




