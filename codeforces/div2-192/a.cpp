#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int vis[22][22];

int main()
{
    int r, c;
    int ret=0;
    char k[22][22];
    cin >> r >> c;
    for(int i=0;i<r;i++)
    {
        int p=0;
        for(int j=0;j<c;j++)
        {
            cin >> k[i][j];
            if(k[i][j] == 'S') p = 1;
        }
        if(!p)
        {
            for(int j=0;j<c;j++)
            {
                if(!vis[i][j]) ret++;
                vis[i][j] = 1;
            }
        }
    }
    for(int i=0;i<c;i++)
    {
        int p=0;
        for(int j=0;j<r;j++) if(k[j][i] == 'S') p = 1;
        if(!p)
        {
            for(int j=0;j<r;j++)
            {
                if(!vis[j][i]) ret++;
                vis[j][i] = 1;
            }
        }

    }
    cout << ret << endl;
    return 0;
}
