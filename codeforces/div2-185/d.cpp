#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cost[310][310];
int l[100100], r[100100], c[100100];

//TODO
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    //memset(cost, 0x01, sizeof(cost));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cost[i][j] = 99;
    cout << cost[0][0] << endl;
    for(int i=0;i<m;i++)
    {
        cin >> l[i] >> r[i] >> c[i];
        for(int j=l[i];j<=r[i];j++) 
        {
            cost[j][r[i]] = min(cost[j][r[i]], c[i]);
            cost[l[i]][j] = min(cost[l[i]][j], c[i]);
        }
    }
    for(int i=0;i<n;i++)
        for(int k=i;k<n;k++)
            for(int j=k+1;j<n;j++)
                cost[i][j] = min(cost[i][j],cost[i][k]+cost[k+1][j]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%3d", cost[i][j]);
        printf("\n");
    }
    return 0;
}
