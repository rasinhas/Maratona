#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define mp make_pair

using namespace std;

int c[222][222];
int d[222][222];
int vis[222][222];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n;

bool in(int a, int b)
{
    return (a>=0 && a<n && b>=0 && b<n);
}

void dijkstra(int a, int b)
{
    priority_queue<pair<int,pair<int,int> > > q;
    d[a][b] = c[a][b];
    q.push(mp(-d[a][b],mp(a,b)));
    while(!q.empty())
    {
        int dd=-q.top().first;
        int x=q.top().second.first;
        int y=q.top().second.second;
        q.pop();
        if(vis[x][y]) continue;
        vis[x][y] = 1;
        d[x][y] = dd;
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(in(nx,ny) && !vis[nx][ny]) q.push(mp(-(dd+c[nx][ny]),mp(nx,ny)));
        }
    }
}

int main()
{
    int t=1;
    while((cin >> n)&&n)
    {
        cout << "Problem " << t++ << ": ";
        memset(d,0,sizeof(d));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> c[i][j];
        dijkstra(0,0);
        cout << d[n-1][n-1] << endl;
    }
    return 0;
}
