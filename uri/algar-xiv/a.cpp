#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string add(string a, string b) {
    string r;
    int c = 0;
    if(a.size() < b.size()) swap(a,b);
    for(int i=0;i<a.size();i++) {
        int v = a[a.size()-i-1]-'0'+c;
        if(i < b.size()) v += b[b.size()-i-1]-'0';
        c = v/10;
        v = v%10;
        r += v+'0';
    }
    if(c) r += '0'+c;
    reverse(r.begin(),r.end());
    return r;
}

string mult(string a, int bb) {
    string r = "0";
    string b;
    while(bb) {
        b += bb%10+'0';
        bb /= 10;
    }
    reverse(b.begin(),b.end());
    if(a.size() < b.size()) swap(a,b);
    for(int i=b.size()-1;i>=0;i--) {
        string sr="";
        for(int j=0;j<b.size()-i-1;j++) sr += '0';
        int c = 0;
        for(int j=a.size()-1;j>=0;j--) {
            int v = (a[j]-'0')*(b[i]-'0') + c;
            c = v/10;
            v = v%10;
            sr += v+'0';
        }
        if(c) sr += c+'0';
        reverse(sr.begin(),sr.end());
        r = add(r,sr);
    }
    return r;
}

bool great(string a, string b) {
    if(a.size() > b.size()) return 1;
    if(b.size() > a.size()) return 0;
    for(int i=0;i<a.size();i++) {
        if(a[i] > b[i]) return 1;
        else return 0;
    }
    return 0;
}

string f[111111];

int main() {
    int n, q, v;
    f[0] = "1";
    for(int i=1;i<=100001;i++) {
        f[i] = mult(f[i-1],i);
        if(f[i].size() > 5000) {
            v = i;
            break;
        }
    }
    while(scanf("%d%d", &n, &q) && n) {
        string m;
        cin >> m;
        if(n-q+1 > v) cout << "descartado" << endl;
        else cout << (great(f[n-q+1],m) ? "descartado" : f[n-q+1]) << endl;
    }
    return 0;
}

