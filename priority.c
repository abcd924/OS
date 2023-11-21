#include<stdio.h>
#include<stdlib.h>
struct process
{
       char name[10];
       int at,bt,wt,tat,tbt,pr;
};
typedef struct process PROCESS[10];

PROCESS p;
int i;
int currenttime;
float totalwt=0,totaltat=0;

void setProcess(int n)
{
      for(i=0;i<n;i++)
      {
        printf("Enter Process Name : ");
        scanf("%s",p[i].name);
        printf("Enter Arrivel Time : ");
        scanf("%d",&p[i].at);
        printf("Enter Brust Time : ");
        scanf("%d",&p[i].bt);
        printf("Enter Priority : ");
        scanf("%d",&p[i].pr);
        p[i].tbt=p[i].bt;
       }
}

void displayAll(int n)
{
       printf("\nProcess\tAt\tBt\tPriority\tWt\tTAT\n");
       for(i=0;i<n;i++)
      {
              printf("%s\t%d\t%d\t%d\t\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].pr,p[i].wt,p[i].tat);
       }
}

void display(int n)
{
       printf("\nProcess\tAt\tBt\tPriority\n");
       for(i=0;i<n;i++)
      {
              printf("%s\t%d\t%d\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].pr);
       }
}

void sort(int n)
{
       printf("\nAfter Sorting : ");
       int j;
       for(i=1;i<n;i++)
       {
              for(j=0;j<n-1;j++)
              {
                     if(p[i].at < p[j].at )
                     {
                            PROCESS temp;
                            temp[1] = p[i];
                            p[i] = p[j];
                            p[j] = temp[1];
                       }
               }
        }
}

int getProcess(int n)
{
       int i=0,min=999,p1=-1;
       for(i=0;i<n;i++)
       {
              if(p[i].at<=currenttime && p[i].tbt!=0)
              {      
                     if(p[i].pr<min)
                     {
                            min=p[i].pr;
                            p1=i;
                     }
               }
        }
        return p1;
}

void cpuProcess(int n)
{      
       int i=0,cnt=0;
       printf("\nGanr Chart :\n");
       while(1)
       {      
              i=getProcess(n);
              if(i==-1)
              {
                     printf("|%d Ideal ",currenttime);
                     currenttime=p[cnt].at;
                     printf("%d",currenttime);
               } 
               
               else
               {         
                     printf("|%d %s ",currenttime,p[i].name); 
                     p[i].wt=currenttime-p[i].at;
                     p[i].tat=p[i].wt+p[i].bt;
                     currenttime=currenttime+p[i].bt;
                     printf("%d",currenttime);
                     
                     p[i].tbt=0;
                     
                     totalwt+=p[i].wt;
                     totaltat+=p[i].tat;                     
                     
                     cnt++;
                      
                 }
                 
                 if(cnt==n)
                     {
                            printf("|\n");
                            break;
                      }
       }
}
                 
int main()
{
       int n;
       printf("Enter How Many Processes : ");
       scanf("%d",&n);
       setProcess(n);
       display(n);
       sort(n);
       display(n);
       cpuProcess(n);
       displayAll(n);
       printf("\nTotal  Waiting Time :  %.2f\n",totalwt);
       printf("Average  Waiting Time :  %.2f\n",totalwt/n);
       
        printf("Total  Turn Around Time Time :  %.2f\n",totaltat);
        printf("Average  Turn Around Time Time :  %.2f\n",totaltat/n);
       return 0;
 }
       




