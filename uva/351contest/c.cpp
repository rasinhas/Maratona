#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair
#define var(x) cerr << #x << " = " << x << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int a , b;
    while(scanf("%d%d", &a, &b) != EOF) {
        cout << max(a,b) << endl;
    }
    return 0;
}

