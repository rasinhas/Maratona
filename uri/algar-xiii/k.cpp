#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    double q, d, p;
    while(cin >> q && q) {
        cin >> d >> p;
        double pv = p*(d*q)/(p-q);
        ll v = (ll) pv;
        printf("%lld pagina", v);
        if(v > 1) printf("s\n");
        else printf("\n");
    }
    return 0;
}
