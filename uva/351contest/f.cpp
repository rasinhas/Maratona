#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int f[111];
int m;

int main() {
    f[0] = 1;
    for(int i=1;f[i-1]<1e5;i++) {
        f[i] = f[i-1]*i;
        m = i;
    }
    int n;
    while(scanf("%d", &n) != EOF) {
        int k = m, r = 0;
        while(n) {
            if(f[k] <= n) {
                n -= f[k];
                r++;
            } else k--;
        }
        cout << r << endl;
    }
    return 0;
}

