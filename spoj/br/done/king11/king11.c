#include <stdio.h>

int cmp (const void * a, const void * b)
{
	  return ( *(int*)a - *(int*)b );
}

int maior(int a, int b)
{
	if(a>b) return a;
	return b;
}

int  main()
{
	int a[5];
	while(scanf("%d %d %d", &a[0], &a[1], &a[2]) && a[0])
	{
		qsort(a,3,sizeof(int),cmp);
		if(a[0]==a[1] && a[1]==a[2]) 
		{
			if(a[0]==13) printf("*\n");
			else printf("%d %d %d\n", a[0]+1, a[1]+1, a[2]+1);
		}
		else if(a[0]==a[1] && a[1]!=a[2])
		{
			if(a[2]==13) a[0]+=1, a[1]+=1, a[2]=1;
			else a[2]+=1;
			qsort(a,3,sizeof(int),cmp);
			if(a[0]==a[1] && a[1]==a[2])
			{
				if(a[0]==13) a[0]=1, a[1]=1, a[2]=1;
				else a[2]+=1;
			}
			printf("%d %d %d\n",a[0], a[1], a[2]);
		}
		else if(a[0]!=a[1] && a[1]==a[2])
		{
			if(a[0]==13) a[0]=1, a[1]+=1, a[2]+=1;
			else a[0]+=1;
			qsort(a,3,sizeof(int),cmp);
			if(a[0]==a[1] && a[1]==a[2])
			{
				if(a[0]==13) a[0]=1, a[1]=1, a[2]=1;
				else a[2]+=1;
			}
			printf("%d %d %d\n",a[0], a[1], a[2]);
		}
		else
		{
			a[0]=1, a[1]=1, a[2]=2;
			printf("%d %d %d\n",a[0], a[1], a[2]);
		}
	}
	return 0;
}
