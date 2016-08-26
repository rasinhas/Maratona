#include <bits/stdc++.h>

using namespace std;

int vis[22];
int a[5][5];

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        memset(vis,0,sizeof(vis));
        int r, c;
        cin >> r;
        for(int i=1;i<=4;i++) for(int j=1;j<=4;j++) {
            cin >> a[i][j];
            if(i == r) vis[a[i][j]]++;
        }
        cin >> r;
        for(int i=1;i<=4;i++) for(int j=1;j<=4;j++) {
            cin >> a[i][j];
            if(i == r) vis[a[i][j]]++;
        }
        int s = -1, ok = 1;;
        for(int i=1;i<=16;i++) {
            if(vis[i] == 2) {
                if(s != -1) ok = 0;
                s = i;
            }
        }
        printf("Case #%d: ", t);
        if(s == -1) cout << "Volunteer cheated!" << endl;
        else if(ok == 0) cout << "Bad magician!" << endl;
        else cout << s << endl;
    }
    return 0;
}
