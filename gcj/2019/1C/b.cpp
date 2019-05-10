#include <bits/stdc++.h>

using namespace std;

vector <int> v[4][5];
int vis[5];

int main() {
    int T, W;
    cin >> T >> W;
    for(int t=1;t<=T;t++) {
        string s = "";
        char c;
        for(int j=0;j<4;j++) for(int i=0;i<5;i++) v[j][i].clear();
        memset(vis,0,sizeof(vis));
        for(int i=0;i<119;i++) {
            cout << i*5 + 1 << endl;
            cin >> c;
            v[0][c-'A'].push_back(i);
        }
        for(int i=0;i<5;i++) if(!vis[i] && v[0][i].size() < 24) {
            vis[i] = 1;
            s += 'A'+i;
        }
        int next = s[0]-'A';
        for(int i=0;i<v[0][next].size();i++) {
            cout << v[0][next][i]*5 + 2 << endl;
            cin >> c;
            v[1][c-'A'].push_back(v[0][next][i]);
        }
        for(int i=0;i<5;i++) if(!vis[i] && v[1][i].size() < 6) {
                vis[i] = 1;
                s += 'A'+i;
        }
        next = s[1]-'A';
        for(int i=0;i<v[1][next].size();i++) {
            cout << v[1][next][i]*5 + 3 << endl;
            cin >> c;
            v[2][c-'A'].push_back(v[1][next][i]);
        }
        for(int i=0;i<5;i++) if(!vis[i] && v[2][i].size() < 2) {
            vis[i] = 1;
            s += 'A'+i;
        }
        next = s[2]-'A';
        for(int i=0;i<v[2][next].size();i++) {
            cout << v[2][next][i]*5 + 4 << endl;
            cin >> c;
            v[3][c-'A'].push_back(v[2][next][i]);
        }
        for(int i=0;i<5;i++) if(!vis[i] && v[3][i].size() < 1) {
            vis[i] = 1;
            s += 'A'+i;
        }
        for(int i=0;i<5;i++) if(!vis[i]) s += 'A'+i;
        cout << s << endl;
        char r;
        cin >> r;
        if(r == 'N') break;
    }
    return 0;
}
