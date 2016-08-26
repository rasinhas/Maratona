#include <bits/stdc++.h>

using namespace std;

int a[1111111], b[1111111], q[11];

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        scanf("%d", &a[i]);
        if(i) b[i] += b[i-1];
        b[i] += a[i];
    }
    for(int i=0;i<n;i++) q[b[i]%8]++;
    long long ret = q[0];
    for(int i=0;i<8;i++) ret += (1ll*q[i]*(q[i]-1))/2;
    cout << ret << endl;
    return 0;
}
