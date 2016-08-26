#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int a, b, c, d, e, f;
    int g, h;
    cin >> a >> b >> c >> d >> e >> f;
    g = a+b+c;
    h = d+e+f;
    cin >> a;
    int ma = (g+4)/5;
    int mb = (h+9)/10;
    if(a < ma+mb) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}

