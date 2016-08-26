#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string s[2];
int n, ret;

void mark(int r, int c) {
    ret++;
    s[r][c] = 'G';
    if(s[1^r][c] == '.') s[1^r][c] = '*';
    for(int i=c+1;s[r][i]!='X';i++) s[r][i] = '*';
    for(int i=c-1;s[r][i]!='X';i--) s[r][i] = '*';
}

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        ret = 0;
        string a;
        cin >> n;
        s[0] = s[1] = "X";
        cin >> a;
        s[0] += a + "X";
        cin >> a;
        s[1] += a + "X";
        n += 2;
        for(int i=1;i<n-1;i++) for(int j=0;j<2;j++) {
            if(s[j][i] == '.' && s[j][i-1] == 'X' && s[j][i+1] == 'X') {
                if(s[1^j][i] == 'X') mark(j,i);
                else mark(1^j,i);
            }
        }
        for(int i=0;i<n;i++) for(int j=0;j<2;j++) if(s[j][i] == '.') mark(j,i);
        //cout << s[0] << endl << s[1] << endl;
        printf("Case #%d: %d\n", t, ret);
    }
    return 0;
}
