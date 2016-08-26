#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int g[444][444], ac[444][444];

int main()
{
    freopen("lazy.in", "r", stdin);
    freopen("lazy.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
        cin >> g[i][j];
        ac[i][j] = g[i][j];
        ac[i][j] += ac[i][j-1];
    }
    int best = 0;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) {
        int miny = max(1,i-k);
        int maxy = min(n,i+k);
        int r = k-(i-miny), d = 1;
        int v = 0;
        for(int l=miny;l<=maxy;l++) {
            v += (ac[l][min(j+r,n)]-ac[l][max(j-r-1,0)]);
            if(l == i) d = -1;
            r += d;
        }
        best = max(best,v);
    }
    cout << best << endl;
    return 0;
}
