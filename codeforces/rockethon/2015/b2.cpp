#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int p[55];

int main() {
    int n;
    ll k;
    cin >> n >> k;
    int f = 0, b = n-1;
    k--;
    for(int i=0;i<n-1;i++) {
        if((k&(1ll<<(n-i-2))) == 0ll){
            p[f++] = (i+1);
        }
        else {
            p[b--] = (i+1);
        }
    }
    p[f] = n;
    cout << p[0];
    for(int i=1;i<n;i++) cout << " " << p[i];
    cout << endl;
    return 0;
}
