#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    string s, r="";
    cin >> s;
    int h = 0;
    for(int i=0;i<s.size();) {
        int k = 1;
        while(s[i] == s[i+k]) k++;
        if(k > 1) {
            if(h == 0) {
                r += s[i]; r += s[i];
                h = 1;
            } else {
                r += s[i];
                h = 0;
            }
        } else {
            r += s[i];
            h = 0;
        }
        i += k;
    }
    cout << r << endl;
    return 0;
}

