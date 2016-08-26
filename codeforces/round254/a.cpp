#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string s[1111];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> s[i];
        for(int j=0;j<m;j++) {
            if(s[i][j] == '.') {
                if((i+j)%2) s[i][j] = 'B';
                else s[i][j] = 'W';
            }
        }
        cout << s[i] << endl;
    }
    return 0;
}

