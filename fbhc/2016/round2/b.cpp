#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long double e[4444];

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int n, k;
        long double p;
        cin >> n >> k >> p;
        for(int i=0;i<=n;i++) {
            if(i < k) e[i] = 0;
        }
    }
    return 0;
}

