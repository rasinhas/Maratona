#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

pii a[1111], b[1111];

int mod(int a) { return max(a,-a); }

vector <pii> ret;

int main() {
    int n, sa=0, sb=0;
    cin >> n;
    for(int i=0;i<n;i++) {
        scanf("%d", &a[i].ff);
        a[i].ss = i+1;
        sa += a[i].ff;
    }
    for(int i=0;i<n;i++) {
        scanf("%d", &b[i].ff);
        b[i].ss = i+1;
        sb+= b[i].ff;
    }
    sort(a,a+n);
    sort(b,b+n);
    if(sa > sb) reverse(b,b+n);
    else reverse(a,a+n);
    for(int i=0;i<n;i++) cout << a[i].ss << " " << b[i].ss << endl;
    return 0;
}

