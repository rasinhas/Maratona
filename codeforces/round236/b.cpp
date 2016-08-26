#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>

using namespace std;

const int N = (int)1e5;
int a[55555], b[55555];
map <int,bool> is_bad;
map <int,int> f;
vector <int> prime;
int np[111111];

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

void sieve() {
    for(int i=4;i<N;i+=2) np[i] = 1;
    prime.push_back(2);
    for(int i=3;i<N;i+=2) {
        if(!np[i]) {
            for(int j=2*i;j<N;j+=i) np[j] = 1;
            prime.push_back(i);
        }
        
    }
}

int go(int k) {
    int r=0, i;
    if(f.count(k)) return f[k];
    for(i=0;prime[i]*prime[i]<=k;i++) {
        if(k % prime[i] == 0) return f[k] = go(k/prime[i]) + (is_bad.count(prime[i]) ? -1 : 1);
    }
    return f[k] = (is_bad.count(k) ? -1 : 1);
}

int main() 
{
    int n, m;
    int s = 0;
    cin >> n >> m;
    sieve();
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) { cin >> b[i]; is_bad[b[i]] = 1;}
    f[1] = 0;
    for(int i=0;i<n;i++) {
        go(a[i]);
        s += f[a[i]];
    }
    for(int i=0;i<n;i++) {
        int g = a[0];
        for(int j=1;j<(n-i);j++) g = gcd(g,a[j]);
        int v = (n-i)*f[g];
        if(v < 0) {
            for(int j=0;j<(n-i);j++) a[j] /= g;
            s -= v;
        }
    }
    cout << s << endl;
    return 0;
}
