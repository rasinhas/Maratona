#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct carro
{
	int placa;
	int tamanho;
};

int main()
{
	carro estac[1100];
    int placa[10000];
	int i, j, k, tam;
	int lucro;
	int vaga;
	int c, n, q, p;
	char s;
	while(scanf("%d %d", &c, &n) != EOF)
	{
		for(i=0;i<c;i++) 
		{
			estac[i].placa = 0; 
			estac[i].tamanho = 0;
		}
        for(i=1000;i<10000;i++) placa[i]=0;
		lucro = 0;
		for(i=0;i<n;i++)
		{
			getchar();
			scanf("%c", &s);
			if(s == 'C')
			{
				scanf("%d %d", &p, &q);
				vaga = 0;
                if(placa[p]==0)
                {
                    for(j=0;j<c;j++)
                    {
                        if(estac[j].placa==0) vaga++;
                        else
                        {
                            vaga = 0;
                            j+=estac[j].tamanho-1;
                        }
                        if(vaga == q)
                        {
                            estac[j-q+1].placa = p;
                            estac[j-q+1].tamanho = q;
                            lucro+=10;
                            placa[p]=1;
                            break;
                        }
                    }
                }
			}
			else if(s == 'S')
			{
				scanf("%d", &p);
				for(j=0;j<c;j++)
				{
					if(estac[j].placa == p)
					{
						tam = estac[j].tamanho;
                        placa[p]=0;
                        estac[j].placa = 0;
                        estac[j].tamanho = 0;
						break;
					}
				}
			}
		}
		printf("%d\n", lucro);
	}
	return 0;
}
