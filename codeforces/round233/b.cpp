#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int dp[55];

int main() 
{
    int n;
    string s;
    cin >> n >> s;
    long long k = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == 'R') k += (1ll<<i);
    }
    cout << ((1ll<<n)-1-k) << endl;
    return 0;
}
