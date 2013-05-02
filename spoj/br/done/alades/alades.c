#include <stdio.h>

int main()
{
	int H1, H2, M1, M2, T;
	while(1)
	{
		scanf("%d %d %d %d", &H1, &M1, &H2, &M2);
		T = 0;
		if(H1 + H2 + M1 + M2 == 0)
			return 0;
		T = 60*(H2 - H1) + (M2 - M1);
		if(T < 0)
			T += 1440;
		printf("%d\n", T);
	}
}

