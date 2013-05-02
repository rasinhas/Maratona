#include <stdio.h>

int main()
{
	int n, voltas, v, vtempo, tempo, t, i, j;
	scanf("%d %d", &n, &voltas);
	vtempo = 0x3f3f3f3f;
	for(i=0;i<n;i++)
	{
		tempo = 0;
		for(j=0;j<voltas;j++)
		{
			scanf("%d", &t);
			tempo += t;
		}
		if(tempo < vtempo)
		{
			vtempo = tempo;
			v = i+1;
		}
	}
	printf("%d\n", v);
	return 0;
}
