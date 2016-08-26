#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz size()

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const ll inf = (int)1e18;
int a[3][111];
int dp[111][111][111];
int n;

void go(int x, int y, int z) {
    if(x < 0 || y < 0 || z < 0) return;
    if(dp[x][y][z]) return;
    dp[x][y][z] = 1;
    if((a[0][x]%3) == 0) go(x-1,y,z);
    if((a[1][y]%3) == 0) go(x,y-1,z);
    if((a[2][z]%3) == 0) go(x,y,z-1);
    if((a[0][x]+a[1][y])%3 == 0) go(x-1,y-1,z);
    if((a[0][x]+a[2][z])%3 == 0) go(x-1,y,z-1);
    if((a[1][y]+a[2][z])%3 == 0) go(x,y-1,z-1);
    if((a[0][x]+a[1][y]+a[2][z])%3 == 0) go(x-1,y-1,z-1);
}

int main() 
{
    while(scanf("%d", &n) && n) {
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++) cin >> a[0][n-i] >> a[1][n-i] >> a[2][n-i];
        go(n,n,n);
        cout << (dp[0][0][0] == 1 ? 1 : 0) << endl;
    }
    return 0;
}
