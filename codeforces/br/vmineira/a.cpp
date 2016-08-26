#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    if(b > a && c > b && d > c && e > d) cout << "SIM" << endl;
    else cout << "NAO" << endl;
    return 0;
}

