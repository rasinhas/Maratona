#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#define INF 0x3f3f3f3f
#define rep(i,k) for((i)=0;(i)<(k);(i)++)

using namespace std;

typedef struct team
{
	int tempo;
	int problemas;
	int erros;
}team;

bool compara(team a, team b)
{
	if(a.problemas > b.problemas) return false;
	else if(a.problemas == b.problemas)
	{
		if(a.tempo > b.tempo) return true;
		else return false;
	}
	else return true;
}

int main()
{
	team aux, ant, at;
	int i, j, k, t, p, f, len, base1, base2, mai, men, dt;
	char prob[10];
	vector <team> times;
	while(scanf("%d %d", &t, &p) && t)
	{
		for(i=0;i<t;i++)
		{
			aux.tempo = 0;
			aux.problemas = 0;
			aux.erros = 0;
			for(j=0;j<p;j++)
			{
				scanf("%s", prob);
				len = strlen(prob);
				for(k=0;k<len;k++)
				{
					if(prob[k] == '/')
					{
						f = k+1;
						break;
					}
				}
				if(prob[f] != '-')
				{
					aux.problemas++;
					base1 = 1;
					base2 = 1;
					for(k=f-2;k>=0;k--)
					{
						aux.erros += base1*(prob[k]-48);
						base1 *= 10;
					}
					for(k=len-1;k>=f;k--)
					{
						aux.tempo += base2*(prob[k]-48);
						base2 *= 10;
					}
					aux.erros--;
				}
			}
			aux.tempo += 20*aux.erros;
			times.push_back(aux);
		}
		sort(times.begin(),times.end(),compara);
		mai = INF;
		men = 1;
		ant = times.back();
		times.pop_back();
		//printf("%d %d %d\n", ant.problemas, ant.erros, ant.tempo);
		while(!times.empty())
		{
			at = times.back();
			times.pop_back();
			//printf("%d %d %d\n", at.problemas, at.erros, at.tempo);
			if(ant.problemas == at.problemas && ant.tempo == at.tempo && ant.erros != at.erros && at.problemas)
			{
				mai = 20;
				men = 20;
				break;
			}
			if(ant.problemas == at.problemas && ant.erros > at.erros)
			{
				dt = (at.tempo - 20*at.erros) - (ant.tempo - 20*ant.erros) - 1;
				dt = dt / (ant.erros - at.erros); 
				mai = min(dt, mai);
			}
			if(ant.problemas == at.problemas && ant.erros < at.erros)
			{
				dt = (at.tempo - 20*at.erros) - (ant.tempo - 20*ant.erros);
				dt = (dt / (ant.erros - at.erros)) + 1; 
				men = max(dt, men);
			}
			ant = at;
		}
		printf("%d ", men);
		if(mai == INF)
			printf("*");
		else
			printf("%d", mai);
		printf("\n");
		times.clear();
	}
	return 0;
}


