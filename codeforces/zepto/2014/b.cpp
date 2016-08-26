#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int spid[2222];
string grid[2222];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int move(char k) {
    if(k == 'U') return 3;
    if(k == 'D') return 2;
    if(k == 'L') return 1;
    if(k == 'R') return 0;
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    for(int i=0;i<n;i++) cin >> grid[i];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) if(grid[i][j] != '.'){
            if(grid[i][j] == 'D') continue;
            if(grid[i][j] == 'U') {
                if(i%2 == 0) spid[j]++;
                continue;
            }
            int nc = j + dx[move(grid[i][j])]*i;
            if(nc >= 0 && nc < m) spid[nc]++;
        }
    }
    for(int i=0;i<m;i++) {
        if(i) cout << " ";
        cout << spid[i];
    }
    cout << endl;
    return 0;
}

