#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string c[111];
int vis[11][11];
int n;

int decode(char c) {
    if(c > '0' && c < '6') return c-'1';
    else {
        if(c == 'R') return 5;
        if(c == 'G') return 6;
        if(c == 'B') return 7;
        if(c == 'Y') return 8;
        if(c == 'W') return 9;
    }
}

char encode(int k) {
    if(k < 5) return '1'+k;
    else {
        if(k == 5) return 'R';
        if(k == 6) return 'G';
        if(k == 7) return 'B';
        if(k == 8) return 'Y';
        if(k == 9) return 'W';
    }
}

int valid(int msk) {
    int v[111];
    memset(v,0,sizeof(v));
    for(int i=0;i<10;i++) {
        if(msk&(1<<i)) {
            char k = encode(i);
            for(int j=0;j<n;j++) {
                if(i < 5 && c[j][1] == k) v[j]|=1;
                else if(i >= 5 && c[j][0] == k) v[j]|=2;
            }
        }
    }
    int sol = 0, zc = 0;
    set <string> zz;
    vector <string> nn, cc;
    for(int i=0;i<n;i++) {
        if(v[i] == 3) sol++;
        if(v[i] == 2) cc.push_back(c[i]);
        if(v[i] == 1) nn.push_back(c[i]);
        if(v[i] == 0) zz.insert(c[i]);
    }
    if(zz.size() > 1) return 0;
    string z = "00";
    if(zz.size()) string z = (*zz.begin());
    int ok = 1;
    for(int i=0;i<nn.size();i++) {
        for(int j=i+1;j<nn.size();j++) {
            if(nn[i] == nn[j]) continue;
            if(nn[i][1] == nn[j][1]) ok = 0;
            if(nn[i][1] == z[1]) ok = 0;
        }
    }
    for(int i=0;i<cc.size();i++) {
        for(int j=i+1;j<cc.size();j++) {
            if(cc[i] == cc[j]) continue;
            if(cc[i][0] == cc[j][0]) ok = 0;
            if(cc[i][0] == z[0]) ok = 0;
        }
    }
    return ok;
}

set <int> ss;

int main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> c[i];
        vis[decode(c[i][0])][decode(c[i][1])] = 1;
    }
    int ret = 100;
    for(int i=0;i<(1<<10);i++) {
        if(valid(i)) ret = min(ret,__builtin_popcount(i));
    }
    cout << ret << endl;
    return 0;
}

