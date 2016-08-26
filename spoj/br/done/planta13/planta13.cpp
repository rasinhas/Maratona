#include <bits/stdc++.h>

using namespace std;

int f[1111111], c[1111111], v[1111111];

int main() {
    int n, m;
    char p;
    cin >> m >> n;
    long long s=0, r=0, a=0;
    for(int i=0;i<n;i++) {
        cin >> f[i];
        c[f[i]]++;
        s += f[i];
    }
    for(int i=0;i<m;i++) {
        cin >> p;
        if(p == 'E') {
            s -= n;
            r += s;
            a++;
            if(a > 0 && !v[a]) {
                n -= c[a];
                v[a] = 1;
            }
        } else if(p == 'C') {
            s += n;
            r += s;
            a--;
        }
    }
    cout << r << endl;
    return 0;
}
