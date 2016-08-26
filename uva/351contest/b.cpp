#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int p[222222], b[2][222222];

int main() {
    int n, c;
    while(scanf("%d %d", &n, &c) != EOF) {
        for(int i=0;i<n;i++) scanf("%d", &p[i]);
        for(int i=0;i<n;i++) b[0][i] = b[1][i] = -1e9;
        b[0][0] = 0;
        b[1][0] = -p[0]-c;
        for(int i=1;i<n;i++) {
            b[0][i] = max(b[0][i-1],b[1][i-1]+p[i]);
            b[1][i] = max(b[1][i-1],b[0][i-1]-p[i]-c);
        }
        cout << max(b[0][n-1],b[1][n-1]) << endl;
    }
    return 0;
}

