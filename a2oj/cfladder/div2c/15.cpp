#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int n;
    string s = "";
    cin >> n;
    while(n > 0) {
        if(n%7 == 0) {
            s += '7';
            n -= 3;
        } else s += '4';
        n -= 4;
    }
    cout << (n < 0 ? "-1" : s) << endl;
    return 0;
}

