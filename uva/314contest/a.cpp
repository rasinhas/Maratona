#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <cmath>
#define pb push_back
#define mp make_pair
#define read(x) scanf("%d", &x)
#define inf 0x3f3f3f3f

using namespace std;

int main()
{
    char str[20][200], slg[20][200], qry[200];
    int n, q, f, len;
    scanf("%d", &n);
    getchar();
    for(int i=0;i<n;i++)
    {
        scanf("%[^\n]", str[i]);
        getchar();
        scanf("%[^\n]", slg[i]);
        getchar();
    }
    scanf("%d", &q);
    getchar();
    for(int i=0;i<q;i++)
    {   
        scanf("%[^\n]", qry);
        getchar();
        len = strlen(qry);
        for(int j=0;j<n;j++)
        {
            f=0;
            if(strlen(str[j]) < len) continue;
            for(int k=0;k<len;k++)
            {
                if(str[j][k] != qry[k])
                {
                    f=1;
                    break;
                }
            }
            if(f==0) 
            {
                printf("%s\n", slg[j]);
                break;
            }
        }
    }
    return 0;
}
