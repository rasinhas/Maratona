#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define pb push_back

using namespace std;

long long p[40000];
int used[40000];

//TODO
int main()
{
    vector <int> sol;
    int c, n, sz;
    int v, k;
    cin >> c;
    for(int t=1;t<=c;t++)
    {
        cin >> n;
        sz = (n*(n-1))/2;
        for(int i=0;i<sz;i++) cin >> p[i];
        sort(p,p+sz);
        k = 0;
        memset(used,0,sizeof(used));
        for(int i=2;i<p[sz-1];i++)
        {
            v = i;
            if(used[k] == 1) v = p[k]; 
            if(used[k] == 2) k++;
            if(p[k]%v == 0)
            {
                sol.pb(i);
                int cnt = 0;
                for(int j=0;j<sz;j++)
                {
                    if(p[k+j]%i == 0)
                    {
                        p[k+j]/=i;
                        used[k+j]++;
                        cnt++;
                    }
                    if(cnt == n) break;
                }
            }
        }
        sort(sol.begin(),sol.end());
        printf("Case %d:", t);
        for(int i=0;i<n;i++) printf(" %d", sol[i]);
        printf("\n");
        sol.clear();
    }
    return 0;
}
