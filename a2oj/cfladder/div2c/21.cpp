#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector<int> sol[1111];

int main() {
    int n, d, k;
    cin >> n >> k >> d;
    ll kk = 1ll;
    for(int i=0;i<d;i++) {
        kk *= k;
        if(kk >= n) break;
    }
    if(kk < n) cout << "-1" << endl;
    else {
        for(int i=0;i<n;i++) {
            int v = i;
            for(int j=0;j<d;j++) {
                sol[j].push_back((v%k)+1);
                v /= k;
            }
        }
        for(int i=0;i<d;i++) {
            for(int j=0;j<n;j++) {
                printf("%d ", sol[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

