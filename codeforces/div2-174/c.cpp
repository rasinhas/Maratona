#include <iostream>
#include <cstdio>

using namespace std;

int l[201000], p[201000]; 

int main()
{
    int n, k, a, t, x, top=0;
    double sum=0.0;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &t);
        if(t == 1)
        {
            scanf("%d%d", &a, &x);
            p[a-1] += x;
            sum += a*x;
        }
        else if(t == 2)
        {
            scanf("%d", &k);
            l[++top] = k;
            sum += k;
        }
        else
        {
            sum -= (l[top] + p[top]);
            p[top-1] += p[top];
            p[top] = 0;
            l[top--] = 0;
        }
        printf("%.6lf\n", sum/(top+1));
    }
    return 0;
}
