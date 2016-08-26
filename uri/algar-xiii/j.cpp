#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;


int main()
{
    double a, b, c;
    while(scanf("%lf", &a) && a) {
        cin >> b >> c;
        double ar = a*b*100;
        double lo=1, hi=1e4, mi;
        for(int i=0;i<200;i++) {
            mi = (lo+hi)/2;
            if(ar/(mi*mi) < c) hi = mi;
            else lo = mi;
        }
        printf("%d\n", (int)mi);
    }
    return 0;
}
