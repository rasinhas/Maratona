#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, y;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> x >> y;
        if(y%x == 0) {
            printf("%d %d\n", 1, y/x);
        } else printf("0 0\n");
    }
    return 0;
}
