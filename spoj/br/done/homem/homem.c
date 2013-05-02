#include <stdio.h>

typedef struct {
    int h, e, r, lazy;
} interval;

interval M[500000];

interval join(interval i1, interval i2)
{
    interval aux;
    aux.h=i1.h+i2.h;
    aux.e=i1.e+i2.e;
    aux.r=i1.r+i2.r;
    return aux;
}

void initialize(int node, int b, int e)
{
    if(b==e)
    {
        M[node].h=1;
        M[node].e=M[node].r=M[node].lazy=0;
    }
    else
    {
        initialize(2*node, b, (b+e)/2);
        initialize(2*node+1, (b+e)/2+1, e);
        M[node].h=M[2*node].h+M[2*node+1].h;
        M[node].e=M[node].r=M[node].lazy=0;
    }
}

interval query(int node, int b, int e, int i, int j)
{
    interval p1, p2;
    int auxh, auxe, auxr;
    if(M[node].lazy==1)
    {
        auxh=M[node].h;
        auxe=M[node].e;
        auxr=M[node].r;
        M[node].h=auxr;
        M[node].e=auxh;
        M[node].r=auxe;
        if(b!=e)
        {
            M[2*node].lazy=(M[2*node].lazy+M[node].lazy)%3; 
            M[2*node+1].lazy=(M[2*node+1].lazy+M[node].lazy)%3; 
        }
        M[node].lazy=0;
    }
    else if(M[node].lazy==2)
    {
        auxh=M[node].h;
        auxe=M[node].e;
        auxr=M[node].r;
        M[node].h=auxe;
        M[node].e=auxr;
        M[node].r=auxh;
        if(b!=e)
        {
            M[2*node].lazy=(M[2*node].lazy+M[node].lazy)%3; 
            M[2*node+1].lazy=(M[2*node+1].lazy+M[node].lazy)%3; 
        }
        M[node].lazy=0;
    }
    if(j<b || i>e)
    {
        p1.h=-1;
        return p1;
    }
    if(i<=b && j>=e) return M[node];
    p1=query(2*node, b, (b+e)/2, i, j);
    p2=query(2*node+1, (b+e)/2+1, e, i, j);
    M[node].h = M[2*node].h+M[2*node+1].h;
    M[node].e = M[2*node].e+M[2*node+1].e;
    M[node].r = M[2*node].r+M[2*node+1].r;
    if(p1.h==-1) return p2;
    if(p2.h==-1) return p1;
    return join(p1, p2);
}

void update(int node, int b, int e, int i, int j)
{
    int auxh, auxe, auxr;
    if(i<=b && j>=e) M[node].lazy = (M[node].lazy+1)%3;
    if(M[node].lazy==1)
    {
        auxh=M[node].h;
        auxe=M[node].e;
        auxr=M[node].r;
        M[node].h=auxr;
        M[node].e=auxh;
        M[node].r=auxe;
    }
    if(M[node].lazy==2)
    {
        auxh=M[node].h;
        auxe=M[node].e;
        auxr=M[node].r;
        M[node].h=auxe;
        M[node].e=auxr;
        M[node].r=auxh;
    }
    if(b!=e)
    {
        M[2*node].lazy=(M[2*node].lazy+M[node].lazy)%3;   
        M[2*node+1].lazy=(M[2*node+1].lazy+M[node].lazy)%3;   
    }
    M[node].lazy=0;
    if(j<b || i>e) return;
    if(!(i<=b && j>=e))
    {
        update(2*node, b, (b+e)/2, i, j);
        update(2*node+1, (b+e)/2+1, e, i, j);
        M[node].h = M[2*node].h+M[2*node+1].h;
        M[node].e = M[2*node].e+M[2*node+1].e;
        M[node].r = M[2*node].r+M[2*node+1].r;
    }
}

int main()
{
    int i, n, m, a, b;
    char c[2];
    interval resp;
    while(scanf("%d %d", &n, &m)!=EOF)
    {
        initialize(1, 0, n-1);
        for(i=0; i<m; i++)
        {
            scanf("%s %d %d", c, &a, &b);
            a--, b--;
            if(c[0]=='M')
            {
                update(1, 0, n-1, a, b);
            }
            else
            {
                resp=query(1, 0, n-1, a, b);
                printf("%d %d %d\n", resp.h, resp.e, resp.r);
            }
        }
        printf("\n");
    }
    return 0;   
}


