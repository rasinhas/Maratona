#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#define inf 0x3f3f3f3f;
#define pb push_back
#define sz size()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long h[100000];
long long x[100000];
int g[31] = {0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};

bool mark[100000];

map <int,int> gg;

int grundy(int mask)
{
    int nmask;
    int used[40];
    memset(used,0,sizeof(used));
    // tenta tirar cada um dos vertices
    for(int i=1;i<30;i++)
    {
        // se existe o vertice tento tirar os multiplos
        if(mask&(1<<i))
        {
            nmask = mask;
            for(int k=i;k<30;k+=i) if(mask&1<<k) nmask -= (1<<k);    
            if(gg.count(nmask)) used[gg[nmask]] = 1;
            else
            {
                gg[nmask] = grundy(nmask);
                used[gg[nmask]] = 1;
            }
        }
    }
    for(int i=0;i<30;i++) if(!used[i]) return i;
}

int main()
{
    int n, c1, s, r, m;
    /*
    g[0] = 0;
    gg[0] = 0;
    m = 0;
    for(int i=1;i<30;i++)
    {
        m += (1 << i);
        g[i] = grundy(m);
    }
    for(int i=0;i<30;i++)
    {
        printf("%d, ", g[i]);
    }
    */
    cin >> n;
    h[1] = 1;
    s = n-(int)sqrt(n);
    c1 = s;
    for(int i=2;i*i<=n;i++)
    {
        if(!mark[i]) 
        {
            int j;
            int p=n;
            for(j=0;p>0;j++)
            {
                p/=i;
            }
            h[i] = j-1;
        }
        long long k = i*i;
        while(k*k < n)
        {
            mark[k] = 1;
            k*=i;
        }
        c1 -= (h[i]+1)/2;
    }
    if(c1%2 == 0) r = 0;
    else r = 1;
    for(int i=1;i*i<=n;i++) if(!mark[i]) r ^= g[h[i]];
    if(r == 0) cout << "Petya" << endl;
    else cout << "Vasya" << endl;
    return 0;
}
