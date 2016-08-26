#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    int i = 0;
    while(n1>0 && n2>0) {
        if(i%2) n2--;
        else n1--;
        i++;
    }
    cout << (!n1 ? "Second" : "First") << endl;
    return 0;
}
