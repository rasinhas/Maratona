#include <bits/stdc++.h>

using namespace std;

double a[1111], b[1111];
int n;

int solve1() {
    int bt=n-1, bb=0;
    for(int i=0;i<n;i++) {
        if(a[i] > b[bb]) bb++;
        else bt--;
    }
    return bb;
}

int solve2() {
    int bt=n-1, bb=0;
    for(int i=n-1;i>=0;i--) {
        if(a[i] > b[bt]) bb++;
        else bt--;
    }
    return bb;
}

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        sort(a,a+n);
        sort(b,b+n);
        printf("Case #%d: %d %d\n", t, solve1(), solve2());
    }
    return 0;
}
