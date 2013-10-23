#include <iostream>
#include <cstdio>
#include <string>
#define mod 1000000000

using namespace std;

string s;
long long q[44444];
long long f[2][4444], dp[2][4444];

int divide()
{
    int cur=0;
    string a="";
    for(int i=0;i<s.size();i++)
    {
        cur += (s[i]-'0');
        if(!(cur/4 == 0 && i == 0)) a += ('0'+cur/4);
        cur %= 4;
        cur *= 10;
    }
    s = a;
    return cur/10;
}

int main()
{
    int i;
    long long ret=0;
    cin >> s;
    for(i=0;s!="";i++) q[i] = divide();
    int w = 0;
    for(int j=i;j>=0;j--) w += q[j];
    f[0][i] = w;
    f[1][i] = 1000000000;
    dp[0][i] = 1;
    dp[1][i] = 0;
    for(int j=i-1;j>=0;j--)
    {
        f[0][j] = min(f[0][j+1],f[1][j+1]);
        if(f[0][j] == f[0][j+1]) dp[0][j] = (dp[0][j]+dp[0][j+1])%mod;
        if(f[0][j] == f[1][j+1]) dp[0][j] = (dp[0][j]+dp[1][j+1])%mod;
        f[1][j] = min(f[0][j+1]+5-2*q[j],f[1][j+1]+3-2*q[j]);
        if(f[1][j] == f[0][j+1]+5-2*q[j]) dp[1][j] = (dp[1][j]+dp[0][j+1])%mod;
        if(f[1][j] == f[1][j+1]+3-2*q[j]) dp[1][j] = (dp[1][j]+dp[1][j+1])%mod;
    }
    if(f[0][0] <= f[1][0]) ret += dp[0][0];
    if(f[1][0] <= f[0][0]) ret += dp[1][0];
    cout << ret%mod << endl;
    return 0;
}
