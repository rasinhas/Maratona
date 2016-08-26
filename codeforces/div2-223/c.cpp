#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define ff first
#define ss second

using namespace std;

typedef long long ll;

int m;
pair<int,int> que[111111];
ll sz[111111];
map <ll,int> memo;


int main()
{
    int n, x;
    ll k, l, c;
    cin >> m;
    sz[0] = 0;
    for(int i=0;i<m;i++)
    {
        cin >> k;
        if(k == 1) 
        {
            cin >> x;
            sz[i+1] = sz[i] + 1;
            que[i] = make_pair(-1,x);
            memo[sz[i+1]] = x;
        }
        else
        {
            cin >> l >> c;
            sz[i+1] = sz[i] + l*c;
            que[i] = make_pair(l,c);
        }
    }
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> k;
        while(1)
        {
            if(memo.count(k)) break;
            int p = lower_bound(sz, sz+m+1, k)-sz-1;
            if(que[p].ff == -1) 
            {
                memo[k] = que[p].second;
                break;
            }
            k = (k - sz[p] - 1)%que[p].ff + 1;
        }
        cout << memo[k] << " ";
    }
    cout << endl;
    return 0;
}
