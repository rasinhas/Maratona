#include <stdio.h>

int main()
{
	float campox[70000], campoy[70000];
	int i, j, k, p, x, y, n, caso=1;
	int N, c, A, B;
	int a, b;
	scanf("%d", &N);
	while(N--)
	{
		scanf("%d %d", &a, &b);
		p = 1;
		x = 0;
		y = 0;
		n = 0;
		if(b != 0)
		{
			campox[0] = 0;
			campoy[0] = 0;
			n = 1;
		}
		for(i=0;i<128;i++)
		{
			for(k=0;k<p;k++)
			{
				x--;
				if(a*x+b-y != 0)
				{
					campox[n] = x;
					campoy[n] = y;
					n++;
				}
			}
			for(k=0;k<p;k++)
			{
				y++;
				if(x*a+b-y != 0)
				{
					campox[n] = x;
					campoy[n] = y;
					n++;
				}
			}
			p++;
			for(k=0;k<p;k++)
			{
				x++;
				if(a*x+b-y != 0)
				{
					campox[n] = x;
					campoy[n] = y;
					n++;
				}
			}
			for(k=0;k<p;k++)
			{
				y--;
				if(a*x+b-y != 0)
				{
					campox[n] = x;
					campoy[n] = y;
					n++;
				}
			}
			p++;
		}
		scanf("%d", &c);
		printf("Caso %d\n", caso++);
		//for(i=0;i<30;i++)
		//{
		//	printf("casa[%d] x=%d y=%d\n", i, (int)campox[i], (int)campoy[i]);
		//}
		for(i=0;i<c;i++)
		{
			scanf("%d %d", &A, &B);
			if((a*campox[A]-campoy[A]+b)*(a*campox[B]-campoy[B]+b) >= 0)
				printf("Mesmo lado da fronteira\n");
			else
				printf("Lados opostos da fronteira\n");
		}
	}
	return 0;
}


