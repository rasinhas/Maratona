#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

// bignum using strings for POSITIVE numbers (division is float) and the rest integer
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

string rstrip(string a) {
    int s = a.size()-1;
    while(a[s] == '0' && s) {
        a.erase(s);
        s--;
    }
    return a;
}

string lstrip(string a) {
    reverse(a.begin(),a.end());
    a = rstrip(a);
    reverse(a.begin(),a.end());
    return a;
}

string sub(string a, string b) {
    string r = "";
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int c = 0;
    for(int i=0;i<a.size();i++) {
        if(i >= b.size()) {
            if(a[i] < '0'+c) {
                r += a[i]+10-c;
                c = 1;
            } else {
                r += a[i]-c;
                c = 0;
            }
        } else {
            if(a[i] < b[i]+c) {
                r += a[i]+10-(b[i]-'0')-c;
                c = 1;
            } else {
                r += a[i]-(b[i]-'0')-c;
                c = 0;
            }
        }
    }
    if(r != "0") r = rstrip(r);
    reverse(r.begin(),r.end());
    return r;
}

bool great(string a, string b) {
    if(a.size() > b.size()) return 1;
    if(b.size() > a.size()) return 0;
    for(int i=0;i<a.size();i++) {
        if(a[i] > b[i]) return 1;
        else if(a[i] < b[i]) return 0;
    }
    return 0;
}

string format(string a, int prec) {
    int s = a.size();
    string r = "";
    if(!prec) return a;
    if(s <= prec) {
        r = "0.";
        for(int i=s;i<prec;i++) r += '0';
        for(int i=0;i<s;i++) r += a[i];
    } else {
        for(int i=0;i<s-prec;i++) r += a[i];
        r += '.';
        for(int i=s-prec;i<s;i++) r += a[i];
    }
    return r;
}

string div(string a, string b, int prec) {
    string r = "", cur = "";
    for(int i=0;i<prec;i++) a += '0';
    for(int i=0;i<a.size();i++) {
        cur += a[i];
        cur = lstrip(cur);
        for(int j=1;j<=10;j++) {
            string aux = mult(b,j);
            if(great(aux,cur)) {
                if(j == 1 && r == "") break;
                r += '0'+j-1;
                cur = sub(cur,mult(b,j-1));
                break;
            }
        }
    }
    r = format(r,prec);
    if(!r.size()) r = "0";
    return r;
}

int main() {
    string l;
    while(cin >> l && l != "0") {
        int x=0, k=1;
        for(int i=l.size()-1; i>=0; i--) {
            x+=(l[i]-'0')*k;
            k*=10;
        }
        string d = sub(l,"3");
        cout << d << endl;
        cout << div(d,l,6) << endl;
        printf("%.10lf\n", 1.0*(x-3)/x);
    }
    return 0;
}
