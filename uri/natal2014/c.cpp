#include <bits/stdc++.h>
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double pi = 3.141592654;

int main() {
    double a, b, c;
    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        printf("%.2lf\n", 5.0*(b*tan((a*pi)/180.0)+c));
    }
    return 0;
}

