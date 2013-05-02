#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int n, m, c, i, k, d[10], c2;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        c2 = 0;
        c = 0;
        for(i=n;i<=m;i++)
        {
            memset(d,0,10*sizeof(int));
            k = i;
            while(k > 0)
            {
                d[k%10]++;
                if(d[k%10] > 1) 
                {
                    c++;
                    break;
                }
                k/=10;
            }
            c2++;
        }
        printf("%d\n", c2-c);
    }
    return 0;
}
