#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define sz size()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        double n, m;
        int a, b;
        printf("Case #%d: ", t);
        scanf("%lf %lf %d %d", &n, &m, &a, &b);
        double s = m*(a+b) - n*a;
        if(s < 0 || s > 10*b) printf("Impossible\n");
        else printf("%.2lf\n", s/b);
    }
    return 0;
}
