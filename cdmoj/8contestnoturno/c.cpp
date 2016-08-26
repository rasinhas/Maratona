#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

set <int> il;

int main() {
    int n, a;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a;
        il.insert(a);
    }
    while(scanf("%d", &n) != EOF) {
        cout << (il.count(n) ? "sim" : "nao") << endl;
    }
    return 0;
}

