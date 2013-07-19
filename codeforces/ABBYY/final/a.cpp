#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <map>
#define pb push_back
#define mp make_pair
#define sz size()

using namespace std;

typedef long long ll;

ll a[500000];
ll ac[500000];
map <int,int> p;

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        p[a[i]] = i;
    }
    if(a[0] > 0) ac[0] = a[0];
    else ac[0] = 0;
    for(int i=1;i<n;i++)
    {
        if(a[i] >= 0) ac[i] = ac[i-1]+a[i];
        else ac[i] = ac[i-1];
    }
    ll r = -5000000000;
    ll x, y, v;
    for(int i=0;i<n;i++)
    {
        if(p[a[i]] != i)
        {
            v = ac[p[a[i]]-1] - ac[i] + 2*a[i];
            if(v > r)
            {
                x = i;
                y = p[a[i]];
                r = v;
            }
        }
    }
    int c = 0;
    for(int i=0;i<n;i++) if(i < x || i > y || (a[i] < 0 && i != x && i != y)) c++;
    cout << r << " " << c << endl;
    for(int i=0;i<n;i++) if(i < x || i > y || (a[i] < 0 && i != x && i != y)) cout << i+1 << " ";
    cout << endl;
    return 0;
}
