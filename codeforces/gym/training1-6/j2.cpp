# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>
# include<cstdlib>
using namespace std;
const int maxn=10010;
const int mol=1000000000;
int len=0, num=0;
int c[maxn], que[maxn], f[maxn][2], g[maxn][2];
char ch;

inline void Init()
{
    ch=getchar();
    while (ch>'9' || ch<'0') ch=getchar();
    while (ch!='\n')
        c[len++]=ch-48, ch=getchar();
}

inline void Divide(int &n)
{    
    n=0;
    for (int i=len-1; i>=0; i--)
    {
        n*=10, n+=c[i];
        c[i]=n/4, n%=4;
    }
}

inline void Change()
{
    for (int i=0; i<len/2; i++)
        swap(c[i],c[len-i-1]);
    while (len)
    {
        Divide(que[num++]);
        while (len && !c[len-1]) len--;
    }
}

inline void Dp()
{
    que[num]=0;
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    g[num][0]=g[num][1]=f[num][1]=1;
    for (int i=num-1; i>=0; i--)
        for (int j=0; j<2; j++)
        {
            f[i][j]=min(f[i+1][0]+que[i]+j, f[i+1][1]+4-que[i]-j);
            if (f[i][j]==f[i+1][0]+que[i]+j)
                g[i][j]+=g[i+1][0];
            g[i][j]%=mol;
            if (f[i][j]==f[i+1][1]+4-que[i]-j)
                g[i][j]+=g[i+1][1];
            g[i][j]%=mol;
        }
}

inline void Putans()
{
    printf("%d\n",g[0][0]);
}

int main()
{
    Init();
    Change();
    Dp();
    Putans();
    return 0;
}
