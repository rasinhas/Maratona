#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#define pb push_back

using namespace std;

vector <int> sz;
char l[1010][1010];
int l2[1010][1010];
int vis[1010][1010];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int v[26];

void dfs(int i, int j)
{
    vis[i][j] = 1;
    for(int k=0;k<4;k++)
    {
        ni = i+dx[k];
        nj = j+dy[k]
        if(l2[ni][nj] == l2[i][j] && !vis[ni][nj]) dfs(ni,nj);
        else if(l[i][j]) v[l[i][j]-'A'] = 1;
    }
    vis[i][j] = 2;

}

int main()
{
    int n, m, t, p;
    cin >> n >> m;
    t = n*m;
    p = 0;
    for(int i=1;;i++)
    {
        if(t-i > i) 
        {
            t-=i;
            p++;
            sz.pb(i);
        }
        if(t-i <= i)
        {
            sz.pb(t);
            p++;
            break;
        }
    }
    cout << p << endl;
    int x, y;
    int d;
    x = y = 0;
    d = 1;
    for(int i=0;i<sz.size();i++)
    {
        while(sz[i] != 0)
        {
            l2[x][y] = i+1;
            if(x+d == -1)
            {
                d = 1;
                y++;
            }
            else if(x+d == n)
            {
                d = -1;
                y++;
            }
            else x += d;
            sz[i]--;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j])
            {
                dfs(i,j);
                memset(v,0,sizeof(v));
            }
        }
    }
    for(int i=0;i<n;i++) cout << l2[i] << endl;
    return 0;
}
