#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#define inf 1e9
#define sz size()

using namespace std;

int isp[2222][2222];
int b[2222];

int main()
{
    int n;
    int t=1;
    string s;
    while(scanf("%d", &n) && n)
    {
        printf("Teste %d\n", t++);
        cin >> s;
        for(int i=0;i<n;i++) memset(isp[i],0,n*sizeof(int));
        for(int i=0;i<n;i++) b[i] = inf;
        for(int i=0;i<n;i++) isp[i][i] = 1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i] == s[j]) 
                {
                    if(j-i < 2) isp[i][j] = 1;
                    else if(isp[i+1][j-1]) isp[i][j] = 1;
                }
            }
        }
        b[0] = 1;
        for(int i=0;i<n;i++) for(int j=0;j<=i;j++) if(isp[j][i]) b[i] = min(b[j-1]+1,b[i]);
        cout << b[n-1] << endl << endl;;
    }
    return 0;
}
