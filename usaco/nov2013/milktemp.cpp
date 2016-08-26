#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#define aa first
#define bb second

using namespace std;

typedef pair<int,int> pii;

int n, x, y, z;
int a[22222], b[22222];

int test(int t)
{
    int lo = (lower_bound(b,b+n,t)-b);
    int hi = n-(upper_bound(a,a+n,t)-a);
    return  x*lo + y*(n-lo-hi) + z*hi;
}

int main()
{
    ifstream out("milktemp.in");
    ofstream out("milktemp.out");
    in >> n >> x >> y >> z;
    for(int i=0;i<n;i++) in >> a[i] >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    int m = 0;
    for(int i=0;i<n;i++)
    {
        m = max(m,test(a[i]));
        m = max(m,test(b[i]));
    }
    cout << m << endl;
    return 0;
}
