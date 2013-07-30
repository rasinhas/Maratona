#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define mp make_pair
#define INF 0x3f3f3f3f
#define EPS 1e-9

using namespace std;

typedef pair<double,double> pt;

double ang[44444], p;

double mod(double a) { return a > 0 ? a : -a; }

int main()
{
    int n, r, k;
    long long sum;
    int t=1;
    while(scanf("%d %d", &n, &r) && n)
    {
        for(int i=0;i<n;i++) scanf("%lf", &ang[i]);
        sort(ang,ang+n);
        for(int i=0;i<n;i++) ang[n+i] = ang[i]+360.0; 
        int l=0;
        sum = 0;
        for(int i=0;i<n;i++){
            while(l < 2*n && ang[l] < ang[i] + 180 + EPS) l++;
            int left = l - i - 1;
            int right = n - left - 1;
            if(ang[l-1] > ang[i] + 180 - EPS) right++;
            sum += left*(left-1)/2;
            sum += right*(right-1)/2;
        }
        long long tot=1ll*n*(n-1)*(n-2)/6;
        printf("Case %d: %lld\n", t++, tot-sum/2);
    }
	return 0;
}
