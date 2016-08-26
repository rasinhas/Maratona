#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

int xo[77];
ll a[1111111];

int main()
{
    int t, n;
    ll k;
    cin >> t;
    while(t--) {
        cin >> n;
        memset(a,0,n*sizeof(ll));
        memset(xo,0,sizeof(xo));
        for(int i=0;i<n;i++) {
            cin >> k;
            a[i] = k;
            for(int j=0;k>0;j++) {
                xo[j] = (xo[j]+k%2)%3;
                k /= 2;
            }
        }
        int g = 2;
        for(int i=0;i<64;i++) if(xo[i]) g = 1;
        if(g != 2) {
            for(int i=0;i<n;i++) {
                int fail = 0;
                k = a[i];
                for(int j=0;k>0;j++) {
                    xo[j] = (xo[j]+(3-k%2))%3;
                    if(xo[j] == 2) fail = 1;
                    k /= 2;
                }
                for(int j=0;j<63;j++) cout << xo[j];
                cout << endl;
                if(!fail) {
                    int p = 1, v = 0;
                    for(int i=0;i<64;i++) {
                        if(xo[i] == 1) v += p;
                        p *= 2;
                    }
                    if(v < a[i]) g = 0;
                }
                k = a[i];
                for(int j=0;k>0;j++) {
                    xo[j] = (xo[j]+(k%2))%3;
                    k /= 2;
                }
            }
        }
        cout << (char)('A'+g) << endl;
    }
    return 0;
}
