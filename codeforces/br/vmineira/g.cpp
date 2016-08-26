#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

bool check(string s, int d) {
    int sz = s.size()/d;
    for(int i=0;i<d/2;i++) {
        for(int j=0;j<sz;j++) {
            if(s[i*sz+j] != s[(d-i-1)*sz+j]) return 0;
        }
    }
    return 1;
}

int main() {
    int n, r = 1;
    string s;
    cin >> s;
    n = s.size();
    for(int i=n;i>0;i--) {
        if(n%i == 0){
            if(check(s,i)) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}

