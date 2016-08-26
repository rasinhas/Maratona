#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

typedef pair<int,int> pii;
typedef unsigned long long ll;

ll val[1111111];
pair<int,pii> edge[2222222];

unsigned long long rond() {
    return (ll)(1e9+7*rand());
}

int main() {
    int n, q, e=1;
    scanf("%d%d", &n, &q);
    srand(time(NULL));
    for(int i=0;i<q;i++) {
        int t, m, a, b;
        scanf("%d", &t);
        if(t == 1) {
            scanf("%d%d", &a, &b);
            ll xo = rond();
            val[a] ^= xo;
            val[b] ^= xo;
            edge[e++] = make_pair(xo, pii(a,b));
        }
        else if(t == 2) {
            scanf("%d", &m);
            a = edge[m].second.first;
            b = edge[m].second.second;;
            ll l = edge[m].first;
            val[a] ^= l;
            val[b] ^= l;
            edge[m].first = 0;
        }
        else {
            scanf("%d", &m);
            b = 0;
            for(int i=0;i<m;i++) {
                scanf("%d", &a);
                b ^= val[a];
            }
            printf("%s\n", (b ? "NO" : "YES"));
        }
    }
    return 0;
}
