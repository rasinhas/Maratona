#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define mod 1000000007

using namespace std;

typedef long long ll;

int len(ll a)
{
    int l=0;
    while(a)
    {
        a/=10;
        l++;
    }
    return l;
}

int rmd(int a, int n, int l)
{
    int p=1, d=1;
    ll v=0;
    for(int i=0;i<l;i++)
    {
        if(n & (1<<i))
        {
            v += ((a/d)%10)*p;
            p *= 10;
        }
        d *= 10;
    }
    return v;
}

class LittleElephantAndArray
{
    public:
    int getNumber(ll A, int N)
    {
        ll s[22222];
        ll idx[22222];
        map <ll,ll> dp[111];
        map <ll,ll>::iterator it;
        int l = len(A);
        for(int i=1;i<(1<<l);i++) dp[0][rmd(A,i,l)]++;
        int sz=0;
        for(it=dp[0].begin();it!=dp[0].end();it++)
        {
            if(sz > 0) s[sz] = (s[sz-1]+it->second)%mod;
            else s[sz] = it->second;
            idx[sz++] = it->first;
        }
        for(int i=1;i<=N;i++)
        {
            l = len(A+i);
            for(int j=1;j<(1<<l);j++)
            {
                ll k = rmd(A+i,j,l);
                int p = upper_bound(idx,idx+sz,k)-idx;
                dp[i][k] = (dp[i][k]+s[p-1])%mod;
            }
            sz=0;
            for(it=dp[i].begin();it!=dp[i].end();it++) 
            {
                if(sz > 0) s[sz] = (s[sz-1]+it->second)%mod;
                else s[sz] = it->second;
                idx[sz++] = it->first;
            }
        }
        return s[sz-1];
    }
};

int main()
{
    LittleElephantAndArray a;
    cout << a.getNumber(1,9) << endl;
    //cout << a.getNumber(10,2) << endl;
    //cout << a.getNumber(4747774,1) << endl;
    cout << a.getNumber(6878542150015ll,74) << endl;
    //cout << a.getNumber(1000000000000000ll,100) << endl;
    return 0;
}
