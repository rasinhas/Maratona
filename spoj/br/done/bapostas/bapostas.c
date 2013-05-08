#include <stdio.h>
#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

int main()
{
	int N, P, Atual, Max, Uneg;
	int i;
	while(1)
	{
		scanf("%d", &N);
		if(N == 0)
			return 0;
		Max = 0;
		Atual = 0;
		FOR(i, N)
		{
			scanf("%d", &P);
			Atual += P;
			if(Atual < 0)
				Atual = 0;
			if(Atual > Max)
				Max = Atual;
		}
		if(Max == 0)
			printf("Losing streak.\n");
		else
			printf("The maximum winning streak is %d.\n", Max);
	}
}



