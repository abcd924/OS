#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

void search(char ch,char* pattern,char fname[])
{
    
    char c;
    char *arg;
    int handle;
    int cnt=0,lc=1;
    handle = open(fname,O_RDONLY);
    if(handle==-1)
    {
        printf("File Cant Open");
        return;
    }

    switch(ch)
    {
    case 'f':
        lc=1;
        while(read(handle,&c,1)!=0)
        {
           if(c=='\n')
           {
             
             arg[cnt]='\0';
             cnt=0;
            if(strstr(arg,pattern)!=NULL)
            {
                 printf("Line %d -> %s\n",lc,arg);
                 break;
            }
             lc++;
           }
           else
           {
             arg[cnt++]=c;
           }
        }
        break;

   case 'a':
        lc=1;
        while(read(handle,&c,1)!=0)
        {
           if(c=='\n')
           {
             
             arg[cnt]='\0';
             cnt=0;
            if(strstr(arg,pattern)!=NULL)
            {
                 printf("Line %d -> %s\n",lc,arg);
                
            }
             lc++;
           }
           else
           {
             arg[cnt++]=c;
           }
        }
        break;

    case 'c':
        lc=1;
        int count=0;
        while(read(handle,&c,1)!=0)
        {
           if(c=='\n')
           {
             
             arg[cnt]='\0';
             cnt=0;
            if(strstr(arg,pattern)!=NULL)
            {
                count++;
            }
             lc++;
           }
           else
           {
             arg[cnt++]=c;
           }
        }
        printf("Total %d Times Present the Word...\n",count);
    break;

    }

}

int main()
{
    char cmd[80];
    char t1[10],t2[10],t3[10],t4[10];
    int n;
    while(1)
    {
        printf("$SHELL : ");
        fgets(cmd,80,stdin);
        n=sscanf(cmd,"%s%s%s%s",t1,t2,t3,t4);
        switch(n)
        {
            case 1:
                if(!fork())
                {
                    execlp(t1,t1,NULL);
                    perror(t1);
                }
                break;
            case 2:
                if(!fork())
                {
                    execlp(t1,t1,t2,NULL);
                    perror(t1);
                }
                break;
            case 3:
                if(!fork())
                {
                    execlp(t1,t1,t2,t3,NULL);
                    perror(t1);
                }
                break;
            case 4:
                if(strcmp(t1,"search")==0)
                {
                    search(t2[0],t3,t4);
                }
                else if(!fork())
                {
                    execlp(t1,t1,t2,t3,t4,NULL);
                    perror(t1);
                }
                break;
            default : printf("Error\n");

        }
    }
}