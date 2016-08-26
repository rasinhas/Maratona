#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[111111], b[111111];

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b,b+n);
    int c = 0;
    for(int i=0;i<n;i++) if(b[i] != a[i]) c++;
    if(c <= 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

