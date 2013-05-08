#include <stdio.h>

using namespace std;

struct retangulo
{
	int x1, x2;
	int y1, y2;
};

int main()
{
	int i, n, teste = 1, inters;
	retangulo a, inter;
	while(scanf("%d", &n) && n != 0)
	{
		scanf("%d %d %d %d", &inter.x1, &inter.y1, &inter.x2, &inter.y2);
		inters = 1;
		for(i=1;i<n;i++)
		{
			scanf("%d %d %d %d", &a.x1, &a.y1, &a.x2, &a.y2);
			if(inters == 1)
			{
				if(a.x2 < inter.x1 || a.y2 > inter.y1 || a.x1 > inter.x2 || a.y1 < inter.y2) inters = 0;
				else
				{
					if(a.x1 > inter.x1 && a.x1 < inter.x2) inter.x1 = a.x1;
					if(a.x2 > inter.x1 && a.x2 < inter.x2) inter.x2 = a.x2;
					if(a.y1 < inter.y1 && a.y1 > inter.y2) inter.y1 = a.y1;
					if(a.y2 < inter.y1 && a.y2 > inter.y2) inter.y2 = a.y2;
				}
			}
		}
		printf("Teste %d\n", teste++);
		if(inters == 0)
			printf("nenhum\n\n");
		else
			printf("%d %d %d %d\n\n", inter.x1, inter.y1, inter.x2, inter.y2);	
	}
	return 0;
}


