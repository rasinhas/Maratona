#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
typedef pair<int, int> pii;
typedef unsigned long long ull;

set<ull> s[3];

int p[2];
bool vis[3][1<<25];

int encode(int r, int c) {
    int ret=0;
    for(int j=0;j<3;j++) ret |= ((r & (1<<j)) != 0) * (1<<j);
    for(int j=0;j<3;j++) ret |= ((c & (1<<j)) != 0) * (1<<(j+3));
    return ret;
}

int encode_stone(int i, int r, int c) {
    return (1<<(6*i)) * encode(r, c);
}

pii decode_stone(int i, int x) {
    int r=0, c=0;
    for(int pos=0, j=(1<<(6*i)) ; j<(1<<(6*i+3)); j*=2, pos++) if(x & j) r |= (1<<pos);
    for(int pos=0, j=(1<<(6*i+3)) ; j<(1<<(6*i+6)); j*=2, pos++) if(x & j) c |= (1<<pos);
    return pii(r, c);
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(int flag, int ini) {
    queue<pii> q;
    vis[flag][ini] = 1;
    q.push(pii(ini, 0));
    while(!q.empty()) {
        ini = q.front().first;
        int d = q.front().second;
        q.pop();
        pii stone[4];
        for(int i=0;i<4;i++) stone[i] = decode_stone(i, ini);
        ull tab_ini = 0;
        for(int i=0;i<4;i++) tab_ini |= 1ull<<(8*stone[i].first + stone[i].second);
        s[flag].insert(tab_ini);
        for(int i=0;i<4;i++) {
            int x, y;
            for(int j=0;j<4;j++) {
                x = stone[i].first + dx[j];
                y = stone[i].second + dy[j];
                if(x < 0 || x >= 8 || y < 0 || y >= 8) continue;
                int k;
                for(k=0;k<4;k++) if(i != k && pii(x, y) == stone[k]) break;
                if(k != 4) {
                    x += dx[j];
                    y += dy[j];
                    if(x < 0 || x >= 8 || y < 0 || y >= 8) continue;
                    k=0;
                    for(k=0;k<4;k++) if(i != k && pii(x, y) == stone[k]) break;
                    if(k != 4) continue;
                }
                int ini2 = ini;
                for(k=(1<<(6*i));k<(1<<(6*i+6));k*=2) if(ini2 & k) ini2 -= k;
                ini2 |= encode_stone(i, x, y);
                if(!vis[flag][ini2]) {
                    vis[flag][ini2] = 1;
                    if(d < 4) q.push(pii(ini2, d+1));
                }
            }
        }
    }
    return 0;
}

int main() {
    for(int pos=0;pos<2;pos++) for(int i=0;i<4;i++) {
        int r;
        int c;
        cin>>r>>c; 
        r--; c--;
        p[pos] |= encode_stone(i, r, c);
    }
    bfs(0, p[0]);
    bfs(1, p[1]);
    int valid=0;
    for(set<ull>::iterator it = s[0].begin(); it != s[0].end(); it++) if(s[1].count(*it)) {
        valid=1;
        break;
    }
    if(valid) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
