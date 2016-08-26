#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

string s[22];
int sq[22][22];
int valid;

void find(int xi, int yi, int k)
{
    if(k > 1) valid = 0;
    int xf, yf;
    for(yf=yi;s[xi][yf+1] == '#';yf++);
    xf = xi + yf - yi;
    for(int x=xi;x<=xf;x++) for(int y=yi;y<=yf;y++) 
    {
        if(s[x][y] != '#') valid = 0;
        else sq[x][y] = k;
    }
}

int main()
{
    int n, T;
    cin >> T;
    for(int t=1;t<=T;t++)
    {
        cin >> n;
        valid = 1;
        memset(sq,0,sizeof(sq));
        for(int i=0;i<n;i++) cin >> s[i];
        int v = 1;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) 
        {
            if(!sq[i][j] && s[i][j] == '#')
            {
                find(i,j,v);
                v++;
            }
        }
        printf("Case #%d: %s\n", t, (valid ? "YES" : "NO"));
    }
    return 0;
}
