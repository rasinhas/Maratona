#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int acm[5555][5555], a[5555], m[5555];

int main()
{
    int n, sol = 0;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++)
    {
        acm[i][i] = 0;
        for(int j=i-1;j>=0;j--)
        {
            acm[i][j] = acm[i][j+1];
            if(a[i] < a[j])
            {
                acm[i][j]++;
                m[i]++;
            }
            else acm[i][j]--;
        }
        for(int j=i+1;j<n;j++)
        {
            acm[i][j] = acm[i][j-1];
            if(a[i] > a[j]) acm[i][j]++;
            else acm[i][j]--;
        }
        sol += m[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%3d", acm[i][j]);
        }
        cout << endl;
    }
    int best = 0, k = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            int c = acm[i][j] + acm[j][i] - 1;
            if(c > best)
            {
                best = c;
                k = 0;
            }
            if(c == best) k++;
        }
    }
    cout << sol-best << " " << k << endl;
    return 0;
}
