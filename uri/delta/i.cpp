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

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const ll inf = (int)1e18;
int pai[100100], rnk[100100], sz[100100];
int pw[100100];

void init_set(int p)
{
    for(int i=0;i<p;i++) 
    {
        pai[i] = i;
        rnk[i] = 0;
        sz[i] = 1;
    }
}

int find_set(int x)
{
    if(x != pai[x]) pai[x] = find_set(pai[x]);
    return pai[x];
}

void merge_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if(x==y) return;
    if(rnk[x] > rnk[y])
    {
        pai[y] = x;
        sz[x] += sz[y];
        pw[x] += pw[y];
    }
    else
    {
        pai[x] = y;
        sz[y] += sz[x];
        if(rnk[x] == rnk[y]) rnk[y]++;
        pw[y] += pw[x];
    }
}

int main()
{
    int n, q;
    while(scanf("%d %d", &n, &q) && n) {
        init_set(n);
        int w = 0;
        for(int i=0;i<n;i++) scanf("%d", &pw[i]);
        for(int i=0;i<q;i++) {
            int t, a, b;
            scanf("%d %d %d", &t, &a, &b);
            a--; b--;
            if(t == 1) {
                merge_set(a, b);
            } else if(t == 2) {
                int la = find_set(a), lb = find_set(b);
                int r = find_set(0);
                if(pw[lb] > pw[la] && lb == r) w++; 
                if(pw[lb] < pw[la] && la == r) w++; 
            }
        }
        cout << w << endl;
    }
    return 0;
}

