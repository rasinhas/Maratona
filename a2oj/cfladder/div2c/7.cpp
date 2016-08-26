#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int n, m;
    cin >> n >> m;
    cout << min(m,n)+1 << endl;
    for(int i=0;i<=min(m,n);i++) cout << i << " " << min(m,n)-i << endl;
    return 0;
}

