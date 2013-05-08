#include <stdio.h>

typedef struct
{
    int l, r;
}soldier;

int main()
{
    soldier sold[101000];
    int i, s, b, r, l;
    while(scanf("%d %d", &s, &b) && s)
    {
        for(i=1;i<=s;i++)
        {
            sold[i].l = i-1;
            sold[i].r = i+1;
        }
        sold[s].r = 0;
        for(i=0;i<b;i++)
        {
            scanf("%d%d", &l, &r);
            sold[sold[l].l].r = sold[r].r;
            sold[sold[r].r].l = sold[l].l;
            if(sold[l].l == 0 && sold[r].r == 0) printf("* *\n");
            else if(sold[l].l == 0) printf("* %d\n", sold[r].r);
            else if(sold[r].r == 0) printf("%d *\n", sold[l].l);
            else printf("%d %d\n", sold[l].l, sold[r].r);
        }
        printf("-\n");
    }
    return 0;
}
