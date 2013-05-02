#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define pb push_back
#define sz size

using namespace std;

int o[500000];

int mod(int a) { return a > 0 ? a : -a;}

int main()
{
    long long m;
    long long n, p, k;
    vector <int> v;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> p;
        v.pb(p);
    }
    sort(v.begin(),v.end());
    k = 0;
    m = 0;
    for(int i=1;i<=n;i++)
    {
        if(!o[i])
        {
            m += mod(v[k] - i);
            k++;
        }
        else continue;
    }
    cout << m << endl;
    return 0;
}
