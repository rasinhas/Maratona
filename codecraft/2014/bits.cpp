#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

ll go(int n) {
    if(n<=0) return 0;
    int p = 1<<(31-__builtin_clz(n));
    return vis[n] = n-p+1 + go(n-p) + go(p-1);
}

int main() {
    int a, t;
    scanf("%d", &t);
    while(t--) {
        cin>>a;
        scanf("%d", &a);
        printf("%lld\n", go(a));
    }
    return 0;
}
