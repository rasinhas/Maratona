#include <stdio.h>
#include <math.h>

int main()
{
    float bact[70000], max;
    int i, a, b, n, maxi;
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d", &a, &b);
        if(b*log((float)a) > max)
        {
            max = b*log((float)a);
            maxi = i;
        }
    }
    printf("%d\n", maxi);
    return 0;
}
