#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string t[1111];
int tt[1111][1111];
int dh[1111][1111], dv[1111][1111], vis[1111][1111];
int aux[1111][1111], aux2[1111][1111];
int si = -1, sj = -1;
int n, m;

int walk(int pi, int pj, int sh) {
    int sv = 1;
    int i = 0;
    while(1) {
        if(dh[pi][pj] == sh) {
            if(dv[pi][pj] == sv) return sv;
            else if(dv[pi][pj] > sv) pi++;
            else if(dv[pi][pj] < sv) return -1;
        } else if(dh[pi][pj] > sh) {
            if(dv[pi][pj] == sv) pj++;
            else if(dv[pi][pj] > sv) return dv[pi][pj];
            else if(dv[pi][pj] < sv) return -1;
        } else return -1;
        i++;
    }
}

int valid(int pi, int pj, int sh, int sv) {
    memset(vis,0,sizeof(vis));
    for(int i=0;i<sv;i++) for(int j=0;j<sh;j++) vis[pi+i][pj+j] = 1;
    while(1) {
        if(dv[pi][pj] == sv && dh[pi][pj] == sh) {
            break;
        }
        else if(dh[pi][pj] > sh) {
            for(int i=0;i<sv;i++) vis[pi+i][pj+sh] = 1;
            pj++;
        }
        else if(dv[pi][pj] > sv) {
            for(int i=0;i<sh;i++) vis[pi+sv][pj+i] = 1;
            pi++;
        }
        else break;
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(tt[i][j] != vis[i][j]) {
        return 0;
    }
    return 1;
}

int main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> t[i];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) tt[i][j] = (t[i][j] == 'X' ? 1 : 0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(t[i][j] == 'X') {
                si = i;
                sj = j;
                break;
            }
        }
        if(si != -1) break;
    }
    for(int i=0;i<n;i++) {
        int s=0, e=0;
        while(s < m) {
            if(t[i][e+1] == 'X') e++;
            else {
                dh[i][s] = e-s+1;
                if(t[i][s] == '.') dh[i][s] = 0;
                s++;
                if(e < s) e = s;
            }
        }
    }
    for(int i=0;i<m;i++) {
        int s=0, e=0;
        while(s < n) {
            if(t[e+1][i] == 'X') e++;
            else {
                dv[s][i] = e-s+1;
                if(t[s][i] == '.') dv[s][i] = 0;
                s++;
                if(e < s) e = s;
            }
        }
    }
    int sv = walk(si,sj,dh[si][sj]);
    int ret = 1e9;
    if(sv != -1 && valid(si,sj,dh[si][sj],sv)) ret = sv*dh[si][sj];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) aux[i][j] = dh[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        dh[j][i] = dv[i][j];
        aux2[i][j] = tt[i][j];
    }
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
        dv[j][i] = aux[i][j];
        tt[j][i] = aux2[i][j];
    }
    swap(n,m);
    swap(si,sj);
    sv = walk(si,sj,dh[si][sj]);
    if(sv != -1 && valid(si,sj,dh[si][sj],sv)) ret = min(ret,sv*dh[si][sj]);
    cout << ( ret == 1e9 ? -1 : ret ) << endl;
    return 0;
}
