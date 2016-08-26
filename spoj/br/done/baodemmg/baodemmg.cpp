#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t, a, s;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        s = 0;
        for(int i=0;i<n;i++) {
            scanf("%d", &a);
            s += a;
        }
        if(s > n) printf("precisa\n");
        else printf("nao precisa\n");
    }
    return 0;
}
