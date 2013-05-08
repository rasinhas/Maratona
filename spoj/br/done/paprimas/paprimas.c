#include <stdio.h>
#include <string.h>
int main()
{
	int i, tam, num, flag, val;
	char palavra[21];
	while(scanf("%s",palavra) != EOF)
	{
		flag = 0;
		num = 0;
		tam = strlen(palavra);
		for(i=0;i<tam;i++)
		{
			val = (int)palavra[i];
			if(val > 95)
				num = num + val - 96;
			else
				num = num + val - 38;
		}
		for(i=2;i<num;i++)
		{
			if(num == 2 || num == 1 || num == 0)
				break;
			if(num%i == 0)
			{
				flag = 1;
				break;
			}
			if(i*i > num)
				break;
		}
		if(flag == 1)
			printf("It is not a prime word.\n");
		else
			printf("It is a prime word.\n");
	}
}

