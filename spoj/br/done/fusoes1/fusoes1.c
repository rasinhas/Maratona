#include <stdio.h>
#include <string.h>

int pai[100100], rank[100100], sz[100100];

void init_set(int p)
{
    int i;
    for(i=0;i<p;i++) 
    {
        pai[i] = i;
        rank[i] = 0;
        sz[i] = 1;
    }
}

int find_set(int x)
{
    if(x != pai[x])
    {
        pai[x] = find_set(pai[x]);
    }
    return pai[x];
}

void merge_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if(x==y) return;
    if(rank[x] > rank[y])
    {
        pai[y] = x;
        sz[x] += sz[y];
    }
    else
    {
        pai[x] = y;
        sz[y] += sz[x];
        if(rank[x] == rank[y]) rank[y]++;
    }
}

int main()
{
    int i, n, k, b, a;
    char q;
    scanf("%d %d", &n, &k);
    init_set(n);
    for(i=0;i<k;i++)
    {
        scanf(" %c %d %d", &q, &a, &b);
        if(q == 'F')
        {
            if(find_set(a) != find_set(b)) merge_set(a,b);
        }
        else
        {
            if(find_set(a) != find_set(b)) printf("N\n");
            else printf("S\n");
        }
    }
    return 0;
}
