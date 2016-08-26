#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector <pii> adj[22222];
int d[22222];

int main() {
    int c, v;
    while(scanf("%d %d", &c, &v) != EOF) {
        int x, y, z;
        for(int i=0;i<v;i++) {
            cin >> x >> y >> z;
            x--; y--;
            adj[x].push_back(make_pair(y+c,z));
            adj[y+c].push_back(make_pair(x,z));
            adj[x+c].push_back(make_pair(y,z));
            adj[y].push_back(make_pair(x+c,z));
        }
        memset(d,-1,sizeof(d));
        priority_queue <pii> q;
        q.push(make_pair(0,0));
        while(!q.empty()) {
            x = q.top().ss;
            int dd = -q.top().ff;
            q.pop();
            if(d[x] > -1) continue;
            d[x] = dd;
            for(int i=0;i<adj[x].size();i++) {
                int y = adj[x][i].ff;
                int dy = adj[x][i].ss;
                if(d[y] == -1) q.push(make_pair(-(dd+dy),y));
            }
        }
        for(int i=0;i<2*c;i++) adj[i].clear();
        cout << d[c-1] << endl;
    }
    return 0;
}

