#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define mod 1000000007
#define sz size()

typedef long long ll;

using namespace std;

int main()
{
    ll ret;
    ll pow[200]; 
    string bin;
    cin >> bin;
    pow[0] = 1;
    ret = 0;
    for(int i=1;i<101;i++) pow[i] = (pow[i-1]*2)%mod;
    for(int i=0;i<bin.sz;i++)
    {
        if(bin[i] == '1') ret = (ret+((pow[bin.sz-1]*pow[bin.sz-i-1])%mod))%mod;
    }
    cout << ret << endl;
    return 0;
}
