#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector <pair<int, string> > d;
const double pi =  3.14159265358979;
const double e = 2.71828182845905; 

double cmb[33][33];

bool isv(char c) {
    return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
}

double v(string s, double a, double c, double p) {
    double z = 0.0;
    int n = s.size();
    for(int i=1;i<=n;i++) z += cos(i*pi)*pow(p,1.0/i);
    if(z < 0) z *= -1;
    int k = 0;
    for(int i=0;i<n;i++) if(isv(s[i])) k++;
    z *= 1.0*cmb[max(k,n-k)+1][min(k,n-k)-1];
    z *= 1.0*ceil(sqrt(pow(k,e)+pow(n-k,e)));
    z /= 1.0*floor(pi+log(1+a*c));
    return z;
}

int main() {
    int n;
    cin >> n;
    cmb[0][0] = 1;
    for(int i=1;i<23;i++) for(int j=0;j<=i;j++) cmb[i][j] = cmb[i-1][j-1]+cmb[i-1][j];
    for(int i=0;i<n;i++) {
        string s;
        double a, b, c;
        cin >> s >> a >> b >> c;
        d.push_back(mp(v(s,a,b,c),s));
    }
    sort(d.begin(),d.end());
    for(int i=0;i<n;i++) {
        cout << d[i].ss;
        for(int j=0;j<log10(d[i].ff);j++) cout << "!";
        cout << endl;
    }
    return 0;
}

