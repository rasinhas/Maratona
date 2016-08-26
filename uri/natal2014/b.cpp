#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    int n;
    double sq3 = sqrt(3.0);
    while(scanf("%d", &n) != EOF) {
        double a = sq3*n*n/4.0;
        printf("%.2lf\n", a+(a/3)*9/5);
    }
    return 0;
}

