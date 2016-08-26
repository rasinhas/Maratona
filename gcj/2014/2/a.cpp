#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int f[11111];

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int n, s;
        cin >> n >> s;
        for(int i=0;i<n;i++) cin >> f[i];
        sort(f,f+n);
        int tp=n-1, bt=0, d=0;
        while(tp >= bt) {
            if(tp == bt) {
                bt++;
                d++;
            }
            else if(f[bt]+f[tp] <= s) {
                bt++; tp--;
                d++;
            } else {
                tp--;
                d++;
            }
        }
        printf("Case #%d: %d\n", t, d);
    }
    return 0;
}

