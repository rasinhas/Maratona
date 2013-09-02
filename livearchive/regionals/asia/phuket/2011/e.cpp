#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

int g[3333][33];
int R = 3333;
int C = 25;

void mark(int x, int y)
{
    int vis[4444];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<x;i++) vis[g[i][y]] = 1; 
    for(int i=0;i<y;i++) vis[g[x][i]] = 1;
    for(int i=0;i<min(x,y);i++) vis[g[x-i-1][y-i-1]] = 1;
    for(int i=0;i<4444;i++) if(!vis[i])
    {
        g[x][y] = i;
        break;
    }
}

void precalc()
{
    g[0][0] = 0;
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++) mark(i,j); 
    }
}

void print()
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++) printf("%5d", g[i][j]-g[i][0]);
        cout << endl;
    }
}

/*
void check()
{
    for(int i=0;i<r;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            int ok = 1;
            for(int k=0;k<c;k++)
            {
                if(g[i][k]-g[i][0] != g[j][k]-g[j][0])
                {
                    ok = 0;
                    break;
                }
            }
            if(ok) 
            {
                cout << "#" << i << " X " << i - j << endl;
                break;
            }
        }
    }
}
*/

ll grundy(ll x, ll y)
{
    if(x <= 3072) return g[x][y];
    else 
    {
        int k=2304+x%768;
        return x - k + g[k][y];
    }
}

int main()
{
    precalc();
    //check();
    //print();
    ll t, r, c, n;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        ll x, y, ret=0;
        cin >> r >> c >> n;
        for(int i=0;i<n;i++)
        {
            cin >> x >> y;
            x--; y--;
            ret ^= grundy(y, x);
        }
        if(ret == 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
