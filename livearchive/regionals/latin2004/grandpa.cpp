#include <stdio.h>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int i, j, n, m, first, second, p;
    int pont[10100];
    while(scanf("%d%d", &n, &m) && n)
    {
        for(i=0;i<10001;i++) pont[i] = 0;
        first = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d", &p);
                pont[p]++;
                first = max(first,pont[p]);
            }
        }
        second = 0;
        for(i=0;i<10001;i++)
        {
            if(pont[i] < first) second = max(second,pont[i]);
        }
        for(i=0;i<10001;i++) if(pont[i] == second) printf("%d ", i);
        printf("\n");
    }
    return 0;
}
