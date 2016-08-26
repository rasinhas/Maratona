#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

long long p[2222222];

const long long M=1000000000000000001ll;

int main()
{
    int t, l;
    long long n;
    ifstream in("army.in");
    in >> t;
    long long s = 0;
    for(long long i=1;s<=M;i++)
    {
        s += i*i;
        p[i] = s;
        l = i;
    }
    for(int i=1;i<=t;i++)
    {
        in >> n;
        assert(n < M);
        int r = 0;
        long long pos = (upper_bound(p,p+l,n)-p)-1;
        r = pos*pos;
        s = p[pos];
        pos++;
        if((pos*pos+pos) >= 2*(n-s))
        {
            long long y = (n-s);
            long long x = (sqrt(1+8*y)-1)/2;
            r += x;
            if(x*x + x - 2*y < 0) r++;
        }
        else
        {
            r += pos;
            s += (pos*pos+pos)/2;
            pos--;
            long long y = (pos*pos+pos)/2-(n-s);
            long long x = (sqrt(1+8*y)-1)/2;
            r += (pos-x);
        }
        printf("Case %d: %d\n", i, r);
    }
    return 0;
}
