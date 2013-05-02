#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int n, k, t;
    string str;
    int ret;
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        scanf("%d%d", &n, &k);
        cin >> str;
        printf("Case %d: ", i+1);
        ret = 0;
        for(int j=0;j<n;j++)
        {
            for(int l=j-1;l>=max(0,j-k);l--)
            {
                if(str[j] == str[l])
                {
                    ret++;
                    break;
                }
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
