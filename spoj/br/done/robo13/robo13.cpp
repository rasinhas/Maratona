#include <bits/stdc++.h>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int t[1111][1111];
int a, b;

void go() {
    t[a][b] = 0;
    for(int i=0;i<4;i++) {
        if(t[a+dx[i]][b+dy[i]] == 1) {
            a = a+dx[i];
            b = b+dy[i];
            go();
            return ;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    cin >> a >> b;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d", &t[i][j]);
    go();
    printf("%d %d\n", a, b);
    return 0;
}
