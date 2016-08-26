#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int mod(int a) { return a > 0 ? a : -a; }

int main() {
    int n;
    cin >> n;
    int cur, last = 1, r=0;
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        if(s[0] == 'A') cur = 1;
        if(s[0] == 'B') cur = 2;
        if(s[0] == 'D') cur = 3;
        if(s[0] == 'G') cur = 3;
        if(s[0] == 'J') cur = 3;
        if(s[0] == 'P') cur = 1;
        if(s[0] == 'O') cur = 1;
        if(s[0] == 'M') cur = 2;
        if(s[0] == 'K') cur = 3;
        if(s[0] == 'R') cur = 1;
        if(s[0] == 'S') cur = 2;
        if(s[0] == 'T') cur = 3;
        if(s[0] == 'W') cur = 3;
        r += mod(cur-last);
        last = cur;
    }
    cout << r << endl;
    return 0;
}

