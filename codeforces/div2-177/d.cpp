#include <iostream>
#include <cstdio>
#include <string>
#define mod 1000000007

using namespace std;

int magic[9] = {0, 1, 2, 9, 64, 625, 7776, 117649, 2097152};

int main()
{
    int n, k;
    long long ret;
    scanf("%d%d", &n, &k);
    ret = 1;
    ret = magic[k]%mod; 
    for(int i=k;i<n;i++)
    {
        ret = (ret*(n-k))%mod;
    }
    cout << ret << endl;
    return 0;
}
