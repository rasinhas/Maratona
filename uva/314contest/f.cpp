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
    long long qm, qe, m, e, ret;
    while(scanf("%lld%lld", &m, &e) && m)
    {
       qe = (1<<e)-1;
       if(qe >= m) ret = (1ll<<m)-1 + (qe-m)*(1ll<<m);
       else ret = (1ll<<qe)-1;
       printf("%lld\n", ret);
    }
    return 0;
}
