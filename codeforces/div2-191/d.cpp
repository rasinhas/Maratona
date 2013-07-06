#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#define pb push_back
#define sz size()
#define mp make_pair

using namespace std;

int vis[600][600];
int dx[4] = {1,0,0,-1};
int dy[4] = {0,1,-1,0};
int n, m, c;
string tab[600];
vector <string> v;

bool in(int i, int j) { return (i >= 0 && j >= 0 && i<n && j < m); }

void dfs(int i, int j, int init)
{
    char aux[200];
    string a="";
    sprintf(aux ,"B %d %d\n", i+1,j+1);
    a += aux;
    v.pb(a);

    c++;
    vis[i][j] = 1;
    for(int k=0;k<4;k++)
    {
        int ni = i+dx[k];
        int nj = j+dy[k];
        if(in(ni,nj) && tab[ni][nj] == '.' && !vis[ni][nj]) dfs(ni,nj,0);
    }
    if(!init) 
    {
        sprintf(aux, "D %d %d\n", i+1, j+1);
        a="";
        a += aux;
        v.pb(a);
        sprintf(aux, "R %d %d\n", i+1, j+1);
        a="";
        a += aux;
        v.pb(a);
        c += 2;
    }
}

int main()
{
    cin >> n >> m;
    c = 0;
    for(int i=0;i<n;i++) cin >> tab[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(tab[i][j] == '.' &&  !vis[i][j]) dfs(i,j,1);
        }
    }
    cout << c << endl;
    for(int i=0;i<v.sz;i++)
    {
        cout << v[i];
    }
    return 0;
}
