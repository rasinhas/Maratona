#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz size()

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const ll inf = (int)1e18;

int b[111];

int go(int u) {
    if(b[u] == u) return u;
    return go(b[u]);
}

int main() 
{
    int n, k, q;
    while(scanf("%d", &n) && n) {
        for(int i=1;i<=n;i++) cin >> b[i];
        cin >> q;
        cout << go(q) << endl;
    }
    return 0;
}
