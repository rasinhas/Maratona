#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int a[111][111];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j] = i*j;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}

