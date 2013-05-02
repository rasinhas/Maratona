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

int mod(int a) { return a >= 0 ? a : -a; }

int main()
{
    int i, n, med, ret, tom[10100];
    while(scanf("%d", &n) != EOF)
    {
        med = 0;
        ret = -1;
        for(i=0;i<n;i++)
        {
            scanf("%d", &tom[i]);
            med += tom[i];
        }
        if(med%n == 0)
        {
            med /= n;
            ret = 0;
            for(i=0;i<n;i++)
            {
                ret += mod(tom[i]-med);
            }
            ret /= 2;
            ret += 1;
        }
        printf("%d\n", ret);
    }
	return 0;
}
