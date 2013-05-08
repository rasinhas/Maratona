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
#include <ctype.h>
#define INF 0x3f3f3f3f

using namespace std;

long long c[2][10];
int pot10[8] = {1,10,100,1000,10000,100000,1000000,10000000};

void digits(int x, int vet){
    int d, dcnt = 0, r = 0, rem0 = 0, v, i;
    while(x)
    {
        d = x%10; x /= 10;
        if(dcnt)
        {
            v = d*pot10[dcnt-1]*dcnt;
            for(i=0;i<10;++i) c[vet][i] += v;
            if(!d) rem0 += (pot10[dcnt]-1) - r;
        }
        v = pot10[dcnt];
        for(i=1;i<d;++i) c[vet][i] += v;
        if(d) c[vet][d] += r + 1;
        r = pot10[dcnt++]*d + r;
    }
    c[vet][0] -= rem0;
}

int main()
{
    int x, y;
    int i;
    while(scanf("%d %d", &x, &y) && x)
    {
        for(i=0;i<10;i++) c[0][i] = c[1][i] = 0;
        digits(y, 0);
        digits(x-1, 1);
        for(i=0;i<10;i++) printf("%lld ", c[0][i] - c[1][i]);
    }
    return 0;
}
