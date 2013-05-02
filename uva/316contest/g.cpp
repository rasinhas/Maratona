#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, t, w, x[1100], p, d, a; 
    scanf("%d", &t);
    for(int i=0;i<t;i++)
    {
        d = 0;
        a = 0;
        scanf("%d%d", &w, &n);
        for(int j=0;j<n;j++)
        {
            scanf("%d%d",&x[j],&p);
            if(j == 0) d += x[j];
            else d += x[j] - x[j-1];
            if(a + p <= w) a += p;
            else 
            {
                d += 2*x[j];
                a = p;
            }
            if(j == n-1)
            {
                d += x[j];
                break;
            }
            if(a == w)
            {
                d += 2*x[j];
                a = 0;
            }
        }
        printf("%d\n", d);
    }
    return 0;
}
