#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <string>
#include <cassert>
#define ff first
#define ss second
#define eps 1e-6

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

double adj[111][111], d[111][111];
double x[111], y[111], r[111];

double abs(int i, int j) { return hypot(x[i]-x[j],y[i]-y[j]); }

const int inf = 1e9;

int main()
{
    int n;
    while(scanf("%d", &n) && n) {
        for(int i=0;i<n;i++) scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
        memset(adj,0,sizeof(adj));
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i != j && abs(i,j) <= r[i]) adj[i][j] = abs(i,j);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
            d[i][j] = inf;
            if(i == j) d[i][j] = 0;
            if(adj[i][j]) d[i][j] = adj[i][j];
        }
        for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        int k;
        cin >> k;
        for(int i=0;i<k;i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            assert(a<n);
            assert(b<n);
            if(a >= n || b >= n || d[a][b] == inf) printf("-1\n");
            else printf("%d\n", (int)d[a][b]);
        }
    }
    return 0;
}
