#include <iostream>
#include <cstdio>

using namespace std;

int a[50];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m, g=0, cur;
        scanf("%d%d", &n, &m);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) scanf("%d", &a[j]);
            cur = a[m-1];
            for(int j=m-2;j>=0;j--) if(a[j] > 0) {
                a[j]--;
                cur = (a[j] >= cur ? a[j]+1 : a[j]);
            }
            g ^= cur;
        }
        printf("%s\n", (g ? "FIRST" : "SECOND"));
    }
    return 0;
}
