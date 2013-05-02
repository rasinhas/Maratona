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

int aut[110];
string prb, brac, prbr;

void kmp()
{
    int m, k;
    m = prb.size();
    aut[1] = 0;
    k = 0;
    for(int i=1;i<m;i++)
    {
        while(k>0 && prb[k] != prb[i]) k=aut[k-1];
        if(prb[k] == prb[i]) k++;
        aut[i]=k;
    }
}

bool match(string t)
{
    int m, n, q;
    n = t.size();
    m = prb.size();
    q = 0;
    for(int i=0;i<n;i++)
    {
        while(q>0 && prb[q]!=t[i]) q = aut[q-1];
        if(prb[q] == t[i]) q++;
        if(q == m) return true;
    }
    return false;
}

int main()
{
    int i, n, f;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        f = 0;
        aut[0] = 0;
        cin >> prb;
        cin >> brac;
        brac += brac;
        kmp();
        f = match(brac);
        if(!f)
        {
            reverse(brac.begin(),brac.end());
            f = match(brac);
        }
        if(f) printf("S\n");
        else printf("N\n");
    }
	return 0;
}
