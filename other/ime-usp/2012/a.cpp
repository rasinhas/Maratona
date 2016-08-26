#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define mod 1000

using namespace std;

typedef pair<int,int> pii;

int fib(string s) 
{
    pii p = pii(0,1);
    for(int i=0;i<s.size();i++)
    {
        int a = p.first;
        int b = p.second;
        int c = (((2*a*b - a*a) % mod) + mod)%mod;
        int d = (a*a + b*b) % mod;
        if(s[i] == '0') p = pii(c, d);
        else p = pii(d, (c+d)%mod);
    }
    return p.first;
}

int main()
{
    int t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        printf("%03d\n", fib(s));
    }
    return 0;
}
