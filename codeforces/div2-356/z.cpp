#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    ll x = 0;
    ll z, c = 0;
    cin >> z;
    for(ll j=1e5;j>0;j--) {
        while(z >= j*j*j) {
            z -= j*j*j;
            c++;
        }
    }
    //x = max(x,c);
    cout << c << endl;
    return 0;
}

