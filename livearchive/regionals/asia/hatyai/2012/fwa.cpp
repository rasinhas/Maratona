#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctype.h>
#define INF 0x3f3f3f3f
#define MOD 10007

using namespace std;

int mod(int a) { return a > 0 ? a : -a; }
int gcd(int a, int b) { return (b) ? gcd(b,a%b): a;}

typedef struct
{
    int c[200];
    int grau;
} polinomio;

int fexp(int n, int e)
{
    if(e == 0) return 1;
    if(e == 1) return n;
    if(e%2 == 0) return fexp((n*n)%MOD,e/2);
    if(e%2 == 1) return (n*fexp(n,e-1))%MOD;
}

void imprimir(polinomio p)
{
    int i;
    for(i=0;i<p.grau;i++) printf("%d ", p.c[i]);
    printf("\n");
}

polinomio produto(polinomio a, polinomio b)
{
    polinomio resp;
    int i, j;
    resp.grau = a.grau + b.grau - 1;
    for(i=0;i<resp.grau;i++) resp.c[i] = 0;
    for(i=0;i<a.grau;i++) for(j=0;j<b.grau;j++) resp.c[i+j] = (resp.c[i+j] + ((((a.c[i] * b.c[j])%MOD)*fexp(gcd(a.c[i],b.c[j]),MOD-2))%MOD))%MOD;
    return resp;
}

int main()
{
    int C, c, t[110], ans, n;
    int i;
    polinomio p[110], pol;
    scanf("%d", &C);
    c = C;
    while(c--)
    {
        memset(pol.c,0,sizeof(pol.c));
        ans = 0;
        pol.c[0] = 1;
        pol.grau = 1;
        scanf("%d", &n);
        for(i=0;i<n;i++)
        {
            scanf("%d", &t[i]);
            p[i].c[0] = -t[i];
            p[i].c[1] = 1;
            p[i].grau = 2;
            pol = produto(pol,p[i]);
            //imprimir(p[i]);
        }
        imprimir(pol);
        for(i=0;i<pol.grau-1;i++) ans = (ans + mod(pol.c[i]))%MOD;
        printf("Case %d: %d\n", C-c, ans);
    }
    return 0;
}
