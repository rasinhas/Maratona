#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int t[2222][2222];
ll d1[4444], d2[4444];

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
        scanf("%d", &t[i][j]);
        d1[n-i+j-1] += 1ll*t[i][j];
        d2[i+j] += 1ll*t[i][j];
    }
    ll x[2], y[2], b[2] = {-1,-1};
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
            if(d1[n-i+j-1] + d2[i+j] - t[i][j] > b[(i+j)%2]) {
                b[(i+j)%2] = d1[n-i+j-1] + d2[i+j] - t[i][j];
                x[(i+j)%2] = i+1;
                y[(i+j)%2] = j+1;
            }
    }
    cout << b[0]+b[1] << endl;
    cout << x[0] << " " << y[0] << " " << x[1] << " " << y[1] << endl;
    return 0;
}

