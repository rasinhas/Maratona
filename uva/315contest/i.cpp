#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#define EPS 1e-6

using namespace std;

int r[20];
int sz;

int f(int x)
{
    int ret = 1;
    for(int i=0;i<sz;i++)
    {
        if(x > r[i]) ret *= 1;
        if(x < r[i]) ret *= -1;
        if(x == r[i]) ret *= 0;
    }
    return ret;
}

int bissect(int xi, int xj, int a)
{
    int x;
    int s;
    for(int i=0;i<7;i++)
    {
        if((xi+xj)%2) return 0;
        x = (xi+xj)/2;
        s = f(xi)*f(x);
        if(x == a) return 1;
        if(s < 0) xj = x;
        else if(s > 0) xi = x;
        else return 0;
    }
    return 0;
}

int main()
{
    int t, ret;
    int x, n;
    char p[10];
    cin >> t;
    while(t--)
    {
        getchar();
        int i=0;
        scanf("%3c", p);
        scanf("%d", &r[i++]);
        while(scanf("%4c", p))
        {
            if(p[2] == '0') break;
            scanf("%d", &r[i++]);
        }
        sz = i;
        cin >> n;
        ret = 0;
        int ret2 = 0;
        for(int j=1;j<128;j++)
        {
            for(int k=0;k<n;k++)
            {
                if((128*n-128*k+j*k)%j != 0) continue;
                x = (128*n-128*k+j*k)/j;
                if(x > 10000) continue;
                if(f(k)*f(x) < 0) ret += bissect(k,x,n);
            }
        }
        cout << ret << endl;
    }
    return 0;
}
