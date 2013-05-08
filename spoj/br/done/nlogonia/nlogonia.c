#include <stdio.h>
#define FOR(i,n) for(i=0;i<n;i++)

using namespace std;

int main()
{
	int Px, Py, N, Divx, Divy;
	int i;
	while(1)
	{
		scanf("%d", &N);
		if(N == 0)
			return 0;
		scanf("%d %d", &Divx, &Divy);
		FOR(i,N)
		{
			scanf("%d %d", &Px, &Py);
			if(Px == Divx || Py == Divy)
				printf("divisa\n");
			else if(Py > Divy && Px > Divx)
				printf("NE\n");
			else if(Py > Divy && Px < Divx)
				printf("NO\n");
			else if(Py < Divy && Px > Divx)
				printf("SE\n");
			else if(Py < Divy && Px < Divx)
				printf("SO\n");
		}
	}
}


