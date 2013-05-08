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

int g[10006];
bool v[10006][1000];

void grundy(int pos)
{
    for(int i=2;i<(pos+1)/2;i++) v[pos][(g[i]^g[pos-i-1])] = true;
    int ret=0;
    while(v[pos][ret] == true) ret++;
    g[pos] = ret;
}

int main()
{
    int i, n, f, ret;
    int cnt;
    char c;
    g[0] = 0;
    g[1] = 0;
    g[2] = 0;
    g[3] = 0;
    g[4] = 0;
    g[5] = 1;
    for(i=6;i<=10005;i++) 
    {
        grundy(i);
    }
    while(scanf("%d", &n) && n)
    {
        f = 0;
        ret = 0;
        cnt = 0;
        getc(stdin);
        for(i=0;i<n;i++)
        {
            scanf("%c", &c);
            if(c == 'X')
            {
                if((cnt == 0 || cnt == 1) && i) f = 1; 
                ret ^= g[cnt];
                cnt = 0;
            }
            else
            {
                cnt++;
                if(i == 0 || i == n-1) cnt+=2;
                if(i == n-1) ret ^= g[cnt];
            }
        }
        getc(stdin);
        if(ret || f) printf("S\n");
        else printf("N\n");
    }
	return 0;
}
