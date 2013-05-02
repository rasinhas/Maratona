#include <stdio.h>
#include <iostream>

using namespace std;

int tree[2][100010];
//t=0 => 0  // t=1 => -
int seq[100010];
int n;

int read(int idx, int t)
{
    int sum=0;
    while(idx > 0)
    {
        sum += tree[t][idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val, int t)
{
    while(idx<=n)
    {
        tree[t][idx]+=val;
        idx+=(idx & -idx);
    }
}

int main()
{
    int i, k;
    int j, v, aux;
    char c;
    while(scanf("%d%d", &n, &k) != EOF)
    {
        for(i=0;i<=n;i++)
        {
            tree[0][i] = 0;
            tree[1][i] = 0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d", &seq[i]);
            if(seq[i] == 0) update(i,1,0);
            else if(seq[i] < 0) update(i,1,1);
        }
        for(i=0;i<k;i++) 
        {
            scanf(" %c %d %d", &c, &j, &v);
            if(c == 'C')
            {
                if(seq[j] < 0 && v >= 0) update(j,-1,1);// diminui o contador de negativos
                if(seq[j] >= 0 && v < 0) update(j,1,1);// aumenta o contador de negativos
                if(v != 0 && seq[j] == 0) update(j,-1,0);// diminui o contador de zeros
                if(seq[j] != 0 && v == 0) update(j,1,0);// aumenta o contador de zeros
                seq[j] = v;
            }
            else
            {
                if((read(v,0)-read(j-1,0)) > 0) printf("0");
                else if((read(v,1)-read(j-1,1))%2 == 1) printf("-");
                else printf("+");
            }
        }
        printf("\n");
    }
    return 0;
}

