#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 0x3f3f3f3f

using namespace std;

int d[100][100];

int main()
{
    int n, m;
    int u, v, w;
    cin >> n >> m;
    memset(d,inf,sizeof(d));
    for(int i=0;i<m;i++)
    {
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }
    for(int i=0;i<n;i++) d[i][i] = 0;
    for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    int mv, cv;
    cv = inf;
    for(int i=0;i<n;i++)
    {
        mv = 0;
        for(int j=0;j<n;j++) mv = max(mv, d[i][j]);
        cv = min(cv,mv);
    }
    cout << cv << endl;
    return 0;
}
