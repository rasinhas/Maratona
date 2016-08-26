#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int n;
    while(scanf("%d", &n) && n) {
        for(int i=1;i<=n;i++) {
            double a, b, c, s;
            scanf("%lf %lf %lf", &a, &b, &c);
            s = a*(b+c)*5.0/2.0;
            printf("Size #%d:\n", i); 
            printf("Ice Cream Used: %.2lf cm2\n", s);
        }
        cout << endl;
    }
    return 0;
}

