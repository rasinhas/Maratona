#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string s1, s2;
int r = 0;

int check(int sz, string s) {
    if(s.size()%sz) return 0;
    for(int i=0;i<s.size();i++) if(s1[i%sz] != s[i]) return 0;
    return 1;
}

int main() {
    cin >> s1 >> s2;
    for(int i=1;i<=s1.size();i++) {
        if(s1.size()%i) continue;
        if(check(i,s1) && check(i,s2)) r++;
    }
    cout << r << endl;
    return 0;
}

