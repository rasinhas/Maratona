#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

struct afnd
{
	struct estado
	{
		vector<int> adj[2];
		int tipo;
	};

	estado e[1000];
	int vis[1000];
	int tam;

	void aloca_estado()
	{
		e[tam].tipo = 0;
		e[tam].adj[0].clear();
		e[tam].adj[1].clear();
		tam++;
	}

	afnd() { tam=0, aloca_estado(); }

	void regra(char *c)
	{
		int atual=0;
		int N = strlen(c);
		for(int i=0;i<N;i++)
		{
			aloca_estado();
			e[atual].adj[c[i] - '0'].push_back(tam-1);
			atual = tam-1;
		}
		e[atual].tipo = 1;
	}
	
	void go(int pos)
	{
		int i, j;
		vis[pos] = 1;
		for(j=0;j<=1;j++) for(i=0;i<e[pos].adj[j].size();i++) if(!vis[e[pos].adj[j][i]]) go(e[pos].adj[j][i]);
		if(e[pos].tipo == 1) for(j=0;j<=1;j++) for(i=0;i<e[0].adj[j].size();i++) e[pos].adj[j].push_back(e[0].adj[j][i]);
	}

	void estrela()
	{
		for(int i=0;i<tam;i++) vis[i] = 0;
		go(0);
	}
};

struct afd
{
	struct estado
	{
		int adj[2];
		int tipo;
	};

	estado e[1000];
	int tam;
	
	afd() { tam = 0;}

	afd(afnd a)
	{
		int v, n, i, j;
		map<set<int>,int> m;
		queue<set<int> > q;
		set<int> s, u;
		set<int>::iterator it;
		tam = 2;
		m[s] = 1;
		e[1].adj[0] = 1;
		e[1].adj[1] = 1;
		e[1].tipo = 0;
		s.insert(0);
		m[s] = 0;
		q.push(s);
		while(!q.empty())
		{
			u = q.front();
			q.pop();
			v = m[u];
			e[v].tipo = 0;
			for(it=u.begin();it!=u.end();it++) if(a.e[*it].tipo == 1) e[v].tipo = 1;
			for(j=0;j<=1;j++)
			{
				s.clear();
				for(it=u.begin();it!=u.end();it++)
				{
					n = *it;
					for(i=0;i<a.e[n].adj[j].size();i++) s.insert(a.e[n].adj[j][i]);
				}
				if(m.count(s) == 0)
				{
					m[s] = tam++;
					q.push(s);
				}
				e[v].adj[j] = m[s];
			}
		}
	}
};

int inter[1000000][2], intertipo[1000000], intervis[1000000];
int intertam;

void intersecao(afd a, afd b)
{
	int i, j, atual;
	intertam = a.tam * b.tam;
	for(i=0;i<a.tam;i++) for(j=0;j<b.tam;j++)
	{
		atual = i * b.tam + j;
		intertipo[atual] = a.e[i].tipo * b.e[j].tipo;
		inter[atual][0] = a.e[i].adj[0] * b.tam + b.e[j].adj[0];
		inter[atual][1] = a.e[i].adj[1] * b.tam + b.e[j].adj[1];
	}
}

void dfs(int v)
{
	intervis[v] = 1;
	if(!intervis[inter[v][0]]) dfs(inter[v][0]);
	if(!intervis[inter[v][1]]) dfs(inter[v][1]);
}

bool vazio()
{
	for(int i=0;i<intertam;i++) intervis[i] = 0;
	dfs(0);
	for(int i=0;i<intertam;i++) if(intervis[i] && intertipo[i] == 1) return false;
	return true;
}

int equi[1000][1000];

afd minimo(afd a)
{
	afd m;
	int i, j, x, p, q, flag;
	int vis[1000], grupo[1000], first[1000], count;
	for(i=0;i<a.tam;i++) for(j=i;j<a.tam;j++)
	{
		if(a.e[i].tipo != a.e[j].tipo) equi[i][j] = equi[j][i] = 0;
		else equi[i][j] = equi[j][i] = 1;
	}
	flag = 0;
	while(!flag)
	{
		flag = 1; 
		for(i=0;i<a.tam;i++) for(j=0;j<a.tam;j++) if(equi[i][j])
		{
			for(x=0;x<=1;x++)
			{
				p = a.e[i].adj[x];
				q = a.e[j].adj[x];
				if(!equi[p][q])
				{
					equi[i][j] = equi[j][i] = 0;
					flag = 0;
					break;
				}
			}
		}
	}
	for(i=0;i<a.tam;i++) vis[i] = 0;
	count = 0;
	for(i=0;i<a.tam;i++) if(!vis[i])
	{
		grupo[i] = count;
		first[count] = i;
		for(j=i+1;j<a.tam;j++) if(equi[i][j] && !vis[j])
		{
			grupo[j] = count;
			vis[j] = 1;
		}
		count++;
	}
	m.tam = count;
	for(i=0;i<count;i++)
	{
		m.e[i].adj[0] = grupo[a.e[first[i]].adj[0]];
		m.e[i].adj[1] = grupo[a.e[first[i]].adj[1]];
		m.e[i].tipo = a.e[first[i]].tipo;
	}
	return m;
}

int main()
{
	char s[200];
	int na, nb, i, j;
	afnd a, b;
	afd p, q;
	while(scanf("%d%d", &na, &nb) != EOF)
	{
		a = afnd();
		b = afnd();
		for(i=0;i<na;i++)
		{
			scanf("%s", s);
			a.regra(s);
		}
		for(i=0;i<nb;i++)
		{
			scanf("%s", s);
			b.regra(s);
		}
		a.estrela(); b.estrela();
		//p = minimo(afd(a));
		//q = minimo(afd(b));
		p = afd(a);
		q = afd(b);
		intersecao(p,q);
		//printf("p.tam: %d, q.tam: %d, inter.tam: %d\n", p.tam, q.tam, intertam);
		//for(i=0;i<inter.tam;i++) printf("estado %d tipo %d\n%d %d\n", i, inter.e[i].tipo, inter.e[i].adj[0], inter.e[i].adj[1]);
		//for(i=0;i<p.tam;i++) printf("estado %d tipo %d\n%d %d\n", i, p.e[i].tipo, p.e[i].adj[0], p.e[i].adj[1]);
		if(vazio()) printf("N\n");
		else printf("S\n");
	}
	return 0;
}
