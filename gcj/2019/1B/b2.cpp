#include <bits/stdc++.h>

using namespace std;

long long r[6];

int main() {
    int T, W;
    cin >> T >> W;
    for(int t=1;t<=T;t++) {
        long long a, b;
        cout << 220 << endl;
        cin >> a;
        r[3] = a/(1ll<<55);
        r[4] = (a%(1ll<<55))/(1ll<<44);
        r[5] = (a%(1ll<<44))/(1ll<<36);
        cout << 55 << endl;
        cin >> b;
        b -= (r[3]*(1ll<<13) + r[4]*(1ll<<11) + r[5]*(1ll<<9));
        r[0] = b/(1ll<<55);
        r[1] = (b%(1ll<<55))/(1ll<<27);
        r[2] = (b%(1ll<<27))/(1ll<<18);
        printf("%lld %lld %lld %lld %lld %lld\n", r[0], r[1], r[2], r[3], r[4], r[5]);
        int R;
        cin >> R;
        if(R != 1) break;
    }
    return 0;
}
