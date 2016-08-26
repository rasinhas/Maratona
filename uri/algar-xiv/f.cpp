#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int f[13] = {-1, 306, 337, 0, 31, 61, 92, 122, 153, 184, 214,
245, 275};
int days_from_0(int d, int m, int y) {
    if(m <= 2) y--;
    int a=y/4, b=y/100, c=y/400;
    return d+f[m]+y*365+a-b+c;
}

int mod(int a) { return a > 0 ? a : -a; }

int main() {
    int t;
    cin >> t;
    while(t--) {
        int y, m, d, d1, d2;
        scanf("%d-%d-%d", &y, &m, &d);
        d1 = days_from_0(d,m,y);
        scanf("%d-%d-%d", &y, &m, &d);
        d2 = days_from_0(d,m,y);
        cout << mod(d1-d2) << endl;
    }
    return 0;
}

