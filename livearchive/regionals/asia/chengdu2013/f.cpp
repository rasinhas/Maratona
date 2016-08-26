#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

int n, m;
int pai[100100], rank[100100], sz[100100];
int f[30];

void init() {
    for(int i=0;i<n;i++) {
        pai[i] = i;
        rank[i] = 0;
        sz[i] = 1;
    }
}

int find(int x) {
    if(x != pai[x]) pai[x] = find(pai[x]);
    return pai[x];
}

int merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return 0;
    if(rank[x] > rank[y]) {
        pai[y] = x;
        sz[x] += sz[y];
    }
    else {
        pai[x] = y;
        sz[y] += sz[x];
        if(rank[x] == rank[y]) rank[y]++;
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    f[0] = 1; f[1] = 2;
    for(int i=2;f[i-1]<1e5;i++) f[i] = f[i-1]+f[i-2];
    for(int t=1;t<=T;t++) {
        int a, b, c;
        vector <pair<int,int> > white, all;
        cin >> n >> m;
        for(int i=0;i<m;i++) {
            scanf("%d%d%d", &a, &b, &c);
            a--; b--;
            if(c == 1) white.push_back(make_pair(a,b));
            else all.push_back(make_pair(a,b));
        }
        int bl = all.size();
        all.insert(all.end(),white.begin(),white.end());
        printf("Case #%d: ", t);
        init();
        int miw = 0;
        for(int i=0;i<all.size();i++) if(merge(all[i].ff,all[i].ss) && i >= bl) miw++;
        if(sz[find(0)] < n) printf("No\n");
        else {
            init();
            int maw = 0;
            for(int i=0;i<white.size();i++) if(merge(white[i].ff,white[i].ss)) maw++;
            int fl = 0;
            for(int i=0;f[i-1]<1e5;i++) if(f[i] >= miw && f[i] <= maw) fl = 1;
            printf("%s\n", fl ? "Yes" : "No");
        }
    }
    return 0;
}
