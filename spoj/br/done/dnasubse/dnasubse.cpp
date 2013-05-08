#include <iostream>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f

using namespace std;

typedef pair <int, int> pii;

int lcs[1001][1001];
int subs[1001][1001];

int main()
{
    int n, len1, len2, ret, k;
    int i, j;
    char s1[1001], s2[1001];
    while(scanf("%d", &n) && n)
    {
        scanf("%s",s1);
        scanf("%s",s2);
        len1 = strlen(s1);
        len2 = strlen(s2);
        for(i=0;i<=len1;i++)
        {
            memset(subs[i],0,(len2+1)*sizeof(int));
            memset(lcs[i],0,(len2+1)*sizeof(int));
        }
        ret = 0;
        for(i=len1-1;i>=0;i--)
        {
            for(j=len2-1;j>=0;j--)
            {
                lcs[i][j] = max(lcs[i+1][j], lcs[i][j+1]);
                if(s1[i] == s2[j]) 
                {
                    subs[i][j] = subs[i+1][j+1] + 1;
                    if(subs[i][j] >= n) for(k=n;k<=subs[i][j];k++) lcs[i][j] = max(lcs[i][j],lcs[i+k][j+k]+k);
                }
                ret = max(ret, lcs[i][j]) ;
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}


