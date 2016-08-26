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
    int t;
    cin >> t;
    while(t--) {
        double y1, y2, a, b;
        cin >> y1 >> a >> y2 >> b;
        double r = (b-a)/(y2-y1);
        ll r2 = r*100;
        printf("%lld,%.2lld\n", r2/100, r2%100);
    }
    return 0;
}
