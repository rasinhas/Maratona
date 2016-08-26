#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

pii a[5555];

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i].ff >> a[i].ss;
    sort(a,a+n);
    int last = 0, i;
    for(i=0;i<n;i++) {
        if(a[i].ss >= last) last = a[i].ss;
        else if(a[i].ff >= last) last = a[i].ff;
        else break;
    }
    cout << last << endl;
    return 0;
}
