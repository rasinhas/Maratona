#include <iostream>
#include <cstdio>
#define maxn 20

using namespace std;

int main()
{
    int v, c;
    long long fat[maxn];
    fat[0] = 1;
    for(int i=1;i<maxn;i++) fat[i] = fat[i-1]*i;
    while(cin >> c >> v && c + v != -2) printf("%lld %lld %lld\n", v == 0 ? fat[c] : fat[c+1], (v == 0 ? fat[c] : fat[c+1])*fat[v], fat[v+c]/fat[v]);
    return 0;
}
