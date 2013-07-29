#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define sz size()
#define pb push_back

using namespace std;

int p[1001000];
int dif[1001000];
int n, k;
int t;

bool valid(int d)
{
    vector <int> s;
    for(int i=0;i<t-1;i++)
    {
        if(dif[i] <= d) 
        {
            s.pb(i);
            i++;
        }
        if(s.sz == n) break;
    }
    if(s.sz < n) return 0;
    for(int i=s.sz-1;i>=0;i--)
    {
        int r = t - s[i];
        int used = 2*(n-i-1)*k;
        if(r-used < 2*k) return 0;
    }
    return 1;
}

int main()
{
    while(scanf("%d%d", &n, &k) != EOF)
    {
        t = 2*n*k;
        for(int i=0;i<t;i++) cin >> p[i];
        sort(p,p+t);
        for(int i=1;i<t;i++) dif[i-1] = p[i]-p[i-1];
        int l = 0, h = p[2*n*k-1]-p[0];
        int m;
        int lv;
        while(l <= h)
        {
            m = (l+h)/2;
            if(valid(m)) 
            {
                lv = m;
                h = m-1;
            }
            else l = m+1;
        }
        cout << lv << endl;
    }
    return 0;
}
