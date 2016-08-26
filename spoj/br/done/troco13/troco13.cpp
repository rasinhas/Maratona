#include <bits/stdc++.h>

using namespace std;

int s[111111];
int a[1111];

int main() {
    int v, n;
    cin >> v >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    s[0] = 1;
    int mx = 0;
    for(int i=0;i<n;i++) {
        for(int j=mx;j>=0;j--) {
            if(s[j] == 1 && j+a[i] < 1e5+1) {
                s[j+a[i]] = 1;
                mx = max(mx,j+a[i]);
            }
        }
    }
    cout << (s[v] ? 'S' : 'N') << endl;
    return 0;
}
