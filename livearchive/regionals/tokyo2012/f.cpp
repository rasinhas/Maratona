#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int inf = (int)1e9;
int pai[111111], rnk[1111111], sz[111111], d[111111];

void init_set(int p)
{
    for(int i=0;i<p;i++)
    {
        pai[i] = i;
        rnk[i] = 0;
        sz[i] = 1;
        d[i] = 0;
    }
}

int find_set(int x)
{
    if(x != pai[x]) {
        int k = find_set(pai[x]);
        d[x] = d[x] + d[pai[x]];
        pai[x] = k;
    }
    return pai[x];
}

int find_dif(int x, int y) {
    int dx = 0, dy = 0;
    while(x != y) {
        if(sz[x] >= sz[y]) {
            dy += d[y];
            y = pai[y];
        } else {
            dx += d[x];
            x = pai[x];
        }
    }
    return dy - dx;
}

void merge_set(int x, int y, int dif)
{
    int px = find_set(x);
    int py = find_set(y);
    if(px==py) return;
    if(rnk[px] > rnk[py])
    {
        pai[py] = px;
        sz[px] += sz[py];
        d[py] = d[x] - d[y] + dif;
    }
    else
    {
        pai[px] = py;
        sz[py] += sz[px];
        if(rnk[px] == rnk[py]) rnk[py]++;
        d[px] = d[y] - d[x] - dif;
    }
}

int main() {
    int n, m;
    while(scanf("%d%d", &n, &m) && n) {
        init_set(n);
        for(int i=0;i<m;i++) {
            char s;
            int a, b, c;
            cin >> s;
            if(s == '!') {
                cin >> a >> b >> c;
                a--; b--;
                merge_set(a,b,c);
            } else {
                cin >> a >> b;
                a--; b--;
                if(find_set(a) != find_set(b)) cout << "UNKNOWN" << endl;
                else cout << find_dif(a,b) << endl;
            }
        }
    }
    return 0;
}

