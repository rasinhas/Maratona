#include <bits/stdc++.h>

using namespace std;

int x[2222222];

int main() {
    int n, t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i=0;i<n;i++) scanf("%d", &x[i]);
        int a=0, b=0, cur=x[0], s=0;
        while(1) {
            if(a == b && a == n-1) break;
            if(b > n-1) break;
            if(cur == 42) {
                a = b = b+1;
                cur = x[a];
                s++;
                continue;
            }
            if(a == b) {
                cur += x[++b];
                continue;
            }
            if(b == n-1) {
                cur -= x[a++];
                continue;
            }
            if(cur > 42) cur -= x[a++];
            else if(cur < 42) cur += x[++b];
        }
        printf("%d\n", s);
    }
    return 0;
}
