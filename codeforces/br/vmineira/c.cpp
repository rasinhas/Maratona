#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

set <string> s;
char c[111];

int main() {
    int n, q;
    string a, b;
    cin >> n >> q;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        s.insert(a+' '+b);
    }
    for(int i=0;i<q;i++) {
        cin >> a >> b;
        if(s.count(a+' '+b)) cout << "Nao e a mamae" << endl;
        else cout << "nao e o Nao e a mamae" << endl;
    }
    return 0;
}

