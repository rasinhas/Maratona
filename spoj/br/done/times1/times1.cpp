#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f
#define rep(i,n) for(i=0;i<(n);i++)
#define min(x,y) x < y ? x : y
#define max(x,y) x > y ? x : y
#define INF 0x3f3f3f

using namespace std;

typedef struct aluno
{
	char nome[40];
	int habilidade;
}aluno;

int comparahab(const void * p1, const void * p2){
	int r = ((struct aluno *)p1)->habilidade - ((struct aluno *)p2)->habilidade;
	return r;
}

int comparanome(const void * p1, const void * p2){
	return strcmp(((struct aluno *)p2)->nome, ((struct aluno *)p1)->nome);
}

int main()
{
	vector <vector <aluno> > times;
	vector <aluno> lista;
	aluno aux;
	vector <aluno > auxiliar;
	int n, t;
	int i;
	scanf("%d %d", &n, &t);
	for(i=0;i<n;i++)
	{
		scanf("%s %d", aux.nome, &aux.habilidade);
		lista.push_back(aux);
	}
	qsort(&*lista.begin(),lista.size(),sizeof(struct aluno),comparahab);
	for(i=0;i<t;i++)
	{
		auxiliar.push_back(lista.back());
		lista.pop_back();
		times.push_back(auxiliar);
		auxiliar.clear();
	}
	for(i=0;i<n-t;i++)
	{
		times.at(i%t).push_back(lista.back());
		lista.pop_back();
	}
	for(i=0;i<t;i++)
	{
		printf("Time %d\n", i+1);
		qsort(&*times.at(i).begin(), times.at(i).size(),sizeof(struct aluno), comparanome);
		while(!times.at(i).empty())
		{
			printf("%s\n", times.at(i).back().nome);
			times.at(i).pop_back();
		}
		printf("\n");
	}
	return 0;
}



