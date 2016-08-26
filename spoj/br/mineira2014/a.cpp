#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[1111];

int main() {
    int n;
    while(cin >> n && n) {
        for(int i=1;i<=n;i++) cin >> a[i];
        sort(a+1,a+n+1,greater<int>());
        int i;
        for(i=1;i<=n;i++) if(i >= a[i]) break;
        cout << a[i] << endl;
    }
    return 0;
}

