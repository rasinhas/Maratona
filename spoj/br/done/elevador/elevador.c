#include <stdio.h>
int main()
{
	int L, C, R1, R2;
	while(1)
	{
		scanf("%d",&L);
		scanf("%d",&C);
		scanf("%d",&R1);
		scanf("%d",&R2);
		if(L == 0 && C == 0 && R1 == 0 && R2 == 0)
			return 0;
		if(2*R1 > L || 2*R2 > L || 2*R1 > C || 2*R2 > C )
			printf("N\n");
		else if((L-R1-R2)*(L-R1-R2)+(C-R1-R2)*(C-R1-R2) >= (R1+R2)*(R1+R2))
			printf("S\n");
		else if((C-R1-R2)*(C-R1-R2)+(R1-R2)*(R1-R2) >= (R1+R2)*(R1+R2))
			printf("S\n");
		else
			printf("N\n");
	}
}

