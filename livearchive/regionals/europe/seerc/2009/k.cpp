#include <iostream>
#include <cstdio>

using namespace std;

int go(int n, int m, int k, int c)
{
    int ret = 1e9+1;
    //printf("%d %d %d %d\n", n, m, k, c);
    if(m == 0)
    {
        if(c%n) return c;
        else return ret;
    }
    if(n == 1) return ret;
    else if(n == 2 && m%2 == 0) return ret;
    else if(k == 1 && m%n == 0) return ret;
    else if(m <= k)
    {
        if(m%n > 0)
        {
            if((c+1)%n) return c+1;
            else return c+2;
        }
        else 
        {
            if((c+2)%n > 0) return c+2;
            else return c+3;
        }
    }
    else 
    {
        for(int i=k;i>0;i--)
        {
            if(i%n == 0) continue;
            int d = m/i;
            if(d == 0) continue;
            ret = min(ret, go(n,m%i,i,c+d));
            if(d > 1) 
            {
                if((m+1)%i > 0) ret = min(ret, go(n,(m%i)+1,i,c+d));
            }
            if(c+d >= ret) break;
        }
        return ret;
    }
}

int main()
{
    int t, n, m, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        int val = go(n,m,k,0);
        cout << (val <= 1e9 ? val : -1) << endl;
    }
    return 0;
}
