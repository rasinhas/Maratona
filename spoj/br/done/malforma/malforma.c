#include <stdio.h>
#include <string.h>

long long pd[55][55];

void int2coco(long long k, int n, char *str)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(k%2) str[i] = ')';
        else str[i] = '(';
        k/=2;
    }
    str[n] = '\0';
}

long long solve(long long k, int n)
{
    int acc, i;
    long long ret;
    char str[52];
    int2coco(k,n,str);
    ret = 0;
    acc = 0;
    for(i=n-1;i>=0;i--)
    {
        if(str[i] == '(') acc++;
        else
        {
            ret += pd[i][acc+1];
            acc--;
        }
        if(acc < 0) break;
    }
    if(acc == 0) ret++;
    return ret;
}

int main()
{
    int i, j, n, t;
    long long k, last, curr;
    char str[52];
    memset(pd[0],0,51*sizeof(int));
    pd[0][0] = 1;
    for(i=1;i<51;i++)
    {
        for(j=0;j<51;j++)
        {
            if(j>0) pd[i][j] += pd[i-1][j-1];
            if(j<51) pd[i][j] += pd[i-1][j+1];
        }
    }
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
        scanf("%d %lld", &n, &k);
        curr = solve(k,n);
        last = 0;
        while(curr - last)
        {
            k += (curr - last);
            last = curr;
            if(k >= (long long)1<<(n)) break;
            curr = solve(k,n);
        }
        if(k >= (long long)1<<n) printf("-1\n");
        else
        {
            int2coco(k,n,str);
            for(j=n-1;j>=0;j--) printf("%c", str[j]);
            printf("\n");
        }
    }
    return 0;
}
