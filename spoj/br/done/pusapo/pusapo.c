#include <stdio.h>

int main()
{
	int pedras[110];
	int s, p, dist, pi, i, j;
	scanf("%d %d", &p, &s);
	for(i=0;i<=p;i++) pedras[i] = 0;
	for(i=1;i<=s;i++)
	{
		scanf("%d %d", &pi, &dist);
		for(j=0;(pi%dist)+(j*dist) <= p;j++) pedras[(pi%dist)+(j*dist)] = 1;
	}
	for(i=1;i<=p;i++) printf("%d\n", pedras[i]);
	return 0;
}
