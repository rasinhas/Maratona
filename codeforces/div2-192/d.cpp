#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <utility>
#include <queue>
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int r, c;
int sd;
char t[1111][1111];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int vis[1111][1111];
int d[1111][1111];

int bfs(int i, int j)
{
    queue <pair<int,pii> > q;
    q.push(mp(0,mp(i,j)));
    while(!q.empty())
    {
        int dd = q.front().first;
        int u = q.front().second.first;
        int v = q.front().second.second;
        q.pop();
        if(vis[u][v]) continue;
        vis[u][v] = 1;
        if(t[u][v] == 'S') sd = dd;
        d[u][v] = dd;
        for(int k=0;k<4;k++)
        {
            int nu = u+dx[k];
            int nv = v+dy[k];
            if(nu >= 0 && nv >= 0 && nu < r && nv < c)
            {
                if(t[nu][nv] != 'T' && !vis[nu][nv])
                {
                    q.push(mp(dd+1,mp(nu,nv)));
                }
            }
        }
    }
}

int main()
{
    int ret=0;
    cin >> r >> c;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) d[i][j] = 1000000000;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin >> t[i][j];
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(t[i][j] == 'E') bfs(i,j);
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) if(t[i][j] > '0' && t[i][j] <= '9' && d[i][j] <= sd) ret += t[i][j]-'0';
    cout << ret << endl;
    return 0;
}
