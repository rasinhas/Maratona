#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int pw[11];

string transform(int n) {
    char c[11];
    sprintf(c,"%d",n);
    int l = strlen(c);
    int a = 0;
    for(int i=0;i<l;i++) {
        if(a == 1) c[i] = '1';
        if(c[i] > '1') {
            c[i] = '1';
            a = 1;
        }
    }
    string s = c;
    return s;
}

int main() {
    int n;
    cin >> n;
    string s = transform(n);
    int p = 1, r = 0;
    for(int i=s.size()-1;i>=0;i--) {
        if(s[i] == '1') r += p;
        p <<= 1;
    }
    cout << r << endl;
    return 0;
}

