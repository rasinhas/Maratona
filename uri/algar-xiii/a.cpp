#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int vis[33][1111], lim[33];

int main()
{
    for(int i=30;i>0;i--) {
        int cur = 0;
        int v = i;
        do {
            int t = v;
            while(t--){
                cur += v;
                if(cur > 1000) break;
                vis[i][cur] = 1;
            }
            if(cur > 1000) break;
        } while(v--);
    }
    int n, v;
    while(scanf("%d%d", &n, &v) && n) {
        int ok = 0;
        for(int i=v;i>0;i--) if(vis[i][n]) ok = 1;
        cout << (ok ? "possivel" : "impossivel") << endl;
    }
    return 0;
}
