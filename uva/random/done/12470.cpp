#include <stdio.h>
#include <string.h>
#define MOD 1000000009

using namespace std;

long long trib[3][3], ret[3][3];

void init()
{
    memset(trib,0,sizeof(trib));
    memset(ret,0,sizeof(ret));
    trib[0][0] = 1;
    trib[0][1] = 1;
    trib[0][2] = 1;
    trib[1][0] = 1;
    trib[2][1] = 1;
    ret[0][0] = 1;
    ret[1][1] = 1;
    ret[2][2] = 1;
}

void square()
{
    int aux[3][3];
    memset(aux,0,sizeof(aux));
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) for(int k=0;k<3;k++) aux[i][j] = (aux[i][j] + (trib[i][k]*trib[k][j])%MOD)%MOD;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) trib[i][j] = aux[i][j];
}

void tribxret()
{
    int aux[3][3];
    memset(aux,0,sizeof(aux));
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) for(int k=0;k<3;k++) aux[i][j] = (aux[i][j] + (ret[i][k]*trib[k][j])%MOD)%MOD;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) ret[i][j] = aux[i][j];
}

void fastexp(long long n)
{
    n -= 3;
    while(n > 0)
    {
        if(n%2) tribxret();
        square();
        n /= 2;
    }
}

int app(long long n)
{
    if(n == 1) return 0;
    if(n == 2) return 1;
    return (2*ret[0][0] + ret[0][1])%MOD;
}

int main()
{
    long long n;
    while(scanf("%lld", &n) && n)
    {
        init();
        fastexp(n);
        printf("%d\n", app(n));
    }
    return 0;
}
