#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#define ff first
#define ss second
#define inf 1000000000000000000

using namespace std;

long long adj[222][222];
long long d[222][222];

int main()
{
    int n, m, k, q;
    int x, y;
    long long v;
    ifstream in("vacation.in");
    ofstream out("vacation.out");
    in >> n >> m >> k >> q;
    for(int i=0;i<222;i++) for(int j=0;j<222;j++) d[i][j] = inf;
    for(int i=0;i<n;i++) d[i][i] = 0;
    for(int i=0;i<m;i++)
    {
        in >> x >> y >> v;
        x--; y--;
        if(adj[x][y]) adj[x][y] = min(adj[x][y],v);
        else adj[x][y] = v;
        d[x][y] = adj[x][y];
    }
    for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    long long c = 0, r = 0;
    for(int i=0;i<q;i++) 
    {
        in >> x >> y;
        x--; y--;
        if(x < k || y < k)
        {
            if(d[x][y] != inf)
            {
                c++;
                r += d[x][y];
            }
        }
        else
        {
            long long m = inf;
            for(int i=0;i<k;i++) if(d[x][i] != inf && d[i][y] != inf) m = min(m,d[x][i]+d[i][y]);
            if(m < inf) 
            {
                c++;
                r += m;
            }
        }
    }
    out << c << endl << r << endl;
    return 0;
}
