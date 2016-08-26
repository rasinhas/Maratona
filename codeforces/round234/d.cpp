#include <iostream>
#include <cstdio>

using namespace std;

int c[1111], tip[111111];
int adj[555][555];
const int inf = (int)1e9;
int pai[100100], rnk[100100], sz[100100];

void init_set(int p)
{
    for(int i=0;i<p;i++) 
    {
        pai[i] = i;
        rnk[i] = 0;
        sz[i] = 1;
    }
}

int find_set(int x)
{
    if(x != pai[x]) pai[x] = find_set(pai[x]);
    return pai[x];
}

void merge_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if(x==y) return;
    if(rnk[x] > rnk[y])
    {
        pai[y] = x;
        sz[x] += sz[y];
    }
    else
    {
        pai[x] = y;
        sz[y] += sz[x];
        if(rnk[x] == rnk[y]) rnk[y]++;
    }
}

int main() 
{
    int n, m, k;
    cin >> n >> m >> k;
    init_set(n);
    for(int i=0;i<k;i++) for(int j=0;j<k;j++) adj[i][j] = inf;
    for(int i=0;i<k;i++) {
        cin >> c[i];
        if(c[i] == 1) adj[i][i] = 0;
        if(i) c[i] += c[i-1];
    }
    for(int i=0;i<k;i++) {
        for(int j=(i ? c[i-1] : 0);j<c[i];j++) tip[j] = i;
    }
    for(int i=0;i<m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        if(w == 0) merge_set(u,v);
        adj[tip[u]][tip[v]] = min(adj[tip[u]][tip[v]], w);
        adj[tip[v]][tip[u]] = min(adj[tip[v]][tip[u]], w);
    }
    int ok = 1;
    for(int i=0;i<n;i++) if(find_set(i) != find_set(c[tip[i]]-1)) ok = 0;
    if(ok) {
        cout << "Yes" << endl;
        for(int l=0;l<k;l++) for(int i=0;i<k;i++) for(int j=0;j<k;j++) adj[i][j] = min(adj[i][j], adj[i][l]+adj[l][j]);
        for(int i=0;i<k;i++) {
            for(int j=0;j<k;j++) {
                if(j) printf(" ");
                if(adj[i][j] == inf) printf("-1");
                else printf("%d", adj[i][j]);
            }
            printf("\n");
        }
    } else cout << "No" << endl;
    return 0;
}
