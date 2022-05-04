#include <bits/stdc++.h>

using namespace std;

int a[222222], b[222222];

int main() {
    int n, m;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> m;
        for(int j=0;j<m;j++) scanf("%d", &a[j]);
        int j = 0;
        int ok = 1;
        if(m%2) {
            b[0] = a[0];
            j++;
        }
        for(;j<m;j+=2) {
            if(a[j] > a[j+1]) {
                b[j] = a[j+1];
                b[j+1] = a[j];
            } else {
                b[j] = a[j];
                b[j+1] = a[j+1];
            }
            if(j && b[j] < b[j-1]) ok = 0;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
