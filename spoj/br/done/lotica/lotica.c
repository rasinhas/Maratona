#include <stdio.h>
#define FOR(i,n) for(i=0;i<n;i++)

int main()
{
	int i, j, f;
	int Cinza[5], N, Resp;
	while(1)
	{
		scanf("%d", &N);
		if(N == 0)
			return 0;
		FOR(i,N)
		{
			scanf("%d %d %d %d %d", &Cinza[0], &Cinza[1], &Cinza[2], &Cinza[3], &Cinza[4]);
			f = 0;
			Resp = 0;
			FOR(j,5)
			{
				if(Cinza[j] <= 127)
				{
					Resp = j;
					f++;
				}
			}
			if(f > 1 || f == 0)
				printf("*\n");
			else
				printf("%c\n", 65+Resp);
		}
	}
}


