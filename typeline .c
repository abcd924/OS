#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
// #include<systypes.h>
#include<fcntl.h>
#include<string.h>

void typeline(char* ch,char fname[])
{
    char c;
    int handle;
    handle = open(fname,O_RDONLY);
    if(handle==-1)
    {
        printf("File Cant Open");
        return;
    }
    if(ch[0]=='a')
    {
        while(read(handle,&c,1)!=0)
        {
            printf("%c",c);
        }
    }
    int n = atoi(ch);
    if(n>0)
    {
        int cnt=0;
        while(read(handle,&c,1)!=0)
        {
            if(c=='\n')
            {
                cnt++;
            }
            printf("%c",c);
            if(cnt==n)
            {
                break;
            }
        }
    }
    else if(n<0)
    {
        int cnt=1;
        while(read(handle,&c,1)!=0)
        {
            if(c=='\n')
            {
                cnt++;
            }
        }
        n=cnt+n;
        cnt=0;
        lseek(handle,0,SEEK_SET);
        while(read(handle,&c,1)!=0)
        {
            if(c=='\n')
            {
                cnt++;
            }
            if(cnt>=n)
            {
                printf("%c",c);
            }
        }
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
                if(strcmp(t1,"typeline")==0)
                {
                    typeline(t2,t3);
                }
                else if(!fork())
                {
                    execlp(t1,t1,t2,t3,NULL);
                    perror(t1);
                }
                break;
            case 4:
               if(!fork())
                {
                    execlp(t1,t1,t2,t3,t4,NULL);
                    perror(t1);
                }
                break;
            default : printf("Error\n");

        }
    }
}