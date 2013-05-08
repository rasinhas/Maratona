#include <stdio.h>

int main()
{
	long int H, M, S, C, HF;
	double R;
	char Hora[9];
	while(scanf("%s", Hora) != EOF)
	{
		H = (10*((int)Hora[0]) + (int)Hora[1] - 528)*3600*100;
		M = (10*((int)Hora[2]) + (int)Hora[3] - 528)*60*100;
		S = (10*((int)Hora[4]) + (int)Hora[5] - 528)*100;
		C = (10*((int)Hora[6]) + (int)Hora[7] - 528);
		R = (double)(10*100*100)/(24*60*60);
		HF = (long)(H + M + S + C)*R;
		printf("%07ld\n", (long)HF);
	}
	return 0;
}


