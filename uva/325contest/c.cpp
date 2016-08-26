#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int h[7][7];
pair <int,int> t[7];

bool match(int s, int k, int r)
{
    if(s == 0) return 1;
    else 
    {
        int lp = t[s-1].first, lr=t[s-1].second;
        if(s == 1) return (h[t[0].first][(6-t[0].second)%6] == h[k][(9-r)%6]);
        else if(s == 2) return (h[t[0].first][(7-t[0].second)%6] == h[k][(10-r)%6] && h[lp][(8-lr)%6] == h[k][(5-r)%6]);
        else if(s == 3) return (h[t[0].first][(8-t[0].second)%6] == h[k][(11-r)%6] && h[lp][(9-lr)%6] == h[k][(6-r)%6]);
        else if(s == 4) return (h[t[0].first][(9-t[0].second)%6] == h[k][(12-r)%6] && h[lp][(10-lr)%6] == h[k][(7-r)%6]);
        else if(s == 5) return (h[t[0].first][(10-t[0].second)%6] == h[k][(13-r)%6] && h[lp][(11-lr)%6] == h[k][(8-r)%6]);
        else if(s == 6) return (h[t[0].first][(11-t[0].second)%6] == h[k][(14-r)%6] && h[lp][(12-lr)%6] == h[k][(9-r)%6] && h[t[1].first][(10-t[1].second)%6] == h[k][(7-r)%6]);
    }
}

bool go(int s, int msk)
{
    int r;
    if(msk == (1<<7)-1) return 1;
    for(int i=0;i<7;i++)
    {
        if(!((1<<i)&msk)) for(int j=0;j<6;j++)
        {
            if(match(s,i,j))
            {
                t[s] = (make_pair(i,j));
                r = go(s+1,msk+(1<<i));
                if(r) return r;
            }
        }
    }
    return 0;
}

int main()
{
    int t;
    while(1)
    {
        for(int i=0;i<7;i++)
        {
            for(int j=0;j<6;j++)
            {
                if(scanf("%d", &t) == EOF) return 0;
                h[i][j] = t;     
            }
        }
        if(go(0,0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
