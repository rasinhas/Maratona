#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef pair<int,int> pii;

int s;
pair <int,int> b[222222];
int r[222222], l[222222], vis[222222];

int cmp(pii a, pii b)
{
    if(a.first != b.first) return a.first > b.first;
    else return b.second > a.second;
}

void go()
{
}

int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        s = 0;
        r[0] = 1;
        l[n+1] = n;
        for(int i=1;i<=n;i++)
        {
            cin >> b[i].first >> b[i].second;
            r[i] = i+1;
            l[i] = i-1;
        }
        sort(b+1,b+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            if(!vis[i]) go(i);
        }
    }
    return 0;
}
