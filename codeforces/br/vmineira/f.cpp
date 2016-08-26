#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

/* tabuleiro 9x9
 * 4 chaves
 * 4 baus
 * 8 portas
 * bfs -> 9x9x16*16*256
 */

int d[9][9][1<<4][1<<4][1<<8];
string g[9];
map <pii,int> pp;
map <char,int> c;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n, m, t;

int in(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }
char l(char c) { return c - 'A' + 'a'; }

int main() {
    cin >> n >> m >> t;
    for(int i=0;i<n;i++) cin >> g[i];
    memset(d,-1,sizeof(d));
    queue <pair<pii,pair<pii,int> > > q;
    int z = 0;
    c['c'] = 0;
    c['d'] = 1;
    c['h'] = 2;
    c['s'] = 3;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        if(g[i][j] == 'I') { q.push(mp(mp(i,j),mp(mp(0,0),0))); d[i][j][0][0][0] = 0; }
        if(g[i][j] == 'C' || g[i][j] == 'D' || g[i][j] == 'H' || g[i][j] == 'S') pp[mp(i,j)] = z++;
    }
    while(!q.empty()) {
        int x = q.front().ff.ff;
        int y = q.front().ff.ss;
        int i = q.front().ss.ff.ff;
        int b = q.front().ss.ff.ss;
        int p = q.front().ss.ss;
        if(g[x][y] == 'E') { cout << d[x][y][i][b][p] << endl; return 0; }
        q.pop();
        for(int j=0;j<4;j++) {
            int nx = x+dx[j];
            int ny = y+dy[j];
            if(in(nx,ny) && d[nx][ny][i][b][p] == -1 && g[nx][ny] != '#') {
                //se for chave 
                if(g[nx][ny] >= 'a' && g[nx][ny] <= 'z') {
                    //se tiver espaço no inventário
                    if(__builtin_popcount(i) < t) {
                        d[nx][ny][i|(1<<c[g[nx][ny]])][b][p] = d[x][y][i][b][p]+1;
                        q.push(mp(mp(nx,ny),mp(mp(i|(1<<c[g[nx][ny]]),b),p)));
                    }
                    d[nx][ny][i][b][p] = d[x][y][i][b][p]+1;
                    q.push(mp(mp(nx,ny),mp(mp(i,b),p)));
                }
                //se for porta 
                if(pp.count(mp(nx,ny))) {
                    //se a porta já estiver aberta
                    if((p&(1<<pp[mp(nx,ny)])) > 0) {
                        d[nx][ny][i][b][p] = d[x][y][i][b][p]+1;
                        q.push(mp(mp(nx,ny),mp(mp(i,b),p)));
                    }
                    //se tiver a chave 
                    else if((i&(1<<c[l(g[nx][ny])])) > 0) {
                        d[nx][ny][i][b][p|(1<<pp[mp(nx,ny)])] = d[x][y][i][b][p]+1;
                        q.push(mp(mp(nx,ny),mp(mp(i,b),p|(1<<pp[mp(nx,ny)]))));
                    }
                }
                // se for o bau
                if(g[nx][ny] == 'B') {
                    int nb = i|b;
                    int ni = 0;
                    for(int j=0;j<16;j++) {
                        if(__builtin_popcount(j) <= t) {
                            int ok = 1;
                            for(int k=0;k<4;k++) if(((1<<k)&j) > 0 && ((1<<k)&nb) == 0) ok = 0;
                            if(ok) {
                                nb -= j;
                                ni = j;
                                d[nx][ny][ni][nb][p] = d[x][y][i][b][p] + 1;
                                q.push(mp(mp(nx,ny),mp(mp(ni,nb),p)));
                            }
                        }
                    }
                }
                // se for '.', 'I' ou 'E'
                if(g[nx][ny] == 'I' || g[nx][ny] == 'E' || g[nx][ny] == '.') {
                    d[nx][ny][i][b][p] = d[x][y][i][b][p]+1;
                    q.push(mp(mp(nx,ny),mp(mp(i,b),p)));
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}


