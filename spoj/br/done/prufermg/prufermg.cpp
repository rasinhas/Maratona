#include <bits/stdc++.h>

using namespace std;

int g[1111111];

int main() {
    int n, a;
    while(scanf("%d", &n) != EOF) {
        for(int i=1;i<=n+2;i++) g[i] = 1;
        for(int i=0;i<n;i++) {
            scanf("%d", &a);
            g[a]++;
        }
        for(int i=1;i<=n+2;i++) {
            if(i > 1) printf(" ");
            printf("%d", g[i]);
        }
        printf("\n");
    }
    return 0;
}
