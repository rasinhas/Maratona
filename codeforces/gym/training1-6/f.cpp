#include <iostream>
#include <cstdio>

using namespace std;

int a[111], p[111];
int cost[111], ac[111];

int main()
{
    int t, c;
    cin >> t;
    while(t--)
    {
        cin >> c;
        for(int i=0;i<c;i++)
        {
            cin >> a[i] >> p[i];
            if(i) ac[i] = ac[i-1] + a[i];
            else ac[i] = a[i];
        }
        int b=0;
        for(int i=0;i<c;i++)
        {
            cost[i] = 0x3f3f3f3f;
            for(int j=b;j<=i;j++)
            {
                if(j == 0 && p[i]*(ac[i]+10) < cost[i]) cost[i] = p[i]*(ac[i]+10);
                if(p[i]*(ac[i]-ac[j]+10)+cost[j] < cost[i])
                {
                    b = j;
                    cost[i] = p[i]*(ac[i]-ac[j]+10)+cost[j];
                }
            }
        }
        cout << cost[c-1] << endl;
    }
    return 0;
}
