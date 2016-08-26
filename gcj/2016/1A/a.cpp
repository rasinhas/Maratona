#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        string s, r="";
        printf("Case #%d: ", t);
        cin >> s;
        r += s[0];
        for(int i=1;i<s.size();i++) {
            if(s[i] >= r[0]) r = s[i]+r;
            else r = r+s[i];
        }
        cout << r << endl;
    }
    return 0;
}
