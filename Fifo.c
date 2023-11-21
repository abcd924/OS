#include<stdio.h>
int RS[16]={12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8};
int frame[10],n,pf=0,fcnt=0;

int search(int no)
{
	int i;
	for(i=0;i<n;i++)
		if(frame[i]==no)
		return 1;
	return 0;
}

void add(int no)
{
	if(fcnt==n)
	 fcnt=0;
	frame[fcnt++]=no;
	pf++;
}
main()
{
	int i,j=0;
	printf("enter frame size");
	scanf("%d",&n);
	for(i=0;i<16;i++)
		{
			if(search(RS[i])==0)
			add(RS[i]);
		}
	printf("total page fault :%d",pf);
}
