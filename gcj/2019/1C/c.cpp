#include <bits/stdc++.h>

//https://codingcompetitions.withgoogle.com/codejam/round/00000000000516b9/0000000000134cdf

using namespace std;

int grundy[51][51][51][51];
string grid[51];

int solve(int r0, int rn, int c0, int cn) {
    if(r0 > rn || c0 > cn) return 0;
    if(grundy[r0][rn][c0][cn] != -1) return grundy[r0][rn][c0][cn];
    set <int> reach;
    for(int i=r0;i<=rn;i++) {
        int o = 1;
        for(int j=c0;j<=cn;j++) if(grid[i][j] == '#') o = 0;
        if(!o) continue;
        reach.insert(solve(r0,i-1,c0,cn)^solve(i+1,rn,c0,cn));
    }
    for(int i=c0;i<=cn;i++) {
        int o = 1;
        for(int j=r0;j<=rn;j++) if(grid[j][i] == '#') o = 0;
        if(!o) continue;
        reach.insert(solve(r0,rn,c0,i-1)^solve(r0,rn,i+1,cn));
    }
    int mex = 0;
    for(set<int>::iterator it=reach.begin();it!=reach.end();it++) {
        if(*it == mex) mex++;
    }
    return grundy[r0][rn][c0][cn] = mex;
}

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int r, c;
        int count = 0;
        cin >> r >> c;
        memset(grundy,-1,sizeof(grundy));
        for(int i=0;i<r;i++) cin >> grid[i];
        solve(0,r-1,0,c-1);
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) {
            int o = 1;
            for(int k=0;k<c;k++) if(grid[i][k] == '#') o = 0;
            if(o && (solve(0,i-1,0,c-1)^solve(i+1,r-1,0,c-1)) == 0) count++;
            o = 1;
            for(int k=0;k<r;k++) if(grid[k][j] == '#') o = 0; 
            if(o && (solve(0,r-1,0,j-1)^solve(0,r-1,j+1,c-1)) == 0) count++;
        }
        printf("Case #%d: %d\n", t, count);
    }
    return 0;
}
