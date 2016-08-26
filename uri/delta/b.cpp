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
int n;

pii p[111];

void solve(int v) {
    int less=0, eq=0;
    for(int i=0;i<n;i++) {
        if(p[i].ss < v) less += (p[i].ss - p[i].ff + 1);
        else if(p[i].ff > v) continue;
        else {
            less += (v - p[i].ff);
            eq++;
        }
    }
    if(eq == 0) printf("%d not found\n", v);
    else printf("%d found from %d to %d\n", v, less, less+eq-1);
}

int main() 
{
    while(scanf("%d", &n) != EOF) {
        int s, e, k;
        for(int i=0;i<n;i++) cin >> p[i].ff >> p[i].ss;
        sort(p,p+n);
        cin >> k;
        solve(k);
    }
    return 0;
}
