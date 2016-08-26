#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string a, b;
        cin >> a >> b;
        int na = a.size(), nb = b.size();
        if(((a[na-1]-'0')+(b[nb-1]-'0'))%2 == 0) printf("Par\n");
        else printf("Impar\n");
    }
    return 0;
}

