#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int d[111][6];

int main() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<6;j++) {
            string s;
            int m = 0;
            cin >> s;
            for(int k=0;k<s.size();k++) m |= (1<<(s[k]-'A'));
            d[i][j] = m;
        }
    }
    for(int i=0;i<6;i++) {
        int m = d[0][i];
        for(int j=1;j<n;j++) m &= d[j][i];
        for(char j='A';j<='L';j++) if(m&(1<<(j-'A'))) cout << j;
        if(i < 5) cout << " ";
    }
    cout << endl;
    return 0;
}

