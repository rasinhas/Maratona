#include <iostream>
#include <ctype.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f

using namespace std;

typedef pair <int, int> pii;

int finv(int a)
{
    int gasto = 0;
    if(a <= 200) gasto = a/2;
    else if(a <= 29900) gasto = 100 + (a-200)/3;
    else if(a <= 4979900) gasto = 10000 + (a-29900)/5;
    else gasto = 1000000 + (a-4979900)/7;
    return gasto;
}

int f(int a)
{
    int preco = 0;
    if(a <= 100) preco = a*2;
    else if(a <= 10000) preco = 200 + 3*(a-100);
    else if(a<= 1000000) preco = 29900 + 5*(a-10000);
    else preco = 4979900 + 7*(a-1000000);
    return preco;
}

int bin(int lo, int hi, int a, int b)
{
    int mi = (hi+lo)/2;
    if(mi == lo) return hi;
    if(f(a-mi)-f(mi) > b) return bin(mi,hi,a,b);
    else if(f(a-mi)-f(mi) < b) return bin(lo,mi,a,b);
    else return mi;
}

int main()
{
    int a, b, gasto, ret;
    while(scanf("%d%d", &a, &b) && a)
    {
        ret = bin(0,finv(a)/2, finv(a), b);
        printf("%d\n", f(ret));
    }
	return 0;
}
