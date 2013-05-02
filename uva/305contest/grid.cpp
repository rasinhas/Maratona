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

int main()
{
    int i, n, v1[100], v2[100], t, j, a;
    while(scanf("%d", &n) != EOF)
    {
        t=0;
        for(i=0;i<n;i++)
        {
            scanf("%d", &a);
            v1[a] = i;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d", &a);
            v2[v1[a]] = i;
        }
        for(i=0;i<n;i++)
            for(j=0;j<i;j++)
                if(v2[i] < v2[j]) t++;
        printf("%d\n", t);
    }
	return 0;
}
