#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string a[11], s="";
int b[22];

int main() {
    int p = 0;
    for(int i=0;i<10;i++) {
        cin >> a[i];
        s += a[i];
    }
    for(int i=0;i<s.size();i++) {
        if(s[i] == 'X') b[i] = 10;
        else if(s[i] == '/') b[i] = 10-b[i-1];
        else b[i] = s[i]-'0';
    }
    for(int i=0;i<s.size()-a[9].size();i++) {
        p += b[i];
        if(s[i] == 'X') p += b[i+1]+b[i+2];
        else if(s[i] == '/') p += b[i+1];
    }
    for(int i=s.size()-a[9].size();i<s.size();i++) p += b[i];
    cout << p << endl;
    return 0;
}

