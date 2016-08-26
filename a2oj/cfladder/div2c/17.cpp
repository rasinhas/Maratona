#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[111];

int check(int n, int k) {
    for(int i=0;i<n;i++) if(a[i] < i/k) return 0;
    return 1;
}

int main() {
    int n, ma = 0;
    cin >> n;
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    sort(a,a+n);
    for(int i=1;i<=n;i++) if(check(n,i)) {
        cout << i << endl;
        break;
    }
    return 0;
}

