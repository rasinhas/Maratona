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

using namespace std;

int main()
{
    int a[110000], s[110000];
    int ac, n, t, ini, fin, ret, ta;
    scanf("%d%d", &n, &t);
    ac = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    ini = 0;
    fin = 0;
    ret = 0;
    ta = 0;
    while(fin < n)
    {
        if(ta + a[fin] <= t)
        {
            ta += a[fin];
            fin++;
        }
        else
        {
            if(ini == fin)
            {
                ini++;
                fin++;
            }
            else
            {
                ta -= a[ini];
                ini++;
            }
        }
        ret = max(ret,fin-ini);
    }
    printf("%d\n", ret);
    return 0;
}
