#include <bits/stdc++.h>

using namespace std;

long long r[6];

int main() {
    int T, W;
    cin >> T >> W;
    for(int t=1;t<=T;t++) {
        long long a, b, c, d, e, f;
        cout << 1 << endl;
        cin >> a;
        cout << 2 << endl;
        cin >> b;
        cout << 3 << endl;
        cin >> c;
        cout << 4 << endl;
        cin >> d;
        cout << 5 << endl;
        cin >> e;
        cout << 6 << endl;
        cin >> f;
        r[0] = ((d-c)+(e-d)+(f-e)-5*(b-a)-(c-b)-a)/40;
        r[1] = (b-a)-2*r[0];
        r[2] = (c-b)-4*r[0];
        r[3] = (d-c)-2*(b-a)-4*r[0];
        r[4] = (e-d)-16*r[0];
        r[5] = (f-e)-2*(c-b)-4*(b-a)-16*r[0];
        printf("%lld %lld %lld %lld %lld %lld\n", r[0], r[1], r[2], r[3], r[4], r[5]);
        int k;
        cin >> k;
        if(k != 1) break;
    }
    return 0;
}
