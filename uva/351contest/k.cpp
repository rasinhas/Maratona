#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int p[2222];
const int M = 2001;
int lcs[2222][2222];

int main() {
    int n;
    string s, sr;
    while(cin >> s && ! cin.eof()) {
        sr = s;
        reverse(sr.begin(),sr.end());
        scanf("%d", &n);
        memset(p,0,sizeof(p));
        memset(lcs,0,sizeof(lcs));
        for(int i=0;i<n;i++) {
            int k;
            scanf("%d", &k);
            k--;
            p[k] = 1;
        }
        int best = 0;
        for(int i=s.size()-1;i>=0;i--) {
            for(int j=s.size()-1;j>=0;j--) {
                lcs[i][j] = max(lcs[i+1][j],lcs[i][j+1]);
                if(s[i] == sr[j]) {
                    int t = 1;
                    if(p[i]) t += M;
                    if(p[s.size()-1-j]) t += M;
                    lcs[i][j] = max(lcs[i+1][j+1]+t,lcs[i][j]);
                }
                best = max(best,lcs[i][j]);
            }
        }
        cout << best%M << endl;
    }
    return 0;
}

