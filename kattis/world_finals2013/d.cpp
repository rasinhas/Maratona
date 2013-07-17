#include <iostream>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

typedef ull long long;

set <ull> vis;
map <ull,ull> f;
int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};

void dfs(ll n, int i)
{
    vis.insert(n);
    while(n*p[i]/p[i] == n)
    {
        if(vis.count(n*p[i])) dfs(n*p[i], i);
    }
}

int main()
{
    dfs(2,0);
    return 0;
}
