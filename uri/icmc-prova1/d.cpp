#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string s[55], d[55];
int cn[55];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int l, c, p;
        scanf("%d%d", &l, &c);
        memset(cn,0,sizeof(cn));
        for(int i=0;i<l;i++) cin >> s[i];
        scanf("%d", &p);
        for(int i=0;i<p;i++) cin >> d[i];
        for(int i=0;i<l;i++) for(int j=0;j<c;j++) for(int k=0;k<p;k++) {
            int m = 0;
            if(j + d[k].size() - 1 < c) for(m=0;m<d[k].size();m++) {
                if(d[k][m] != s[i][j+m]) break;
            }
            if(m == d[k].size()) cn[k]++;
            if(d[k].size() == 1) continue;
            m = 0;
            if(i + d[k].size() - 1 < l) for(m=0;m<d[k].size();m++) {
                if(d[k][m] != s[i+m][j]) break;
            }
            if(m == d[k].size()) cn[k]++;

        }
        for(int i=0;i<p;i++) cout << cn[i] << endl;
    }
    return 0;
}

