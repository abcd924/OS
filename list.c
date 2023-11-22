#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>

void list(char ch,char dn[])
{
    DIR* dir;
    struct dirent* file;
    int cnt=0;
    if((dir=opendir(dn))==NULL)
    {
        printf("Directory Not Found.....\n");
        return;
    }
    switch(ch)
    {
        case 'f':
            while((file=readdir(dir)!=NULL))
                printf("%s\n",file->d_name);
                break;

        case 'c':
            while((file=readdir(dir)!=NULL))
                cnt++;
            printf("Number Of File Is Present In Directory : %d\n",cnt);
            break;

        case 'i':
            while((file=readdir(dir)!=NULL))
            printf("%s\t%d\n",file->d_name,file->d_ino);
            break;

        default : printf("Invalid Token......\n");
    }
    closedir(dir);
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
                if(strcmp(t1,"list")==0)
                {
                    list(t2[0],t3);
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