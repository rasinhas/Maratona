#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int j[111];
int l[11];

int main()
{
    int t, n, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i=0;i<n;i++) cin >> j[i];
        memset(l,0,sizeof(l));
        int k=0;
        int p=9;
        int r=0;
        l[10] = 0;
        while(1)
        {
            int pos = (l[p+1]+k)%n;
            if(j[pos] == p)
            {
                r++;
                l[p] = pos;
            }
            if(p == j[m] && pos == m) break;
            k = (k+1)%n;
            if(k==0) l[p-1] = l[p--];
        }
        cout << r << endl;
    }
    return 0;
}
