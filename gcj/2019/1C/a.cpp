#include <bits/stdc++.h>

using namespace std;

string s[333];
int win[333];

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int a, won = 0;
        string r = "";
        cin >> a;
        memset(win,0,sizeof(win));
        for(int i=0;i<a;i++) cin >> s[i];
        int o = 1;
        for(int i=0;i<a;i++) {
            int msk = 0;
            for(int j=0;j<a;j++) {
                if(!win[j]) {
                    if(s[j][i%s[j].size()] == 'R') msk |= 1;
                    if(s[j][i%s[j].size()] == 'S') msk |= 2;
                    if(s[j][i%s[j].size()] == 'P') msk |= 4;
                }
            }
            if(msk == 7) {
                o = 0;
                break;
            }
            if(msk == 3) r += 'R';
            if(msk == 6) r += 'S';
            if(msk == 5) r += 'P';
            if(msk == 1) r += 'P';
            if(msk == 2) r += 'R';
            if(msk == 4) r += 'S';
            for(int j=0;j<a;j++) if(r[i] != s[j][i%s[j].size()]) {
                if(!win[j]) {
                    won++;
                    win[j] = 1;
                }
            }
            if(won == a) break;
        }
        if(o == 0) r = "IMPOSSIBLE";
        printf("Case #%d: ", t);
        cout << r << endl;
    }
    return 0;
}
