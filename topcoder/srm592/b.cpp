#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

class LittleElephantAndPermutationDiv2
{
    public:
    ll getNumber(int n, int k)
    {
        ll f[11] = {1,1,2,6,24,120,720,5040,40320,362880,3628800};
        int s[11], p[11];
        ll c[111];
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++) s[i] = p[i] = i+1;
        do {
            int r=0;
            for(int i=0;i<n;i++) r += max(s[i],p[i]);
            c[r]++;
        } while(next_permutation(p,p+n));
        for(int i=1;i<101;i++)
        {
            c[i] += c[i-1];
        }
        return (c[100]-c[k-1])*f[n];
    }
};

int main()
{
    LittleElephantAndPermutationDiv2 a;
    cout << a.getNumber(1,1) << endl;;
    return 0;
}
