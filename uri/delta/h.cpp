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

int solve(int l, int d, int c)
{
    int best;
    if(l <= c) return l-d;
    int k = (l+c-1)/c;
    best = max(/*l-(2*k-1)*d*/ ,solve(l-(2*k-1),d-1,c));
    return best;
}

int main() 
{
    int l, d, c, r;
    while(scanf("%d%d%d", &l, &d, &c) != EOF) {
        r = solve(l,d,c);
        if(r < 1) cout << "impossivel" << endl;
        else cout << r << endl;
    }
    return 0;
}
