#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int m, n;
int a[1111];

void go(int v, int idx, int k) {
    if(k == 0) {
        m = max(m, v);
        return;
    }
    if(idx+k > n) return;
    for(int i=idx+1;i<n;i++) go(v&a[i],i,k-1);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int k;
        scanf("%d%d", &n, &k);
        for(int i=0;i<n;i++) scanf("%d", &a[i]);
        m = 0;
        go(INT_MAX,-1,k);
        printf("%d\n", m);
    }
    return 0;
}

