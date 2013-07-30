#include <stdio.h>
#include <string.h>
#include <vector>
#define row(a) (a)
#define col(a) (l+a)
#define src (l+c)
#define snk (l+c+1)

using namespace std;

int grid[111][111], lgrid[3111][111], egrid[3111][3111];
bool adj[3111][3111];
int vis[5555], pai[5555];
int l, c, y, x;

//expandir linhas
void expandl()
{
    int i, j, k, hs;
    for(i=0;i<y;i++)
    {
        hs = 0;
        for(j=0;j<x;j++)
        {
            if(grid[i][j] == 1) hs = 1;
            if(hs && grid[i][j] == 2)
            {
                k = j;
                while(k < x) lgrid[l][k++] = 0;
                l++;
                k = 0;
                while(k < j) lgrid[l][k++] = 0;
                hs = 0;
            }
            lgrid[l][j] = grid[i][j];
        }
        l++;
    }
}

//expandir colunas
void expandc()
{
    int i, j, k, hs;
    for(i=0;i<x;i++)
    {
        hs = 0;
        for(j=0;j<l;j++)
        {
            if(lgrid[j][i] == 1) hs = 1;
            if(hs && lgrid[j][i] == 2)
            {
                k = j;
                while(k < l) egrid[k++][c] = 0;
                c++;
                k = 0;
                while(k < j) egrid[k++][c] = 0;
                hs = 0;
            }
            egrid[j][c] = lgrid[j][i];
        }
        c++;
    }
}

void dfs(int v)
{
	int i;
	vis[v] = 1;
    for(i=0;i<=snk;i++)
    {
        if(adj[v][i] && !vis[i])
        {
            pai[i] = v;
            dfs(i);
            if(vis[snk]) return;
        }
    }
}

int fluxo()
{
	int k, p, i, ret=0;
	while(1)
	{
		for(i=0;i<=snk;i++) vis[i]=0, pai[i]=-1;
		dfs(src);
		if(!vis[snk]) break;
		for(k=snk; pai[k]!=-1; k=pai[k]) { adj[pai[k]][k]=0; adj[k][pai[k]]=1; }
		ret++;
	}
	return ret;
}

int main()
{
    int s, b, t;
    int px, py;
    int i, j;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &y, &x);
        for(i=0;i<y;i++) memset(grid[i],0,y*sizeof(int));
        scanf("%d", &s);
        for(i=0;i<s;i++)
        {
            scanf("%d%d", &py, &px);
            px--; py--;
            grid[py][px] = 1;
        }
        scanf("%d", &b);
        for(i=0;i<b;i++)
        {
            scanf("%d%d", &py, &px);
            px--; py--;
            grid[py][px] = 2;
        }
        l = 0;
        expandl();
        c = 0;
        expandc();
        for(i=0;i<l+c+2;i++) memset(adj[i],0,(l+c+2)*sizeof(bool));
        for(i=0;i<l;i++)
        {
            adj[src][row(i)] = 1;
            for(j=0;j<c;j++)
            {
                if(i==0) adj[col(j)][snk] = 1;
                if(egrid[i][j] == 1) adj[row(i)][col(j)] = 1;
            }
        }
        printf("%d\n", fluxo());
    }
    return 0;
}
