#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#define pb push_back
#define mp make_pair
#define sz size()

using namespace std;

typedef long long ll;

int main()
{
    int c[200], n, q, a, b, p, k[200];
    cin >> n;
    for(int i=0;i<n;i++) 
    {
        cin >> c[i];
        k[c[i]-1] = i;
    }
    cin >> q;
    for(int i=0;i<q;i++)
    {
        cin >> p >> a >> b;
        a--; b--;
        if(p == 1)
        {
            int ans = 1;
            int x=min(k[a],k[b]), y = max(k[a],k[b]);
            for(int i=x;i<y;i++)
            {
                if(c[i] > c[i+1]) ans++;
            }
            cout << ans << endl;
        }
        else 
        {
            swap(c[a],c[b]);
            swap(k[c[a]-1],k[c[b]-1]);
        }
    }
    return 0;
}
