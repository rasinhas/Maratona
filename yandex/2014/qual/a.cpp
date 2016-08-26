#include <bits/stdc++.h>

using namespace std;

int a[555][555];
int dx[] = {0,0,1,1,1,-1,-1,-1};
int dy[] = {1,-1,0,1,-1,0,1,-1};

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d", &a[i][j]);
    int best=0, x, y;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
        int cur = 8*a[i][j];
        for(int k=0;k<8;k++) cur += a[i+dx[k]][j+dy[k]];
        if(cur > best) {
            best = cur;
            x = i;
            y = j;
        }
    }
    cout << x << " " << y << endl;
    return 0;
}
