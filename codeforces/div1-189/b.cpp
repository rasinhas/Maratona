#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#define pb push_back
#define sz size()

using namespace std;

int p[100100];
int l[100100], r[100100];
vector <int> rm[2];
int vis[100100];

int main()
{
    int n;
    cin >> n;
    p[-1] = 0;
    p[n] = 1000000;
    for(int i=0;i<n;i++)
    {
        cin >> p[i];
        r[i] = i+1;
        l[i] = i-1;
        if(p[i] < p[i-1]) rm[0].pb(i);
    }
    int i;
    for(i=0;!rm[i%2].empty();i++)
    {
        rm[(i+1)%2].clear();
        for(int j=0;j<rm[i%2].sz;j++)
        {
            int v = rm[i%2][j];
            vis[v] = 1;
            r[l[v]] = r[v];
            l[r[v]] = l[v];
        }
        for(int j=0;j<rm[i%2].sz;j++)
        {
            int v = rm[i%2][j];
            if(p[r[v]] < p[l[v]]) if(!vis[r[v]]) rm[(i+1)%2].pb(r[v]);
        }
    }
    cout << i << endl;
    return 0;
}
