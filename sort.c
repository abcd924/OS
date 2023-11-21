#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int bubblesort(int a[],int n);
int insertionsort(int a[],int n);

int bubblesort(int a[],int n)
{
      int i,j,temp;
      for(i=1;i<n;i++)
      {     
            for(j=0;j<n-1;j++)
            {
                  if(a[j]>a[j+1])
                  {
                         temp=a[j+1];
                         a[j+1]=a[j];
                         a[j]=temp;
                  }
           }
     }
     printf("After Bubble  Sorting :  " );
     for(i=0;i<n;i++)
     {
            printf("%d\t",a[i]);
     }
     printf("\n" );
}
   
int insertionsort(int a[],int n)
{
    int key,i,j;
    for(int i=1;i<n;i++)
    {
            key=a[i];
            j=i-1;
           while(j>=0&&a[j]>key)
            {             
                   a[j+1]=a[j];
                   j=j-1;
            }
            a[j+1]=key;
    }
    
     printf("After insertion sorting : ");
    for(i=0;i<n;i++)
            {
                  printf(" %d\t",a[i]);
            }     
}
      
int main()
{
      pid_t  pid,ppid;
      int a[10],n,i;
      printf("Enter the value of n\n");
      scanf("%d",&n);
      printf("Enter the array\n");

      for(int i=0;i<n;i++)
      {
            scanf("%d",&a[i]);
      }
      
      pid =fork();
      ppid=pid;
      if(pid==0)
      { 
            sleep(6);
            printf("Child Procss  : \n");                      
            printf("This is child :%d\n ",pid); 
            insertionsort( a, n);
      }
      else if(pid>0)
      {
            printf("Parent Process: \n");
            printf("This is parent :%d\n",ppid);
            bubblesort( a, n);
      }

      else
      {
            printf("fork fail");
      }
return 0;
}

