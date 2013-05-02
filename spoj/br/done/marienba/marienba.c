#include <stdio.h>

int main()
{
    int val, i, n, bin[4], k, j, f, count1=0, count0=0;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<4;j++)
        {
            bin[j] = 0;
        }
        count1 = 0;
        count0 = 0;
        f=0;
        for(j=0;j<6;j++)
        {
            scanf("%d", &val);
            k=0;
            if(val == 0)
                count0++;
            if(val == 1)
                count1++;
            while(val > 0)
            {
                bin[k] += val%2;
                val /= 2;
                k++;
            }
        }
        for(j=0;j<4;j++)
        {
            if(bin[j]%2 != 0)
            {
                f = 1;
                break;
            }
        }
        printf("Instancia %d\n", i);
        if(count1+count0 == 6 && count1%2 == 0)
            printf("sim\n\n");
        else if(count1+count0 == 6 && count1%2 != 0)
            printf("nao\n\n");
        else if(f == 1)
            printf("sim\n\n");
        else
            printf("nao\n\n");
    }
    return 0;
}

