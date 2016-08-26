#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[111][111], b[111][111];

int main()
{
    int T;
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        int n, m, r, q;
        cin >> n >> m;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[i][j];
        cin >> q >> r;
        for(int i=0;i<q;i++) for(int j=0;j<r;j++) cin >> b[i][j];
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            if(a[i][j] == 1)
            {
                int dx=q/2, dy=r/2;
                for(int k=0;k<q;k++) for(int l=0;l<r;l++)
                {
                    if(b[k][l] == 1)
                    {
                        int ni = i-dx+k, nj = j-dy+l;
                        if(ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj] == 0) a[ni][nj] = 2;
                    }
                }
            }
        }
        printf("Case %d:\n", t);
        for(int i=0;i<n;i++) 
        {
            cout << (a[i][0] == 0 ? 0 : 1);
            for(int j=1;j<m;j++)
            {
                cout << " " << (a[i][j] == 0 ? 0 : 1);
            }
            cout << endl;
        }

    }
    return 0;
}
