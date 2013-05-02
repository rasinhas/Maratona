#include <stdio.h>

int main()
{
    int seq[100100];
    int n, i;
    int ret=1;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&seq[i]);
    for(i=2;i<n;i++)
    {
        if(seq[i-1]-seq[i] != seq[i-2]-seq[i-1])
        {
            seq[i-1]=2*seq[i]-seq[i+1];
            ret++;
        }
    }
    printf("%d\n",ret);
    return 0;
}
