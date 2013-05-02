#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
#define pb push_back
#define mp make_pair
#define inf 0x3f3f3f3f
#define eps 1e-9

using namespace std;

double mod(double a) { return (a > 0 ? a : -a); }

int n, i;
int a, b, x, y, ra, rb;
double dx, dy, da, db, delta;
double mindelta=inf;

void test(double v)
{
    delta = mod(v/db - dx/dy);
    if(mindelta - delta > eps)
    {
        mindelta = delta;
        ra = v;
        rb = i;
    }
}

int main()
{
    scanf("%d%d%d", &x, &y, &n);
    dy = y;
    dx = x;
    for(i=1;i<=n;i++)
    {
        db = i;
        da = db*dx/dy;
        a = da;
        da = a;
        if(a > 0) test(da-1);
        test(da);
        test(da+1);
    }
    printf("%d/%d\n", ra, rb);
    return 0;
}
