#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int m, s;
    cin >> m >> s;
    if(m == 1 && s == 0) {
        cout << "0 0" << endl;
        return 0;
    }
    int s2 = s, m2 = m;
    string ma = "", mi = "";
    // max
    while(m2) {
        if(s2 > 9) {
            ma += '9';
            s2 -= 9;
        }
        else {
            ma += '0' + s2;
            s2 -= s2;
        }
        m2--;
    }
    if(s2 > 0 || ma[0] == '0') ma = "-1";
    // min
    while(m > 1) {
        if(s > 10) {
            mi += '9';
            s -= 9;
        }
        else if(s > 1) {
            mi += '0' + s - 1;
            s -= (s-1);
        } else mi += '0';
        m--;
    }
    mi += '0' + s;
    reverse(mi.begin(),mi.end());
    if(s > 9 || mi[0] == '0') mi = "-1";
    cout << mi << " " << ma << endl;
    return 0;
}

