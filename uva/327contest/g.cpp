#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[222];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int c[44], r = 0;
        getchar();
        memset(c,0,sizeof(c));
        scanf("%[^\n]", str);
        int len = strlen(str);
        for(int i=0;i<len;i++)
        {
            if(str[i] == ' ') continue;
            if(str[i] >= 'A' && str[i] <= 'Z') c[str[i]-'A']++;
            else c[str[i]-'0'+26]++;
        }
        sort(c,c+36,greater<int>());
        int k=0;
        for(int i=1;i<=6;i++)
        {
            for(int j=0;j<i;j++)
            {
                r += (i+1)*c[k];
                if(i != 6) r += (12-(i-1))*c[35-k];
                k++;
            }
        }
        cout << r << endl;
    }
    return 0;
}
