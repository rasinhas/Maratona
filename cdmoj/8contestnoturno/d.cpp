#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

map<string,string> n, p;

int main() {
    int i = 0;
    string a, b, c;
    string p1, p2;
    int ok = 1;
    while(cin >> a >> b >> c && !cin.eof()) {
        if(i == 0) p1 = a;
        if(i == 2) p2 = a;
        n[a] = c;
        p[a] = b;
        i++;
    }
    while(p1 != p2) {
        if(p[n[p1]] != p1) ok = 0;
        p1 = n[p1];
        if(!ok) break;
    }
    cout << (ok ? "sana" : "insana") << endl;
    return 0;
}

