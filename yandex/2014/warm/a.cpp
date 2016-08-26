#include <bits/stdc++.h>

using namespace std;

int b[11][11];
int dx[] = {0,0,1,1,1,-1,-1,-1};
int dy[] = {1,-1,0,1,-1,0,1,-1};

string solve() {
    string a[3];
    for(int i=0;i<3;i++) cin >> a[i];
    swap(a[0],a[2]);
    for(int i=0;i<10;i++) b[0][i] = b[i][0] = b[i][9] = b[9][i] = 1;
    b[a[0][0]-'a'+1][a[0][1]-'0'] = 8;
    b[a[2][0]-'a'+1][a[2][1]-'0'] = 2;
    b[a[1][0]-'a'+1][a[1][1]-'0'] = 2;
    for(int i=0;i<8;i++) b[a[2][0]-'a'+1+dx[i]][a[2][1]-'0'+dy[i]] |= 1;
    // rei ataca rei
    if(b[a[0][0]-'a'+1][a[0][1]-'0'] != 8) return "Strange";
    int x = a[1][0]-'a'+2, y = a[1][1]-'0';
    while(x > 0 && x < 9) {
        b[x][y] |= 1;
        if(b[x][y] == 3) break;
        x++;
    }
    x = a[1][0]-'a', y = a[1][1]-'0';
    while(x > 0 && x < 9) {
        b[x][y] |= 1;
        if(b[x][y] == 3) break;
        x--;
    }
    x = a[1][0]-'a'+1, y = a[1][1]-'0'+1;
    while(y > 0 && y < 9) {
        b[x][y] |= 1;
        if(b[x][y] == 3) break;
        y++;
    }
    x = a[1][0]-'a'+1, y = a[1][1]-'0'-1;
    while(y > 0 && y < 9) {
        b[x][y] |= 1;
        if(b[x][y] == 3) break;
        y--;
    }
    // não é atacado
    if(b[a[0][0]-'a'+1][a[0][1]-'0'] == 8) {
        for(int i=0;i<8;i++) if(b[a[0][0]-'a'+1+dx[i]][a[0][1]-'0'+dy[i]]%2 == 0) return "Normal";
        return "Stalemate";
    }
    // é atacado
    else {
        for(int i=0;i<8;i++) if(b[a[0][0]-'a'+1+dx[i]][a[0][1]-'0'+dy[i]]%2 == 0) return "Check";
        return "Checkmate";
    }
}

int main() {
    cout << solve() << endl;
    return 0;
}
