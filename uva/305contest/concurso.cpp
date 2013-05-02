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
    int i, lin, car, pag, len, n, l, c;
    string palavra;
    while(scanf("%d%d%d", &n, &l, &c) != EOF)
    {
        car = 0;
        lin = 1;
        for(i=0;i<n;i++)
        {
            cin >> palavra;
            len = palavra.size();
            if(car == 0) car = len;
            else if(car + len + 1 > c)
            {
                car = len;
                lin++;
            }
            else
            {
                car += len + 1;
            }
        }
        pag = lin/l;
        if(lin%l != 0) pag++;
        printf("%d\n", pag);
    }
	return 0;
}
