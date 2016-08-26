#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int w[111];

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int m = 0;
    for(int i=0;i<26;i++) {
        cin >> w[i];
        m = max(m,w[i]);
    }
    int r = 0;
    for(int i=0;i<s.size();i++) {
        r += w[s[i]-'a']*(i+1);
    }
    for(int i=0;i<k;i++) {
        r += m*(i+s.size()+1);
    }
    cout << (r) << endl;
    return 0;
}

